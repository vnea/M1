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
		/*printf("ok %d\n", *lvl);*/
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

int main() {
pthread_t tid;
        int *arg = malloc(sizeof(*arg));
        *arg = 1;
        printf("main %ld\n", pthread_self());
        if (pthread_create(&tid, NULL, thread_func, arg) != 0) {
            perror("Erreur pthread_create.\n");

            return EXIT_FAILURE;
            }
        if (pthread_join(tid, NULL) != 0) {
            perror("Erreur pthread_join.\n");

            return EXIT_FAILURE;
        }

    
    return EXIT_SUCCESS;
}
