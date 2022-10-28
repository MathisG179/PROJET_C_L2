#ifndef PROJET_C_L2_TREE_H
#define PROJET_C_L2_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include "node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

void createFiles(FILE* dico);
t_tree createTree_Names(t_tree, FILE* names);
void printTree(p_node pn);
void printTreeRecursive(p_node pn, int level);
void printTabs(int count);
t_tree createTree(char a);

#endif //PROJET_C_L2_TREE_H
