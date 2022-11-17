#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "files.h"

#define MAX_BUFFER 1000

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

void extract_line(char *tab){
    FILE *fileptr;
    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    // Lecture du fichier + stockage de la ligne dans un tableau de caractères 1D
    if (fileptr != NULL) {
            fgets(tab, 100, fileptr);  // On récupère la ligne => fgets(tab à remplir, taille max de tab, fichier ouvert)

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
        // strcpy permet de copier une chaîne de caractères dans un tableau de caractères
        token = strtok(NULL, "\t");
        strcpy(tab_off[1], token);  // On récupère le deuxième type
        token = strtok(NULL, "\t");
        strcpy(tab_off[2], token);  // On récupère le troisième type
        tab_off[2][strlen(tab_off[2]) - 1] = '\0';
    }

    // Fermeture du fichier
    fclose(fileptr);
}


int nature_line(char **tab){
    char *token;
    token = strtok(tab[2], "\t"); // strtok permet de d'extraire une partie de la ligne par les tabulations
    if (strncmp(token, "Ver", 3) == 0){  // strncmp permet de comparer les deux chaînes de caractères
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

p_cell child_horiz(p_cell cell, char letter){  // On parcourt la liste horizontale des fils d'un noeud en paramètre appelé cell pour trouver la lettre en paramètre appelée letter
    p_cell temp = cell;
    while (temp != NULL){
        if (temp->p_node->letter == letter){
            return temp;
        }
        temp = temp->next;
    }
    // Si on arrive ici, c'est que la lettre n'existe pas
    // On créé donc un fils avec cette lettre
    p_cell new_cell = malloc(sizeof(t_cell));
    new_cell->p_node = malloc(sizeof(t_letter_node));
    new_cell->p_node->letter = letter;
    new_cell->p_node->son = NULL;
    new_cell->next = cell;
    return new_cell;
}

void parcourir_le_dico(p_letter_node root, int type){
    char *dico = "dico_10_lignes.txt";
    char **tab_off = malloc(100 * sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
    for (int i = 0; i < 100; i++) {
        tab_off[i] = malloc(3 * sizeof(char));
    }
    FILE *fileptr = fopen(dico,"r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }else{
        char buf[200];
        while (fgets(buf, sizeof buf, fileptr) != NULL){
            decompose_line(buf, tab_off);

            if ((nature_line(tab_off) == type)) {  // Création de l'arbre pour tous les types (type = 1 => verbe par ex)
                printf("%s  ", tab_off[0]);
                printf("%s  ", tab_off[1]);
                printf("%s\n", tab_off[2]);
                // Création de l'arbre
                // si arbre vide => create_son
                // si arbre non vide => vérifier si la lettre existe déjà dans l'arbre
                // si la lettre existe déjà => ça renvoie le pointeur de son enfant de cette lettre => revérifier si la lettre suivante existe etc.
                // si la lettre n'existe pas => create_son de la lettre


                // Création de l'arbre Verbes (type = 1) avec les verbes basiques (tab_off[1] = infinitif) pour chaque ligne du dictionnaire
                // On vérifie pour chaque lettre du mot si elle existe déjà dans l'arbre avec la fonction child_horiz qui retourne le pointeur de la lettre
                // Si la lettre n'existe pas, child_horiz créé un fils avec cette lettre

                // sachant que les structures sont :
                //typedef struct s_letter_node t_letter_node, *p_letter_node ;
                //
                //typedef struct s_cell
                //{
                //    p_letter_node p_node ;  // Lettre du fils
                //    struct s_cell * next ;  // Lettre à droite = frère
                //} t_cell, *p_cell ;
                //
                //struct s_letter_node
                //{
                //    char letter ;
                //    p_cell son ;
                //};
                //
                //typedef struct s_tree
                //{
                //    t_letter_node *root;
                //} t_tree, *p_tree;

                // Création de l'arbre
                t_tree Noms;
                Noms.root = malloc(sizeof(t_letter_node));
                Noms.root->letter = tab_off[1][0];
                Noms.root->son = NULL;
                p_cell temp = Noms.root->son;
                for (int i = 1; i < strlen(tab_off[1]); i++){
                    temp = child_horiz(temp, tab_off[1][i]);
                }


            }
        }
    }
    fclose(fileptr);
}

