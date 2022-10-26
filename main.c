#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE* f;
    t_tree t;
    createFiles(f);
    t = createTree_Names(f);
    printTree(t.root);
    return 0;
}
