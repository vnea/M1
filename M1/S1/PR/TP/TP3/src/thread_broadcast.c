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

int nb_thread_execute = 0;

void wait_barrier(int n) {
    pthread_mutex_lock(&mutex_fin);
        pthread_mutex_lock(&mutex);
            ++nb_thread_execute;
            
            /* On débloque la barrière */
            if (nb_thread_execute == n) {
                pthread_cond_broadcast(&cond_fin);
            }
            else {

                /* Chaque thread attend que tous les autres threads arrivent */
                while (nb_thread_execute != n) {
                    pthread_mutex_unlock(&mutex);
                    pthread_cond_wait(&cond_fin, &mutex_fin);
                    pthread_mutex_lock(&mutex);
                }

            }
        pthread_mutex_unlock(&mutex);
     pthread_mutex_unlock(&mutex_fin);
}

void *thread_func() {
    printf("Avant barriere.\n");
    wait_barrier(NB_THREADS);
    printf("Après barriere.\n");
    pthread_exit((void *) 0);
    
    return NULL;
}

int main() {    
    int i;
    
    /* Création threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_create(&tid[i], NULL, thread_func, NULL) != 0) {
            perror("Erreur pthread_create.\n");
            return EXIT_FAILURE;
        }
    }
    
    /* Attente threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_join(tid[i], NULL) != 0) {
            perror("Erreur pthread_join.\n");
            return EXIT_FAILURE;
        }
    }
    
    return EXIT_SUCCESS;
}

