#ifndef SENTENCE_GENERATOR_STRUCT_H
#define SENTENCE_GENERATOR_STRUCT_H

// Liste chaînée
typedef struct s_letter_node t_letter_node, *p_letter_node ;

typedef struct s_cell
{
    p_letter_node son ;
    struct s_cell * next ;
} t_cell, *p_cell ;

typedef struct s_std_list
{
    p_cell head ;
} t_std_list ;

struct s_letter_node
{
    char letter ;
    t_std_list sons ;
};



#endif //SENTENCE_GENERATOR_STRUCT_H
