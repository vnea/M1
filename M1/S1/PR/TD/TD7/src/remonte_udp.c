#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define BUF 1

void fprintf_exit(char *msg) {
    fprintf(stderr, msg, strlen(msg));
    exit(EXIT_FAILURE);
}

void perror_exit(char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void remonte_udp(int nb_fils, int sock, char *nom_socket) {
    struct sockaddr_un su_other;
    int i, msg[BUF], somme;
    unsigned int fromlen;
    pid_t pid;

    /* Création des N fils */
    for (i = 0; i < nb_fils; ++i) {
        if ((pid = fork()) == -1) {
            perror_exit("Erreur fork");
        }
        
        /* Fils */
        if (pid == 0) {
            int sock, nb_alea;
            srand(getpid());
            
            /* Initialisation des données du socket */
            memset(&su_other, '\0', sizeof(struct sockaddr_un));
            su_other.sun_family = AF_UNIX;
            strcpy(su_other.sun_path, nom_socket);
            
            /* Création socket UDP */
            if ((sock = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) {
                perror_exit("Erreur socket");
            }

            /* Génération nombre aléatoire */
            nb_alea = (int) (10 * (float) rand() / RAND_MAX);
            printf("Fils %d génère nb_alea = %d.\n", getpid(), nb_alea);
            
            /* Envoi du message (= nombre aléatoire) */
            if (sendto(sock, &nb_alea, sizeof(nb_alea), 0,
                (struct sockaddr *) &su_other, sizeof(su_other)) == -1) {
                perror_exit("Erreur sendto");
            }
            
            exit(EXIT_SUCCESS);
        }
    }
    
    /* Attente fils */
    while (wait(NULL) != -1);
    
    /* Calcul de la somme */
    fromlen = sizeof(su_other);
    for (i = somme = 0; i < nb_fils; ++i) {
        /* Réception message */
        if (recvfrom(sock, msg, BUF, 0,
            (struct sockaddr *) &su_other, &fromlen) == -1) {
            perror("Erreur recvfrom");
        }
        
        somme += msg[0];
    }
    
    printf("Somme = %d.\n", somme);
}

int main(int argc, char **argv) {
    int nb_proc, sock;
    struct sockaddr_un su_me;

    /* Erreur usage */
    if (argc != 3) {
        fprintf_exit("Usage: ./remonte_udp nom_socket nb_proc\n");
    }
    
    /* Nombre de processus invalide */
    if (!(nb_proc = atoi(argv[2]))) {
        fprintf_exit("nb_proc doit être strictement positif.\n");
    }
   
    /* Initialisation des données du socket */
    memset(&su_me, '\0', sizeof(struct sockaddr_un));
    su_me.sun_family = AF_UNIX;
    strcpy(su_me.sun_path, argv[1]);
    
    /* Création socket UDP */
    if ((sock = socket(AF_UNIX, SOCK_DGRAM, 0)) == -1) {
        perror_exit("Erreur socket");
    }
    
    /* Nommage du socket */
    if (bind(sock, (struct sockaddr *) &su_me, sizeof(su_me.sun_path)) == -1) {
        perror("Erreur bind");
    }
    
    remonte_udp(nb_proc, sock, argv[1]);

    if (unlink(su_me.sun_path) == -1) {
        perror_exit("Erreur unlink");
    }

    return EXIT_SUCCESS;
}

