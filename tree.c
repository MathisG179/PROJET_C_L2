#include "tree.h"

char * ChooseWord(t_tree t) {
    p_node tmp;
    int cpt = 0, random, i = 0, choice, stop;
    char *word = (char *) malloc(50 * sizeof(char));
    tmp = t.root->kid;
    srand( time( NULL ) );
    random = rand() % 26;

    while (cpt < random ) {
        tmp = tmp->siblings;
        cpt++;
    }

    word[i] = tmp->lettre;
    i++;
    tmp = tmp->kid;
    stop = 1;

    while (stop != 0) {  //We will run while stop is different from 0
        if (tmp->siblings == NULL) {  //If it has no sibling we go to the kid.
            if (tmp ->kid != NULL){   // Verify if the kids are null or not, if yes, we are at the end of the word.
                word[i] = tmp->lettre;
                tmp = tmp->kid;
            }
            else {
                word[i] = tmp->lettre;
                stop = 0;
            }
        } else {   // if it has siblings, we will choose randomly one of them.
            choice = rand() % 2;  //Choose randomly if we want to use siblings or not
            if (choice == 0) {
                if (tmp ->kid != NULL){
                    word[i] = tmp->lettre;
                    tmp = tmp->kid;
                }
                else {
                    word[i] = tmp->lettre;
                    stop = 0;
                }

            } else {
                random = rand()% CountSiblings(t,tmp); //count the number of siblings
                cpt = 0;
                while (cpt <= random) {
                    tmp = tmp->siblings;
                    cpt++;
                }
                if( tmp->kid != NULL){
                    word[i] = tmp->lettre;
                    tmp = tmp->kid;
                }
                else {
                    word[i] = tmp->lettre;
                    stop = 0;
                }

            }
        }
        i++;
    }
    word[i + 1] = 0;
    word = (char *) realloc(word, i * sizeof(char));;
    return word;
}

int CountSiblings(t_tree t, p_node p){
    int cpt = 0;
    p_node tmp = p;
    while (tmp->siblings != NULL){
        tmp = tmp->siblings;
        cpt ++;
    }
    return cpt;
}

void DisplayWord(char * word){
    int i = 0;
    while (word[i] != 0){
        printf("%c", word[i]);
        i++;
    }
}

void recherche_mot(t_tree t,char* mot){   // parcourir l arbre au fur et a mesure / creer un stop dans le while et imbrique le if cpt = machin dansle while
    //et mettre le stop a 0. cherchez dansles formes flechies de la node
    p_node pn = t.root;
    pn=pn->kid;
    int i =0;
    int cpt =0;
    int length = strlen(mot);
    while (pn->kid!=NULL) {
        if (mot[i] == pn->lettre) {
            pn = pn->kid;
            cpt+=1;
            i++;
        }
        else {
            pn = pn->siblings;
        }
    }
    if (cpt==length){
        printf("mot trouvé");
    }
    else{
        printf("mot non trouvé");
    }
}

t_tree createTree(char a){
    t_tree nouv;
    nouv.root = createNode(a);
    return nouv;
}

void displayNode(p_node pn, char* filename){
    if(strcmp(filename, "names") == 0){

        for (int j = 0; j < 9; ++j) {
            DisplayWord(pn->toto[j]);/*
            int i = 0;
            while (pn->toto[j][i] != 0){
                printf("%c",pn->toto[j][i]);
                i++;
            }*/
            if (pn->toto[j][0] != 0){
                printf("\n");
            }
        }
    }
    else if(strcmp(filename, "adjectives") == 0){
        for (int j = 0; j < 10; ++j) {
            int i = 0;
            while (pn->toto[j][i] != 0){
                printf("%c",pn->toto[j][i]);
                i++;
            }
            if (pn->toto[j][0] != 0){
                printf("\n");
            }
        }
    }
}

void insertFlechies(p_node pn, char* filename, int StartPosition, int ActualPosition){
    FILE* file;
    int Card = 0;
    float Genre = 0;                    //0.5 = Mas | 3.5 = Fem | 6.5 = InvGEN
    float Nombre = 0;                   //0.5 = SG | 1.5 = PL | 2.5 = InvPL
    const float Mas = 0.5;              //Genre + Nombre = position du tableau(Genre en ligne et Nombre en colone)
    const float Fem = 3.5;              //La 10e case corespond aux Card
    const float InvGEN = 6.5;
    const float SG = 0.5;
    const float PL = 1.5;
    const float InvPL = 2.5;

    int Inf = 0;
    int Personne = 0;
    int Temps = 0;
    const int IPre = 1;
    const int IImp = 2;                 //Personne + Temps = position du tableau(Personne en ligne et Temps en colone)
    const int SPre = 3;
    const int vSG = 0;
    const int vPL = 9;
    const int P1 = 0;
    const int P2 = 3;
    const int P3 = 6;


    char ActualChar;
    int i = 0;
    char name[1000];
    if(strcmp(filename, "names") == 0){
        file = fopen("names.txt", "r");
        fseek(file, ActualPosition, SEEK_SET);
        if(pn->toto == NULL){
            // initialisation d'un tableau de 9 char*
            pn->toto = (char**)malloc(9*sizeof(char*));
            for (int j = 0; j < 9; ++j) {
                //pn->toto[j] = (char*)malloc(100*sizeof(char));
                pn->toto[j] = (char*)calloc(100,sizeof(char));
            }

        }

        do {
            ActualChar = fgetc(file); // On lit le caractère
            /*k++;
            int d = ftell(file);
            if(d > 600000){

                printf("%c", ActualChar);
            }
            if(k>7){
                printf("%d\n",k);

                printf("%d\n", d);
                break;*/
        } while (ActualChar != ':');

        ActualChar = fgetc(file);
        if(ActualChar == 'M'){
            Genre = Mas;
        }else if(ActualChar == 'F'){
            Genre = Fem;
        }else if(ActualChar == 'I'){
            Genre = InvGEN;
        }else {
            int d = ftell(file);
            printf("G%d\n", d);
        }


        do {
            ActualChar = fgetc(file); // On lit le caractère
        } while (ActualChar != '+');



        ActualChar = fgetc(file);
        if(ActualChar == 'S'){
            Nombre = SG;
        }else if(ActualChar == 'P'){
            Nombre = PL;
        }else if(ActualChar == 'I'){
            Nombre = InvPL;
        }else {
            int d = ftell(file);
            printf("N%d\n", d);
        }

        fseek(file, StartPosition, SEEK_SET);




        do {
            ActualChar = fgetc(file);
            name[i] = ActualChar;
            //printf("%c",name[i]);
            i++;
        } while (name[i-1] != '\t');
        i = 0;
        while(name[i] != '\t'){
            pn->toto[(int)(Genre + Nombre-1)][i] = name[i];
            //char b = pn->toto[(int)(Genre + Nombre)][i];
            i++;
        }

    }
    else if(strcmp(filename, "adjectives") == 0){
        file = fopen("adjectives.txt", "r");
        fseek(file, ActualPosition, SEEK_SET);
        if(pn->toto == NULL){
            // initialisation d'un tableau de 10 char*
            pn->toto = (char**)malloc(10*sizeof(char*));
            for (int j = 0; j < 10; ++j) {
                //pn->toto[j] = (char*)malloc(100*sizeof(char));
                pn->toto[j] = (char*)calloc(100,sizeof(char));
            }

        }
        int k = 0;
        do {
            ActualChar = fgetc(file); // On lit le caractère
            /*k++;
            int d = ftell(file);
            if(d > 300000){

                printf("%c", ActualChar);
            }
            if(k>7) {
                printf("%d\n", k);

                printf("%d\n", d);
                break;
            }*/
        } while (ActualChar != ':');

        ActualChar = fgetc(file);
        if(ActualChar == 'M'){
            Genre = Mas;
        }else if(ActualChar == 'F'){
            Genre = Fem;
        }else if(ActualChar == 'I'){
            Genre = InvGEN;
        }else if (ActualChar == 'C'){
            Card = 1;
        }else {
            int d = ftell(file);
            printf("G%d\n", d);
        }
        do {
            ActualChar = fgetc(file); // On lit le caractère
        } while (ActualChar != '+');



        ActualChar = fgetc(file);
        if(ActualChar == 'S'){
            Nombre = SG;
        }else if(ActualChar == 'P'){
            Nombre = PL;
        }else if(ActualChar == 'I'){
            Nombre = InvPL;
        }/*else {
            int d = ftell(file);
            printf("N%d\n", d);
        }*/

        fseek(file, StartPosition, SEEK_SET);

        do {
            ActualChar = fgetc(file);
            name[i] = ActualChar;
            //printf("%c",name[i]);
            i++;
        } while (name[i-1] != '\t');
        i = 0;
        while(name[i] != '\t'){
            if(Card == 1){
                pn->toto[9][i] = name[i];
            }else{
                pn->toto[(int)(Genre + Nombre-1)][i] = name[i];
            }

            i++;
        }
    }
    else if(strcmp(filename, "verbs") == 0){

        file = fopen("verbs.txt", "r");
        fseek(file, ActualPosition, SEEK_SET);
        if(pn->toto == NULL){
            // initialisation d'un tableau de 10 char*
            pn->toto = (char**)malloc(19*sizeof(char*));
            for (int j = 0; j < 19; ++j) {
                //pn->toto[j] = (char*)malloc(100*sizeof(char));
                pn->toto[j] = (char*)calloc(100,sizeof(char));
            }

        }
        do {
            ActualChar = fgetc(file); // On lit le caractère
        } while (ActualChar != ':');

        ActualChar = fgetc(file);
        if(ActualChar == 'I'){
            ActualChar = fgetc(file);
            if(ActualChar == 'P'){
                ActualChar = fgetc(file);
                if(ActualChar == 'r'){
                    ActualChar = fgetc(file);
                    if(ActualChar == 'e'){
                        Temps = IPre;
                    }else {
                        //BREAK
                    }
                }else {
                    //BREAK
                }
            }else if(ActualChar == 'I'){
                ActualChar = fgetc(file);
                if(ActualChar == 'm') {
                    ActualChar = fgetc(file);
                    if (ActualChar == 'p') {
                        Temps = IImp;
                    } else {
                        //BREAK
                    }
                }
            }else if(ActualChar == 'n'){
                ActualChar = fgetc(file);
                if(ActualChar == 'f'){
                    ActualChar = fgetc(file);
                    if(ActualChar == 'p') {
                        Inf = 1;
                    }else{
                        //BREAK
                    }
                }else {
                    //BREAK
                }
            }else {
                //BREAK
            }
        }else if(ActualChar == 'S'){
            ActualChar = fgetc(file);
            if(ActualChar == 'P'){
                ActualChar = fgetc(file);
                if(ActualChar == 'r'){
                    ActualChar = fgetc(file);
                    if(ActualChar == 'e'){
                        Temps = SPre;
                    }else {
                        //BREAK
                    }
                }else {
                    //BREAK
                }
            }else {
                //BREAK
            }
        }else {
            //BREAK
        }

        do {
            ActualChar = fgetc(file); // On lit le caractère
        } while (ActualChar != '+');
    }
    /*
    else if(strcmp(filename, "adverbs") == 0){

    }*/
    /*if (Nombre == InvPL){
        displayNode(pn,filename);
        printf("\n");
    }*/
    fclose(file);
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
    char ActualChar;
    int e = 0;

    if(file != NULL) {
        while (fgetc(file) != EOF) {

            fseek(file, -1, SEEK_CUR);
            int StartPosition = ftell(file);
            // Boucle de lecture des caractères un à un
            do {
                ActualChar = fgetc(file); // On lit le caractère
            } while (ActualChar != '\t');
            int i = 0;

            do {
                ActualChar = fgetc(file);
                name[i] = ActualChar;
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
                                //sib = 1;
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

            int ActualPosition = ftell(file);
            fclose(file);

            //printf("%d\n",e);
            //e++;
            insertFlechies(pn, filename, StartPosition, ActualPosition);

            if(strcmp(filename, "names") == 0){
                file = fopen("names.txt", "r");
            }else if(strcmp(filename, "verbs") == 0){
                file = fopen("verbs.txt", "r");
            }else if(strcmp(filename, "adverbs") == 0){
                file = fopen("adverbs.txt", "r");
            }else if(strcmp(filename, "adjectives") == 0){
                file = fopen("adjectives.txt", "r");
            }

            fseek(file, ActualPosition, SEEK_SET);


            pn = t.root;
            pn = pn->kid;
            fgets(useless, 1000, file);
        }
        return t;
    }
    else{
        printf("Impossible d'ouvrir le dico %c.txt",&filename);
        return t;
    }
}

void createFiles(){
    FILE* dico = fopen("dictionnaire.txt", "r");
    FILE* names = fopen("names.txt", "w+");
    FILE* verbs = fopen("verbs.txt", "w+");
    FILE* adverbs = fopen("adverbs.txt", "w+");
    FILE* adjectives = fopen("adjectives.txt", "w+");
    char ligne[1000];
    char ActualChar;
    char a, b;
    if (dico != NULL && names != NULL && verbs != NULL && adverbs != NULL && adjectives != NULL) {
        while(fgetc(dico) != EOF) {
            fseek(dico,-1, SEEK_CUR);
            // Boucle de lecture des caractères un à un
            int pos = ftell(dico);
            for (int i = 0; i < 2; ++i) {
                do {
                    ActualChar = fgetc(dico); // On lit le caractère
                } while (ActualChar != '\t');
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

