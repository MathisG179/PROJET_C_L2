#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    int start = time(0);
    printf("\n-------------%ld-------------\n",time(0)-start);
    srand(time(NULL));
    FILE* f;
    t_tree NOM = createTree('0');
    //createFiles();
    NOM = createTree_any(NOM, "names");

    t_tree VER = createTree('0');
    VER = createTree_any(VER, "verbs");

    t_tree ADV = createTree('0');
    ADV = createTree_any(ADV, "adverbs");

    t_tree ADJ = createTree('0');
    ADJ = createTree_any(ADJ, "adjectives");

    /*for (int i = 0; i < 10; ++i) {
        WriteSentenceBase(NOM,ADJ,ADV,VER);
        printf("\n");
    }*/
    //p_node a = recherche(NOM, "pietàs", "names");
    //t_baseFlechie bf;
    //t_accords a;

    printf("\n-------------%ld-------------\n",time(0)-start);
    for (int i = 0; i < 10; ++i) {
        WriteSentenceFlechie(NOM,ADJ, ADV, VER);
        printf("\n");
    }
    printf("\n-------------%ld-------------\n",time(0)-start);
    int k = 1;
    //printTree(t.root);
    return 0;
}
