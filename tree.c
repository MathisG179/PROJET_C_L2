#include "tree.h"

t_tree createTree(char a){
    t_tree nouv;
    nouv.root = createNode(a);
    return nouv;
}


t_tree createTree_any(t_tree t, char* filename){
    p_node pn = t.root;
    FILE* file;
    if(strcmp(filename, "names") == 0){
        file = fopen("names.txt", "r");
    }else if(strcmp(filename, "verbs") == 0){
        file = fopen("verbs.txt", "r");
    }else if(strcmp(filename, "adverbs") == 0){
        file = fopen("adverbs.txt", "r");
    }else if(strcmp(filename, "adjectives") == 0){
        file = fopen("adjectives.txt", "r");
    }
    char name[1000];
    char useless[1000];
    char caractereActuel;
    int kid;
    int sib;
    if(file != NULL) {
        while (fgetc(file) != EOF) {

            fseek(file, -1, SEEK_CUR);
            // Boucle de lecture des caractères un à un
            int pos = ftell(file);
            do {
                caractereActuel = fgetc(file); // On lit le caractère
            } while (caractereActuel != '\t');
            int i = 0;
            do {
                caractereActuel = fgetc(file);
                name[i] = caractereActuel;
                //printf("%c",name[i]);
                i++;
            } while (name[i-1] != '\t');
            //printf("\n");
            i = 0;
            while(name[i] != '\t'){
                if(pn->lettre == '0'){
                    pn->kid = createNode(name[i]);
                    pn = pn->kid;
                }else {
                    while (pn->lettre != name[i]) {
                        if (pn->siblings != NULL) {
                            pn = pn->siblings;
                        } else {
                            if(name[i] != '\t'){
                                pn->siblings = createNode(name[i]);
                                sib = 1;
                                pn = pn->siblings;
                            }
                        }
                    }
                    if (pn->kid != NULL) {
                        pn = pn->kid;
                        i++;
                    } else {
                        i++;
                        if(name[i] != '\t'){
                            pn->kid = createNode(name[i]);
                            pn = pn->kid;
                        }
                    }
                }
            }
            pn = t.root;
            pn = pn->kid;
            fgets(useless, 1000, file);
        }
        return t;
    }
    else{
        printf("Impossible d'ouvrir le dico %c.txt",filename);
        return t;
    }
}





/*
t_tree createTree_Names(t_tree t, FILE* names){
    p_node pn = t.root;
    names = fopen("names.txt", "r");
    char name[1000];
    char useless[1000];
    char caractereActuel;
    int kid;
    int sib;
    if(names != NULL) {
        while (fgetc(names) != EOF) {

            fseek(names, -1, SEEK_CUR);
            // Boucle de lecture des caractères un à un
            int pos = ftell(names);
            do {
                caractereActuel = fgetc(names); // On lit le caractère
            } while (caractereActuel != '\t');
            int i = 0;
            do {
                caractereActuel = fgetc(names);
                name[i] = caractereActuel;
                printf("%c",name[i]);
                i++;
            } while (name[i-1] != '\t');
            printf("\n");
            i = 0;
            while(name[i] != '\t'){
                if(pn->lettre == '0'){
                    pn->kid = createNode(name[i]);
                    pn = pn->kid;
                    i++;
                }else {
                    while (pn->lettre != name[i]) {
                        if (pn->siblings != NULL) {
                            pn = pn->siblings;
                        } else {
                            if(name[i] != '\t'){
                                pn->siblings = createNode(name[i]);
                                sib = 1;
                                pn = pn->siblings;
                            }
                        }
                    }
                    if (pn->kid != NULL) {
                        pn = pn->kid;
                        i++;
                    } else {
                        i++;
                        if(name[i] != '\t'){
                            pn->kid = createNode(name[i]);
                            pn = pn->kid;
                        }
                    }
                }
            }
            pn = t.root;
            pn = pn->kid;
            fgets(useless, 1000, names);
        }
        return t;
    }
    else{
        printf("Impossible d'ouvrir le dico names.txt");
        return t;
    }
}*/

void createFiles(FILE* dico){
    dico = fopen("dictionnaire.txt", "r");
    FILE* names = fopen("names.txt", "w+");
    FILE* verbs = fopen("verbs.txt", "w+");
    FILE* adverbs = fopen("adverbs.txt", "w+");
    FILE* adjectives = fopen("adjectives.txt", "w+");
    char ligne[1000];
    char caractereActuel;
    char a, b;
    if (dico != NULL && names != NULL && verbs != NULL && adverbs != NULL && adjectives != NULL) {
        while(fgetc(dico) != EOF) {
            fseek(dico,-1, SEEK_CUR);
            // Boucle de lecture des caractères un à un
            int pos = ftell(dico);
            for (int i = 0; i < 2; ++i) {
                do {
                    caractereActuel = fgetc(dico); // On lit le caractère
                } while (caractereActuel != '\t');
            }
            a = fgetc(dico);
            if (a == 'N') {
                fseek(dico, pos, SEEK_SET);
                fgets(ligne, 1000, dico);
                int i = 0;
                while (ligne[i] != '\n') {
                    fputc(ligne[i], names);
                    i++;
                }
                fputc('\n', names);
            }else if (a == 'V') {
                fseek(dico, pos, SEEK_SET);
                fgets(ligne, 1000, dico);
                int i = 0;
                while (ligne[i] != '\n') {
                    fputc(ligne[i], verbs);
                    i++;
                }
                fputc('\n', verbs);
            }else if (a == 'A') {
                if (fgetc(dico) == 'd') {
                    b = fgetc(dico);
                    if (b == 'v') {
                        fseek(dico, pos, SEEK_SET);
                        fgets(ligne, 1000, dico);
                        int i = 0;
                        while (ligne[i] != '\n') {
                            fputc(ligne[i], adverbs);
                            i++;
                        }
                        fputc('\n', adverbs);
                    }else if (b == 'j') {
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
        fclose(names);
        fclose(verbs);
        fclose(adverbs);
        fclose(adjectives);
    }
    else
    {
        printf("Impossible d'ouvrir le dico dictionnaire.txt");
    }
}
