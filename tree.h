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
t_baseFlechie ChooseWordBase(t_tree t);
t_accords ChooseWordFlechie(t_baseFlechie);

int CountSiblings(p_node p);
void DisplayWord(t_baseFlechie bf);
p_node verif_kid(p_node pn,int row, char* mot);
p_node recherche(t_tree t,char* mot,char* filename);
void WriteSentenceBase(t_tree name,t_tree adj, t_tree adv, t_tree verb);
void WriteSentenceFlechie(t_tree name,t_tree adj, t_tree adv, t_tree verb);
void Affichage(t_tree nom, t_tree adv, t_tree adj, t_tree verb);
int Verif_character(char *input);
int Verif_Genre(char *input);
int Count_flechies(p_node, int);
t_baseFlechie AutoCompletion(t_tree,t_tree,t_tree,t_tree);
void PrintFlechies(p_node,int, int);
char* rechercheNiemeFlechie(p_node, int, int);
void freeTree(p_node, int);

#endif //PROJET_C_L2_TREE_H
