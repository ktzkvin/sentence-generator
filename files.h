#ifndef SENTENCE_GENERATOR_FILES_H
#define SENTENCE_GENERATOR_FILES_H

int **extract_column_1();  // Récupère la première colonne du fichier
int **extract_column_2();  // Récupère la deuxième colonne du fichier
void article_line(char *, char *, int);  // Vérifie le genre et le nombre pour afficher le bon article
void extract_line(char *);  // Récupère une ligne aléatoire du fichier
void extract_line2(char *, int);  // Soit r un nombre aléatoire, récupère la ligne n°r du fichier
void decompose_line(char *, char **, char *);  // Découpe une ligne en plusieurs colonnes
int nature_line(char **);  // Récupère la nature d'une ligne
int adj_ligne(char *, char *);  // Vérifie si l'adjectif est compatible avec le nom
void parcourir_le_dico();  // On parcourt le dictionnaire et on ajoute les mots dans l'arbre

#endif //SENTENCE_GENERATOR_FILES_H
