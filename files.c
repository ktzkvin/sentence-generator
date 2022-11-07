#include <stdlib.h>
#include <stdio.h>
#include "files.h"

#define MAX_BUFFER 1000
//Je veux que la fonction OpenFile() retourne un tableau de caractères
int OpenFile()
{
    FILE *fileptr;
    int *text = malloc(MAX_BUFFER * sizeof(char));
    int i = 0;

    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");

    // Problème lors de la lecture du fichier
    if (fileptr == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    // Lecture du fichier caractère par caractère
    int c;
    while ((c = fgetc(fileptr)) != EOF){
        printf("%c", c);
        text[i] = c;
        i++;
    }

    // Fermeture du fichier
    fclose(fileptr);
    // Retourne le tableau de caractères
    //return text;
    return 0;
}