#ifndef SENTENCE_GENERATOR_FILES_H
#define SENTENCE_GENERATOR_FILES_H
#include "struct.h"
#include "files.h"

int **extract_column_1();
int **extract_column_2();
void article_line(char *, char *, int);
void extract_line(char *);
void decompose_line(char *, char **, char *);
int nature_line(char **);
int adj_ligne(char *, char *);

#endif //SENTENCE_GENERATOR_FILES_H
