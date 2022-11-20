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
            fgets(tab, 1287976, fileptr);  // On récupère la ligne => fgets(tab à remplir, taille max de tab, fichier ouvert)

    }
    // Fermeture du fichier
    fclose(fileptr);
}


void extract_line2(char *tab, int val){
    FILE *fileptr;
    int i = 0;
    // Ouverture du fichier
    fileptr = fopen("dico_10_lignes.txt", "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    }
    // Lecture du fichier + stockage de la ligne dans un tableau de caractères 1D
    while (fileptr != NULL && val != i) {
        fgets(tab, 1287976, fileptr);  // On récupère la ligne => fgets(tab à remplir, taille max de tab, fichier ouvert)
        i++;
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
    token = strtok(tab[2], ":"); // strtok permet de d'extraire une partie de la ligne par les tabulations
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


//vérifie si la lettre est présente dans la liste des fils du noeud
//si oui, retourne le noeud fils correspondant
//sinon, crée un nouveau noeud fils et retourner le fils de ce noeud
p_cell verif_present (p_letter_node cell, char elements) {
    if (cell->son == NULL) {
        create_son(cell, elements);
        return cell->son;
    } else {
        p_letter_node temp = cell->son;
        while (temp->son->next != NULL) {
            if (temp->letter == elements) {
                return temp;
            } else {
                temp->son->p_node = temp->son->next;
            }
        }
        if (temp->letter == elements) {
            return temp;
        } else {
            create_son(temp->son->next, elements);
            return temp->son->next;
        }
    }
}
void parcourir_le_dico(p_letter_node root){
    char *dico = "dico_10_lignes.txt";
    int cpt = 0;
    char **tab_off = malloc(300000 *
                            sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
    for (int i = 0; i < 300000; i++) {
        tab_off[i] = malloc(3 * sizeof(char));
    }
    FILE *fileptr = fopen(dico, "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");
    } else {
        char buf[200];
        while (fgets(buf, sizeof buf, fileptr) != NULL) {
            decompose_line(buf, tab_off);

            if(nature_line(tab_off) == 2) {
                // Création de l'arbre Nom
                t_tree Noms;
                if (Noms.root == NULL) {
                    Noms.root = malloc(sizeof(t_letter_node));
                    Noms.root->letter = tab_off[1][0];
                    Noms.root->son = NULL;
                    cpt++;
                } else {
                    p_letter_node temp = Noms.root;
                    for (int cpt; cpt < strlen(tab_off[1]); cpt++) {
                        p_cell arbre = verif_present(temp, tab_off[1][cpt]);
                        temp = arbre->p_node;
                    }
                }
            }
            if(nature_line(tab_off) == 3) {
                {
                    printf("Adjectif");
                    // Création de l'arbre Adjectif
                    t_tree Adjectifs;
                    if (Adjectifs.root == NULL) {
                        Adjectifs.root = malloc(sizeof(t_letter_node));
                        Adjectifs.root->letter = tab_off[1][0];
                        Adjectifs.root->son = NULL;
                        cpt++;
                    } else {
                        p_letter_node temp = Adjectifs.root;
                        for (int cpt; cpt < strlen(tab_off[1]); cpt++) {
                            p_cell arbre = verif_present(temp, tab_off[1][cpt]);
                            temp = arbre->p_node;
                        }
                    }
                }
            }
            if(nature_line(tab_off) == 4) {
                {
                    printf("Adv");
                    // Création de l'arbre Adverbe
                    t_tree Adverbes;
                    if (Adverbes.root == NULL) {
                        Adverbes.root = malloc(sizeof(t_letter_node));
                        Adverbes.root->letter = tab_off[1][0];
                        Adverbes.root->son = NULL;
                        cpt++;
                    } else {
                        p_letter_node temp = Adverbes.root;
                        for (int cpt; cpt < strlen(tab_off[1]); cpt++) {
                            p_cell arbre = verif_present(temp, tab_off[1][cpt]);
                            temp = arbre->p_node;
                        }
                    }
                }
            }
            if(nature_line(tab_off)==1)
            {
                // Création de l'arbre Verbes
                t_tree Verbes;
                if (Verbes.root == NULL) {
                    Verbes.root = malloc(sizeof(t_letter_node));
                    Verbes.root->letter = tab_off[1][0];
                    Verbes.root->son = NULL;
                    cpt++;
                } else {
                    p_letter_node temp = Verbes.root;
                    for (int cpt; cpt < strlen(tab_off[1]); cpt++) {
                        p_cell arbre = verif_present(temp, tab_off[1][cpt]);
                        temp = arbre->p_node;
                    }
                }
                display_tree(Verbes);
            }
        }
    }
    fclose(fileptr);
}
