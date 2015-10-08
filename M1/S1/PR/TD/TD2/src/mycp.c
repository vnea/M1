#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>


int main(int argc, char **argv) {   
    // Nombre d'arguments invalide
    if (argc != 3) {
        printf("Usage : ./mycp file1 file2\n");
        return EXIT_FAILURE;
    }
    
    // Fichier 1
    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror("Erreur stat.\n");
        return EXIT_FAILURE;
    }
    
    // On vérifie que c'est bien un fichier régulier
    if (!S_ISREG(sb.st_mode)) {
        perror("Le 1er fichier n'est pas un fichier régulier.\n");
        return EXIT_FAILURE;
    }
    
    // Ouverture en lecture seule
    int fd1;
    if ((fd1 = open(argv[1], O_RDONLY, 0600)) == -1) {
        perror("Erreur de l'ouverture du 1er fichier.\n");
        return EXIT_FAILURE;
    }
    
    // Fichier 2
    // Création que si le fichier n'existe pas
    int fd2;
    if ((fd2 = open(argv[2], O_CREAT | O_EXCL | O_WRONLY, 0600)) == -1) {
        perror("Erreur, le 2ème fichier existe déjà.\n");
        return EXIT_FAILURE;
    }
    
    // On récupère le contenu du fichier 1 dans un buffer
    char buf[BUFSIZ];
    int n;
    if ((n = read(fd1, buf, BUFSIZ)) == -1) {
        perror("Erreur read.\n");
        return EXIT_FAILURE;
    }
    close(fd1);
    
    // On recopie ce buffer dans le fichier 2
    if (write(fd2, buf, n) == -1) {
        perror("Erreur d'écriture du 2ème fichier.\n");
        return EXIT_FAILURE;
    }
    close(fd2);
        
    return EXIT_SUCCESS;
}

