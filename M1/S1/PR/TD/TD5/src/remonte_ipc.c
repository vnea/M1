#define _SVID_SOURCE 1
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SIZE 128



void remonte_ipc(int nb_fils, int msg_id) {
    pid_t pid;
    int i;
    
    struct message {
        long type;
        int nb_alea;
    } msg;
    
    /* Création des N fils */
    for (i = 0; i < nb_fils; ++i) {
        /* Erreur fork */
        if ((pid = fork()) == -1) {
            perror("Erreur fork.\n");
            exit(EXIT_FAILURE);
        }
        
        /* Fils */
        if (pid == 0) {
             srand(time(NULL));
             msg.type = 1;
             msg.nb_alea = (int) (10 * (float) rand() / RAND_MAX);
             msgsnd(msg_id, &msg, MSG_SIZE, 0);
             
             exit(EXIT_SUCCESS);
        }
    }

    /* Attente des fils */
    /* while (wait(NULL) != -1) {
    }*/
}

int main(int argc, char **argv) {
    int nb_fils, msg_id;
    key_t cle;

    /* Nombre d'arguments invalide */
    if (argc != 2) {
        printf("Usage : ./remonte_ipc nb_fils\n");
        return EXIT_FAILURE;
    }

    /* Nombre de files invalide */
    nb_fils = atoi(argv[1]);
    if (!nb_fils) {
        printf("nb_fils doit être un nombre strictement positif.\n");
        return EXIT_FAILURE;
    }
    
    /* Création clé = (nom du programme, 8 LSB du pid) */
    if ((cle = ftok(argv[0], getpid() & 0xFF)) == -1) {
        perror("Erreur ftok.\n");
        return EXIT_FAILURE;
    }
    
    /* Création ID de la file de message */
    if ((msg_id = msgget(cle, 0666 | IPC_CREAT)) == -1) {
        perror("Erreur msgget.\n");
        return EXIT_FAILURE;
    }
    
    remonte_ipc(nb_fils, msg_id);
   
    return EXIT_SUCCESS;
}

