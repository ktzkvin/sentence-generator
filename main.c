#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.c"
#include "files.c"

// créer un nœud root qui contient 4 autres nœuds : verbes, noms, adjectifs, adverbes
// verbes : à leurs formes conjuguées, en fonction de la personne, du singulier, du pluriel, du temps
// noms : à leurs formes au singulier et au pluriel
// Adjectifs : à leurs formes au singulier et au pluriel, au masculin et au féminin
// Adverbes : à leurs formes de base puisqu'ils sont invariables
// créer un nœud pour chaque verbe, nom, adjectif, adverbe

// dico_10_lignes contient 10 lignes
// chaque ligne au fichier dico_10_lignes contient 3 champs différents : sa forme fléchie, sa forme de base, son type
// les champs sont séparés, dans le fichier, par des tabulations
// exemple :
// stabilimetre stabilimetre    Nom:Mas+SG
// stabilimetres    stabilimetre    Nom:Mas+PL

// Il faut donc créer 4 arbres séparés : verbes, noms, adjectifs, adverbes
// Un nœud sous chacun contient 1 seule lettre de l'alphabet
// Sous chacun de ces nœuds se trouvent 26 autres nœuds, chacun contenant 1 seule lettre de l'alphabet, et ainsi de suite 25 fois au total
// Le but étant de créer un arbre comportant tous les mots de "base" du dico_10_lignes.txt.
// Les mots de base sont le 2e mot de chaque ligne du fichier dico_10_lignes.txt.
// Exemple : "stabilimetre" est le 2e mot de la ligne "stabilimetres    stabilimetre Nom:Mas+PL" et est la forme de base.


int main()
{
    // pour appeler la fonction int *OpenFile(char text[100][100]), il faut déclarer un tableau de 100 lignes de 100 caractères
    char **text = malloc(100 * sizeof(char));
    char **text2 = malloc(100 * sizeof(char));
    char **text3 = malloc(100 * sizeof(char));
    for (int i = 0; i < 100; i++) {
        text[i] = malloc(100 * sizeof(char));
        text2[i] = malloc(100 * sizeof(char));
        text3[i] = malloc(100 * sizeof(char));
    }
    text = (char **) extract_column_1();
    text2 = (char **) extract_column_2();
    text3 = (char **) extract_column_3();

    char *temp_ligne = malloc(100 * sizeof(char));  // Création d'un tableau temporaire pour enregistrer une ligne

    char **tab_off = malloc(100 * sizeof(char));  // Création d'un tableau pour séparer les 3 types d'une ligne dans un tableau en 3 lignes
    for (int i = 0; i < 100; i++) {
        tab_off[i] = malloc(3 * sizeof(char));
    }
    int number_line = 6;  // Numéro de la ligne du fichier
    extract_line(temp_ligne, number_line);  // Extraction de la ligne
    printf("\n--------------\nLigne numero %d :\n%s", number_line, temp_ligne);
    printf("--------------\n");
    decompose_line(temp_ligne, tab_off);  // temp_ligne = tableau temporaire contenant la ligne, tab_off = tableau séparant les 3 types de la ligne
    printf("Separation :\n");
    printf("tab_off[0] = %s\n", tab_off[0]);
    printf("tab_off[1] = %s\n", tab_off[1]);
    printf("tab_off[2] = %s", tab_off[2]);
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


    printf("\n");

    // Création de l'arbre avec le dico_10_lignes.txt
    // Création de l'arbre des verbes :
    t_tree tree_verbs = create_tree();
    printf("-%c-", tree_verbs.root->letter);
    p_letter_node tmp = tree_verbs.root;
    // -> vérifie le type de la ligne tab_off[2] si = Ver
    // -> ajoute la forme de base dans l'arbre (= tab_off[1])
    add_word(tmp, tab_off[1]);
    // -> affiche l'arbre

    number_line = 11;  // Numéro de la ligne du fichier
    extract_line(temp_ligne, number_line);  // Extraction de la ligne
    printf("\n--------------\nLigne numero %d :\n%s", number_line, temp_ligne);
    printf("--------------\n");
    decompose_line(temp_ligne, tab_off);  // temp_ligne = tableau temporaire contenant la ligne, tab_off = tableau séparant les 3 types de la ligne
    printf("Separation :\n");
    printf("tab_off[0] = %s\n", tab_off[0]);
    printf("tab_off[1] = %s\n", tab_off[1]);
    printf("tab_off[2] = %s", tab_off[2]);
    printf("--------------\n");


    add_word(tmp, tab_off[1]);
    // -> affiche l'arbre
    printf("\n");













    return 0;
}

