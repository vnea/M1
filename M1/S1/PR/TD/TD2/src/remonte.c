#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define NB_FILS 5
#define NOM_FICHIER "liste_nb"
#define TAILLE_BUF 2

int main() {
    if (NB_FILS > 0) {
        // Fichier où seront stockés les nombres
        int fd;
        if ((fd = open (NOM_FICHIER, O_RDWR| O_CREAT | O_TRUNC, 0600)) == -1) {
            return EXIT_FAILURE;
        }
        
        // Création n fils
        int i;
        for (i = 0; i < NB_FILS; ++i) {
            pid_t pid = fork();
            
            // Erreur
            if (pid == -1) {
                perror("Erreur fork.\n");
                return EXIT_FAILURE;
            }
            
            // Fils
            if (pid == 0) {
                srand(time(NULL) + getpid());
                    
                // Conversion de la valeur en chaîne de caractères
                // Ex : 5 devient "5\n"
                int random_val = (int) (10 * (float) rand() / RAND_MAX);
                char random_val_str[TAILLE_BUF];
                sprintf(random_val_str, "%d\n", random_val);
                
                // Ecriture de la chaîne obtenue dans le fichier
                write(fd, random_val_str, TAILLE_BUF);
                exit(1);
            }
            // Père
            else {
                wait(NULL);
                
                // Tous les fils sont morts, le processus principal
                // peut faire la somme
                if (i == NB_FILS - 1) {
                    // On se replace en début de fichier
                    if (lseek(fd, 0, SEEK_SET) == -1) {
                        perror("Erreur lseek.\n");
                        return EXIT_FAILURE;
                    }
                    
                    int nb_octets;
                    char buf[TAILLE_BUF];
                    int somme = 0;
                    while ((nb_octets = read(fd, buf, TAILLE_BUF)) > 0) {
                        somme += atoi(buf);
                    }
                    
                    printf("Somme = %d.\n", somme);
                    close(fd);
                    
                    return EXIT_SUCCESS;
                }
            }   
        }
    }
    
    printf("Aucun fils.\n");
    
    return EXIT_SUCCESS;
}

