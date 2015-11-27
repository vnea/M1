#define _XOPEN_SOURCE 700

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

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
    int sock, port;
    struct sockaddr_in si_me, si_other;
    unsigned int si_me_len, si_other_len;
    
    si_me_len = sizeof(si_me);
    si_other_len = sizeof(si_other);

    /* Erreur usage */
    if (argc != 2) {
        fprintf_exit("Usage: ./env_serveur port\n");
    }

    /* Port invalide */
    if (!(port = atoi(argv[1]))) {
        fprintf_exit("port doit être strictement positif.\n");
    }
    
    /* Création socket UDP */
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
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
    
    printf("Serveur démarré\n");
    /* Boucle principale */
    for (;;) {
        char operation, id[BUFSIZE], val[BUFSIZE], buf[BUFSIZE];
        char *val_of_id;
         
        printf("Attente d'une commande...\n");
        /* Réception de la commande */
        if (recvfrom(sock, buf, BUFSIZE, 0,
            (struct sockaddr *) &si_other, &si_other_len) == -1) {
            perror_exit("Erreur recvfrom");
        }
        
        printf("Commande reçue : %s\n", buf);
        
        /* On récupère les 3 parties du message */
        sscanf(buf, "%c %s %s", &operation, id, val);
        
        /* Traitement de l'opération */
        switch (operation) {
            case 'S':
                strcpy(buf, setenv(id, val, 1) == -1 ? "Ajout impossible"
                                                     : "Ajout réussi");
            break;
            
            case 'G':
                strcpy(buf, (val_of_id = getenv(id)) == NULL ? "L'id n'existe pas"
                                                             : val_of_id);
            break;
            
            case 'Q':
                strcpy(buf, "Bye bye.");
            break;
            
            default:
                strcpy(buf, "Opération invalide.");
            break;
        }
        
        /* Envoi du message */
        strcat(buf, " (message reçu du serveur).");
        if (sendto(sock, &buf, strlen(buf) + 1, 0,
           (struct sockaddr *) &si_other, si_other_len) == -1) {
            perror_exit("Erreur sendto");
        }
    }
    
    if (shutdown(sock, SHUT_RDWR) == -1) {
        perror_exit("Erreur shutdown");
    }
    close(sock);

    return EXIT_SUCCESS;
}

