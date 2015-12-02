#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <dirent.h> 
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
    DIR *dir;
    struct sockaddr_in si_me, si_other;
    char filename[BUFSIZE];
    unsigned int si_me_len, si_other_len;
    si_me_len = sizeof(si_me);
    si_other_len = sizeof(si_other);

    /* Erreur usage */
    if (argc != 3) {
        fprintf_exit("Usage: ./ftp_server port dossier\n");
    }

    /* Port invalide */
    if (!(port = atoi(argv[1]))) {
        fprintf_exit("port doit être strictement positif.\n");
    }
    
    /* Dossier n'existe pas */
    if ((dir = opendir(argv[2])) == NULL) {
        perror_exit("Erreur opendir");
    }
    
    /* Création socket UDP */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror_exit("Erreur socket");
    }
    
    /* Initialisation données */
    memset(&si_me, 0, si_me_len);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    si_me.sin_port = htons(port);
    si_me.sin_family = AF_INET;

    /* Nommage */
    if (bind(sock,(struct sockaddr *) &si_me, si_me_len) < 0) {
        perror_exit("Erreur bind");
    }
    
    listen(sock, 5);
    
    printf("Serveur démarré\n");
    /* Boucle principale */
    for (;;) {
        char operation[BUFSIZE], buf[BUFSIZE];
        int sock_com, done;

        printf("Attente d'une connexion...\n");
        /* On accepte une connexion */
        if ((sock_com = accept(sock, (struct sockaddr *) &si_other,
             &si_other_len)) == -1) {
            perror_exit("Erreur accept");
        }
       
        done = 0;
        while (!done) {
            /* Réception de la commande */
            if (recv(sock_com, buf, BUFSIZE, 0) == -1) {
                perror_exit("Erreur recv");
            }
            
            printf("Commande reçue : %s\n", buf);
            sscanf(buf, "%s %s", operation, filename);
            
            /* Lister les fichiers */
            if (!strcmp(operation, "LIST")) {
                struct dirent *dirent; 
                strcpy(buf, "Le dossier du serveur contient: \n");
                
                rewinddir(dir);
                while ((dirent = readdir(dir)) != NULL) {
                    strcat(buf, dirent->d_name);
                    strcat(buf, "\n");
                }
                
                /* Envoi du message */
                if (send(sock_com, buf, sizeof(buf), 0) == -1) {
                    perror_exit("Erreur send");
                }
            }
            
            /* Uploader un fichier*/
            else if (!strcmp(operation, "UPLOAD")) {
                int fd, nb_bytes;
                char path[BUFSIZE];
                
                /* Création du chemin du fichier */
                strcpy(path, argv[2]);
                strcat(path, "/");
                strcat(path, filename);
                
                /* Création du fichier */
                if ((fd = open (path, O_WRONLY | O_CREAT | O_TRUNC, 0600)) == -1) {
                    strcpy(buf, "L'upload du fichier a échoué.");
                    /* Envoi erreur */
                    if (send(sock_com, buf, sizeof(buf), 0) == -1) {
                        perror_exit("Erreur send");
                    }
                }
                else {
                    /* On attend le contenu du fichier */
                    if ((nb_bytes = recv(sock_com, buf, BUFSIZE, 0)) == -1) {
                        perror_exit("Erreur recv");
                    }
                    
                    /* Ecrire contenu dans fichier */
                    if (write(fd, buf, nb_bytes) == -1) {
                        close(fd);
                        perror_exit("Erreur write");
                    }
                    
                    close(fd);
                    strcpy(buf, "L'upload a réussi.");
                    /* Envoi erreur */
                    if (send(sock_com, buf, sizeof(buf), 0) == -1) {
                        perror_exit("Erreur send");
                    }
                }
            }
            
            /* Télécharger un fichier */
            else if (!strcmp(operation, "DOWNLOAD")) {
                int fsize;
                FILE *f;
                /* Problème fopen (fichier qui n'existe pas par exemple) */
                if ((f = fopen(filename, "r")) == NULL) {
                    strcpy(buf, "Téléchargement du fichier impossible.");
                    /* Envoi erreur */
                    if (send(sock_com, buf, sizeof(buf), 0) == -1) {
                        perror_exit("Erreur send");
                    }
                }
                else {
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
                }
            }
            
            /* Fin du client */
            else if (!strcmp(operation, "Q")) {
                done = 1;
            }
            
            /* Opération invalide (on ne devrait jamais tomber dans ce cas vu)
               qu'il y a une protection côté client
            */
            else {
                strcpy(buf, "Opération invalide.");
                /* Envoi du message */
                if (send(sock_com, buf, sizeof(buf), 0) == -1) {
                    perror_exit("Erreur send");
                }
            }
        }
    }
    
    if (shutdown(sock, SHUT_RDWR) == -1) {
        perror_exit("Erreur shutdown");
    }
    close(sock);
    closedir(dir);

    return EXIT_SUCCESS;
}

