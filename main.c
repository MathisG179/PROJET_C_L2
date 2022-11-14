#include "tree.h"
#include <stdlib.h>
#include <stdio.h>


int main() {
    int start = time(0);
    printf("\n-------------%ld-------------\n",time(0)-start);
    srand(time(NULL));

    FILE* f;

    createFiles();

    t_tree VER = createTree('0');
    //VER = createTree_any(VER, "verbs");

    t_tree NOM = createTree('0');
    //NOM = createTree_any(NOM, "names");

    t_tree ADV = createTree('0');
    ADV = createTree_any(ADV, "adverbs");

    t_tree ADJ = createTree('0');
    //ADJ = createTree_any(ADJ, "adjectives");

    int cpt = 1;
    char add[10];
    printf("\n-------------%ld-------------\n",time(0)-start);
    /*
    for (int i = 0; i < cpt; ++i) {
        WriteSentenceFlechie(NOM,ADJ, ADV, VER);
        printf("\nSouhaitez vous découvir de nouvelles phrases ?\n");
        fgets(add,9, stdin);
        if(add[0] == 'O' || add[0] == 'o' || add[0] == 'Y' || add[0] == 'y' || add[0] == '1'){
            cpt += 1;
        }
        printf("\n");
    }

    for (int i = 0; i < cpt; ++i) {
        t_baseFlechie bf = AutoCompletion(NOM, VER, ADJ, ADV);
        DisplayWord(bf);
        printf("\nSouhaitez chercher d'autres mots avec la completion automatique ?\n");
        fgets(add, 9, stdin);
        //char useless = fgetc(stdin);
        if (add[0] == 'O' || add[0] == 'o' || add[0] == 'Y' || add[0] == 'y' || add[0] == '1') {
            cpt += 1;
        }
    }*/
    printf("\n-------------%ld-------------\n",time(0)-start);
    freeTree(ADV.root, 1);
    printf("\n-------------%ld-------------\n",time(0)-start);
    int k = 1;

    return 0;
}
