#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE* f;
    t_tree t = createTree('0');
    createFiles(f);
    t = createTree_Names(t, f);
    int k = 1;
    //printTree(t.root);
    return 0;
}
