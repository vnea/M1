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

struct message_f {
    long type;
    int nb_msg;
    int msg_id;
};

struct message_p {
    long type;
    int nb_alea;
};

void remonte_ipc(int nb_fils, int msg_id_pere, char *nom_prog) {
    pid_t pid;
    int i, j, status;
    struct message_f msg_f;
    struct message_p msg_p;
    key_t cle;
    int msg_id_fils;
    
    /* Création des N fils */
    for (i = 0; i < nb_fils; ++i) {
        /* Erreur fork */
        if ((pid = fork()) == -1) {
            perror("Erreur fork.\n");
            exit(EXIT_FAILURE);
        }
        
        /* Fils */
        if (pid == 0) {
            int somme;
            pid = getpid();
            srand(pid);
            
            /* Création clé = (nom du programme, 8 LSB du pid) */
            if ((cle = ftok(nom_prog, pid & 0xFF)) == -1) {
                perror("Erreur ftok.\n");
                exit(EXIT_FAILURE);
            }

            msg_f.type = 1L;
            msg_f.nb_msg = (int) (10 * (float) rand() / RAND_MAX) + 1;
            /*printf("Fils %d génère nb_alea = %d.\n", getpid(), msg.nb_alea);*/
            msgsnd(msg_id_pere, &msg_f, MSG_SIZE, 0);

            exit(EXIT_SUCCESS);
        }
    }

    /* On attend de récupérer tous les messages des fils */
    for (i = 0; i < nb_fils; ++i) {
        msgrcv(msg_id_pere, &msg_f, MSG_SIZE, 1L, 0);
        
        /* On envoit au fils spécifié nb_msg nombres aléatoires */
        msg_p.type = 1L;
        for (j = 0; j < msg_f.nb_msg; ++j) {
            msg_p.nb_alea = (int) (100 * (float) rand() / RAND_MAX);
            msgsnd(msg_f.msg_id, &msg_p, MSG_SIZE, 0);
        }
    }


    /* Attente des fils */
    while (wait(&status) != -1) {
        /* Erreur terminaison */
        if (!WIFEXITED(status)) {
            perror("Erreur terminaison.\n");
            
            /* On libère la file */
            if (msgctl(msg_id_pere, IPC_RMID, NULL) == -1) {
                perror("Erreur msgctl.\n");
                exit(EXIT_FAILURE);
            }
            
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv) {
    int nb_fils, msg_id_pere;
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
    if ((msg_id_pere = msgget(cle, 0666 | IPC_CREAT)) == -1) {
        perror("Erreur msgget.\n");
        return EXIT_FAILURE;
    }
    
    remonte_ipc(nb_fils, msg_id_pere, argv[0]);
   
    /* On libère la file */
    if (msgctl(msg_id_pere, IPC_RMID, NULL) == -1) {
        perror("Erreur msgctl.\n");
        return EXIT_FAILURE;
    }
   
    return EXIT_SUCCESS;
}

