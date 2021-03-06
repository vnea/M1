#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define NB_FILS 5

int main(int argc, char **argv) {
    // Pour rand
    srand(time(NULL));
    
    pid_t pid, pids[NB_FILS];
    int i;
    for (i = 0; i < NB_FILS; ++i) {
        // Erreur
        if ((pid = fork()) == -1) {
        perror("Erreur fork.\n");
            exit(-1);
        }

        // Fils
        if (pid == 0) {
            pids[i] = getppid();

            if (i == NB_FILS - 1) {
                printf("Liste des PID :\n");
                int j;
                for (j = 0; j < NB_FILS; ++j) {
                    printf("PID %d : %d\n", (j + 1), pids[j]);
                }
                
                int random = (int)(rand () /(((double) RAND_MAX + 1) /100));
                printf("Valeur aleatoire de retour : %d\n", random);
                exit(random);
            }
        }
        // Père
        else {
            // On attend la du fils
            int status;
            pid_t pid_fils = wait(&status);

            if (!WIFEXITED(status)) {
                perror("Erreur terminaison fils.\n");
                exit(-2);
            }
            
            printf("Mon PID: %d, PID pere: %d, PID fils: %d\n",
                getpid(), getpid(), pid_fils);
            exit(1);
        }
    }
        
    return 0;
}

