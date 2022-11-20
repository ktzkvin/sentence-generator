#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.c"
#include "files.c"
#include <time.h>


int main()
{
    char *temp_ligne = malloc(100 * sizeof(char));  // Création d'un tableau temporaire pour enregistrer une ligne
    char *temp_ligne_2 = malloc(100 * sizeof(char));  // Création d'un tableau temporaire pour enregistrer une ligne


    char **tab_off = malloc(100 * sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
    for (int i = 0; i < 100; i++) {
        tab_off[i] = malloc(3 * sizeof(char));
    }

    int nombreAleatoire;
    const int MAX = 287976, MIN = 1;
    srand(time(NULL));
    char *tab_column_3;  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
    for (int i = 0; i < 100; i++) {
        tab_column_3 = malloc(3 * sizeof(char));
    }

    printf("---------------------\n");
    printf("Generation numero 1 : \n");
    while (nature_line(tab_off) != 2) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);

        decompose_line(temp_ligne, tab_off, temp_ligne_2);
    }
    article_line(temp_ligne_2, tab_column_3, 1);  // Vérifier le genre et le nombre pour afficher le bon article
    printf("%s ", tab_off[0]);

    while (nature_line(tab_off) != 3) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);
        decompose_line(temp_ligne, tab_off, temp_ligne_2);
    }
    printf("%s ", tab_off[0]);
    while (nature_line(tab_off) != 1) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);
        decompose_line(temp_ligne, tab_off, temp_ligne_2);
    }
    printf("%s ", tab_off[0]);
    while (nature_line(tab_off) != 2) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);
        decompose_line(temp_ligne, tab_off, temp_ligne_2);
    }
    article_line(temp_ligne_2, tab_column_3, 0);  // Vérifier le genre et le nombre
    printf("%s \n", tab_off[0]);







    return 0;
}

