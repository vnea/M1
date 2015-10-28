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

struct message {
    long type;
    int nb_alea;
};

void remonte_ipc(int nb_fils, int msg_id) {
    pid_t pid;
    int i, somme, status;
    struct message msg;
    
    /* Création des N fils */
    for (i = 0; i < nb_fils; ++i) {
        /* Erreur fork */
        if ((pid = fork()) == -1) {
            perror("Erreur fork.\n");
            exit(EXIT_FAILURE);
        }
        
        /* Fils */
        if (pid == 0) {
            srand(getpid());
            msg.type = 1L;
            msg.nb_alea = (int) (10 * (float) rand() / RAND_MAX);
            printf("Fils %d génère nb_alea = %d.\n", getpid(), msg.nb_alea);
            msgsnd(msg_id, &msg, MSG_SIZE, 0);

            exit(EXIT_SUCCESS);
        }
    }

    /* Attente des fils */
    while (wait(&status) != -1) {
        /* Erreur terminaison */
        if (!WIFEXITED(status)) {
            perror("Erreur terminaison.\n");
            
            /* On libère la file */
            if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
                perror("Erreur msgctl.\n");
                exit(EXIT_FAILURE);
            }
            
            exit(EXIT_FAILURE);
        }
    }
    
    /* On calcule et on affiche la somme */
    somme = 0;
    for (i = 0; i < nb_fils; ++i) {
        msgrcv(msg_id, &msg, MSG_SIZE, 1L, 0);
        somme += msg.nb_alea;
    }
    
    printf("\nSomme = %d.\n", somme);
}

int main(int argc, char **argv) {
    int nb_fils, msg_id;
    key_t cle;

    /* Nombre d'arguments invalide */
    if (argc != 2) {
        printf("Usage : ./remonte_ipc nb_fils\n");
        return EXIT_FAILURE;
    }

    /* Nombre de fils invalide */
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
   
    /* On libère la file */
    if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
        perror("Erreur msgctl.\n");
        return EXIT_FAILURE;
    }
   
    return EXIT_SUCCESS;
}

