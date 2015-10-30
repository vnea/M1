#define _XOPEN_SOURCE 700
#define _REENTRANT

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MONSHM "/monshm"

int *sp = NULL;
int taille_sp;

void remonte_posix_partagee(int nb_fils) {
    pid_t pid;
    int i, somme, status;
    
    /* Création des N fils */
    for (i = 0; i < nb_fils; ++i) {
        /* Erreur fork */
        if ((pid = fork()) == -1) {
            perror("Erreur fork");
            exit(EXIT_FAILURE);
        }
        
        /* Fils */
        if (pid == 0) {
            srand(time(NULL) * i);
            
            sp[i] = (int) (10 * (float) rand() / RAND_MAX);
            printf("Fils %d génère nb_alea = %d.\n", getpid(), sp[i]);
            
            exit(EXIT_SUCCESS);
        }
    }

    /* Attente des fils */
    while (wait(&status) != -1) {
        /* Erreur terminaison */
        if (!WIFEXITED(status)) {
            perror("Erreur terminaison");
        }
    }
    
    /* On calcule et on affiche la somme */
    for (i = somme = 0; i < nb_fils; ++i) {
        somme += sp[i];
    }
    
    printf("\nSomme = %d.\n", somme);
}

int main(int argc, char **argv) {
    int nb_fils, shm_fd;

    /* Nombre d'arguments invalide */
    if (argc != 2) {
        printf("Usage : ./remonte_posix_partagee nb_fils\n");
        return EXIT_FAILURE;
    }

    /* Nombre de fils invalide */
    nb_fils = atoi(argv[1]);
    if (!nb_fils) {
        printf("nb_fils doit être un nombre strictement positif.\n");
        return EXIT_FAILURE;
    }
    
    /* Création du segment partagé */
    if ((shm_fd = shm_open(MONSHM, O_RDWR | O_CREAT, 0600)) == -1) {
        perror("Erreur shm_open");
        return EXIT_FAILURE;
    }
    
    /* Allouer au segment une taille pour stocker les entiers */
    taille_sp = sizeof(int) * nb_fils;
    if (ftruncate(shm_fd, taille_sp) == -1) {
        perror("Erreur ftruncate");
        
        /* On supprime le segment partagé */
        if (shm_unlink(MONSHM) == -1) {
            perror("Erreur shm_unlink");
        }
        
        return EXIT_FAILURE;
    }
    
    /* On map le segment */
    if ((sp = mmap(NULL, taille_sp, PROT_READ | PROT_WRITE, MAP_SHARED,
                    shm_fd, 0)) == MAP_FAILED) {
        perror("Ereur mmap");
        
        /* On supprime le segment partagé */
        if (shm_unlink(MONSHM) == -1) {
            perror("Erreur shm_unlink");
        }
        
        return EXIT_FAILURE;
    }
    
    remonte_posix_partagee(nb_fils);
    
    /* Détacher segment */
    if (munmap(sp, taille_sp) == -1) {
        perror("Erreur munmap");
        
        /* On supprime le segment partagé */
        if (shm_unlink(MONSHM) == -1) {
            perror("Erreur shm_unlink");
        }
        
        return EXIT_FAILURE;
    }
    
    /* On supprime le segment partagé */
    if (shm_unlink(MONSHM) == -1) {
        perror("Erreur shm_unlink");
        return EXIT_FAILURE;
    }
   
    return EXIT_SUCCESS;
}

