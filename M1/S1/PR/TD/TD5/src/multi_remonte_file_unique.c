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
    long type;      /* Type */
    int nb;         /* Nb msg pour fils - Nb aléa pour père */
    pid_t pid_fils; /* PID du fils */
};

void remonte_ipc(int nb_fils, int msg_id) {
    pid_t pid;
    int i, j, status, nb_nb_alea;
    struct message msg;
    
    /* Création des N fils */
    for (i = 0; i < nb_fils; ++i) {
        /* Erreur fork */
        if ((pid = fork()) == -1) {
            perror("Erreur fork.\n");
            
            /* On libère la file MQN */
            if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
                perror("Erreur msgctl.\n");
            }
            
            exit(EXIT_FAILURE);
        }
        
        /* Fils */
        if (pid == 0) {
            int somme, nb_msg;
            srand(pid = getpid());
            
            /* On met à jour les données du message du fils */
            msg.type = getppid();
            msg.nb = nb_msg = (int) (10 * (float) rand() / RAND_MAX) + 1;
            msg.pid_fils = pid;
            
            /* On envoit au père via la file MQN */
            if (msgsnd(msg_id, &msg, MSG_SIZE, 0) == -1) {
                perror("Erreur msgsnd.\n");
                exit(EXIT_FAILURE);
            }
            
            /* Calcul de la somme */
            for (j = somme = 0; j < nb_msg; ++j) {
                if (msgrcv(msg_id, &msg, MSG_SIZE, pid, 0) == -1) {
                    perror("Erreur msgrcv.\n");
                    exit(EXIT_FAILURE);
                }
                
                printf("Fils %d reçoit %d\n", pid, msg.nb);
                somme += msg.nb;
            }
            
            printf("Somme du fils %d = %d\n\n", pid, somme);
            
            exit(EXIT_SUCCESS);
        }
    }

    pid = getpid();
    /* On attend de récupérer tous les messages des fils */
    for (i = 0; i < nb_fils; ++i) {
        /* Attente file MQN */
        if (msgrcv(msg_id, &msg, MSG_SIZE, pid, 0) == -1) {
            perror("Erreur msgrcv.\n");
            exit(EXIT_FAILURE);
        }
        
        /* On envoit au fils spécifié nb nombres aléatoires */
        nb_nb_alea = msg.nb;
        for (j = 0; j < nb_nb_alea; ++j) {
            msg.type = msg.pid_fils;
            msg.nb = (int) (100 * (float) rand() / RAND_MAX);

            if (msgsnd(msg_id, &msg, MSG_SIZE, 0) == -1) {
                perror("Erreur msgsnd.\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    /* Attente des fils */
    while (wait(&status) != -1) {
        /* Erreur terminaison */
        if (!WIFEXITED(status)) {
            perror("Erreur terminaison d'un fils.\n");
            
            /* On libère la file MQN */
            if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
                perror("Erreur msgctl.\n");
                exit(EXIT_FAILURE);
            }
            
            exit(EXIT_FAILURE);
        }
    }
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
    
    /* Création ID de la file MQN */
    if ((msg_id = msgget(cle, 0666 | IPC_CREAT)) == -1) {
        perror("Erreur msgget.\n");
        return EXIT_FAILURE;
    }
    
    remonte_ipc(nb_fils, msg_id);
   
    /* On libère la file MQN */
    if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
        perror("Erreur msgctl.\n");
        return EXIT_FAILURE;
    }
   
    return EXIT_SUCCESS;
}

