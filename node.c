#include "node.h"


p_node createNode(char a)
{
    p_node nouv;

    nouv = (p_node)malloc(sizeof(t_node));
    nouv->lettre = a;
    nouv->toto = (p_flechie)malloc(sizeof (t_flechie));
    nouv->kid = NULL;
    nouv->siblings = NULL;

    return nouv;
}