#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex_creation = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_creation = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex_terminaison = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_terminaison = PTHREAD_COND_INITIALIZER;
pthread_t *tid;
int num_thread = 0;
int NB_THREADS;
int tousCrees = 0;

void *create_thread() {
    pthread_mutex_lock(&mutex);
        printf("Thread %ld - %d\n", pthread_self(), num_thread);
        
        /* Dernière thread */
        if (num_thread == NB_THREADS) {
            /* Réveiller le main */
                pthread_mutex_lock(&mutex_creation);
                    pthread_cond_signal(&cond_creation);
                pthread_mutex_unlock(&mutex_creation);
        }
        /* On continue la chaine de création */
        else if (pthread_create(&tid[num_thread++], NULL,
                 create_thread, NULL) != 0) {
            perror("Erreur pthread_create.\n");
            free(tid);
            tid = NULL;
            exit(EXIT_FAILURE);
        }
        
        /* On attend le signal du main */
        pthread_mutex_lock(&mutex_terminaison);
            while (!tousCrees) {
                pthread_mutex_unlock(&mutex);
                pthread_cond_wait(&cond_terminaison, &mutex_terminaison);
                pthread_mutex_lock(&mutex);
            }
        pthread_mutex_unlock(&mutex_terminaison);
    pthread_mutex_unlock(&mutex);

    pthread_exit((void *) 0);
    return NULL;
}

int main(int argc, char **argv) {
    int i, sig;
    sigset_t ens;

    /* Erreur : nombre d'arguments invalide */
    if (argc != 2) {
        printf("Usage : signal_thread nb_threads\n");
        return EXIT_FAILURE;
    }
    
    /* Erreur : nombre de threads négatif */
    NB_THREADS = atoi(argv[1]);
    if (!NB_THREADS) {
        printf("nb_threads doit être un nombre strictement positif.\n");
        return EXIT_FAILURE;
    }

    /* On masque tous les signaux */
    sigfillset(&ens);
    pthread_sigmask(SIG_SETMASK, &ens, NULL);
    
    /* On démarre la chaîne de création */
    tid = malloc(sizeof(pthread_t) * NB_THREADS);
    if (pthread_create(&tid[num_thread++], NULL, create_thread, NULL) != 0) {
        perror("Erreur pthread_create.\n");
        free(tid);
        tid = NULL;
        return EXIT_FAILURE;
    }
    
    /* On attend d'être réveillé par la dernière thread */
    pthread_mutex_lock(&mutex_creation);
        pthread_cond_wait(&cond_creation, &mutex_creation);
    pthread_mutex_unlock(&mutex_creation);
    printf("Tous mes descendants sont créés.\n");
    
    /* On attent le signal SIGINT */
    do {
        printf("\nAttente du signal CTRL + C.\n");
        sigwait(&ens, &sig);
    } while (sig != SIGINT);

    /* On réveille toutes les threads */
    pthread_mutex_lock(&mutex_terminaison);
        tousCrees = 1;
        pthread_cond_broadcast(&cond_terminaison);
    pthread_mutex_unlock(&mutex_terminaison);
    
    /* On attend toutes les threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("Erreur pthread_join.\n");
            free(tid);
            tid = NULL;
            return EXIT_FAILURE;
        }
    }
    
    printf("\nTous mes descendants se sont terminés.\n");
    
    free(tid);
    
    return EXIT_SUCCESS;
}

