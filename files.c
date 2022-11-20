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
    fileptr = fopen("dictionnaire.txt", "r");
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
    fileptr = fopen("dictionnaire.txt", "r");
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

void article_line(char *temp_ligne, char *tab_vide, int var){
    int voyelle = 0;
    // Vérifier si le mot commence par une voyelle:
    if (temp_ligne[0] == 'a' || temp_ligne[0] == 'e' || temp_ligne[0] == 'i' || temp_ligne[0] == 'o' || temp_ligne[0] == 'u' || temp_ligne[0] == 'y' || temp_ligne[0] == 'h'){
        voyelle = 1;
    }
    // extraction de la 3ème colonne de temp_ligne dans tab_off
    char *token;
    token = strtok(temp_ligne, "\t");
    token = strtok(NULL, "\t");
    token = strtok(NULL, "\t");
    strcpy(tab_vide, token);

    // tab_off est maintenant de la forme Type:Genre+Accord
    // on veut récupérer l'accord
    token = strtok(tab_vide, ":");
    token = strtok(NULL, ":");
    // token est maintenant de la forme Genre+Accord
    // Il faut supprimer le \n
    token[strlen(token)-1] = '\0';
    strcpy(tab_vide, token);

    if (voyelle == 1){  // Si le mot commence par une voyelle
        // retourner 1 si le genre est masculin singulier de la forme "Mas+Sg"
        if (strcmp(tab_vide, "Mas+SG") == 0){
            if (var == 1){
                printf("L'");
            }
            else{
                printf("l'");
            }
        }
        // retourner 2 si le genre est féminin singulier de la forme "Fem+Sg"
        if (strcmp(tab_vide, "Fem+SG") == 0){
            if (var == 1){
                printf("L'");
            }
            else{
                printf("l'");
            }
        }
        // retourner 3 si le genre est masculin pluriel de la forme "Mas+Pl"
        if (strcmp(tab_vide, "Mas+PL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
        // retourner 4 si le genre est féminin pluriel de la forme "Fem+Pl"
        if (strcmp(tab_vide, "Fem+PL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
        if (strcmp(tab_vide, "InvGen+SG") == 0){
            if (var == 1){
                printf("L'");
            }
            else{
                printf("l'");
            }
        }
        if (strcmp(tab_vide, "InvGen+PL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
        if (strcmp(tab_vide, "Fem+InvPL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
        if (strcmp(tab_vide, "Mas+InvPL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
    }
    else{  // Si le mot commence par une consonne
        // retourner 1 si le genre est masculin singulier de la forme "Mas+Sg"
        if (strcmp(tab_vide, "Mas+SG") == 0){
            if (var == 1){
                printf("Le ");
            }
            else{
                printf("le ");
            }
        }
        // retourner 2 si le genre est féminin singulier de la forme "Fem+Sg"
        if (strcmp(tab_vide, "Fem+SG") == 0){
            if (var == 1){
                printf("La ");
            }
            else{
                printf("la ");
            }
        }
        // retourner 3 si le genre est masculin pluriel de la forme "Mas+Pl"
        if (strcmp(tab_vide, "Mas+PL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
        // retourner 4 si le genre est féminin pluriel de la forme "Fem+Pl"
        if (strcmp(tab_vide, "Fem+PL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
        if (strcmp(tab_vide, "InvGen+SG") == 0){
            if (var == 1){
                printf("Le ");
            }
            else{
                printf("le ");
            }
        }
        if (strcmp(tab_vide, "InvGen+PL") == 0){
            if (var == 1){
                printf("Le ");
            }
            else{
                printf("le ");
            }
        }
        if (strcmp(tab_vide, "Fem+InvPL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
        if (strcmp(tab_vide, "Mas+InvPL") == 0){
            if (var == 1){
                printf("Les ");
            }
            else{
                printf("les ");
            }
        }
    }

}

int adj_ligne(char *tab_types_adj, char *tab_types_nom){
    printf("  tab_types_adj : %s\n", tab_types_adj);
    printf("  tab_types_nom : %s\n\n", tab_types_nom);
    // tab_types_adj et tab_types_nom sont de la forme "Type:Genre+Accord"
    // je veux comparer les deux pour savoir si le genre+accord est le même
    // si c'est le cas, on retourne 1
    // sinon, on retourne 0
    char temp_tab[100];
    char temp_tab2[100];
    strcpy(temp_tab, tab_types_adj);
    strcpy(temp_tab2, tab_types_nom);
    char *token = strtok(temp_tab, ":");
    token = strtok(NULL, ":");

    printf("1) %s\n", token);
    printf("2) %s\n", tab_types_nom);
    if (strcmp(token, tab_types_nom) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

void extract_line(char *tab){
    FILE *fileptr;
    // Ouverture du fichier
    fileptr = fopen("dictionnaire.txt", "r");
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
    fileptr = fopen("dictionnaire.txt", "r");
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


void decompose_line(char *temp_ligne, char **tab_off, char *temp_ligne_2){  // temp_ligne = tableau temporaire contenant la ligne, tab_off = tableau séparant les 3 types de la ligne
    strcpy(temp_ligne_2, temp_ligne);

    FILE *fileptr;
    // Ouverture du fichier
    fileptr = fopen("dictionnaire.txt", "r");
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
    if (strcmp(token, "Ver") == 0){  // strncmp permet de comparer les deux chaînes de caractères
        return 1;
    }
    else if (strcmp(token, "Nom") == 0){
        return 2;
    }
    else if (strcmp(token, "Adj") == 0){
        return 3;
    }
    else if (strcmp(token, "Adv") == 0){
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
    char *dico = "dictionnaire.txt";
    int cpt = 0;
    char **tab_off = malloc(100 * sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
    for (int i = 0; i < 100; i++) {
        tab_off[i] = malloc(3 * sizeof(char));
    }
    FILE *fileptr = fopen(dico, "r");
    // Problème lors de la lecture du fichier
    if (fileptr == NULL) {
        printf("Erreur d'ouverture du fichier\n");

    } else {
        char buf[200];
        while (fgets(buf, sizeof buf, fileptr) != NULL) {
            printf("%s", buf);
            decompose_line(buf, tab_off, buf);
            if(nature_line(tab_off) == 2) {
                printf("Nom");
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
            if(nature_line(tab_off) == 4) {
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

            if(nature_line(tab_off)==1) {
                // Création de l'arbre Verbes
                printf("Verbe");
                t_tree Verbes;
                if (Verbes.root == NULL) {
                    Verbes.root = malloc(sizeof(t_letter_node));
                    Verbes.root->letter = tab_off[1][0];
                    printf("[%c]", Verbes.root->letter);
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
