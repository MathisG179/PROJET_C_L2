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
        fclose(dico);
        fclose(names);
    }
    else
    {
        printf("Impossible d'ouvrir le dico dictionnaire.txt");
    }
}

void createFile_verbs(FILE* dico){
    dico = fopen("dictionnaire.txt", "r");
    FILE* verbs = fopen("verbs.txt", "w+");
    char ligne[1000];
    char caractereActuel;
    if (dico != NULL && verbs != NULL) {
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
            if (fgetc(dico) == 'V') {
                fseek(dico, pos, SEEK_SET);
                fgets(ligne, 1000, dico);
                int i = 0;
                while (ligne[i] != '\n') {
                    fputc(ligne[i], verbs);
                    i++;
                }
                fputc('\n', verbs);
            }
            else{
                fgets(ligne, 1000, dico);
            }
        }
        fclose(dico);
        fclose(verbs);
    }
    else
    {
        printf("Impossible d'ouvrir le dico dictionnaire.txt");
    }
}

void createFile_adverbs(FILE* dico){
    dico = fopen("dictionnaire.txt", "r");
    FILE* adverbs = fopen("adverbs.txt", "w+");
    char ligne[1000];
    char caractereActuel;
    if (dico != NULL && adverbs != NULL) {
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
            if (fgetc(dico) == 'A') {
                if (fgetc(dico) == 'd') {
                    if (fgetc(dico) == 'v') {
                        fseek(dico, pos, SEEK_SET);
                        fgets(ligne, 1000, dico);
                        int i = 0;
                        while (ligne[i] != '\n') {
                            fputc(ligne[i], adverbs);
                            i++;
                        }
                        fputc('\n', adverbs);
                    }
                    else{
                        fgets(ligne, 1000, dico);
                    }
                }
                else{
                    fgets(ligne, 1000, dico);
                }
            }
            else{
                fgets(ligne, 1000, dico);
            }
        }
        fclose(dico);
        fclose(adverbs);
    }
    else
    {
        printf("Impossible d'ouvrir le dico dictionnaire.txt");
    }
}

void createFile_adjectives(FILE* dico){
    dico = fopen("dictionnaire.txt", "r");
    FILE* adjectives = fopen("adjectives.txt", "w+");
    char ligne[1000];
    char caractereActuel;
    if (dico != NULL && adjectives != NULL) {
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
            if (fgetc(dico) == 'A') {
                if (fgetc(dico) == 'd') {
                    if (fgetc(dico) == 'j') {
                        fseek(dico, pos, SEEK_SET);
                        fgets(ligne, 1000, dico);
                        int i = 0;
                        while (ligne[i] != '\n') {
                            fputc(ligne[i], adjectives);
                            i++;
                        }
                        fputc('\n', adjectives);
                    }
                    else{
                        fgets(ligne, 1000, dico);
                    }
                }
                else{
                    fgets(ligne, 1000, dico);
                }
            }
            else{
                fgets(ligne, 1000, dico);
            }
        }
        fclose(dico);
        fclose(adjectives);
    }
    else
    {
        printf("Impossible d'ouvrir le dico dictionnaire.txt");
    }
}