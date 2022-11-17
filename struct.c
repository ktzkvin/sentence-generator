#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "files.h"

p_letter_node create_node(p_letter_node node, char letter){
    node = malloc(sizeof(t_letter_node));
    node->letter = letter;
    node->son = NULL;

    return node;
}

p_cell create_son(p_cell son, char letter){
    son = malloc(sizeof(t_cell));
    son->p_node = create_node(son->p_node,letter);
    son->next = NULL;
    return son;
}

void add_son(p_letter_node node, char letter){   // Ajoute un fils à un noeud
    if(node->son == NULL){
        p_cell temporary = create_son(temporary,letter);
        node->son = temporary;
    }
    else{
        p_cell temp = node->son;
        int var = 0;
        while(temp->next != NULL && var == 0){
            if(letter == temp->p_node->letter){
                var = 1;
            }else{
                temp = temp->next;
            }
        }
        if(var == 0){
            if(letter == temp->p_node->letter){
                var = 1;
            }else{
                temp->next = create_son(temp->next,letter);
            }
        }
    }
}

void add_word(p_letter_node node, char * word){  // Ajoute un mot à l'arbre
    if(word[0] == '\0'){
        return;
    }
    add_son(node,word[0]);
    add_word(node->son->p_node,word+1);
}

t_tree create_tree(){
    t_tree tree;
    tree.root->letter = ' ';
    tree.root->son = NULL;
    return tree;
}

// Créer une fonction display_tree qui affiche l'arbre de la façon suivante:
// Afficher toutes les lettres se trouvant dans l'arbre mis en paramètre

void display_tree(p_letter_node node){
    if(node->son == NULL){
        printf("%c",node->letter);
    }else{
        p_cell temp = node->son;
        if(temp != NULL){
            printf("%c",temp->p_node->letter);
            display_tree(temp->p_node);
        }
        if(temp->next != NULL){
            temp = temp->next;
            display_tree(temp->p_node);
        }
    }
}
