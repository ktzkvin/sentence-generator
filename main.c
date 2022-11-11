#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.c"
#include "bintree.c"
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


// Commençons par créer les 4 nœuds : verbes, noms, adjectifs, adverbes
// Créer un arbre non binaire (un arbre dont chaque nœud a au plus 26 fils)

// Affichage exemple d'un arbre :
/*
                [root]
          /    /      \    \
         a     b      c     d
       / \ \ / / \     \   / \

       ainsi de suite, mais avec 26 fils à chaque nœud

Créer une fonction d'affichage de l'arbre nommée DisplayTree()
Cette fonction prend en paramètre un arbre et affiche l'arbre comme dans l'exemple ci-dessus
Cette fonction doit être récursive
*/
// creer une fonction displaytree qui prend en parametre un arbre et une racine

/*void DisplayTree(p_node root) {
    if (root == NULL) {
        return;
    }
    printf("%c", root->letter);
    printf(" [@%d]\n", root);
    DisplayTree(root->a);
    DisplayTree(root->b);
    DisplayTree(root->c);
    DisplayTree(root->d);
    DisplayTree(root->e);
    DisplayTree(root->f);
    DisplayTree(root->g);
    DisplayTree(root->h);
    DisplayTree(root->i);
    DisplayTree(root->j);
    DisplayTree(root->k);
    DisplayTree(root->l);
    DisplayTree(root->m);
    DisplayTree(root->n);
    DisplayTree(root->o);
    DisplayTree(root->p);
    DisplayTree(root->q);
    DisplayTree(root->r);
    DisplayTree(root->s);
    DisplayTree(root->t);
    DisplayTree(root->u);
    DisplayTree(root->v);
    DisplayTree(root->w);
    DisplayTree(root->x);
    DisplayTree(root->y);
    DisplayTree(root->z);
    printf("\n");
}
*/

int main()
{
    // Création de l'arbre Verbes
    t_root Verbes;

    t_letter_node A;
    A.letter = 'a';
    Verbes.a = &A;
    t_letter_node B;
    B.letter = 'b';
    Verbes.b = &B;
    t_letter_node C;
    C.letter = 'c';
    Verbes.c = &C;
    t_letter_node D;
    D.letter = 'd';
    Verbes.d = &D;
    t_letter_node E;
    E.letter = 'e';
    Verbes.e = &E;
    t_letter_node F;
    F.letter = 'f';
    Verbes.f = &F;
    t_letter_node G;
    G.letter = 'g';
    Verbes.g = &G;
    t_letter_node H;
    H.letter = 'h';
    Verbes.h = &H;
    t_letter_node I;
    I.letter = 'i';
    Verbes.i = &I;
    t_letter_node J;
    J.letter = 'j';
    Verbes.j = &J;
    t_letter_node K;
    K.letter = 'k';
    Verbes.k = &K;
    t_letter_node L;
    L.letter = 'l';
    Verbes.l = &L;
    t_letter_node M;
    M.letter = 'm';
    Verbes.m = &M;
    t_letter_node N;
    N.letter = 'n';
    Verbes.n = &N;
    t_letter_node O;
    O.letter = 'o';
    Verbes.o = &O;
    t_letter_node P;
    P.letter = 'p';
    Verbes.p = &P;
    t_letter_node Q;
    Q.letter = 'q';
    Verbes.q = &Q;
    t_letter_node R;
    R.letter = 'r';
    Verbes.r = &R;
    t_letter_node S;
    S.letter = 's';
    Verbes.s = &S;
    t_letter_node T;
    T.letter = 't';
    Verbes.t = &T;
    t_letter_node U;
    U.letter = 'u';
    Verbes.u = &U;
    t_letter_node V;
    V.letter = 'v';
    Verbes.v = &V;
    t_letter_node W;
    W.letter = 'w';
    Verbes.w = &W;
    t_letter_node X;
    X.letter = 'x';
    Verbes.x = &X;
    t_letter_node Y;
    Y.letter = 'y';
    Verbes.y = &Y;
    t_letter_node Z;
    Z.letter = 'z';
    Verbes.z = &Z;
    //printf("%c", A.letter);

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
    printf("tab_off[2] = %s\n", tab_off[2]);


    printf("\n");

    return 0;

}

