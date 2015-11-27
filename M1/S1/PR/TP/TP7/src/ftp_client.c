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
    int sock, port, done;
    struct sockaddr_in si_other;
    unsigned int si_other_len = sizeof(si_other);
    struct addrinfo *result;
    char operation[BUFSIZE], cmd[BUFSIZE], buf[BUFSIZE], filename[BUFSIZE];
    
    /* Erreur usage */
    if (argc != 3) {
        fprintf_exit("Usage: ./ftp_client host port\n");
    }

    /* Port invalide */
    if (!(port = atoi(argv[2]))) {
        fprintf_exit("port doit être strictement positif.\n");
    }
    
    /* Création socket UDP */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
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
    
    /* Connexion */
    if (connect(sock, (struct sockaddr *) &si_other, si_other_len) == -1) {
        perror_exit("Erreur connect");
    }
    
    /* Boucle principale */
    done = 0;
    while (!done) {
        printf("Entrez une opération: ");
        fgets(cmd, BUFSIZE, stdin);
        
        sscanf(cmd, "%s %s", operation, filename);
        
        /* Lister les fichiers */
        if (!strcmp(operation, "LIST")) {
            /* Envoi de la commande */
            if (send(sock, operation, sizeof(operation), 0) == -1) {
                perror_exit("Erreur sendto");
            }
            
            /* Réception du message */
            if (recv(sock, buf, BUFSIZE, 0) == -1) {
                perror_exit("Erreur recvfrom");
            }
            printf("%s\n", buf);
        }
        
        /* Uploader un fichier*/
        else if (!strcmp(operation, "UPLOAD")) {
            int fsize;
            FILE *f;
            /* Problème fopen (fichier qui n'existe pas par exemple) */
            if ((f = fopen(filename, "r")) == NULL) {
                perror("Erreur fopen");
            }
            else {
                /* Envoi de la commande */
                if (send(sock, cmd, sizeof(cmd), 0) == -1) {
                    perror_exit("Erreur sendto");
                }
                
                /* On récupère la taille du fichier */
                fseek(f, 0, SEEK_END);
                fsize = ftell(f) + 1;
                fseek(f, 0, SEEK_SET);
                
                /* On copie son contenu dans un buffer */
                fread(buf, fsize, 1, f);
                fclose(f);
                
                /* Envoi du contenu */
                if (send(sock, buf, fsize, 0) == -1) {
                    perror_exit("Erreur sendto");
                }
                
                /* On attend le message */
                if (recv(sock, buf, BUFSIZE, 0) == -1) {
                    perror_exit("Erreur recv");
                }
                printf("%s\n", buf);
            }
        }
        
        /* Télécharger un fichier */
        else if (!strcmp(operation, "DOWNLOAD")) {
            int fd, nb_bytes;
            /* Envoi de la commande */
            if (send(sock, cmd, sizeof(cmd), 0) == -1) {
                perror_exit("Erreur sendto");
            }
            
            /* On attend le message */
            if ((nb_bytes = recv(sock, buf, BUFSIZE, 0)) == -1) {
                perror_exit("Erreur recv");
            }
            
            /* Création du fichier */
            if ((fd = open (filename, O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1) {
                perror("Erreur open");
            }
            
            /* Ecrire contenu dans fichier */
            if (write(fd, buf, nb_bytes) == -1) {
                close(fd);
                perror("Erreur write");
            }
            
            printf("Téléchargement réussi.\n");
        }
        
        /* Fin du client */
        else if (!strcmp(operation, "Q")) {
            done = 1;
            /* Envoi de la commande */
            if (send(sock, cmd, sizeof(cmd), 0) == -1) {
                perror_exit("Erreur sendto");
            }
        }
        
        /* Opération invalide */
        else {
            printf("Opération invalide.\n");
        }
    }
    
    close(sock);
    
    return EXIT_SUCCESS;
}

