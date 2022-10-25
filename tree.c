#include "tree.h"


t_tree createTree_Nom(FILE* dico){

}

void createFile_names(FILE* dico){
    dico = fopen("dictionnaire.txt", "r");
    FILE* names = fopen("names.txt", "w+");
    char ligne[1000];
    char caractereActuel;
    if (dico != NULL && names != NULL) {
        while(fgetc(dico) != EOF) {
            fseek(dico,-1, SEEK_CUR);
            // Boucle de lecture des caractères un à un
            int pos = ftell(dico);
            for (int i = 0; i < 2; ++i) {
                do {
                    caractereActuel = fgetc(dico); // On lit le caractère
                    //printf("%c", caractereActuel); // On l'affiche
                } while (caractereActuel != '\t');
            }
            if (fgetc(dico) == 'N') {
                fseek(dico, pos, SEEK_SET);
                fgets(ligne, 1000, dico);
                int i = 0;
                while (ligne[i] != '\n') {
                    fputc(ligne[i], names);
                    i++;
                }
                fputc('\n', names);
            }
            else{
                fgets(ligne, 1000, dico);
            }
        }
    }
    else
    {
        printf("Impossible d'ouvrir le dico dictionnaire.txt");
    }
}