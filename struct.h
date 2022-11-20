#ifndef SENTENCE_GENERATOR_STRUCT_H
#define SENTENCE_GENERATOR_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "files.h"

typedef struct s_letter_node t_letter_node, *p_letter_node ;

typedef struct s_cell
{
    p_letter_node p_node ;  // Lettre du fils
    struct s_cell * next ;  // Lettre à droite = frère
} t_cell, *p_cell ;

struct s_letter_node
{
    char letter ;
    p_cell son ;
};

typedef struct s_tree
{
    t_letter_node *root;
} t_tree, *p_tree;

p_letter_node create_node(p_letter_node node, char letter);
p_cell create_son(p_cell son, char letter);
void add_son(p_letter_node node, char letter);
void add_word(p_letter_node node, char * word);
void display_tree(t_tree);


#endif //SENTENCE_GENERATOR_STRUCT_H
