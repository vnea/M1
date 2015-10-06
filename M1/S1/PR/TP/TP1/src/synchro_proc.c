#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>


void p3_cree(int sig) {
    printf("Processus P3 créé.\n");
}

void p3_termine(int sig) {
    printf("Processus P3 terminé.\n");
}

int main(int argc, char **argv) {
    pid_t pid_p1 = getpid();
    pid_t pid_p2 = fork();
	
    // Erreur
    if (pid_p2 == -1) {
        perror("Erreur fork.\n");
        exit(-1);
    }
	
    // P2
    if (pid_p2 == 0) {
        pid_t pid_p3 = fork();
		
        // Erreur
        if (pid_p3 == -1) {
            perror("Erreur fork.\n");
            exit(-1);
        }
		
        // P3
        if (pid_p3 == 0) {
            // Envoi du signal de P3 à P1
            kill(pid_p1, SIGINT);
            exit(3);
        }
		
        // P2 attend la fin de P3
        waitpid(pid_p3);
		
        // Envoi du signal de P2 à P1
        kill(pid_p1, SIGUSR1);
        exit(2);
    }
    // P1
    else {
        // Initialisation et attachement du signal de P3 à P1
        sigset_t sig_proc31;
        struct sigaction action31;
        sigemptyset(&sig_proc31);
	    
        action31.sa_mask = sig_proc31;
        action31.sa_flags = 0;
        action31.sa_handler = p3_cree;
        sigaction(SIGINT, &action31, NULL);
		
		// Initialisation et attachement du signal de P2 à P1
		sigset_t sig_proc21;
		struct sigaction action21;
		sigemptyset(&sig_proc21);
	
        action21.sa_mask = sig_proc21;
        action21.sa_flags = 0;
        action21.sa_handler = p3_termine;
        sigaction(SIGUSR1, &action21, NULL);
		
        // Attente du signal de P3 et P2
        pause();
        pause();

        // P1 attend la fin de P2
        int status;
        waitpid(pid_p2, &status);
        if (WIFEXITED(status)) {
            perror("Erreur terminaison fils P2.\n");
            return -2;
        }
        
        printf("Processus P2 terminé.\n");
    }

    return 0;
}

