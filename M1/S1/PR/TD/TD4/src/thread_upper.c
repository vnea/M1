#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <ctype.h>
#include "../include/upper.h"

void *thread_func(void *arg) {
    upper((char *) arg);
    pthread_exit(0);
    
    return NULL;
}

int main(int argc, char **argv) {
    int i;
    int const NB_THREADS = argc - 1;
    pthread_t *tid;
    
    if (argc < 2) {
        printf("Usage : thread_upper fichier1 ...\n");
        return EXIT_FAILURE;
    }
    
    tid = malloc(sizeof(pthread_t) * NB_THREADS);
    /* Création threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_create(&tid[i], NULL, thread_func, argv[i + 1]) != 0) {
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

