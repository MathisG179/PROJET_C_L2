#include "tree.h"
const float Mas = 0.5;              //Genre + Nombre = position du tableau(Genre en ligne et Nombre en colone)
const float Fem = 3.5;              //La 10e case corespond aux Card
const float InvGEN = 6.5;
const float SG = 0.5;
const float PL = 1.5;
const float InvPL = 2.5;

const int IPre = 1;
const int IImp = 2;                 //Personne + Temps + Nombre = position du tableau(Personne en ligne et Temps en colone)
const int SPre = 3;
const int vSG = 0;
const int vPL = 9;
const int P1 = 0;
const int P2 = 3;
const int P3 = 6;

t_baseFlechie ChooseWordBase(t_tree t) {
    p_node tmp;

    t_baseFlechie bf;

    int cpt = 0, random = 0, i = 0, choice, stop;
    bf.word = (char *) malloc(50 * sizeof(char));
    tmp = t.root->kid;
    int SiblingsCount = CountSiblings(t,tmp);
    if(SiblingsCount != 0){
        random = rand() % (SiblingsCount+1);
    }else{
        random = 0;
    }

    while (cpt < random ) {
        tmp = tmp->siblings;
        cpt++;
    }

    bf.word[i] = tmp->lettre;
    i++;
    if(tmp->kid != NULL){
        tmp = tmp->kid;
    }
    stop = 1;

    while (stop != 0 && tmp != NULL) {  //We will run while stop is different from 0
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

void WriteSentenceBase(t_tree name,t_tree adj, t_tree adv, t_tree verb){

    //Modèle 1   nom-adjectif-verbe-nom
    printf("Modèle 1 :");
    DisplayWord(ChooseWordBase(name));
    printf("-");
    DisplayWord(ChooseWordBase(adj));
    printf("-");
    DisplayWord(ChooseWordBase(verb));
    printf("-");
    DisplayWord(ChooseWordBase(name));
    printf("\n");

    //Modèle 2 nom-verbe-qui-verbe-name-adjectif
    printf("Modèle 2 :");
    DisplayWord(ChooseWordBase(name));
    printf("-qui-");
    DisplayWord(ChooseWordBase(verb));
    printf("-");
    DisplayWord(ChooseWordBase(verb));
    printf("-");
    DisplayWord(ChooseWordBase(name));
    printf("-");
    DisplayWord(ChooseWordBase(adj));

    printf("\n");

    //Modèle 3 ?  nom-adjectif-verbe-adverbe-nom
    printf("Modèle 3 :");
    DisplayWord(ChooseWordBase(name));
    printf("-");
    DisplayWord(ChooseWordBase(adj));
    printf("-");
    DisplayWord(ChooseWordBase(verb));
    printf("-");
    DisplayWord(ChooseWordBase(adv));
    printf("-");
    DisplayWord(ChooseWordBase(name));

    printf("\n");


}

t_accords ChooseWordFlechie(t_baseFlechie bf){
    t_accords a;
    p_node pn = bf.p;
    int i;
    do {
        int random = rand() % 9;
        i = 0;
        while(i<random){
            i++;
        }
    }while(pn->toto[i][0] == 0);

    a.word = pn->toto[i];

    if(i == 0){
        a.Nombre = SG;
        a.Genre = Mas;
    }else if(i == 1){
        a.Nombre = PL;
        a.Genre = Mas;
    }else if(i == 2){
        a.Nombre = InvPL;
        a.Genre = Mas;
    }else if(i == 3){
        a.Nombre = SG;
        a.Genre = Fem;
    }else if(i == 4){
        a.Nombre = PL;
        a.Genre = Fem;
    }else if(i == 5){
        a.Nombre = InvPL;
        a.Genre = Fem;
    }else if(i == 6){
        a.Nombre = SG;
        a.Genre = InvGEN;
    }else if(i == 7){
        a.Nombre = PL;
        a.Genre = InvGEN;
    }else if(i == 8){
        a.Nombre = InvPL;
        a.Genre = InvGEN;
    }else{
        printf("hmmm");
        a.Nombre = -1;
        a.Genre = -1;
    }
    return a;

}

void WriteSentenceFlechie(t_tree name,t_tree adj, t_tree adv, t_tree verb){

    int random;
    int i, k = 0;
    //Modèle 1   nom-adjectif-verbe-nom
    printf("Modèle 1 : ");
    t_accords name11 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name11;
    bf_name11.word = name11.word;

    if(name11.Nombre == PL){
        random = rand()%9;
        if(random == 0){
            printf("les ");
        }else if(random == 2){
            printf("des ");
        }else if(random == 3){
            printf("mes ");
        }else if(random == 4){
            printf("tes ");
        }else if(random == 5){
            printf("ses ");
        }else if(random == 6){
            printf("nos ");
        }else if(random == 7){
            printf("vos ");
        }else if(random == 8){
            printf("leurs ");
        }
    }
    else if(name11.Genre == InvGEN){
        random = rand()%2;
        if(random == 0){
            random = rand()%9;
            if(random == 0){
                printf("le ");
            }else if(random == 2){
                printf("un ");
            }else if(random == 3){
                printf("mon ");
            }else if(random == 4){
                printf("ton ");
            }else if(random == 5){
                printf("son ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }else{
            random = rand()%9;
            if(random == 0){
                printf("la ");
            }else if(random == 2){
                printf("une ");
            }else if(random == 3){
                printf("ma ");
            }else if(random == 4){
                printf("ta ");
            }else if(random == 5){
                printf("sa ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }
    }
    else if(name11.Genre == Mas){
        random = rand()%9;
        if(random == 0){
            printf("le ");
        }else if(random == 2){
            printf("un ");
        }else if(random == 3){
            printf("mon ");
        }else if(random == 4){
            printf("ton ");
        }else if(random == 5){
            printf("son ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name11.Genre == Fem){
        random = rand()%9;
        if(random == 0){
            printf("la ");
        }else if(random == 2){
            printf("une ");
        }else if(random == 3){
            printf("ma ");
        }else if(random == 4){
            printf("ta ");
        }else if(random == 5){
            printf("sa ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else{
        printf("%.1f ",name11.Genre);
    }
    DisplayWord(bf_name11);
    //printf("%.1f;%.1f",name11.Genre,name11.Nombre);
    printf(" | ");

    t_baseFlechie bf_adj11 = ChooseWordBase(adj);
    p_node pn_adj11 = bf_adj11.p;
    do {
        t_baseFlechie bf_adj11 = ChooseWordBase(adj);
        p_node pn_adj11 = bf_adj11.p;
    }while(pn_adj11->toto[(int)(name11.Genre + name11.Nombre - 1)] == 0);
    DisplayWord(bf_adj11);
    printf(" | ");



    t_baseFlechie bf_verb11 = ChooseWordBase(verb);
    p_node pn_verb11 = bf_verb11.p;
    do {
        if (name11.Nombre == SG) {
            random = 7 + rand() % 3;          //7 ou 8 ou 9
        } else if (name11.Nombre == PL) {
            random = 16 + rand() % 3;          //16 ou 17 ou 18
        } else if (name11.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 7 + rand() % 3;          //7 ou 8 ou 9
            } else {
                random = 16 + rand() % 3;          //16 ou 17 ou 18
            }
        }
        i = 0;
        while(i<random){
            i++;
        }
        k++;
        if(k>15){
            k = 0;
            bf_verb11 = ChooseWordBase(verb);
            pn_verb11 = bf_verb11.p;
        }
    }while(pn_verb11->toto[i][0] == 0);

    bf_verb11.word = pn_verb11->toto[i];
    DisplayWord(bf_verb11);
    printf(" | ");

    t_accords name21 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name21;
    bf_name21.word = name21.word;

    if(name21.Nombre == PL){
        random = rand()%9;
        if(random == 0){
            printf("les ");
        }else if(random == 2){
            printf("des ");
        }else if(random == 3){
            printf("mes ");
        }else if(random == 4){
            printf("tes ");
        }else if(random == 5){
            printf("ses ");
        }else if(random == 6){
            printf("nos ");
        }else if(random == 7){
            printf("vos ");
        }else if(random == 8){
            printf("leurs ");
        }
    }
    else if(name21.Genre == Mas){
        random = rand()%9;
        if(random == 0){
            printf("le ");
        }else if(random == 2){
            printf("un ");
        }else if(random == 3){
            printf("mon ");
        }else if(random == 4){
            printf("ton ");
        }else if(random == 5){
            printf("son ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name21.Genre == Fem){
        random = rand()%9;
        if(random == 0){
            printf("la ");
        }else if(random == 2){
            printf("une ");
        }else if(random == 3){
            printf("ma ");
        }else if(random == 4){
            printf("ta ");
        }else if(random == 5){
            printf("sa ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name21.Genre == InvGEN){
        random = rand()%2;
        if(random == 0){
            random = rand()%9;
            if(random == 0){
                printf("le ");
            }else if(random == 2){
                printf("un ");
            }else if(random == 3){
                printf("mon ");
            }else if(random == 4){
                printf("ton ");
            }else if(random == 5){
                printf("son ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }else{
            random = rand()%9;
            if(random == 0){
                printf("la ");
            }else if(random == 2){
                printf("une ");
            }else if(random == 3){
                printf("ma ");
            }else if(random == 4){
                printf("ta ");
            }else if(random == 5){
                printf("sa ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }
    }
    else{
        printf("%.1f ",name21.Genre);
    }
    DisplayWord(bf_name21);
    //printf("%.1f;%.1f",name21.Genre,name21.Nombre);



    //Modèle 2   nom-adjectif-verbe-nom
    printf("\nModèle 2 : ");
    t_accords name12 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name12;
    bf_name12.word = name12.word;

    if(name12.Nombre == PL){
        random = rand()%9;
        if(random == 0){
            printf("les ");
        }else if(random == 2){
            printf("des ");
        }else if(random == 3){
            printf("mes ");
        }else if(random == 4){
            printf("tes ");
        }else if(random == 5){
            printf("ses ");
        }else if(random == 6){
            printf("nos ");
        }else if(random == 7){
            printf("vos ");
        }else if(random == 8){
            printf("leurs ");
        }
    }
    else if(name12.Genre == Mas){
        random = rand()%9;
        if(random == 0){
            printf("le ");
        }else if(random == 2){
            printf("un ");
        }else if(random == 3){
            printf("mon ");
        }else if(random == 4){
            printf("ton ");
        }else if(random == 5){
            printf("son ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name12.Genre == Fem){
        random = rand()%9;
        if(random == 0){
            printf("la ");
        }else if(random == 2){
            printf("une ");
        }else if(random == 3){
            printf("ma ");
        }else if(random == 4){
            printf("ta ");
        }else if(random == 5){
            printf("sa ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name12.Genre == InvGEN){
        random = rand()%2;
        if(random == 0){
            random = rand()%9;
            if(random == 0){
                printf("le ");
            }else if(random == 2){
                printf("un ");
            }else if(random == 3){
                printf("mon ");
            }else if(random == 4){
                printf("ton ");
            }else if(random == 5){
                printf("son ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }else{
            random = rand()%9;
            if(random == 0){
                printf("la ");
            }else if(random == 2){
                printf("une ");
            }else if(random == 3){
                printf("ma ");
            }else if(random == 4){
                printf("ta ");
            }else if(random == 5){
                printf("sa ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }
    }
    else{
        printf("%.1f ",name12.Genre);
    }
    DisplayWord(bf_name12);
    //printf("%.1f;%.1f",name12.Genre,name12.Nombre);
    printf(" | ");

    printf("qui");
    printf(" | ");

    t_baseFlechie bf_verb12 = ChooseWordBase(verb);
    p_node pn_verb12 = bf_verb12.p;
    do {
        if (name12.Nombre == SG) {
            random = 7 + rand() % 3;          //7 ou 8 ou 9
        } else if (name12.Nombre == PL) {
            random = 16 + rand() % 3;          //16 ou 17 ou 18
        } else if (name12.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 7 + rand() % 3;          //7 ou 8 ou 9
            } else {
                random = 16 + rand() % 3;          //16 ou 17 ou 18
            }
        }
        i = 0;
        while(i<random){
            i++;
        }
        k++;
        if(k>15){
            k = 0;
            bf_verb12 = ChooseWordBase(verb);
            pn_verb12 = bf_verb12.p;
        }
    }while(pn_verb12->toto[i][0] == 0);

    bf_verb12.word = pn_verb12->toto[i];
    DisplayWord(bf_verb12);
    printf(" | ");

    t_baseFlechie bf_verb22 = ChooseWordBase(verb);
    p_node pn_verb22 = bf_verb22.p;
    do {
        if (name12.Nombre == SG) {
            random = 7 + rand() % 3;          //7 ou 8 ou 9
        } else if (name12.Nombre == PL) {
            random = 16 + rand() % 3;          //16 ou 17 ou 18
        } else if (name12.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 7 + rand() % 3;          //7 ou 8 ou 9
            } else {
                random = 16 + rand() % 3;          //16 ou 17 ou 18
            }
        }
        i = 0;
        while(i<random){
            i++;
        }
        k++;
        if(k>15){
            k = 0;
            bf_verb22 = ChooseWordBase(verb);
            pn_verb22 = bf_verb11.p;
        }
    }while(pn_verb22->toto[i][0] == 0);

    bf_verb22.word = pn_verb22->toto[i];
    DisplayWord(bf_verb22);
    printf(" | ");

    t_accords name22 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name22;
    bf_name22.word = name22.word;

    if(name22.Nombre == PL){
        random = rand()%9;
        if(random == 0){
            printf("les ");
        }else if(random == 2){
            printf("des ");
        }else if(random == 3){
            printf("mes ");
        }else if(random == 4){
            printf("tes ");
        }else if(random == 5){
            printf("ses ");
        }else if(random == 6){
            printf("nos ");
        }else if(random == 7){
            printf("vos ");
        }else if(random == 8){
            printf("leurs ");
        }
    }
    else if(name22.Genre == Mas){
        random = rand()%9;
        if(random == 0){
            printf("le ");
        }else if(random == 2){
            printf("un ");
        }else if(random == 3){
            printf("mon ");
        }else if(random == 4){
            printf("ton ");
        }else if(random == 5){
            printf("son ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name22.Genre == Fem){
        random = rand()%9;
        if(random == 0){
            printf("la ");
        }else if(random == 2){
            printf("une ");
        }else if(random == 3){
            printf("ma ");
        }else if(random == 4){
            printf("ta ");
        }else if(random == 5){
            printf("sa ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name22.Genre == InvGEN){
        random = rand()%2;
        if(random == 0){
            random = rand()%9;
            if(random == 0){
                printf("le ");
            }else if(random == 2){
                printf("un ");
            }else if(random == 3){
                printf("mon ");
            }else if(random == 4){
                printf("ton ");
            }else if(random == 5){
                printf("son ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }else{
            random = rand()%9;
            if(random == 0){
                printf("la ");
            }else if(random == 2){
                printf("une ");
            }else if(random == 3){
                printf("ma ");
            }else if(random == 4){
                printf("ta ");
            }else if(random == 5){
                printf("sa ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }
    }
    else{
        printf("%.1f ",name22.Genre);
    }

    DisplayWord(bf_name22);
    //printf("%.1f;%.1f",name22.Genre,name22.Nombre);
    printf(" | ");

    t_baseFlechie bf_adj12 = ChooseWordBase(adj);
    p_node pn_adj12 = bf_adj12.p;
    do {
        t_baseFlechie bf_adj12 = ChooseWordBase(adj);
        p_node pn_adj12 = bf_adj12.p;
    }while(pn_adj12->toto[(int)(name22.Genre + name22.Nombre - 1)] == 0);
    DisplayWord(bf_adj12);



    //Modèle 3   nom-adjectif-verbe-nom
    printf("\nModèle 3 : ");
    t_accords name13 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name13;
    bf_name13.word = name13.word;

    if(name13.Nombre == PL){
        random = rand()%9;
        if(random == 0){
            printf("les ");
        }else if(random == 2){
            printf("des ");
        }else if(random == 3){
            printf("mes ");
        }else if(random == 4){
            printf("tes ");
        }else if(random == 5){
            printf("ses ");
        }else if(random == 6){
            printf("nos ");
        }else if(random == 7){
            printf("vos ");
        }else if(random == 8){
            printf("leurs ");
        }
    }
    else if(name13.Genre == InvGEN){
        random = rand()%2;
        if(random == 0){
            random = rand()%9;
            if(random == 0){
                printf("le ");
            }else if(random == 2){
                printf("un ");
            }else if(random == 3){
                printf("mon ");
            }else if(random == 4){
                printf("ton ");
            }else if(random == 5){
                printf("son ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }else{
            random = rand()%9;
            if(random == 0){
                printf("la ");
            }else if(random == 2){
                printf("une ");
            }else if(random == 3){
                printf("ma ");
            }else if(random == 4){
                printf("ta ");
            }else if(random == 5){
                printf("sa ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }
    }
    else if(name13.Genre == Mas){
        random = rand()%9;
        if(random == 0){
            printf("le ");
        }else if(random == 2){
            printf("un ");
        }else if(random == 3){
            printf("mon ");
        }else if(random == 4){
            printf("ton ");
        }else if(random == 5){
            printf("son ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name13.Genre == Fem){
        random = rand()%9;
        if(random == 0){
            printf("la ");
        }else if(random == 2){
            printf("une ");
        }else if(random == 3){
            printf("ma ");
        }else if(random == 4){
            printf("ta ");
        }else if(random == 5){
            printf("sa ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else{
        printf("%.1f ",name13.Genre);
    }

    DisplayWord(bf_name13);
    //printf("%.1f;%.1f",name13.Genre,name13.Nombre);
    printf(" | ");

    t_baseFlechie bf_adj13 = ChooseWordBase(adj);
    p_node pn_adj13 = bf_adj13.p;
    do {
        t_baseFlechie bf_adj13 = ChooseWordBase(adj);
        p_node pn_adj13 = bf_adj13.p;
    }while(pn_adj13->toto[(int)(name13.Genre + name13.Nombre - 1)] == 0);
    DisplayWord(bf_adj13);
    printf(" | ");



    t_baseFlechie bf_verb13 = ChooseWordBase(verb);
    p_node pn_verb13 = bf_verb13.p;
    do {
        if (name13.Nombre == SG) {
            random = 7 + rand() % 3;          //7 ou 8 ou 9
        } else if (name13.Nombre == PL) {
            random = 16 + rand() % 3;          //16 ou 17 ou 18
        } else if (name13.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 7 + rand() % 3;          //7 ou 8 ou 9
            } else {
                random = 16 + rand() % 3;          //16 ou 17 ou 18
            }
        }
        i = 0;
        while(i<random){
            i++;
        }
        k++;
        if(k>15){
            k = 0;
            bf_verb13 = ChooseWordBase(verb);
            pn_verb13 = bf_verb13.p;
        }
    }while(pn_verb13->toto[i][0] == 0);

    bf_verb13.word = pn_verb13->toto[i];
    DisplayWord(bf_verb13);
    printf(" | ");

    DisplayWord(ChooseWordBase(adv));
    printf(" | ");


    t_accords name23 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name23;
    bf_name23.word = name23.word;

    if(name23.Nombre == PL){
        random = rand()%9;
        if(random == 0){
            printf("les ");
        }else if(random == 2){
            printf("des ");
        }else if(random == 3){
            printf("mes ");
        }else if(random == 4){
            printf("tes ");
        }else if(random == 5){
            printf("ses ");
        }else if(random == 6){
            printf("nos ");
        }else if(random == 7){
            printf("vos ");
        }else if(random == 8){
            printf("leurs ");
        }
    }
    else if(name23.Genre == Mas){
        random = rand()%9;
        if(random == 0){
            printf("le ");
        }else if(random == 2){
            printf("un ");
        }else if(random == 3){
            printf("mon ");
        }else if(random == 4){
            printf("ton ");
        }else if(random == 5){
            printf("son ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name23.Genre == Fem){
        random = rand()%9;
        if(random == 0){
            printf("la ");
        }else if(random == 2){
            printf("une ");
        }else if(random == 3){
            printf("ma ");
        }else if(random == 4){
            printf("ta ");
        }else if(random == 5){
            printf("sa ");
        }else if(random == 6){
            printf("notre ");
        }else if(random == 7){
            printf("votre ");
        }else if(random == 8){
            printf("leur ");
        }
    }
    else if(name23.Genre == InvGEN){
        random = rand()%2;
        if(random == 0){
            random = rand()%9;
            if(random == 0){
                printf("le ");
            }else if(random == 2){
                printf("un ");
            }else if(random == 3){
                printf("mon ");
            }else if(random == 4){
                printf("ton ");
            }else if(random == 5){
                printf("son ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }else{
            random = rand()%9;
            if(random == 0){
                printf("la ");
            }else if(random == 2){
                printf("une ");
            }else if(random == 3){
                printf("ma ");
            }else if(random == 4){
                printf("ta ");
            }else if(random == 5){
                printf("sa ");
            }else if(random == 6){
                printf("notre ");
            }else if(random == 7){
                printf("votre ");
            }else if(random == 8){
                printf("leur ");
            }
        }
    }
    else{
        printf("%.1f ",name23.Genre);
    }
    DisplayWord(bf_name23);
    //printf("%.1f;%.1f",name23.Genre,name23.Nombre);
    printf("\n");
}

p_node recherche(t_tree t,char* mot,char* filename){
    p_node s=t.root;
    s=s->kid;
    int row=0;
    if (strcmp(filename, "adverbs") == 0){
        row=1;
    }
    if (strcmp(filename, "verbs") == 0){
        row=19;
    }
    if(strcmp(filename, "names") == 0){
        row=9;
    }
    if(strcmp(filename, "adjectives") == 0){  // adjectives
        row=10;
    }
    return verif_kid(s,row,mot);

}

p_node verif_kid(p_node pn,int row, char* mot){
    p_node tmp;
    int k;
    if (pn!=NULL) {
        if (pn->toto != NULL) {
            for (int i = 0; i < row; i++) {
                int j = 0;
                for (j = 0; j < strlen(mot); ++j) {
                    if(mot[j] == pn->toto[i][j]) {
                        tmp = pn;
                    }else{
                        break;
                    }
                }
                if (j == strlen(mot)){
                    k = 1;
                }
            }
            if(k == 1){
                return tmp;
            }
        }

        p_node tmp= verif_kid(pn->kid,row,mot);
        p_node tmp1=verif_kid(pn->siblings,row,mot);
        if (tmp!=NULL){
            return tmp;
        }
        else{
            return tmp1;
        }

        return tmp;

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
    if(bf.word != NULL) {
        while (bf.word[i] != 0) {
            printf("%c", bf.word[i]);
            i++;
        }
    }else{
        printf("ATTENTION tentative de print un NULL");
    }
}

t_tree createTree(char a){
    t_tree nouv;
    nouv.root = createNode(a);
    return nouv;
}

void insertFlechies(p_node pn, char* filename, int StartPosition, int ActualPosition){
    FILE* file;
    int Card = 0;
    float Genre = 0;                    //0.5 = Mas | 3.5 = Fem | 6.5 = InvGEN
    float Nombre = 0;                   //0.5 = SG | 1.5 = PL | 2.5 = InvPL

    int Inf = 0;
    int Personne = -10000;
    int Temps = -10000;
    int vNombre = -10000;

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

            i = 0;
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
                    if(Temps + Personne + vNombre >= 0){
                        pn->toto[(int) (Temps + Personne + vNombre)][i] = name[i];
                    }
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

