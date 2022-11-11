#ifndef SENTENCE_GENERATOR_FILES_H
#define SENTENCE_GENERATOR_FILES_H
#include "struct.h"
#include "files.h"

// Créer une fonction qui ouvre un fichier, l'extrait et le stocke dans un tableau de caractères
int OpenFile();
void OpenFile_1();
void OpenFile_2();
int **extract_column_1();
int **extract_column_2();
int **extract_column_3();
void extract_line(char *, int);
void decompose_line(char *, char **);
int nature_line(char **);

#endif //SENTENCE_GENERATOR_FILES_H
