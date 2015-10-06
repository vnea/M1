#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>

#define NB_FILS 5

void sig_hand(int sig) {
    kill(getppid(), SIGSTOP);
    pause();
}

int main(int argc, char **argv) {
    pid_t pid, pid_init, pids[NB_FILS];
    pid_init = getpid();
    
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
                
                kill(getppid(), SIGSTOP);
                exit(1);
            }
        }
        // Père
        else {
            sigset_t sig_proc1;
            struct sigaction action1;
            sigemptyset(&sig_proc1);
            
            action1.sa_mask = sig_proc1;
            action1.sa_flags = 0;
            action1.sa_handler = sig_hand;
            sigaction(SIGSTOP, &action1, NULL);
            
            // On attend le signal du fils
            pause();
        	if (getpid() == pid_init) {
            	printf("Tous les descendants stoppés.\n");
            }
            exit(1);
        }
    }
        
    return 0;
}

