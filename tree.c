#include "tree.h"
void maFonction() {
    int test = rand();
    printf("%d\n", test);
}
t_baseFlechie ChooseWord(t_tree t) {
    //srand(time(NULL));
    p_node tmp;

    t_baseFlechie bf;

    int cpt = 0, random = 0, i = 0, choice, stop;
    bf.word = (char *) malloc(50 * sizeof(char));
    tmp = t.root->kid;
    int SiblingsCount = CountSiblings(t,tmp);
    if(SiblingsCount == 0){
        SiblingsCount = 1;
    }
    random = rand() % SiblingsCount;
    /*bf.random = random;
    if(bf.random == random){
        random = random+1%23456789;
        bf.random = random;
    }*/
    while (cpt < random ) {
        tmp = tmp->siblings;
        cpt++;
    }

    bf.word[i] = tmp->lettre;
    i++;
    tmp = tmp->kid;
    stop = 1;

    while (stop != 0) {  //We will run while stop is different from 0
        if (tmp->siblings == NULL) {  //If it has no sibling we go to the kid.
            if (tmp ->kid != NULL){  //a changer comparer toto != null                   // Verify if the kids are null or not, if yes, we are at the end of the word.
                bf.word[i] = tmp->lettre;
                tmp = tmp->kid;
            }
            else {
                bf.word[i] = tmp->lettre;
                stop = 0;
            }
        } else {   // if it has siblings, we will choose randomly one of them.
            choice = rand() % 2;  //Choose randomly if we want to use siblings or not

            if (choice == 0) {
                if (tmp ->kid != NULL){
                    bf.word[i] = tmp->lettre;
                    tmp = tmp->kid;
                }
                else {
                    bf.word[i] = tmp->lettre;
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
                    bf.word[i] = tmp->lettre;
                    tmp = tmp->kid;
                }
                else {
                    bf.word[i] = tmp->lettre;
                    stop = 0;
                }

            }
        }
        i++;
    }
    bf.word[i + 1] = 0;
    bf.word = (char *) realloc(bf.word, i * sizeof(char));
    bf.p = tmp;
    return bf;
}

void WriteSentence(t_tree name,t_tree adj, t_tree adv, t_tree verb){

    //Modèle 1   nom-adjectif-verbe-nom
    printf("Modèle 1 :");
    DisplayWord(ChooseWord(name));
    printf("-");
    DisplayWord(ChooseWord(adj));
    printf("-");
    DisplayWord(ChooseWord(verb));
    printf("-");
    DisplayWord(ChooseWord(name));
    printf("\n");

    //Modèle 2 nom-verbe-qui-verbe-name-adjectif
    printf("Modèle 2 :");
    DisplayWord(ChooseWord(name));
    printf("-qui-");
    DisplayWord(ChooseWord(verb));
    printf("-");
    DisplayWord(ChooseWord(verb));
    printf("-");
    DisplayWord(ChooseWord(name));
    printf("-");
    DisplayWord(ChooseWord(adj));

    printf("\n");

    //Modèle 3 ?  nom-adjectif-verbe-adverbe-nom
    printf("Modèle 3 :");
    DisplayWord(ChooseWord(name));
    printf("-");
    DisplayWord(ChooseWord(adj));
    printf("-");
    DisplayWord(ChooseWord(verb));
    printf("-");
    DisplayWord(ChooseWord(adv));
    printf("-");
    DisplayWord(ChooseWord(name));

    printf("\n");


}

p_node recherche(t_tree t,char* mot,char* filename){
    p_node s=t.root;
    s=s->kid;
    int row=0;
    if (filename=="adverbs"){
        row=1;
    }
    if (filename=="verbs"){
        row=19;
    }
    if(filename=="names"){
        row=9;
    }
    else{  // adjectives
        row=10;
    }
    return verif_kid(s,row,mot);

}

p_node verif_kid(p_node pn,int row, char* mot){
    if (pn!=NULL) {
        if (pn->toto != NULL) {
            for (int i = 0; i < row; i++) {
                if (mot == pn->toto[i]) {
                    return pn;
                }
                else{
                    return NULL;
                }
            }

        }
        else {
            p_node tmp= verif_kid(pn->kid,row,mot);
            p_node tmp1=verif_kid(pn->siblings,row,mot);
            if (tmp!=NULL){
                return tmp;
            }
            else{
                return tmp1;}
        }

    }
    else{
        return NULL;
    }

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

void DisplayWord(t_baseFlechie bf){
    int i = 0;
    while (bf.word[i] != 0){
        printf("%c", bf.word[i]);
        i++;
    }
}

t_tree createTree(char a){
    t_tree nouv;
    nouv.root = createNode(a);
    return nouv;
}

/*
void displayNode(p_node pn, char* filename){
    if(strcmp(filename, "names") == 0){

        for (int j = 0; j < 9; ++j) {
            DisplayWord(pn->toto[j]);
            }
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
}*/

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
    int vNombre = 0;
    const int IPre = 1;
    const int IImp = 2;                 //Personne + Temps + Nombre = position du tableau(Personne en ligne et Temps en colone)
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
        int k;
        do {
            ActualChar = fgetc(file); // On lit le caractère
            /*k++;
            int d = ftell(file);
            if(d > 600000){

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
    else if(strcmp(filename, "verbs") == 0) {

        file = fopen("verbs.txt", "r");
        fseek(file, ActualPosition, SEEK_SET);
        if (pn->toto == NULL) {
            // initialisation d'un tableau de 10 char*
            pn->toto = (char **) malloc(19 * sizeof(char *));
            for (int j = 0; j < 19; ++j) {
                //pn->toto[j] = (char*)malloc(100*sizeof(char));
                pn->toto[j] = (char *) calloc(100, sizeof(char));
            }

        }
        do {
            ActualChar = fgetc(file); // On lit le caractère
        } while (ActualChar != ':');

        while(ActualChar != EOF && ActualChar != '\n') {

            ActualChar = fgetc(file);
            if (ActualChar == 'I') {
                ActualChar = fgetc(file);
                if (ActualChar == 'P') {
                    ActualChar = fgetc(file);
                    if (ActualChar == 'r') {
                        ActualChar = fgetc(file);
                        if (ActualChar == 'e') {
                            Temps = IPre;
                        } else {
                            int d = ftell(file);
                            //printf("Temps IPr%d\n", d);
                        }
                    } else {
                        int d = ftell(file);
                        //printf("Temps IP%d\n", d);
                    }
                } else if (ActualChar == 'I') {
                    ActualChar = fgetc(file);
                    if (ActualChar == 'm') {
                        ActualChar = fgetc(file);
                        if (ActualChar == 'p') {
                            Temps = IImp;
                        } else {
                            int d = ftell(file);
                            //printf("Temps IIm%d\n", d);
                        }
                    } else {
                        int d = ftell(file);
                        //printf("Temps II%d\n", d);
                    }
                } else if (ActualChar == 'n') {
                    ActualChar = fgetc(file);
                    if (ActualChar == 'f') {
                        Inf = 1;
                    } else {
                        int d = ftell(file);
                        //printf("Temps In%d\n", d);
                    }
                } else {
                    int d = ftell(file);
                    //printf("Temps I%d\n", d);
                }
            } else if (ActualChar == 'S') {
                ActualChar = fgetc(file);
                if (ActualChar == 'P') {
                    ActualChar = fgetc(file);
                    if (ActualChar == 'r') {
                        ActualChar = fgetc(file);
                        if (ActualChar == 'e') {
                            Temps = SPre;
                        } else {
                            int d = ftell(file);
                            //printf("Temps SPr%d\n", d);
                        }
                    } else {
                        int d = ftell(file);
                        //printf("Temps SP%d\n", d);
                    }
                } else {
                    int d = ftell(file);
                    //printf("Temps S %d\n", d);
                }
            } else {
                int d = ftell(file);
                //printf("Temps %d\n", d);
            }

            if (Inf != 1) {
                do{
                    ActualChar = fgetc(file); // On lit le caractère

                }while (ActualChar != '+');


                ActualChar = fgetc(file);
                if (ActualChar == 'S') {
                    vNombre = vSG;
                } else if (ActualChar == 'P') {
                    vNombre = vPL;
                } else {
                    int d = ftell(file);
                    //printf("Nombre %d\n", d);
                }

                do{
                    ActualChar = fgetc(file); // On lit le caractère

                }while (ActualChar != '+');

                ActualChar = fgetc(file);
                ActualChar = fgetc(file);
                if (ActualChar == '1') {
                    Personne = P1;
                } else if (ActualChar == '2') {
                    Personne = P2;
                } else if (ActualChar == '3') {
                    Personne = P3;
                } else {
                    int d = ftell(file);
                    //printf("Personne %d\n", d);
                }
            }

            int last = ftell(file);
            fseek(file, StartPosition, SEEK_SET);

            do {
                ActualChar = fgetc(file);
                name[i] = ActualChar;
                //printf("%c",name[i]);
                i++;
            } while (name[i - 1] != '\t');
            i = 0;
            while (name[i] != '\t') {
                if (Inf == 1) {
                    pn->toto[18][i] = name[i];
                } else {
                    pn->toto[(int) (Temps + Personne + vNombre)][i] = name[i];
                }

                i++;

            }
            fseek(file, last, SEEK_SET);
            ActualChar = fgetc(file);
        }

    }
    else if(strcmp(filename, "adverbs") == 0){
        file = fopen("adverbs.txt", "r");
        fseek(file, ActualPosition, SEEK_SET);
        if (pn->toto == NULL) {
            // initialisation d'un tableau de 10 char*
            pn->toto = (char **) malloc(sizeof(char *));
            pn->toto[0] = (char *) calloc(100, sizeof(char));
        }
        fseek(file,StartPosition, SEEK_SET);

        do {
            ActualChar = fgetc(file);
            name[i] = ActualChar;
            //printf("%c",name[i]);
            i++;
        } while (name[i-1] != '\t');
        i = 0;
        while(name[i] != '\t'){
            pn->toto[0][i] = name[i];
            i++;
        }
    }

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

