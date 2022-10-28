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
        if(pn->lettre != '0') {
            printTabs(level);
            printf("Node: %c\n", pn->lettre);

            if (pn->kid != NULL) {
                printTabs(level);
                printf("Children:\n");
                printTreeRecursive(pn->kid, level + 1);
            }
        }
        pn = pn->kid;
    }
}


t_tree createTree_Names(t_tree t, FILE* names){
    //t_tree t = createTree('0');
    p_node pn = t.root;
    names = fopen("names.txt", "r");
    char name[1000];
    char useless[1000];
    char caractereActuel;
    int kid;
    int sib;
    if(names != NULL) {
        //for (int c = 0; c < 4478; ++c) {   //TEMPORAIRE !!!! (sera remplacé par le while ci-dessous)


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
                //printf("%c",name[i]);
                i++;
            } while (name[i-1] != '\t');
            //name[i] = '\0';

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
                    //i++;
                    //else if(pn->lettre == name[i]){
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
                /*}else{
                    while(pn->lettre != name[i]){
                        if(pn->siblings != NULL){
                            pn = pn->siblings;
                        }else{
                            pn->siblings = createNode(name[i]);
                            sib = 1;
                            pn = pn->siblings;
                        }
                    }
                    i++;
                }*/

                /*    sib
                if(sib == 1){
                    while(name[i] != '\t'){
                        pn->kid = createNode(name[i]);
                        pn = pn->kid;
                        i++;
                    }
                    sib = 0;
                }*/

                /*
                if(pn->lettre == '0'){
                    if(name[i] != '\t'){
                        pn->kid = createNode(name[i]);
                        pn = pn->kid;
                    }
                    i++;
                }
                else if(name[i] == pn->lettre){
                    if(pn->kid == NULL){
                        i++;
                        if(name[i] != '\t'){
                            pn->kid = createNode(name[i]);
                            pn = pn->kid;
                        }
                    }else{
                        pn = pn->kid;
                        i++;

                        while(pn->lettre != name[i]){
                            if(pn->siblings == NULL && name[i] != '\t'){
                                pn->siblings = createNode(name[i]);
                                pn = pn->siblings;
                            }else{
                                if(name[i] != '\t'){
                                    pn = pn->siblings;
                                }
                            }
                        }
                    }
                }else{
                    while(pn->lettre != name[i]){
                        if(pn->siblings == NULL){
                            pn->siblings = createNode(name[i]);
                            pn = pn->siblings;
                        }else{
                            pn = pn->siblings;
                        }
                    }
                    i++;
                }*/
            }
            pn = t.root;
            pn = pn->kid;
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
    dico = fopen("dictionnaire_non_accentue.txt", "r");
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







/*      OLD
                int kidsibling = KidOrSibling(pn, name[i]);
                if(kidsibling == 1){
                    pn->siblings = storeInTree(pn->siblings,name[i]);
                }else if(kidsibling == 0){
                    pn->kid = storeInTree(pn, name[i]);
                }
                if(kidsibling != -2 && pn->kid != NULL) {
                    pn = pn->kid;
                }else if(kidsibling != -2  && pn->siblings != NULL){
                    pn = pn->siblings;
                    while(pn->lettre != name[i]  && pn->siblings != NULL){
                        pn = pn->siblings;
                    }
                }else{
                    pn->kid = createNode(name[i+1]);

                    p_node tmp1 = pn->kid;
                    p_node tmp2 = pn->siblings;
                    if(tmp1 != NULL &&tmp1->lettre == '\t'){
                        pn->kid = NULL;
                        kid = 0;
                    }else if(tmp2 != NULL && tmp2->lettre == '\t'){
                        pn->kid = NULL;
                        kid = 0;
                    }else{
                        kid = 1;
                    }
                    if(kid == 1){
                        pn = pn->kid;
                    }
                }


                //printf("char %c stored\n",name[i]);


        OLD


void printTree(p_node pn)
{
    printTreeRecursive(pn, 0);
}
int KidOrSibling(p_node pn, char c) {

    if (pn == NULL || (pn->kid == NULL && pn->siblings == NULL)) {
        return 0;
    } else if (pn->lettre == '0') {
        return 0;
    } else if (pn->lettre == c) {
        return -1;
    } else if(pn->lettre == '\t'){
        return -2;
    } else {
        return 1;;
    } else {
        return 1;
    }
}
p_node storeInTree(p_node pn, char c) {
    if(pn== NULL){
        pn = createNode(c);
    }else if(pn->lettre == '0'){
        pn = storeInTree(pn->kid, c);
    }else if(pn->lettre == c){
        pn = NULL;
    }else if(pn->lettre == '\t'){
        pn = NULL;
    }/*else if(pn->kid == NULL){
        pn = storeInTree(pn->kid,c);
    }else{
        pn =storeInTree(pn->siblings, c);
    }

    return pn;
}

*/