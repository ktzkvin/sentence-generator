#ifndef SENTENCE_GENERATOR_STRUCT_H
#define SENTENCE_GENERATOR_STRUCT_H

typedef struct s_letter_node t_letter_node, *p_letter_node ;

typedef struct s_cell  // Structure d'une cellule de la liste chainée
{
    p_letter_node p_node ;  // Lettre du fils
    struct s_cell * next ;  // Lettre à droite = frère
} t_cell, *p_cell ;

struct s_letter_node  // Structure d'un noeud de l'arbree
{
    char letter ;  // Lettre du noeud
    p_cell son ;  // Liste chainée des fils
};

typedef struct s_tree  // Structure de l'arbre
{
    t_letter_node *root;  // Racine de l'arbre
} t_tree, *p_tree;

p_letter_node create_node(p_letter_node, char);  // Créer un noeud
p_cell create_son(p_cell, char);  // Créer un fils
void add_son(p_letter_node, char);  // Ajoute un fils à un noeud
void add_word(p_letter_node, char*);  // Ajoute un mot à l'arbre
void display_tree(t_tree);  // Affiche l'arbre
p_cell verif_present(p_letter_node, char);  // Vérifie si une lettre est présente parmi les fils d'un noeud
struct s_letter_node* add_letter (struct s_letter_node*, char);  // Ajoute une lettre à un noeud version 2


#endif //SENTENCE_GENERATOR_STRUCT_H
