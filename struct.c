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

void add_son(p_letter_node node, char letter){  // Ajoute un fils à un noeud
    if(node->son == NULL){
        p_cell temporary = create_son(temporary,letter);
        node->son = temporary;
    }
    else{
        p_cell temp = node->son;
        int found = 0;
        while(temp->next != NULL && found == 0){
            if(letter == temp->p_node->letter){
                found = 1;
            }else{
                temp = temp->next;
            }
        }
        if(found == 0){
            if(letter == temp->p_node->letter){
                found = 1;
            }else{
                temp->next = create_son(temp->next,letter);
            }
        }
    }
}

void add_word(p_letter_node node, char * word){
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

void display_tree(p_letter_node node, char * word){
    if(node->son == NULL){
        printf("%s",word);
        return;
    }
    p_cell temp = node->son;
    while(temp != NULL){
        char * new_word = malloc(sizeof(char)*(strlen(word)+2));
        strcpy(new_word,word);
        new_word[strlen(word)] = temp->p_node->letter;
        new_word[strlen(word)+1] = '\0';
        display_tree(temp->p_node,new_word);
        temp = temp->next;
    }
}
