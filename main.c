#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE* f;
    //t_tree NOM = createTree('0');
    //createFiles();
    //NOM = createTree_any(NOM, "names");

    t_tree VER = createTree('0');
    VER = createTree_any(VER, "verbs");

    //t_tree ADV = createTree('0');
    //ADV = createTree_any(ADV, "adverbs");

    //t_tree ADJ = createTree('0');
    //ADJ = createTree_any(ADJ, "adjectives");

    //char* a = ChooseWord(NOM);
    //DisplayWord(a);

    int k = 1;
    //printTree(t.root);
    return 0;
}
