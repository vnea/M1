#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "../include/producteur_consommateur.h"

#define TAILLE_PILE 100

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_pile_pleine = PTHREAD_COND_INITIALIZER,
               cond_pile_vide = PTHREAD_COND_INITIALIZER;

char pile[TAILLE_PILE];
int stack_size = 0;

void push(int c) {
    pthread_mutex_lock(&mutex);
        /* Pile pleine */
        if (stack_size == TAILLE_PILE - 1) {
             pthread_cond_wait(&cond_pile_pleine, &mutex);
        }
        
        pile[stack_size] = c;
        
        /* On envoie un signal au consommateur */
        if (stack_size == 0) {
            pthread_cond_signal(&cond_pile_vide);
        }
        
        ++stack_size;
    pthread_mutex_unlock(&mutex);
}

char pop() {
    char c;
    pthread_mutex_lock(&mutex);
        /* Pile vide */
        if (stack_size == 0) {
             pthread_cond_wait(&cond_pile_vide, &mutex);
        }
        
        c = pile[--stack_size];
        
        /* On envoie un signal au producteur */
        if (stack_size == TAILLE_PILE - 1) {
            pthread_cond_signal(&cond_pile_pleine);
        }
    pthread_mutex_unlock(&mutex);
    
    return c;
}

void *prod_thread() {
    PRODUCTEUR
    pthread_exit((void *) 0); 
    
    return NULL;
}

void *cons_thread() {
    CONSOMMATEUR
    pthread_exit((void *) 0); 
    
    return NULL;
}

int main() {
    pthread_t prod, conso;
    
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
    
    /* Attente thread prod */
    if (pthread_join(prod, NULL) != 0) {
        perror("Erreur pthread_join.\n");
        return EXIT_FAILURE;
    }

    /* Attente thread conso */
    if (pthread_join(conso, NULL) != 0) {
        perror("Erreur pthread_join.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

