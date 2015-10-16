#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <ctype.h>
#include "../include/upper.h"

#define NB_ARGS_INUTILES 2

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int num_fichier = NB_ARGS_INUTILES, NB_THREADS, NB_FICHIERS;

void *thread_func(void *arg) {
    char **args = (char **) arg;
    int num;
    
    pthread_mutex_lock(&mutex);
        /* Tant qu'il reste des fichiers à lire */
        while (num_fichier - NB_ARGS_INUTILES < NB_FICHIERS) {
            num = num_fichier;
            ++num_fichier;
            pthread_mutex_unlock(&mutex);
            printf("\"%s\" mis en majuscule par la thread n°%ld.\n",
                   args[num], pthread_self());
            upper((char *) args[num]);
            pthread_mutex_lock(&mutex);
        }
    pthread_mutex_unlock(&mutex);
    pthread_exit(0);
    
    return NULL;
}

int main(int argc, char **argv) {
    int i;
    pthread_t *tid;

    /* Erreur : nombre d'arguments insuffisant */
    if (argc < 3) {
        printf("Usage : thread_uppermax nb_threads fichier1 fichier2 ...\n");
        return EXIT_FAILURE;
    }
    
    /* Erreur : nombre de threads invalide */
    NB_THREADS = atoi(argv[1]);
    if (NB_THREADS <= 0) {
        printf("nb_threads doit être un nombre strictement positif.\n");
        return EXIT_FAILURE;
    }
    
    
    /* Erreur : plus ou autant de threads que de fichiers */
    NB_FICHIERS = argc - 2;
    if (NB_THREADS  >= NB_FICHIERS) {
        printf("nb_threads doit être inférieur au nombre de fichier.\n");
        return EXIT_FAILURE;
    }

    /* Création threads */
    tid = malloc(sizeof(pthread_t) * NB_THREADS);    
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_create(&tid[i], NULL, thread_func, (char *) argv) != 0) {
            perror("Erreur pthread_create.\n");
            free(tid);
            return EXIT_FAILURE;
        }
    }
    
    /* Attente threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("Erreur pthread_join.\n");
            free(tid);
            return EXIT_FAILURE;
        }
    }
    
    free(tid);
    return EXIT_SUCCESS;
}

