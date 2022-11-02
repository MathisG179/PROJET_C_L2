#ifndef PROJET_C_L2_TREE_H
#define PROJET_C_L2_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

void createFiles();
t_tree createTree(char a);
t_tree createTree_any(t_tree, char*);
void insertFlechies(p_node, char*, int, int);
void displayNode(p_node, char*);

#endif //PROJET_C_L2_TREE_H
