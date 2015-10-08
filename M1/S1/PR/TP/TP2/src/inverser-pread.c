#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define TAILLE_BUF 1

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage : ./inverser-pread fichier\n");
        return EXIT_FAILURE;
    }
    
    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror("Erreur stat.\n");
        return EXIT_FAILURE;
    }
    
    // On vérifie que c'est bien un fichier régulier
    if (!S_ISREG(sb.st_mode)) {
        perror("Le fichier n'est pas un fichier régulier.\n");
        return EXIT_FAILURE;
    }
    
    int fd1;
    if ((fd1 = open(argv[1], O_RDONLY, 0600)) == -1) {
        perror("Erreur open.\n");
        exit(EXIT_FAILURE);
    }
    
    // Nom fichier dest = timestamp + fichier
    // Ex : 1444332846fichier
    char nom_fichier_dest[BUFSIZ];
    char time_char[BUFSIZ];
    sprintf(time_char, "%d", time(NULL));
    strcpy(nom_fichier_dest, time_char);
    strcat(nom_fichier_dest, argv[1]);
    
    // Fichier de destination
    int fd2;
    if ((fd2 = open(nom_fichier_dest, O_WRONLY | O_CREAT, 0600)) == -1) {
        perror("Erreur open.\n");
        return EXIT_FAILURE;
    }
    
    int const TAILLE_FICHIER = (int) sb.st_size;
    int cur = 0;
    while (TAILLE_FICHIER - cur > 0) {
        char buf[TAILLE_BUF];

        // On lit un caractère
        int n;
        if ((n = pread(fd1, buf, TAILLE_BUF, TAILLE_FICHIER - ++cur)) == -1) {
            perror("Erreur pread.\n");
            return EXIT_FAILURE;
        }

        // On écrit ce caratère dans le fichier de destination
        if (write(fd2, buf, n) == -1) {
            perror("Erreur write.\n");
            return EXIT_FAILURE;
        }
    }

    close(fd1);
    close(fd2);

    return EXIT_SUCCESS;
}

