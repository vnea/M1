#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "../include/producteur_consommateur.h"

#define TAILLE_PILE 100
#define NB_THREADS 2

pthread_mutex_t mutex_prod = PTHREAD_MUTEX_INITIALIZER, 
                mutex_cons = PTHREAD_MUTEX_INITIALIZER,
                mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_prod = PTHREAD_COND_INITIALIZER,
               cond_cons = PTHREAD_COND_INITIALIZER;
char pile[TAILLE_PILE];
int stack_size = 0;

void push(int c) {
    pthread_mutex_lock(&mutex);
        if (stack_size < TAILLE_PILE) {

            pile[stack_size++] = c;

            pthread_mutex_lock(&mutex_prod);
                pthread_mutex_unlock(&mutex);
                pthread_cond_signal(&cond_prod);
            pthread_mutex_unlock(&mutex_prod);
            
            pthread_mutex_lock(&mutex_cons);
                pthread_cond_wait(&cond_cons, &mutex_cons);
            pthread_mutex_unlock(&mutex_cons);
        }
    pthread_mutex_unlock(&mutex);

/*
    pthread_mutex_lock(&mutex_pile_pleine);
        pthread_mutex_lock(&mutex);
            while (stack_size < TAILLE_PILE) {
                pile[stack_size++] = c;
                pthread_mutex_unlock(&mutex);
                pthread_cond_wait(&cond_pile_pleine, &mutex_pile_pleine);
                pthread_mutex_lock(&mutex);
            }
        pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex_pile_pleine);
    */
}

char pop() {
    char c;
    pthread_mutex_lock(&mutex);
        if (stack_size > 0) {
            printf("pop\n");
            c = pile[stack_size - 1];
            --stack_size;
            
            pthread_mutex_lock(&mutex_prod);
                pthread_cond_wait(&cond_prod, &mutex_prod);
            pthread_mutex_unlock(&mutex_prod);
            
            pthread_mutex_lock(&mutex_cons);
                pthread_mutex_unlock(&mutex);
                pthread_cond_signal(&cond_cons);
            pthread_mutex_unlock(&mutex_cons);
        }
    pthread_mutex_unlock(&mutex);
    
    return c;
}

void *prod_thread() {
    PRODUCTEUR
    return NULL;
}

void *cons_thread() {
    CONSOMMATEUR
    return NULL;
}

int main() {
   /* char buf_pipe[TAILLE_PILE];*/
    pthread_t prod, conso;
    
    /* On récupère l'affichage de echo */
  /*  scanf("%s", buf_pipe);*/
    
    /* Création prod */
    if (pthread_create(&prod, NULL, prod_thread, NULL) != 0) {
            perror("Erreur pthread_create.\n");
            return EXIT_FAILURE;
    }
    
    /* Création conso */
    if (pthread_create(&conso, NULL, cons_thread, NULL) != 0) {
        perror("Erreur pthread_create.\n");
        return EXIT_FAILURE;
    }
    
    if (pthread_join(prod, NULL) != 0) {
        perror("Erreur pthread_join.\n");
        return EXIT_FAILURE;
    }

    /* Attente threads */
    if (pthread_join(conso, NULL) != 0) {
        perror("Erreur pthread_join.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

