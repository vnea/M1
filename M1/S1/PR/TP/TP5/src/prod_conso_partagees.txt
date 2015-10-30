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
        while (stack_size == TAILLE_PILE - 1) {
             pthread_cond_wait(&cond_pile_pleine, &mutex);
        }
        
        pile[stack_size] = c;
        
        /* On envoie un signal au consommateur */
        if (stack_size == 0) {
            pthread_cond_broadcast(&cond_pile_vide);
        }
        
        ++stack_size;
    pthread_mutex_unlock(&mutex);
}

char pop() {
    char c;
    pthread_mutex_lock(&mutex);
        /* Pile vide */
        while (stack_size == 0) {
             pthread_cond_wait(&cond_pile_vide, &mutex);
        }
        
        c = pile[--stack_size];
        
        /* On envoie un signal au producteur */
        if (stack_size == TAILLE_PILE - 1) {
            pthread_cond_broadcast(&cond_pile_pleine);
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

int main(int argc, char **argv) {
    pthread_t *prods, *consos;
    int nb_prods, nb_consos, i;
    
    /* Nombre d'arguments invalide */
    if (argc != 3) {
        printf("Usage : producteurs_consommateurs nb_prod nb_cons\n");
        return EXIT_FAILURE;
    }
    
    /* Vérification nb_prod */
    nb_prods = atoi(argv[1]);
    if (!nb_prods) {
        printf ("nb_prod doit être un nombre strictement positif.\n");
        return EXIT_FAILURE;
    }
    
    /* Vérification nb_cons */
    nb_consos = atoi(argv[2]);
    if (!nb_consos) {
        printf ("nb_cons doit être un nombre strictement positif.\n");
        return EXIT_FAILURE;
    }
    
    /* Création des producteurs */
    prods = malloc(sizeof(pthread_t) * nb_prods);
    for (i = 0; i < nb_prods; ++i) {
        if (pthread_create(&prods[i], NULL, prod_thread, NULL) != 0) {
            perror("Erreur pthread_create.\n");
            free(prods);
            return EXIT_FAILURE;
        }
    }
    
    /* Création des consommateurs */
    consos = malloc(sizeof(pthread_t) * nb_consos);
    for (i = 0; i < nb_consos; ++i) {
        if (pthread_create(&consos[i], NULL, cons_thread, NULL) != 0) {
            perror("Erreur pthread_create.\n");
            free(prods);
            free(consos);
            return EXIT_FAILURE;
        }
    }

    /* Attente des producteurs */
    for (i = 0; i < nb_prods; ++i) {
        if (pthread_join(prods[i], NULL) != 0) {
            perror("Erreur pthread_join.\n");
            free(prods);
            free(consos);
            return EXIT_FAILURE;
        }
    } 
    
    /* Attente des consommateurs */
    for (i = 0; i < nb_consos; ++i) {
        if (pthread_join(consos[i], NULL) != 0) {
            perror("Erreur pthread_join.\n");
            free(prods);
            free(consos);
            return EXIT_FAILURE;
        }
    }

    free(prods);
    free(consos);
    
    return EXIT_SUCCESS;
}

