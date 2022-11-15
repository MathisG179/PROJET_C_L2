#include "tree.h"
#include <stdlib.h>
#include <stdio.h>




int main() {

    char *menu = "1.Générateur de phrases\n2.Recherche de mot\n3.Exit";
    char *menu_s = "1.Formes de base\n2.Formes fléchies\n3.Exit";
    char *menu_ss ="1.Recherche d'un mot\n2.Auto completion d'un mot\n3.Exit";
    int choice = 0, choice_s = 0, choice_ss=0;
    char* mot = malloc(50*sizeof(char));
    char* nature = malloc(50*sizeof(char));
    int start = time(0);
    printf("\n--------------%ld--------------\n",time(0)-start);
    srand(time(NULL));

    FILE* f;

    //createFiles();

    t_tree VER = createTree('0');
    VER = createTree_any(VER, "verbs");

    printf("\n-------------VER-------------\n\n-------------%ld-------------\n",time(0)-start);

    t_tree NOM = createTree('0');
    NOM = createTree_any(NOM, "names");

    printf("\n-------------NOM-------------\n\n-------------%ld-------------\n",time(0)-start);

    t_tree ADV = createTree('0');
    ADV = createTree_any(ADV, "adverbs");

    printf("\n-------------ADV-------------\n\n-------------%ld-------------\n",time(0)-start);

    t_tree ADJ = createTree('0');
    ADJ = createTree_any(ADJ, "adjectives");

    printf("\n-------------ADJ-------------\n\n-------------%ld-------------\n",time(0)-start);

    int cpt = 1;
    char add[10];
    char useless;


    while (choice != 3) {
        choice = Verify_input(Menu(menu), 1, 3);
        printf("\n");
        if (choice == 1) {
            while (choice_s != 3) {
                choice_s = Verify_input(Menu(menu_s), 1, 3);
                printf("\n");
                useless = fgetc(stdin);
                if (choice_s == 1) {
                    WriteSentenceBase(NOM,ADJ,ADV,VER);
                }
                if (choice_s == 2) {

                    WriteSentenceFlechie(NOM,ADJ,ADV,VER);
                }
            }
        }
        if (choice == 2) {
            while (choice_ss != 3) {
                choice_ss = Verify_input(Menu(menu_ss), 1, 3);
                printf("\n");
                useless = fgetc(stdin);
                if(choice_ss==1) {
                    mot = Mot_recherche(mot);
                    nature = Nature(nature);
                    Affichage(NOM, ADV, ADJ, VER, mot, nature);
                }
                if(choice_ss==2){
                    nature = Nature(nature);
                    t_baseFlechie bf = AutoCompletion(NOM,VER,ADJ,ADV, nature);
                    if ( bf.word != NULL){
                        Affichage(NOM, ADV, ADJ, VER, bf.word, nature);
                    }
                }
            }
        }
    }
    freeTree(ADV.root, 1);
    return 0;

}













/*
int main() {
    int start = time(0);
    printf("\n--------------%ld--------------\n",time(0)-start);
    srand(time(NULL));

    FILE* f;

    //createFiles();

    t_tree VER = createTree('0');
    VER = createTree_any(VER, "verbs");

    printf("\n-------------VER-------------\n\n-------------%ld-------------\n",time(0)-start);

    t_tree NOM = createTree('0');
    NOM = createTree_any(NOM, "names");

    printf("\n-------------NOM-------------\n\n-------------%ld-------------\n",time(0)-start);

    t_tree ADV = createTree('0');
    ADV = createTree_any(ADV, "adverbs");

    printf("\n-------------ADV-------------\n\n-------------%ld-------------\n",time(0)-start);

    t_tree ADJ = createTree('0');
    ADJ = createTree_any(ADJ, "adjectives");

    printf("\n-------------ADJ-------------\n\n-------------%ld-------------\n",time(0)-start);
    int cpt = 1;
    char add[10];





    for (int i = 0; i < cpt; ++i) {
        t_baseFlechie bf = AutoCompletion(NOM, VER, ADJ, ADV);
        DisplayWord(bf);
        printf("\nSouhaitez chercher d'autres mots avec la completion automatique ?\n");
        fgets(add, 9, stdin);
        //char useless = fgetc(stdin);
        if (add[0] == 'O' || add[0] == 'o' || add[0] == 'Y' || add[0] == 'y' || add[0] == '1') {
            cpt += 1;
        }
    }

    //printf("\n-------------%ld-------------\n",time(0)-start);
    freeTree(ADV.root, 1);
    //printf("\n-------------%ld-------------\n",time(0)-start);
    int k = 1;

    return 0;
}
*/