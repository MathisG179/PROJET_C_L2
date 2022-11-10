#ifndef PROJET_C_L2_TREE_H
#define PROJET_C_L2_TREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include<sys/wait.h>
#include<unistd.h>
#include "node.h"

typedef struct s_tree
{
    p_node root;
} t_tree, *p_tree;

void createFiles();
t_tree createTree(char a);
t_tree createTree_any(t_tree, char*);
void insertFlechies(p_node, char*, int, int);
t_baseFlechie ChooseWord(t_tree t);
int CountSiblings(t_tree t, p_node p);
void DisplayWord(t_baseFlechie bf);
p_node verif_kid(p_node pn,int row, char* mot);
p_node recherche(t_tree t,char* mot,char* filename);
void WriteSentence(t_tree name,t_tree adj, t_tree adv, t_tree verb);


#endif //PROJET_C_L2_TREE_H
