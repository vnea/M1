#define _SVID_SOURCE 1
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_EXCL_MUT 0
#define NB_SEM 1

int sem_id, nb_fils;

void P() {
    struct sembuf op;
    op.sem_num = SEM_EXCL_MUT;
    op.sem_op = -1;
    op.sem_flg = SEM_UNDO;
    if (semop(sem_id, &op, 1) == -1) {
        perror("Erreur P semop.\n");
        exit(EXIT_FAILURE);
    }
}

void V() {
    struct sembuf op;
    op.sem_num = SEM_EXCL_MUT;
    op.sem_op = 1;
    op.sem_flg = SEM_UNDO;
    if (semop(sem_id, &op, 1) == -1) {
        perror("Erreur V semop.\n");
        exit(EXIT_FAILURE);
    }
}

void wait_barrier(int NB_PCS) {
    /*
    FAUX
    if (NB_PCS == nb_fils - 1) {
        V();
    }
    else {
        P();
    }
    */
    
    /* NE PAS OUBLIEZ DE SUPPRIMER SEMAPHORE A LA MAIN (pour le moment) */
    P();
}

void process(int NB_PCS) {
    printf("avant barrière\n");
    wait_barrier(NB_PCS);
    printf("après barrière\n");
    exit(0);
}

int main(int argc, char **argv) {
    int i, status;
    pid_t pid;
    key_t key;
    
    /* Nombre d'arguments invalide */
    if (argc != 2) {
        printf("Usage : ./wait_barrier nb_fils\n");
        return EXIT_FAILURE;
    }
    
    nb_fils = atoi(argv[1]);
    /* Nombre de fils invalide */
    if (!nb_fils) {
        printf("nb_fils doit être un nombre strictement positif.\n");
        return EXIT_FAILURE;
    }
    
    /* Création clé */
    if ((key = ftok(argv[0], getpid() & 0xFF)) == -1) {
        perror("Erreur ftok.\n");
        return EXIT_FAILURE;
    }
    
    /* Création ID sémaphore */
    if ((sem_id = semget(key, NB_SEM, IPC_CREAT | 0660)) == -1) {
        perror("Erreur semget.\n");
        return EXIT_FAILURE;
    }
    
    /* Initialisation sémaphore */
    /*
    if (semctl(sem_id, SEM_EXCL_MUT, SETVAL, 0) == -1) {
        perror("Erreur semctl SETVAL.\n");
        return EXIT_FAILURE;
    }
    */
    
    /* Création des fils */
    for (i = 0; i < nb_fils; ++i) {
        if ((pid = fork()) == -1) {
            perror("Erreur fork.\n");
            return EXIT_FAILURE;
        }
        
        /* Fils */
        if (pid == 0) {
            process(i);
        }
    }
    
    /* Attente des fils */
    while (wait(&status) != -1) {
        /* Erreur terminaison */
        if (!WIFEXITED(status)) {
            perror("Erreur terminaison fils.\n");
            return EXIT_FAILURE;
        }
    }
    
    /* Destruction sémaphore */
    if (semctl(sem_id, SEM_EXCL_MUT, IPC_RMID, NULL) == -1) {
        perror("Erreur semctl IPC_RMID.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

