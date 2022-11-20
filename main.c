#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "struct.c"
#include "files.c"
#include "struct.h"
#include "files.h"


int main()
{
    int choice = 0;
    printf("------------------------------\n");
    printf("     [Sentence Generator]\n");
    printf("------------------------------\n");
    printf("1. Generer une phrase\n");
    printf("2. Creation des arbres\n");
    printf("3. Quitter\n");
    scanf("%d", &choice);
    if (choice == 1){
        char *temp_ligne = malloc(100 * sizeof(char));  // Création d'un tableau temporaire pour enregistrer une ligne
        char *temp_ligne_2 = malloc(100 * sizeof(char));
        char *temp_ligne_3 = malloc(100 * sizeof(char));
        char *verif_tab = malloc(100 * sizeof(char));

        char **tab_off = malloc(100 * sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
        for (int i = 0; i < 100; i++) {
            tab_off[i] = malloc(3 * sizeof(char));
        }

        // Recherche aléatoire d'une ligne dans le dictionnaire
        int nombreAleatoire, verif = 0, a = 0;
        const int MAX = 287975, MIN = 1;
        srand(time(NULL));
        char *tab_column_3;  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
        for (int i = 0; i < 100; i++) {
            tab_column_3 = malloc(3 * sizeof(char));
        }

        printf("---------------------\n");
        printf("Generation numero 1 : \n");

        // --------------------- //  nature : Nom
        while (nature_line(tab_off) != 2) {
            a = rand() + rand()*(1+MAX);  // Génération d'un nombre aléatoire : rand() génère un nombre aléatoire entre 0 et 32767, on le multiplie par 2 pour avoir un nombre entre 0 et 65534, on ajoute 1 pour avoir un nombre entre 1 et 65535, on multiplie par MAX pour avoir un nombre entre 1 et MAX
            if (a < 0){
                a=a*-1;
            }
            nombreAleatoire = a%MAX;
            extract_line2(temp_ligne, nombreAleatoire);
            decompose_line(temp_ligne, tab_off, temp_ligne_2);
            // Récupérer le genre et le nombre pour le comparer avec l'adjectif et le verbe
            strcpy(verif_tab, tab_off[2]);
            //printf("%s \n", verif_tab);
        }
        article_line(temp_ligne_2, tab_column_3, 1);  // Vérifier le genre et le nombre pour afficher le bon article
        printf("%s ", tab_off[0]);

        // --------------------- //  nature : Adj
        while ((nature_line(tab_off) != 3)) {
            a = rand() + rand()*(1+MAX);  // Génération d'un nombre aléatoire : rand() génère un nombre aléatoire entre 0 et 32767, on le multiplie par 2 pour avoir un nombre entre 0 et 65534, on ajoute 1 pour avoir un nombre entre 1 et 65535, on multiplie par MAX pour avoir un nombre entre 1 et MAX
            if (a < 0){
                a=a*-1;
            }
            nombreAleatoire = a%MAX;
            extract_line2(temp_ligne, nombreAleatoire);
            decompose_line(temp_ligne, tab_off, temp_ligne_2);
            //verif = adj_ligne(tab_off[2], verif_tab);
            //printf("[[%d]] [%d] ", nature_line(tab_off), verif);
        }
        printf("%s ", tab_off[0]);

        // --------------------- // nature : Verbe
        while (nature_line(tab_off) != 1) {
            a = rand() + rand()*(1+MAX);  // Génération d'un nombre aléatoire : rand() génère un nombre aléatoire entre 0 et 32767, on le multiplie par 2 pour avoir un nombre entre 0 et 65534, on ajoute 1 pour avoir un nombre entre 1 et 65535, on multiplie par MAX pour avoir un nombre entre 1 et MAX
            if (a < 0){
                a=a*-1;
            }
            nombreAleatoire = a%MAX;
            extract_line2(temp_ligne, nombreAleatoire);
            decompose_line(temp_ligne, tab_off, temp_ligne_2);
        }
        printf("%s ", tab_off[0]);

        // --------------------- // nature : Nom
        while (nature_line(tab_off) != 2) {
            a = rand() + rand()*(1+MAX);  // Génération d'un nombre aléatoire : rand() génère un nombre aléatoire entre 0 et 32767, on le multiplie par 2 pour avoir un nombre entre 0 et 65534, on ajoute 1 pour avoir un nombre entre 1 et 65535, on multiplie par MAX pour avoir un nombre entre 1 et MAX
            if (a < 0) {
                a = a * -1;
            }
            nombreAleatoire = a%MAX;
            extract_line2(temp_ligne, nombreAleatoire);
            decompose_line(temp_ligne, tab_off, temp_ligne_2);
        }
        article_line(temp_ligne_2, tab_column_3, 0);  // Vérifier le genre et le nombre
        printf("%s \n", tab_off[0]);


        printf("---------------------\n");
        printf("Generation numero 2 : \n");


        char *temp_ligne_4 = malloc(100 * sizeof(char));  // Création d'un tableau temporaire pour enregistrer une ligne
        char *temp_ligne_5 = malloc(100 * sizeof(char));
        char *temp_ligne_6 = malloc(100 * sizeof(char));
        char *verif_tab_2 = malloc(100 * sizeof(char));
        char *tab = malloc(100 * sizeof(char));

        char **tab_off_1 = malloc(100 * sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
        for (int i = 0; i < 100; i++) {
            tab_off_1[i] = malloc(3 * sizeof(char));
        }

        while (nature_line(tab_off) != 2) {
            a = rand() + rand()*(1+MAX);
            if (a<  0)
            {
                a=a*-1;
            }
            nombreAleatoire = a%MAX;

            extract_line2(temp_ligne_4, nombreAleatoire);
            decompose_line(temp_ligne_4, tab_off, temp_ligne_5);
            strcpy(tab, tab_off[2]);
        }

        article_line(temp_ligne_5, tab_column_3, 1);  // Vérifier le genre et le nombre pour afficher le bon article
        printf("%s qui ", tab_off[0]);

        while (nature_line(tab_off) != 1 ) {
            a = rand() + rand()*(1+MAX);
            if (a<  0)
            {
                a=a*-1;
            }
            nombreAleatoire = a%MAX;
            extract_line2(temp_ligne_4, nombreAleatoire);
            decompose_line(temp_ligne_4, tab_off, temp_ligne_5);
        }
        printf("%s ", tab_off[0]);

        a = rand() + rand()*(1+MAX);
        if (a<  0)
        {
            a=a*-1;
        }
        nombreAleatoire = a%MAX;
        extract_line2(temp_ligne_4, nombreAleatoire);
        decompose_line(temp_ligne_4, tab_off, temp_ligne_5);

        while (nature_line(tab_off) != 1 ) {
            a = rand() + rand()*(1+MAX);
            if (a<  0)
            {
                a=a*-1;
            }
            nombreAleatoire = a%MAX;
            extract_line2(temp_ligne_4, nombreAleatoire);
            decompose_line(temp_ligne_4, tab_off, temp_ligne_5);
        }
        printf("%s ", tab_off[0]);

        while (nature_line(tab_off) != 2) {
            a = rand() + rand()*(1+MAX);
            if (a<  0)
            {
                a=a*-1;
            }
            nombreAleatoire = a%MAX;

            extract_line2(temp_ligne_4, nombreAleatoire);
            decompose_line(temp_ligne_4, tab_off, temp_ligne_5);
            strcpy(tab, tab_off[2]);
        }

        article_line(temp_ligne_5, tab_column_3, 0);  // Vérifier le genre et le nombre pour afficher le bon article
        printf("%s ", tab_off[0]);

        while (nature_line(tab_off) != 3) {
            a = rand() + rand() * (1 + MAX);
            if (a < 0) {
                a = a * -1;
            }
            nombreAleatoire = a % MAX;
            extract_line2(temp_ligne_4, nombreAleatoire);
            decompose_line(temp_ligne_4, tab_off, temp_ligne_5);
        }

        printf("%s ", tab_off[0]);

        // --------------------- //  Création des arbres

    }
    else if (choice == 2){
        parcourir_le_dico();
    }
    else if (choice == 3){
        printf("Au revoir !\n");
        return 0;
    }
    else {
        printf("Choix invalide\n");
    }




    return 0;
}

