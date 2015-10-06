#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

void lecture_posix() {
}

void lecture_libc() {
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage : ./lectures fichier\n");
        return EXIT_FAILURE;
    }
    
    struct stat sb;
    if (stat(argv[1], &sb) == -1) {
        perror("Erreur stat.\n");
        return EXIT_FAILURE;
    }
    
    // On vérifie que c'est bien un fichier régulier
    if (sb.st_mode & S_IFMT != S_IFREG) {
        perror("Le fichier n'est pas un fichier régulier.\n");
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}
