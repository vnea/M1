#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <netdb.h>

#define BUFSIZE 4096

void fprintf_exit(char *msg) {
    fprintf(stderr, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

void perror_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    int sock, port, fsize;
    struct sockaddr_in si_other;
    unsigned int si_other_len = sizeof(si_other);
    char buf[BUFSIZE];
    FILE *f;
    struct addrinfo *result;

    /* Erreur usage */
    if (argc != 4) {
        fprintf_exit("Usage: ./sendfile host port nom_fichier\n");
    }
    
    /* Port invalide */
    if (!(port = atoi(argv[2]))) {
        fprintf_exit("port doit être strictement positif.\n");
    }
    
    /* Ouverture fichier */
    if ((f = fopen(argv[3], "r")) == NULL) {
        perror_exit("Erreur fopen");
    }
    
    /* On récupère la taille du fichier */
    fseek(f, 0, SEEK_END);
    fsize = ftell(f) + 1;
    fseek(f, 0, SEEK_SET);
    
    /* On copie son contenu dans un buffer */
    fread(buf, fsize, 1, f);
    fclose(f);
    
    /* Création socket TCP */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror_exit("Erreur socket");
    }
    
    /* Inialisation des données */    
    if (getaddrinfo(argv[1], 0, 0, &result) != 0) {
        perror_exit("Erreur getaddrinfo");
    }
    memset(&si_other, 0, sizeof(si_other));
    memcpy((void *) &((struct sockaddr_in*) result->ai_addr)->sin_addr,
           (void *) &si_other.sin_addr, si_other_len);
    si_other.sin_port = htons(port);
    si_other.sin_family = AF_INET;

    /* Connexion */
    if (connect(sock, (struct sockaddr *) &si_other, si_other_len) == -1) {
        perror_exit("Erreur connect");
    }

    /* Envoi du nom du fichier au serveur */
    if (send(sock, argv[3], sizeof(argv[3]), 0) == -1) {
        perror_exit("Erreur connect");
    }
    
    /* Envoi du contenu du fichier au serveur */
    if (send(sock, buf, fsize, 0) == -1) {
        perror_exit("Erreur connect");
    }
    
    if (shutdown(sock, SHUT_RDWR) == -1) {
        perror_exit("Erreur shutdown");
    }
    
    close(sock);

    return EXIT_SUCCESS;
}

