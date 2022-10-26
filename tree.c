#include "tree.h"

t_tree createTree(char a){
    t_tree nouv;
    nouv.root = createNode(a);
    return nouv;
}

void printTabs(int count)
{
    for (int i = 0; i < count; i++)
    {
        putchar('\t');
    }
}

void printTreeRecursive(p_node pn, int level)
{
    while (pn != NULL)
    {
        printTabs(level);
        printf("Node: %c\n", pn->lettre);

        if (pn->kids != NULL)
        {
            printTabs(level);
            printf("Children:\n");
            printTreeRecursive(pn->kids, level + 1);
        }

        pn = pn->kids;
    }
}

void printTree(p_node pn)
{
    printTreeRecursive(pn, 0);
}


p_node storeInTree(p_node pn, char c) {
    if(pn== NULL){
        pn = createNode(c);
    }else if(pn->lettre == '0'){
        storeInTree(pn->kids,c);
    }else if(pn->lettre == c){
        storeInTree(pn->kids,c);
    }else{
        storeInTree(pn->siblings, c);
    }
    return pn;
}


t_tree createTree_Names(FILE* names){
    t_tree t = createTree('0');
    p_node pn = t.root;
    names = fopen("names.txt", "r");
    char name[1000];
    char useless[1000];
    char caractereActuel;
    if(names != NULL) {
        for (int c = 0; c < 5; ++c) {   //TEMPORAIRE !!!! (sera remplacé par le while ci-dessous)


        //while (fgetc(names) != EOF) {
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
                //printf("%c",name[i]);
                i++;
            } while (name[i-1] != '\t');
            //name[i] = '\0';
            i = 0;
            int found = 0;
            while(name[i] != '\t'){
                storeInTree(pn,name[i]);
                i++;
            }
            fgets(useless, 1000, names);
        }
        return t;
    }
    else{
        printf("Impossible d'ouvrir le dico dictionnaire.txt");
        return t;
    }
}

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
                    //printf("%c", caractereActuel); // On l'affiche
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