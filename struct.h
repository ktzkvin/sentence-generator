#ifndef SENTENCE_GENERATOR_STRUCT_H
#define SENTENCE_GENERATOR_STRUCT_H

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

typedef struct root
{
    p_letter_node a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z ;
} t_root, *p_root ;


#endif //SENTENCE_GENERATOR_STRUCT_H
