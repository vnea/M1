#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define NB_THREADS 5

pthread_t tid[NB_THREADS];
pthread_mutex_t mutex_fin = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_fin = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int somme = 0;
int nb_thread_execute = 0;

void *func_thread() {
    int nb_alea; 
    /* Détachement de la thread */
    if (pthread_detach(pthread_self()) != 0) {
        perror("Erreur pthread_detach.\n"); 
        exit(EXIT_FAILURE);
    }

    nb_alea = (int) (10 * ((double) rand()) / RAND_MAX);
    printf("Nombre généré par la thread : %d.\n", nb_alea);
    
    /* Sécuriser accès à la variable somme */
    pthread_mutex_lock(&mutex);
        somme += nb_alea;
        ++nb_thread_execute;
        
        /* Dernière thread = on envoie le signal */
        if (nb_thread_execute == NB_THREADS) {
            pthread_mutex_lock(&mutex_fin);
            pthread_cond_signal(&cond_fin);
            pthread_mutex_unlock(&mutex_fin);
        }
    pthread_mutex_unlock(&mutex);
    
    pthread_exit((void *) (2 * pthread_self()));

    return NULL;
}

void *func_thread_fin() {
    /* On attend le signal de la dernière thread */
    pthread_mutex_lock(&mutex_fin);
        pthread_cond_wait(&cond_fin, &mutex_fin);
    pthread_mutex_unlock(&mutex_fin);
    
    printf("Thread final, somme = %d.\n", somme);
    pthread_exit((void *) 0);

    return NULL;
}

int main() {    
    pthread_t tid_fin;
    int i, status;
    
    srand(time(NULL));
    
    /* Création threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_create(&tid[i], NULL, func_thread, NULL) != 0) {
            perror("Erreur pthread_create.\n");
            return EXIT_FAILURE;
        }
    }

    /* Création de la thread finale */
    if (pthread_create(&tid_fin, NULL, func_thread_fin, NULL) != 0) {
        perror("Erreur pthread_create.\n");
        return EXIT_FAILURE;
    }
    
    /* Attente de la thread finale */
    if (pthread_join(tid_fin, (void **) &status) != 0) {
        perror("Erreur pthread_join.\n");
        return EXIT_FAILURE;
    }

    printf("Thread final fini avec status : %d.\n", status);
    
    return EXIT_SUCCESS;
}

