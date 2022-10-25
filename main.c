#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    FILE* f;
    createFile_adverbs(f);
    createFile_names(f);
    createFile_verbs(f);
    createFile_adjectives(f);
    return 0;
}
