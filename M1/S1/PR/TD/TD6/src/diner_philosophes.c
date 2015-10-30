#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void fprintf_exit_failure(char *msg) {
    fprintf(stderr, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

void perror_exit_failure(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int N, C, P, M, i;
    pid_t pid;
    
    /* Nombre d'arguments invalide */
    if (argc != 5) {
        fprintf_exit_failure("Usage : ./diner_philosophes N C P M\n");
    }
    
    N = atoi(argv[1]);
    C = atoi(argv[2]);
    P = atoi(argv[3]);
    M = atoi(argv[4]);
    
    /* Création des fils */
    for (i = 0; i < N; ++i) {
        if ((pid = fork()) == -1) {
            perror_exit_failure("Erreur fork");
        }
    }
   
    return EXIT_SUCCESS;
}

