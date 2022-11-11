#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "files.h"

#define MAX_BUFFER 1000
int OpenFile()
{
    FILE *fileptr;
    int *text = malloc(MAX_BUFFER * sizeof(char));

    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");

    // Problème lors de la lecture du fichier
    if (fileptr == NULL)
    {
        printf("Erreur d'ouverture du fichier\n");
        return 1;
    }

    // Lecture du fichier caractère par caractère
    int c, i = 0;
    int text2[100];
    while (((c = fgetc(fileptr)) != EOF) && (c != '\t')){
        text2[i] = c;
        i++;
    }
    for (int j = 0; j < i; j++){
        printf("%c", text2[j]);
    }

    // Fermeture du fichier
    fclose(fileptr);
    // Retourne le tableau de caractères
    //return text;
    return 0;
}

// La fonction OpenFile_1() retourne un tableau de caractères 2D text[100][100]
// Elle doit ouvrir le fichier dico_10_lignes.txt et stocker seulement la première colonne limitée par une tabulation \t
// A chaque nouvelle ligne du fichier, on passe à la ligne suivante du tableau de caractères
// Exemple : pour les deux premières lignes:
//stabilimetre	stabilimetre	Nom:Mas+SG
//stabilisaient	stabiliser	Ver:IImp+PL+P3
// Le tableau de caractères devra être :
// text[0] = "stabilimetre" soit text[0][0] = 's', text[0][1] = 't', text[0][2] = 'a', text[0][3] = 'b', text[0][4] = 'i', text[0][5] = 'l', text[0][6] = 'i', text[0][7] = 'm', text[0][8] = 'e', text[0][9] = 't', text[0][10] = 'r', text[0][11] = 'e'
// text[1] = "stabilisaient" soit text[1][0] = 's', text[1][1] = 't', text[1][2] = 'a', text[1][3] = 'b', text[1][4] = 'i', text[1][5] = 'l', text[1][6] = 'i', text[1][7] = 's', text[1][8] = 'a', text[1][9] = 'i', text[1][10] = 'e', text[1][11] = 'n', text[1][12] = 't'

// maintenant je veux que ces fonctions soient des int et non des void
// Je dois donc prendre en paramètre un tableau de caractères 2D text[100][100]
// et le remplir avec les lignes du fichier dico_10_lignes.txt
// La fonction OpenFile_1() doit remplir le tableau de caractères 2D text[100][100] avec la première colonne du fichier dico_10_lignes.txt
// La fonction OpenFile_2() doit remplir le tableau de caractères 2D text[100][100] avec la deuxième colonne du fichier dico_10_lignes.txt

int **extract_column_1(){
    FILE *fileptr;
    char **text = malloc(100 * sizeof(char));
    for (int i = 0; i < 100; i++){
        text[i] = malloc(100 * sizeof(char));
    }
    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    // Lecture du fichier + stockage dans un tableau de caractères 2D
    if (fileptr != NULL) {
        char line[100];
        char *token;
        int i = 0;
        while (fgets(line, sizeof(line), fileptr) != NULL) {
            token = strtok(line, "\t");
            strcpy(text[i], token);
            i++;
        }
    }
    // Fermeture du fichier
    fclose(fileptr);
    return (int **) text;
}

int **extract_column_2(){
    FILE *fileptr;
    char **text = malloc(100 * sizeof(char));
    for (int i = 0; i < 100; i++){
        text[i] = malloc(100 * sizeof(char));
    }
    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    // Lecture du fichier + stockage dans un tableau de caractères 2D
    if (fileptr != NULL) {
        char line[100];
        char *token;
        int i = 0;
        while (fgets(line, sizeof(line), fileptr) != NULL) {
            token = strtok(line, "\t");
            token = strtok(NULL, "\t");
            strcpy(text[i], token);
            i++;
        }
    }
    // Fermeture du fichier
    fclose(fileptr);
    return (int **) text;
}

int **extract_column_3(){
    FILE *fileptr;
    char **text = malloc(100 * sizeof(char));
    for (int i = 0; i < 100; i++){
        text[i] = malloc(100 * sizeof(char));
    }
    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    // Lecture du fichier + stockage dans un tableau de caractères 2D
    if (fileptr != NULL) {
        char line[100];
        char *token;
        int i = 0;
        while (fgets(line, sizeof(line), fileptr) != NULL) {
            token = strtok(line, "\t");
            token = strtok(NULL, "\t");
            token = strtok(NULL, "\t");
            strcpy(text[i], token);
            i++;
        }
    }
    // Fermeture du fichier
    fclose(fileptr);
    return (int **) text;
}

void extract_line(char *tab, int line_number){
    FILE *fileptr;
    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    // Lecture du fichier + stockage de la ligne dans un tableau de caractères 1D
    if (fileptr != NULL) {
        while (line_number != 0){  // On se place sur la ligne voulue
            fgets(tab, 100, fileptr);  // On récupère la ligne => fgets(tab à remplir, taille max de tab, fichier ouvert)
            line_number--;
        }
    }
    // Fermeture du fichier
    fclose(fileptr);
}

void decompose_line(char *temp_ligne, char **tab_off){  // temp_ligne = tableau temporaire contenant la ligne, tab_off = tableau séparant les 3 types de la ligne
    FILE *fileptr;
    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }

    // Lecture du fichier + stockage de la ligne
    if (fileptr != NULL) {
        char *token;
        token = strtok(temp_ligne, "\t");
        strcpy(tab_off[0], token);  // On récupère le premier type
        token = strtok(NULL, "\t");
        strcpy(tab_off[1], token);  // On récupère le deuxième type
        token = strtok(NULL, "\t");
        strcpy(tab_off[2], token);  // On récupère le troisième type
    }

    // Fermeture du fichier
    fclose(fileptr);
}


int nature_line(char **tab){
    char *token;
    token = strtok(tab[2], "\t");
    if (strncmp(token, "Ver", 3) == 0){
        return 1;
    }
    else if (strncmp(token, "Nom", 3) == 0){
        return 2;
    }
    else if (strncmp(token, "Adj", 3) == 0){
        return 3;
    }
    else if (strncmp(token, "Adv", 3) == 0){
        return 4;
    }
    else{
        return 0;
    }
}
