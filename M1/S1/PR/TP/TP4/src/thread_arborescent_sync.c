#define _XOPEN_SOURCE 700


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <pthread.h>
#include <unistd.h>

#define max 3

void* thread_func(void* arg) {

  int i, nb;
  int *param;
  int *lvl = (int*)arg;
  pthread_t *tid;

  nb = (*lvl)+1;
	
  if (*lvl < max) {
    param = (int*)malloc(sizeof(int));
    *param = nb;
    tid = calloc(nb, sizeof(pthread_t));
    printf("%ld cree %d fils\n", pthread_self(), nb);
    for (i = 0; i < nb; i++) {
      pthread_create((tid+i), 0, thread_func, param);
    }
    for (i = 0; i < nb; i++)
      pthread_join(tid[i], NULL);
  }

  if (*lvl > 1)
    pthread_exit ( (void*)0);
	
  return (void*)0;
}

int main(int argc, char **argv) {
    pthread_t tid;
    int profondeur, *lvl;
    
    /* Nombre d'arguments invalide */
    if (argc != 2) {
        printf("Usage : thread_arborescent_sync profondeur\n");
        return EXIT_FAILURE;
    }
    
    profondeur = atoi(argv[1]);
    if (!profondeur) {
        printf("La profondeur doit être strictement positive.\n");
        return EXIT_FAILURE;
    }
    
    lvl = malloc(sizeof(int));
    *lvl = profondeur;

    /* Création de la thread */
    if (pthread_create(&tid, NULL, thread_func, lvl) != 0) {
        perror("Erreur pthread_create.\n");
        return EXIT_FAILURE;
    }
    
    /* Attente de la thread */
    if (pthread_join(tid, NULL) != 0) {
        perror("Erreur pthread_join.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

