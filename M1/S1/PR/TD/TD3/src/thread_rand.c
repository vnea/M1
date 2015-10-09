#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

#define NB_THREADS 5

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int somme = 0;

void *func_thread() {
    int nb_alea = (int) (10 * ((double) rand()) / RAND_MAX);
    printf("Nombre généré par le thread : %d.\n", nb_alea);
    
    /* Sécuriser accès à la variable somme */
    pthread_mutex_lock(&mutex);
        somme += nb_alea;
    pthread_mutex_unlock(&mutex);
    
    pthread_exit((void *) (2 * pthread_self()));

    return NULL;
}

int main() {    
    pthread_t tid[NB_THREADS];
    int i;
    long status;
    
    srand(time(NULL));
    
    /* Création threads */
    for (i = 0; i < NB_THREADS; ++i) {
        if (pthread_create(&tid[i], NULL, func_thread, NULL) != 0) {
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
    
    /* Pas besoin de sécuriser somme vu que tous les threads sont terminés */
    printf("Somme = %d.\n", somme);
    
    return EXIT_SUCCESS;
}

