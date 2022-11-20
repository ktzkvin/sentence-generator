#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "files.h"

p_letter_node create_node(p_letter_node node, char letter){  // Créer un noeud
    node = malloc(sizeof(t_letter_node));
    node->letter = letter;
    node->son = NULL;

    return node;
}

p_cell create_son(p_cell son, char letter){  // Créer un fils
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


void display_tree(t_tree tree){
    // Afficher toutes les lettres se trouvant dans l'arbre mis en paramètre
    p_cell temp = tree.root->son;
    while(temp != NULL){
        printf("%c",temp->p_node->letter);
        temp = temp->next;
    }

}

p_cell verif_present(p_letter_node cell, char elements) {  // Vérifie si une lettre est présente parmi les fils d'un noeud
    if (cell->son == NULL) {
        create_son(cell, elements);
        return cell->son;
    } else {
        p_letter_node temp = cell->son;
        while (temp->son->next != NULL) {
            if (temp->letter == elements) {
                return temp;
            } else {
                temp->son->p_node = temp->son->next;
            }
        }
        if (temp->letter == elements) {
            return temp;
        } else {
            create_son(temp->son->next, elements);
            return temp->son->next;
        }
    }
}

struct s_letter_node* add_letter (struct s_letter_node* cell, char elements) {  // Ajoute une lettre à un noeud
    p_cell temp = cell->son;
    if (temp == NULL) {
        create_son(temp, elements);
        return temp;
    } else {
        do {
            if (temp->p_node->letter == elements) {
                return temp;
            }
            temp = temp->next;
        } while (temp->next != NULL);
        create_son(temp, elements);
        return temp;
    }
}
