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
    int sock, port;
    struct sockaddr_in si_me, si_other;
    unsigned int si_other_len = sizeof(si_other);
    
    /* Erreur usage */
    if (argc != 2) {
        fprintf_exit("Usage: ./recvfile port\n");
    }

    /* Port invalide */
    if (!(port = atoi(argv[1]))) {
        fprintf_exit("port doit être strictement positif.\n");
    }
    
    /* Création socket TCP */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror_exit("Erreur socket");
    }
    
    /* Initialisation des données */
    memset(&si_me, '\0', sizeof(struct sockaddr_in));
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    si_me.sin_port = htons(port);
    si_me.sin_family = AF_INET;
    
    /* Nommage du socket */
    if (bind(sock, (struct sockaddr *) &si_me, sizeof(si_me)) < 0) {
        perror_exit("Erreur bind");
    }
    
    if ((listen(sock, 5)) == -1) {
        perror_exit("Erreur listen");
    }

    /* Boucle principale du serveur */
    for (;;) {
        int sock_com, fd, nb_bytes;
        char buf[BUFSIZE] = { 0 }, path[BUFSIZE], filename[BUFSIZE];
        
        printf("Attente d'une connexion...\n");
        
        /* On accepte une connexion */
        if ((sock_com = accept(sock, (struct sockaddr *) &si_other,
             &si_other_len)) == -1) {
            perror_exit("Erreur accept");
        }
        
        printf("Connexion acceptée.\n");
  
        /* Recevoir nom fichier */
        if (recv(sock_com, buf, BUFSIZE, 0) == -1) {
            perror_exit("Erreur recv");
        }
        strcpy(filename, buf);
        
        /* Création du chemin du fichier dans le répertoir de l'éxécutable */
        strcpy(path, "bin/");
        strcat(path, filename);
                
        /* Création fichier */
        if ((fd = open (path, O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1) {
            perror_exit("Erreur open");
        }

        /* Recevoir contenu fichier */
        if ((nb_bytes = recv(sock_com, buf, BUFSIZE, 0)) == -1) {
            perror_exit("Erreur recv");
        }
        
        /* Ecrire contenu dans fichier */
        if (write(fd, buf, nb_bytes) == -1) {
            close(fd);
            perror_exit("Erreur write");
        }
        
        close(fd);
        printf("Fichier %s créé.\n", filename);
        printf("Fin de la connextion.\n\n");
    }
    
    if (shutdown(sock, SHUT_RDWR) == -1) {
        perror_exit("Erreur shutdown");
    }
    close(sock);
    
    return EXIT_SUCCESS;
}

