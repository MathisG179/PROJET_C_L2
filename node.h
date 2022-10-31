#ifndef PROJET_C_L2_NODE_H
#define PROJET_C_L2_NODE_H

#include <stdlib.h>
#include <stdio.h>

/*
typedef struct s_flechie{
    int n;                      //n : nb de formes flechies
    char** flechies;
}t_flechie, *p_flechie;
*/

typedef  struct s_node
{
    char lettre;
    char** toto;
    //p_flechie toto;
    struct s_node *kid;
    struct s_node *siblings;
}t_node, *p_node;

p_node createNode(char);

#endif //PROJET_C_L2_NODE_H
