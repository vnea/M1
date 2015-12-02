#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 256

void fprintf_exit(char *msg) {
    fprintf(stderr, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

void perror_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sock, port, done;
    struct sockaddr_in si_other;
    unsigned int si_other_len = sizeof(si_other);
    struct addrinfo *result;
    char cmd[BUFSIZE], buf[BUFSIZE];
    
    /* Erreur usage */
    if (argc != 3) {
        fprintf_exit("Usage: ./env_client host port\n");
    }

    /* Port invalide */
    if (!(port = atoi(argv[2]))) {
        fprintf_exit("port doit être strictement positif.\n");
    }
    
    /* Création socket UDP */
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror_exit("Erreur socket");
    }
    
    /* Initialisation données */
    if (getaddrinfo(argv[1], 0, 0, &result) != 0) {
        perror_exit("Erreur getaddrinfo");
    }
    memset(&si_other, 0, si_other_len);
    memcpy((void *) &((struct sockaddr_in *) result->ai_addr)->sin_addr,
           (void *) &si_other.sin_addr, si_other_len);
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(port);
    
    /* Boucle principale */
    done = 0;
    while (!done) {
        printf("Entrez une commade: ");
        fgets(cmd, BUFSIZE, stdin);
        
        /* Envoi de la commande */
        if (sendto(sock, &cmd, strlen(cmd) + 1, 0,
           (struct sockaddr *) &si_other, si_other_len) == -1) {
            perror_exit("Erreur sendto");
        }
        
        /* Réception du message */
        if (recvfrom(sock, buf, BUFSIZE, 0,
            (struct sockaddr *) &si_other, &si_other_len) == -1) {
            perror_exit("Erreur recvfrom");
        }
        
        printf("%s\n", buf);
        done = cmd[0] == 'Q';
    }
    
    
    if (shutdown(sock, SHUT_RDWR) == -1) {
        perror_exit("Erreur shutdown");
    }
    close(sock);
    
    return EXIT_SUCCESS;
}

