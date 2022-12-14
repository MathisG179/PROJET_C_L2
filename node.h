#ifndef PROJET_C_L2_NODE_H
#define PROJET_C_L2_NODE_H

#include <stdlib.h>
#include <stdio.h>

typedef  struct s_node
{
    char lettre;
    char** toto;
    struct s_node *kid;
    struct s_node *siblings;
}t_node, *p_node;

typedef struct s_baseFlechie{
    char* word;
    p_node p;
}t_baseFlechie;

typedef struct s_accords{
    char* word;
    float Genre;
    float Nombre;

}t_accords;


p_node createNode(char);

#endif //PROJET_C_L2_NODE_H