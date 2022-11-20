#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.c"
#include "files.c"
#include <time.h>


int main()
{
    char *temp_ligne = malloc(100 * sizeof(char));  // Création d'un tableau temporaire pour enregistrer une ligne

    char **tab_off = malloc(100 * sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
    for (int i = 0; i < 100; i++) {
        tab_off[i] = malloc(3 * sizeof(char));
    }

    int number_line = 6;  // Numéro de la ligne du fichier
    extract_line(temp_ligne);  // Extraction de la ligne
    printf("--------------\n");

    decompose_line(temp_ligne, tab_off);  // temp_ligne = tableau temporaire contenant la ligne, tab_off = tableau séparant les 3 types de la ligne
    printf("Ligne %d : %s\n", number_line, temp_ligne);
    printf("Separation :\n");
    printf("tab_off[0] = %s\n", tab_off[0]);
    printf("tab_off[1] = %s\n", tab_off[1]);
    printf("tab_off[2] = %s\n", tab_off[2]);
    printf("--------------\n");
    if (nature_line(tab_off) == 1){
        printf("Type : Verbe\n");
    } else if (nature_line(tab_off) == 2){
        printf("Type : Nom\n");
    } else if (nature_line(tab_off) == 3){
        printf("Type : Adjectif\n");
    } else {
        printf("Type : Inconnu\n");
    }


    // Création de l'arbre avec le dico_10_lignes.txt
    // Création de l'arbre des verbes :
    t_tree tree_verbs = create_tree();
    p_letter_node tmp = tree_verbs.root;
    // -> vérifie le type de la ligne tab_off[2] si = Ver
    // -> ajoute la forme de base dans l'arbre (= tab_off[1])
    add_word(tmp, tab_off[1]);
    // -> affiche l'arbre

    number_line = 11;  // Numéro de la ligne du fichier
    extract_line(temp_ligne);  // Extraction de la ligne
    printf("\n--------------\nLigne numero %d :\n%s", number_line, temp_ligne);
    printf("--------------\n");
    decompose_line(temp_ligne, tab_off);  // temp_ligne = tableau temporaire contenant la ligne, tab_off = tableau séparant les 3 types de la ligne
    printf("Separation :\n");
    printf("tab_off[0] = %s\n", tab_off[0]);
    printf("tab_off[1] = %s\n", tab_off[1]);
    printf("tab_off[2] = %s\n", tab_off[2]);
    printf("--------------\n");
    if (nature_line(tab_off) == 1){
        printf("Type : Verbe\n");
    } else if (nature_line(tab_off) == 2){
        printf("Type : Nom\n");
    } else if (nature_line(tab_off) == 3){
        printf("Type : Adjectif\n");
    } else {
        printf("Type : Inconnu\n");
    }





    printf("--------------------\n");


    int nombreAleatoire = 0;
    const int MAX = 287976, MIN = 1;
    srand(time(NULL));
    nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;

    while (nature_line(tab_off) != 2) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);
        decompose_line(temp_ligne, tab_off);
    }
    printf("%s\t", tab_off[0]);
    while (nature_line(tab_off) != 3) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);
        decompose_line(temp_ligne, tab_off);
    }
    printf("%s\t", tab_off[0]);
    while (nature_line(tab_off) != 1) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);
        decompose_line(temp_ligne, tab_off);
    }
    printf("%s\t", tab_off[0]);
    while (nature_line(tab_off) != 2) {
        nombreAleatoire = (rand() % (MAX - MIN + 1)) + MIN;
        extract_line2(temp_ligne, nombreAleatoire);
        decompose_line(temp_ligne, tab_off);
    }
    printf("%s\t", tab_off[0]);





    return 0;
}

