#include <stdlib.h>
#include <stdio.h>
#include "files.h"

#define MAX_BUFFER 1000
//Je veux que la fonction OpenFile() retourne un tableau de caractères
int OpenFile()
{
        FILE *fileptr;

    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");

    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }

    // Lecture du fichier + stockage dans un tableau de caractères 2D
    // fgets() pour lire une ligne du fichier
    // strtok() pour découper la ligne en plusieurs parties
    // strcpy() pour copier la première partie dans le tableau de caractères 2D
    char text[100][100];
    if (fileptr != NULL) {
        char line[100];
        char *token;
        int i = 0;
        while (fgets(line, sizeof(line), fileptr) != NULL) {
            token = strtok(line, "\t");
            strcpy(text[i], token);
            i++;
        }
        for (int j = 0; j < i; j++) {
            printf("%s\n", text[j]);
        }
    }

    // Fermeture du fichier
    fclose(fileptr);
}
