#ifndef PROJET_C_L2_TREE_H
#define PROJET_C_L2_TREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct s_flechie{
    int n;                      //n : nb de formes flechies
    char** flechies;
}t_flechie, *p_flechie;

typedef  struct s_node
{
    char lettre;
    p_flechie toto;
    int numKids;
    struct t **kids;
}t_node, *p_node;


typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

void createFile_names(FILE* dico);
void createFile_verbs(FILE* dico);
void createFile_adverbs(FILE* dico);
void createFile_adjectives(FILE* dico);

#endif //PROJET_C_L2_TREE_H
