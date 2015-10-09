#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define NB_THREADS 5

void *affichier_tid() {
    long tid = pthread_self();
    printf("Identité du thread : %ld.\n", tid);
    pthread_exit((void *) (tid * 2));
    
    return NULL;
}

int main() {
    pthread_t tid[NB_THREADS];
    int i;
    long status;
    
    /* Création threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_create(&tid[i], NULL, affichier_tid, NULL) != 0) {
            perror("Erreur pthread_create.\n");
            return EXIT_FAILURE;
        }
    }

    /* Attente threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_join(tid[i], (void **) &status) != 0) {
            perror("Erreur pthread_join.\n");
            return EXIT_FAILURE;
        }
        
        printf("Thread %d fini avec status : %ld.\n", i + 1, status);
    }
    
    return EXIT_SUCCESS;
}

