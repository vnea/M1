#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>


/* Détache et si erreur supprime le segment */
void shmdt_shmctl(char *adr_att, int shm_id) {
    /* On détache le segment */
    if (shmdt(adr_att) == -1) {
        perror("Erreur shmdt.\n");

        /* On supprime le segment partagé */
        if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
            perror("Erreur shmctl.\n");
        }

        exit(EXIT_FAILURE);
    }
}

void remonte_partagee(int nb_fils, int shm_id, char *adr_att) {
    pid_t pid;
    int i, somme, status;
    int *p_int;
    
    p_int = (int *) adr_att;
    
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
            p_int[i] = (int) (10 * (float) rand() / RAND_MAX);
            printf("Fils %d génère nb_alea = %d.\n", getpid(), p_int[i]);
            
            shmdt_shmctl(adr_att, shm_id);

            exit(EXIT_SUCCESS);
        }
    }

    /* Attente des fils */
    while (wait(&status) != -1) {
        /* Erreur terminaison */
        if (!WIFEXITED(status)) {
            perror("Erreur terminaison.\n");
            
            /* On supprime le segment partagé */
            if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
                perror("Erreur shmctl.\n");
            }
            
            exit(EXIT_FAILURE);
        }
    }
    
    /* On calcule et on affiche la somme */
    somme = 0;
    for (i = 0; i < nb_fils; ++i) {
        somme += p_int[i];
    }
    
    printf("\nSomme = %d.\n", somme);
}

int main(int argc, char **argv) {
    int nb_fils, shm_id;
    char *adr_att;
    key_t cle;

    /* Nombre d'arguments invalide */
    if (argc != 2) {
        printf("Usage : ./remonte_ipc nb_fils\n");
        return EXIT_FAILURE;
    }

    /* Nombre de file invalide */
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
    
    /* Création ID du segment partagé */
    if ((shm_id = shmget(cle, nb_fils * sizeof(int), 0666 | IPC_CREAT)) == -1) {
        perror("Erreur shmget.\n");
        return EXIT_FAILURE;
    }
    
    /* On récupère l'addresse du segment partagé */
    adr_att = shmat(shm_id, NULL, 0600);
    
    remonte_partagee(nb_fils, shm_id, adr_att);
   
    shmdt_shmctl(adr_att, shm_id);
   
    /* On supprime le segment partagé */
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        perror("Erreur shmctl.\n");
        return EXIT_FAILURE;
    }
   
    return EXIT_SUCCESS;
}

