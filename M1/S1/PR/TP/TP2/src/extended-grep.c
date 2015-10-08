#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>
#include <errno.h>

#define REP_COURANT "."
#define REP_PARENT  ".."
#define SEPAR_CHEM  "/"

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage : ./extended-grep expr chemin\n");
        return EXIT_FAILURE;
    }
    
    struct stat sb;
    if (stat(argv[2], &sb) == -1) {
        perror("Erreur stat.\n");
        return EXIT_FAILURE;
    }
    
    // On vérifie que c'est bien un répertoire
    if (!S_ISDIR(sb.st_mode)) {
        perror("Le fichier n'est pas un répertoire.\n");
        return EXIT_FAILURE;
    }
    
    // Ouverture du répertoire
    DIR *dir;
    if ((dir = opendir(argv[2])) == NULL) {
        perror("Erreur opendir.\n");
        return EXIT_FAILURE;
    }
    
    printf("Fichier(s) contenant l'expression \"%s\" :\n", argv[1]);
    
    int nb_fichiers_exp = 0;
    struct dirent* dirent;
    
    // On parcourt l'ensemble des fichiers du répertoires
    while ((dirent = readdir(dir)) != NULL) {
        // Si pas répertoire courant et pas répertoire parent
        if (strcmp(dirent->d_name, REP_COURANT) &&
            strcmp(dirent->d_name, REP_PARENT)) {
            
            // On construit le chemin du fichier
            char tmp[BUFSIZ];
            strcpy(tmp, argv[2]);
            strcat(tmp, SEPAR_CHEM);
            strcat(tmp, dirent->d_name);
            if (stat(tmp, &sb) == -1) {
                perror("Erreur stat.\n");
                return EXIT_FAILURE;
            }

            // On vérifie que c'est bien un fichier régulier
            if (S_ISREG(sb.st_mode)) {
                int fd;
                if ((fd = open(tmp, O_RDONLY, 0600)) == -1) {
                    perror("Erreur open.\n");
                    return EXIT_FAILURE;
                }
                
                // On récupère le contenu du fichier
                char buf[BUFSIZ];
                if (read(fd, buf, BUFSIZ) == -1) {
                    perror("Erreur read\n");
                    return EXIT_FAILURE;
                }
                
                // On regarde si l'expression existe dans le fichier
                if (strstr(buf, argv[1]) != NULL) {
                    printf("%s\n", dirent->d_name);
                    ++nb_fichiers_exp;
                }
                
                memset(buf, 0, BUFSIZ);
            }
            
            memset(tmp, 0, BUFSIZ);
        }
    }
	
    closedir(dir);
    if (nb_fichiers_exp == 0) {
        printf("Aucun fichier ne contient l'expression \"%s\".\n", argv[1]);
    }
    
    return EXIT_SUCCESS;
}

