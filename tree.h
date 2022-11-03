#ifndef PROJET_C_L2_TREE_H
#define PROJET_C_L2_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
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
void recherche_mot(t_tree t,char* mot);
char * ChooseWord(t_tree t);
int CountSiblings(t_tree t, p_node p);
void DisplayWord(char * word);


#endif //PROJET_C_L2_TREE_H
