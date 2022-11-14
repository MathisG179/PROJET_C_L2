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


void Affichage(t_tree nom, t_tree adv, t_tree adj, t_tree verb) {
    char* motrecherche;
    char* nature;
    p_node tmp;
    char *nature2;
    char *genre;
    int i = 0;
    char *nombre;
    int cpt=0;
    int j=0;
    char ** tab_type = (char**)malloc(20 * sizeof(char*));
    int *idx = (int*)malloc(20*sizeof(int));
    char **type = (char**)malloc(50 * sizeof(char*));
    printf("Quel est le mot recherché au masculin singulier");
    scanf("%c", &motrecherche);
    while(Verif_character(motrecherche)==0){
        printf("Wrong input");
        printf("Quel est le mot recherché au masculin singulier ?");
        scanf("%c", &motrecherche);
    }
    printf("Quel est la nature de votre mot ? adjectives/adverbs/verbs/names");
    scanf("%c", &nature);
    while(Verif_character(&nature)==0){
        printf("Wrong input");
        printf("Quel est la nature de votre mot ? adjectives/adverbs/verbs/names");
        scanf("%c", &nature);
    }
    while(Verif_Genre(&nature)!=0){
        printf("Wrong input");
        printf("Quel est la nature de votre mot ? adjectives/adverbs/verbs/names");
        scanf("%c", &nature);
    }
    if (nature == "names") {
        nature2 = "NOM";
        tmp = recherche(nom, motrecherche, "names");
    }
    if (nature == "verbs") {
        nature2 = "VERB";
        tmp = recherche(verb, motrecherche, "verbs");
    }
    if (nature == "adjectives") {
        nature2 = "ADJ";
        tmp = recherche(adj, motrecherche, "adjectives");
    }
    if (nature == "adverbs") {
        nature2 = "ADV";
        tmp = recherche(adv, motrecherche, "adverbs");
    }
    if (tmp == NULL) {
        printf("Le mot n'est dans le dico");
    } else {
        if (nature == "adverbs") {
            printf("%s  %s  ADV\nLa forme fléchie des adverbes est leur forme de base.", motrecherche, tmp->toto[0]);
        }
        if (nature == "adjectives") {

            while (tmp->toto[i] != motrecherche) {  //Trouver la forme fléchie du mot correspondant
                i++;
            }

            // Trouver le genre et le nombre de l'adjectif
            if (i == 0) {
                genre = "Mas";
                nombre = "SG";
            }
            if (i == 1) {
                genre = "Mas";
                nombre = "PL";
            }
            if (i == 2) {
                genre = "Mas";
                nombre = "InvPL";
            }
            if (i == 3) {
                genre = "Fem";
                nombre = "SG";
            }
            if (i == 4) {
                genre = "Fem";
                nombre = "PL";
            }
            if (i == 5) {
                genre = "Fem";
                nombre = "InvPl";
            }
            if (i == 6) {
                genre = "InvGen";
                nombre = "SG";
            }
            if (i == 7) {
                genre = "InvGen";
                nombre = "PL";
            }
            if (i == 8) {
                genre = "InvGen";
                nombre = "InvPl";
            }
            if (i == 9) {
                genre = "Card"; // pour les nombres
                nombre=" ";
            }
            printf("%s   %s   %s : %s+%s\n%s est un adjectif, accordé au %s  %s , et dont la forme de base est %s", motrecherche,
                   tmp->toto[0], nature2, genre, nombre, motrecherche, genre, nombre, tmp->toto[0]);
        }
        if (nature == "names") {

            while (tmp->toto[i] != motrecherche) {  //Trouver la forme fléchie du mot correspondant
                i++;
            }

            // Trouver le genre et le nombre du mot
            if (i == 0) {
                genre = "Mas";
                nombre = "SG";
            }
            if (i == 1) {
                genre = "Mas";
                nombre = "PL";
            }
            if (i == 2) {
                genre = "Mas";
                nombre = "InvPL";
            }
            if (i == 3) {
                genre = "Fem";
                nombre = "SG";
            }
            if (i == 4) {
                genre = "Fem";
                nombre = "PL";
            }
            if (i == 5) {
                genre = "Fem";
                nombre = "InvPl";
            }
            if (i == 6) {
                genre = "InvGen";
                nombre = "SG";
            }
            if (i == 7) {
                genre = "InvGen";
                nombre = "PL";
            }
            if (i == 8) {
                genre = "InvGen";
                nombre = "InvPl";
            }
            printf("%s   %s   %s : %s+%s\n%s est un Nom %s qui est %s de la forme de base %s", motrecherche,
                   tmp->toto[0], nature2, genre, nombre, motrecherche, genre, nombre, tmp->toto[0]);
        }
        if (nature == "verbs") {
            for (int i=0;i<=18;i++){  // On cherche l'index de notre mot
                if(tmp->toto[i]==motrecherche){
                    idx[j]=i;
                    j++;
                }
            }
            idx[j+1]=-1;  // Pour marquer la fin du tableau
            while(idx[cpt]!=-1){  // On cherche toutes les formes du mot qui correspond au mot recherché
                if(idx[cpt] == 0) {
                    tab_type[cpt] = "IPre + SG + P1";
                    type[cpt] = "Indicatif Présent, singulier, première personne";
                    cpt++;
                }
                if(idx[cpt] == 1) {
                    tab_type[cpt] = "IImp + SG + P1";
                    type[cpt] = "Indicatif Imparfait, singulier, première personne";
                    cpt++;
                }if(idx[cpt] == 2) {
                    tab_type[cpt] = "SPre + SG + P1";
                    type[cpt] = "Indicatif Subjonctif, singulier, première personne";
                    cpt++;
                }if(idx[cpt] == 3) {
                    tab_type[cpt] = "IPre + SG + P2";
                    type[cpt] = "Indicatif Présent, singulier, deuxième personne";
                    cpt++;
                }if(idx[cpt] == 4) {
                    tab_type[cpt] = "IImp + SG + P2";
                    type[cpt] = "Indicatif Imparfait, singulier, deuxième personne";
                    cpt++;
                }if(idx[cpt] == 5) {
                    tab_type[cpt] = "SPre + SG + P2";
                    type[cpt] = "Indicatif Subjonctif, singulier, deuxième personne";
                    cpt++;
                }if(idx[cpt] == 6) {
                    tab_type[cpt] = "IPre + SG + P3";
                    type[cpt] = "Indicatif Présent, singulier, troisième personne";
                    cpt++;
                }if(idx[cpt] == 7) {
                    tab_type[cpt] = "IImp + SG + P3";
                    type[cpt] = "Indicatif Imparfait, singulier, troisième personne";
                    cpt++;
                }if(idx[cpt] == 8) {
                    tab_type[cpt] = "SPre + SG + P3";
                    type[cpt] = "Indicatif Subjonctif, singulier, troisième personne";
                    cpt++;
                }if(idx[cpt] == 9) {
                    tab_type[cpt] = "IPre + PL + P1";
                    type[cpt] = "Indicatif Présent, pluriel, première personne";
                    cpt++;
                }if(idx[cpt] == 10) {
                    tab_type[cpt] = "IImp + PL + P1";
                    type[cpt] = "Indicatif Imparfait, pluriel, première personne";
                    cpt++;
                }if(idx[cpt] == 11) {
                    tab_type[cpt] = "SPre + PL + P1";
                    type[cpt] = "Indicatif Subjonctif, pluriel, première personne";
                    cpt++;
                }if(idx[cpt] == 12) {
                    tab_type[cpt] = "IPre + PL + P2";
                    type[cpt] = "Indicatif Présent, pluriel, deuxième personne";
                    cpt++;
                }if(idx[cpt] == 13) {
                    tab_type[cpt] = "IImp + PL + P2";
                    type[cpt] = "Indicatif Imparfait, pluriel, deuxième personne";
                    cpt++;
                }if(idx[cpt] == 14) {
                    tab_type[cpt] = "SPre + Pl + P2";
                    type[cpt] = "Indicatif Subjonctif, pluriel, deuxième personne";
                    cpt++;
                }if(idx[cpt] == 15) {
                    tab_type[cpt] = "IPre + PL + P3";
                    type[cpt] = "Indicatif Présent, pluriel, troisième personne";
                    cpt++;
                }if(idx[cpt] == 16) {
                    tab_type[cpt] = "IImp + PL + P3";
                    type[cpt] = "Indicatif Imparfait, pluriel, troisième personne";
                    cpt++;
                }if(idx[cpt] == 17) {
                    tab_type[cpt] = "SPre + PL + P3";
                    type[cpt] = "Indicatif subjonctif, pluriel, troisième personne";
                    cpt++;
                }if(idx[cpt] == 18) {
                    tab_type[cpt] = "Inf";
                    type[cpt] = "Infinitif";
                    cpt++;
                }
            }
            tab_type[cpt+1]=" ";
            type[cpt+1]=" ";
            printf("%s   %s  Ver : ",motrecherche,tmp->toto[18]);
            i=0;
            while(tab_type[i]!=" "){
                printf("%s",tab_type[i]);
                if (tab_type[i+1]!=" "){
                    printf("+");
                }
            }
            printf("\n%s  est un verbe conjugué, dont sa forme de base est %s , la forme conjuguée correspond à\n",motrecherche,tmp->toto[18]);
            while(tab_type[cpt]!=" "){
                printf("%s : %s\n",tab_type[cpt],type[cpt]);
            }

        }
    }

    free(tab_type);
    free(idx);
    free(type);
}

int Verif_character(char *input){
    int i=0;
    int stop = 0;
    while(stop != 1 || input[i]=='\0' || input[i]!='\n'){ // last character of a string
        if(input[i]<'a' || input[i]>'z'){ // verify if there is a number in the word
            stop = 0;
        }
        else{
            stop = 1;
        }
        i++;
    }
    return stop;
}

int Verif_Genre(char* input){
    if (strcmp(input,"adjectives\n") != 0 && strcmp(input,"adverbs\n") != 0 && strcmp(input,"verbs\n") != 0 && strcmp(input,"names\n") != 0){
        return -1;
    }
    else{
        return 0;
    }
}

/** Fonction permetant de choisir une forme de base aléatoire pour un mot. Fonction appelée dans WriteSenteceFlechie(), ChooseWordFlechie()*/
t_baseFlechie ChooseWordBase(t_tree t) {
    p_node tmp;

    t_baseFlechie bf;

    int cpt = 0, random = 0, i = 0, choice, stop;
    bf.word = (char *)calloc(50,sizeof(char));
    tmp = t.root->kid;
    int SiblingsCount = CountSiblings(tmp);
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
            if (tmp->toto == NULL){   // Verify if the kids are null or not, if yes, we are at the end of the word.
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
                if (tmp->toto == NULL){
                    bf.word[i] = tmp->lettre;
                    tmp = tmp->kid;
                }
                else {
                    bf.word[i] = tmp->lettre;
                    stop = 0;
                }

            } else {
                random = rand()% CountSiblings(tmp); //count the number of siblings
                cpt = 0;
                while (cpt <= random) {
                    tmp = tmp->siblings;
                    cpt++;
                }
                if( tmp->toto == NULL){
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

    bf.word = (char *) realloc(bf.word, i * sizeof(char));
    bf.p = tmp;
    return bf;
    free(bf.word);
}

/** Fonction permetant d'écrire des phrases avec les formes de base des mots (quatres modèles différents)*/
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

/** Fonction permetant de choisir une forme fléchie aléatoire pour un nom. Fonction appelée dans WriteSenteceFlechie()*/
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

/** Fonction permetant d'écrire des phrases gramaticalement correctes (quatres modèles différents)*/
void WriteSentenceFlechie(t_tree name, t_tree adj, t_tree adv, t_tree verb) {

    int random;
    int i, k = 0, ajout = 0, no = 0;
    char add[10];
    printf("Il se peut que certaines formes fléchies soient manquantes, souhaitez vous les ajouter au dictionnaire ?\n");

    fgets(add,9, stdin);

    if(add[0] == 'O' || add[0] == 'o' || add[0] == 'Y' || add[0] == 'y' || add[0] == '1'){
        ajout = 1;
    }




    //Modèle 1   nom-adjectif-verbe-nom




    t_accords name11 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name11;
    bf_name11.word = name11.word;
    char* det11;

    if (name11.Nombre == PL) {
        random = rand() % 8;
        if (random == 0) {
            det11 = "Les ";
        } else if (random == 1) {
            det11 = "Des ";
        } else if (random == 2) {
            det11 = "Mes ";
        } else if (random == 3) {
            det11 = "Tes ";
        } else if (random == 4) {
            det11 = "Ses ";
        } else if (random == 5) {
            det11 = "Nos ";
        } else if (random == 6) {
            det11 = "Vos ";
        } else if (random == 7) {
            det11 = "Leurs ";
        } else {
            det11 = "DETERMINANT PL";
        }
    }
    else if (name11.Genre == InvGEN) {
        random = rand() % 2;
        if (random == 0) {
            random = rand() % 8;
            if (random == 0) {
                det11 = "Le ";
            } else if (random == 1) {
                det11 = "Un ";
            } else if (random == 2) {
                det11 = "Mon ";
            } else if (random == 3) {
                det11 = "Ton ";
            } else if (random == 4) {
                det11 = "Son ";
            } else if (random == 5) {
                det11 = "Notre ";
            } else if (random == 6) {
                det11 = "Votre ";
            } else if (random == 7) {
                det11 = "Leur ";
            } else {
                det11 = "DETERMINANT InvGen -> Mas";
            }
        } else {
            random = rand() % 8;
            if (random == 0) {
                det11 = "La ";
            } else if (random == 1) {
                det11 = "Une ";
            } else if (random == 2) {
                det11 = "Ma ";
            } else if (random == 3) {
                det11 = "Ta ";
            } else if (random == 4) {
                det11 = "Sa ";
            } else if (random == 5) {
                det11 = "Notre ";
            } else if (random == 6) {
                det11 = "Votre ";
            } else if (random == 7) {
                det11 = "Leur ";
            } else {
                det11 = "DETERMINANT InvGen -> Fem";
            }
        }
    }
    else if (name11.Genre == Mas) {
        random = rand() % 8;
        if (random == 0) {
            det11 = ("le ");
        } else if (random == 1) {
            det11 = ("Un ");
        } else if (random == 2) {
            det11 = ("Mon ");
        } else if (random == 3) {
            det11 = ("Ton ");
        } else if (random == 4) {
            det11 = ("Son ");
        } else if (random == 5) {
            det11 = ("Notre ");
        } else if (random == 6) {
            det11 = ("Votre ");
        } else if (random == 7) {
            det11 = ("Leur ");
        } else {
            det11 = ("DETERMINANT InvGen -> Mas");
        }
    }
    else if (name11.Genre == Fem) {
        random = rand() % 8;
        if (random == 0) {
            det11 = ("La ");
        } else if (random == 1) {
            det11 = ("Une ");
        } else if (random == 2) {
            det11 = ("Ma ");
        } else if (random == 3) {
            det11 = ("Ta ");
        } else if (random == 4) {
            det11 = ("Sa ");
        } else if (random == 5) {
            det11 = ("Notre ");
        } else if (random == 6) {
            det11 = ("Votre ");
        } else if (random == 7) {
            det11 = ("Leur ");
        } else {
            det11 = ("DETERMINANT InvGen -> Fem");
        }
    }
    else {
        det11 = ("%.1f ");
    }

    t_baseFlechie bf_adj11;
    p_node pn_adj11;
    do {
        bf_adj11 = ChooseWordBase(adj);
        pn_adj11 = bf_adj11.p;

        if(pn_adj11->toto[(int) (name11.Genre + name11.Nombre - 1)][0] == 0 && ajout == 1){
            printf("La forme au ");

            char* genre;
            if(name11.Genre == Mas){
                printf("masculin ");
                genre = "Mas";
            }else if(name11.Genre == Fem){
                printf("feminin ");
                genre = "Fem";
            }else{
                printf("invariable en genre ");
                genre = "InvGen";
            }

            char* nombre;
            if(name11.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name11.Nombre == PL){
                printf("pluriel ");
                nombre = "PL";
            }else{
                printf("invariable en nombre ");
                nombre = "InvPL";
            }


            printf("de l'adjectif \"");
            DisplayWord(bf_adj11);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                        pn_adj11->toto[(int) (name11.Genre + name11.Nombre - 1)][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tAdj:%s+%s",missingFlechie,bf_adj11.word,genre,nombre);
                fclose(file);
            }
        }
    } while (pn_adj11->toto[(int) (name11.Genre + name11.Nombre - 1)][0] == 0);


    bf_adj11.word = pn_adj11->toto[(int) (name11.Genre + name11.Nombre - 1)];



    t_baseFlechie bf_verb11 = ChooseWordBase(verb);
    p_node pn_verb11 = bf_verb11.p;
    do {
        if (name11.Nombre == SG) {
            random = 6 + rand() % 3;          //6 ou 7 ou 8
        } else if (name11.Nombre == PL) {
            random = 15 + rand() % 3;          //15 ou 16 ou 17
        } else if (name11.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 6 + rand() % 3;          //6 ou 7 ou 8
            } else {
                random = 15 + rand() % 3;          //15 ou 16 ou 17
            }
        }
        i = 0;
        while (i < random) {
            i++;
        }
        k++;
        if(pn_verb11->toto[i][0] == 0 && ajout == 1 && no == 0){
            printf("La forme à la troisième personne du ");

            char* nombre;
            if(name11.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name11.Nombre == PL){
                printf("pluriel ");
                nombre = "PL";
            }
            char* temps;
            if(random%3 == 0){
                printf("au présent de l’indicatif ");
                temps = "IPre";
            }else if(random%3 == 1){
                printf("à l’imparfait de l’indicatif ");
                temps = "IImp";
            }else if(random%3 == 2){
                printf("au présent du subjonctif ");
                temps = "SPre";
            }

            printf("du verbe \"");
            DisplayWord(bf_verb11);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_verb11->toto[i][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tVer:%s+%s+P3",missingFlechie,bf_verb11.word,temps,nombre);
                fclose(file);
            }else{
                no = 1;
            }
        }

        if (k > 10) {
            k = 0;
            bf_verb11 = ChooseWordBase(verb);
            pn_verb11 = bf_verb11.p;
            no = 0;
        }
    } while (pn_verb11->toto[i][0] == 0);


    bf_verb11.word = pn_verb11->toto[i];


    t_accords name21 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name21;
    bf_name21.word = name21.word;
    char* det21;

    if (name21.Nombre == PL) {
        random = rand() % 8;
        if (random == 0) {
            det21 = ("les ");
        } else if (random == 1) {
            det21 = ("des ");
        } else if (random == 2) {
            det21 = ("mes ");
        } else if (random == 3) {
            det21 = ("tes ");
        } else if (random == 4) {
            det21 = ("ses ");
        } else if (random == 5) {
            det21 = ("nos ");
        } else if (random == 6) {
            det21 = ("vos ");
        } else if (random == 7) {
            det21 = ("leurs ");
        } else {
            det21 = ("DETERMINANT PL ");
        }
    }
    else if (name21.Genre == InvGEN) {
        random = rand() % 2;
        if (random == 0) {
            random = rand() % 8;
            if (random == 0) {
                det21 = ("le ");
            } else if (random == 1) {
                det21 = ("un ");
            } else if (random == 2) {
                det21 = ("mon ");
            } else if (random == 3) {
                det21 = ("ton ");
            } else if (random == 4) {
                det21 = ("son ");
            } else if (random == 5) {
                det21 = ("notre ");
            } else if (random == 6) {
                det21 = ("votre ");
            } else if (random == 7) {
                det21 = ("leur ");
            } else {
                det21 = ("DETERMINANT InvGen -> Mas");
            }
        } else {
            random = rand() % 8;
            if (random == 0) {
                det21 = ("la ");
            } else if (random == 1) {
                det21 = ("une ");
            } else if (random == 2) {
                det21 = ("ma ");
            } else if (random == 3) {
                det21 = ("ta ");
            } else if (random == 4) {
                det21 = ("sa ");
            } else if (random == 5) {
                det21 = ("notre ");
            } else if (random == 6) {
                det21 = ("votre ");
            } else if (random == 7) {
                det21 = ("leur ");
            } else {
                det21 = ("DETERMINANT InvGen -> Fem ");
            }
        }
    }
    else if (name21.Genre == Mas) {
        random = rand() % 8;
        if (random == 0) {
            det21 = ("le ");
        } else if (random == 1) {
            det21 = ("un ");
        } else if (random == 2) {
            det21 = ("mon ");
        } else if (random == 3) {
            det21 = ("ton ");
        } else if (random == 4) {
            det21 = ("son ");
        } else if (random == 5) {
            det21 = ("notre ");
        } else if (random == 6) {
            det21 = ("votre ");
        } else if (random == 7) {
            det21 = ("leur ");
        } else {
            det21 = ("DETERMINANT InvGen -> Mas ");
        }
    }
    else if (name21.Genre == Fem) {
        random = rand() % 8;
        if (random == 0) {
            det21 = ("la ");
        } else if (random == 1) {
            det21 = ("une ");
        } else if (random == 2) {
            det21 = ("ma ");
        } else if (random == 3) {
            det21 = ("ta ");
        } else if (random == 4) {
            det21 = ("sa ");
        } else if (random == 5) {
            det21 = ("notre ");
        } else if (random == 6) {
            det21 = ("votre ");
        } else if (random == 7) {
            det21 = ("leur ");
        }
        else {
            det21 = ("DETERMINANT InvGen -> Fem");
        }
    }
    else {
        det21 = ("%.1f ");
    }





    //Modèle 2   nom-adjectif-verbe-nom




    t_accords name12 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name12;
    bf_name12.word = name12.word;
    char* det12;

    if (name12.Nombre == PL) {
        random = rand() % 8;
        if (random == 0) {
            det12 = ("Les ");
        } else if (random == 1) {
            det12 = ("Des ");
        } else if (random == 2) {
            det12 = ("Mes ");
        } else if (random == 3) {
            det12 = ("Tes ");
        } else if (random == 4) {
            det12 = ("Ses ");
        } else if (random == 5) {
            det12 = ("Nos ");
        } else if (random == 6) {
            det12 = ("Vos ");
        } else if (random == 7) {
            det12 = ("Leurs ");
        } else {
            det12 = ("DETERMINANT PL (random = %d");
        }
    }
    else if (name12.Genre == InvGEN) {
        random = rand() % 2;
        if (random == 0) {
            random = rand() % 8;
            if (random == 0) {
                det12 = ("Le ");
            } else if (random == 1) {
                det12 = ("Un ");
            } else if (random == 2) {
                det12 = ("Mon ");
            } else if (random == 3) {
                det12 = ("Ton ");
            } else if (random == 4) {
                det12 = ("Son ");
            } else if (random == 5) {
                det12 = ("Notre ");
            } else if (random == 6) {
                det12 = ("Votre ");
            } else if (random == 7) {
                det12 = ("Leur ");
            } else {
                det12 = ("DETERMINANT InvGen -> Mas (random = %d");
            }
        } else {
            random = rand() % 8;
            if (random == 0) {
                det12 = ("La ");
            } else if (random == 1) {
                det12 = ("Une ");
            } else if (random == 2) {
                det12 = ("Ma ");
            } else if (random == 3) {
                det12 = ("Ta ");
            } else if (random == 4) {
                det12 = ("Sa ");
            } else if (random == 5) {
                det12 = ("Notre ");
            } else if (random == 6) {
                det12 = ("Votre ");
            } else if (random == 7) {
                det12 = ("Leur ");
            } else {
                det12 = ("DETERMINANT InvGen -> Fem (random = %d");
            }
        }
    }
    else if (name12.Genre == Mas) {
        random = rand() % 8;
        if (random == 0) {
            det12 = ("Le ");
        } else if (random == 1) {
            det12 = ("Un ");
        } else if (random == 2) {
            det12 = ("Mon ");
        } else if (random == 3) {
            det12 = ("Ton ");
        } else if (random == 4) {
            det12 = ("Son ");
        } else if (random == 5) {
            det12 = ("Notre ");
        } else if (random == 6) {
            det12 = ("Votre ");
        } else if (random == 7) {
            det12 = ("Leur ");
        } else {
            det12 = ("DETERMINANT InvGen -> Mas (random = %d");
        }
    }
    else if (name12.Genre == Fem) {
        random = rand() % 8;
        if (random == 0) {
            det12 = ("La ");
        } else if (random == 1) {
            det12 = ("Une ");
        } else if (random == 2) {
            det12 = ("Ma ");
        } else if (random == 3) {
            det12 = ("Ta ");
        } else if (random == 4) {
            det12 = ("Sa ");
        } else if (random == 5) {
            det12 = ("Notre ");
        } else if (random == 6) {
            det12 = ("Votre ");
        } else if (random == 7) {
            det12 = ("Leur ");
        } else {
            det12 = ("DETERMINANT InvGen -> Fem (random = %d");
        }
    }
    else {
        det12 = ("%.1f ");
    }


    t_baseFlechie bf_verb12 = ChooseWordBase(verb);
    p_node pn_verb12 = bf_verb12.p;
    do {
        if (name12.Nombre == SG) {
            random = 6 + rand() % 3;          //6 ou 7 ou 8
        } else if (name12.Nombre == PL) {
            random = 15 + rand() % 3;          //15 ou 16 ou 17
        } else if (name12.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 6 + rand() % 3;          //6 ou 7 ou 8
            } else {
                random = 15 + rand() % 3;          //15 ou 16 ou 17
            }
        }

        i = 0;
        while (i < random) {
            i++;
        }
        k++;
        if(pn_verb12->toto[i][0] == 0 && ajout == 1 && no == 0){
            printf("La forme à la troisième personne du ");

            char* nombre;
            if(name12.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name12.Nombre == PL){
                printf("pluriel ");
                nombre = "PL";
            }
            char* temps;
            if(random%3 == 0){
                printf("au présent de l’indicatif ");
                temps = "IPre";
            }else if(random%3 == 1){
                printf("à l’imparfait de l’indicatif ");
                temps = "IImp";
            }else if(random%3 == 2){
                printf("au présent du subjonctif ");
                temps = "SPre";
            }

            printf("du verbe \"");
            DisplayWord(bf_verb12);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_verb12->toto[i][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tVer:%s+%s+P3",missingFlechie,bf_verb12.word,temps,nombre);
                fclose(file);
            }else{
                no = 1;
            }
        }
        if (k > 10) {
            k = 0;
            bf_verb12 = ChooseWordBase(verb);
            pn_verb12 = bf_verb12.p;
            no = 0;
        }
    } while (pn_verb12->toto[i][0] == 0);


    bf_verb12.word = pn_verb12->toto[i];


    t_baseFlechie bf_verb22 = ChooseWordBase(verb);
    p_node pn_verb22 = bf_verb22.p;
    do {
        if (name12.Nombre == SG) {
            random = 6 + rand() % 3;          //6 ou 7 ou 8
        } else if (name12.Nombre == PL) {
            random = 15 + rand() % 3;          //15 ou 16 ou 17
        } else if (name12.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 6 + rand() % 3;          //6 ou 7 ou 8
            } else {
                random = 15 + rand() % 3;          //15 ou 16 ou 17
            }
        }

        i = 0;
        while (i < random) {
            i++;
        }
        k++;
        if(pn_verb22->toto[i][0] == 0 && ajout == 1 && no == 0){
            printf("La forme à la troisième personne du ");

            char* nombre;
            if(name12.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name12.Nombre == PL){
                printf("pluriel ");
                nombre = "PL";
            }
            char* temps;
            if(random%3 == 0){
                printf("au présent de l’indicatif ");
                temps = "IPre";
            }else if(random%3 == 1){
                printf("à l’imparfait de l’indicatif ");
                temps = "IImp";
            }else if(random%3 == 2){
                printf("au présent du subjonctif ");
                temps = "SPre";
            }

            printf("du verbe \"");
            DisplayWord(bf_verb22);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_verb22->toto[i][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tVer:%s+%s+P3",missingFlechie,bf_verb22.word,temps,nombre);
                fclose(file);
            }else{
                no = 1;
            }
        }
        if (k > 10) {
            k = 0;
            bf_verb22 = ChooseWordBase(verb);
            pn_verb22 = bf_verb11.p;
            no = 0;
        }
    } while (pn_verb22->toto[i][0] == 0);


    bf_verb22.word = pn_verb22->toto[i];


    t_accords name22 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name22;
    bf_name22.word = name22.word;
    char* det22;

    if (name22.Nombre == PL) {
        random = rand() % 8;
        if (random == 0) {
            det22 = ("les ");
        } else if (random == 1) {
            det22 = ("des ");
        } else if (random == 2) {
            det22 = ("mes ");
        } else if (random == 3) {
            det22 = ("tes ");
        } else if (random == 4) {
            det22 = ("ses ");
        } else if (random == 5) {
            det22 = ("nos ");
        } else if (random == 6) {
            det22 = ("vos ");
        } else if (random == 7) {
            det22 = ("leurs ");
        } else {
            det22 = ("DETERMINANT PL (random = %d");
        }
    }
    else if (name22.Genre == InvGEN) {
        random = rand() % 2;
        if (random == 0) {
            random = rand() % 8;
            if (random == 0) {
                det22 = ("le ");
            } else if (random == 1) {
                det22 = ("un ");
            } else if (random == 2) {
                det22 = ("mon ");
            } else if (random == 3) {
                det22 = ("ton ");
            } else if (random == 4) {
                det22 = ("son ");
            } else if (random == 5) {
                det22 = ("notre ");
            } else if (random == 6) {
                det22 = ("votre ");
            } else if (random == 7) {
                det22 = ("leur ");
            } else {
                det22 = ("DETERMINANT InvGen -> Mas");
            }
        } else {
            random = rand() % 8;
            if (random == 0) {
                det22 = ("la ");
            } else if (random == 1) {
                det22 = ("une ");
            } else if (random == 2) {
                det22 = ("ma ");
            } else if (random == 3) {
                det22 = ("ta ");
            } else if (random == 4) {
                det22 = ("sa ");
            } else if (random == 5) {
                det22 = ("notre ");
            } else if (random == 6) {
                det22 = ("votre ");
            } else if (random == 7) {
                det22 = ("leur ");
            } else {
                det22 = ("DETERMINANT InvGen -> Fem ");
            }
        }
    }
    else if (name22.Genre == Mas) {
        random = rand() % 8;
        if (random == 0) {
            det22 = ("le ");
        } else if (random == 1) {
            det22 = ("un ");
        } else if (random == 2) {
            det22 = ("mon ");
        } else if (random == 3) {
            det22 = ("ton ");
        } else if (random == 4) {
            det22 = ("son ");
        } else if (random == 5) {
            det22 = ("notre ");
        } else if (random == 6) {
            det22 = ("votre ");
        } else if (random == 7) {
            det22 = ("leur ");
        } else {
            det22 = ("DETERMINANT InvGen -> Mas");
        }
    }
    else if (name22.Genre == Fem) {
        random = rand() % 8;
        if (random == 0) {
            det22 = ("la ");
        } else if (random == 1) {
            det22 = ("une ");
        } else if (random == 2) {
            det22 = ("ma ");
        } else if (random == 3) {
            det22 = ("ta ");
        } else if (random == 4) {
            det22 = ("sa ");
        } else if (random == 5) {
            det22 = ("notre ");
        } else if (random == 6) {
            det22 = ("votre ");
        } else if (random == 7) {
            det22 = ("leur ");
        } else {
            det22 = ("DETERMINANT InvGen -> Fem");
        }
    }
    else {
        det22 = ("%.1f ");
    }


    t_baseFlechie bf_adj12;
    p_node pn_adj12;
    do {
        bf_adj12 = ChooseWordBase(adj);
        pn_adj12 = bf_adj12.p;

        if(pn_adj12->toto[(int) (name22.Genre + name22.Nombre - 1)][0] == 0 && ajout == 1){
            printf("La forme au ");

            char* genre;
            if(name22.Genre == Mas){
                printf("masculin ");
                genre = "Mas";
            }else if(name22.Genre == Fem){
                printf("feminin ");
                genre = "Fem";
            }else{
                printf("invariable en genre ");
                genre = "InvGen";
            }

            char* nombre;
            if(name22.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name22.Nombre == PL){
                printf("pluriel ");
                nombre = "PL";
            }else{
                printf("invariable en nombre ");
                nombre = "InvPL";
            }


            printf("de l'adjectif \"");
            DisplayWord(bf_adj12);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_adj12->toto[(int) (name22.Genre + name22.Nombre - 1)][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tAdj:%s+%s",missingFlechie,bf_adj12.word,genre,nombre);
                fclose(file);
            }
        }
    } while (pn_adj12->toto[(int) (name22.Genre + name22.Nombre - 1)][0] == 0);

    if(name12.Genre == Fem){
        //printf("%.1f;%.1f ",name12.Genre,name12.Nombre);
    }
    bf_adj12.word = pn_adj12->toto[(int) (name22.Genre + name22.Nombre - 1)];





    //Modèle 3   nom-adjectif-verbe-nom



    t_accords name13 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name13;
    bf_name13.word = name13.word;
    char* det13;

    if (name13.Nombre == PL) {
        random = rand() % 8;
        if (random == 0) {
            det13 = ("Les ");
        } else if (random == 1) {
            det13 = ("Des ");
        } else if (random == 2) {
            det13 = ("Mes ");
        } else if (random == 3) {
            det13 = ("Tes ");
        } else if (random == 4) {
            det13 = ("Ses ");
        } else if (random == 5) {
            det13 = ("Nos ");
        } else if (random == 6) {
            det13 = ("Vos ");
        } else if (random == 7) {
            det13 = ("Leurs ");
        } else {
            det13 = ("DETERMINANT PL ");
        }
    }
    else if (name13.Genre == InvGEN) {
        random = rand() % 2;
        if (random == 0) {
            random = rand() % 8;
            if (random == 0) {
                det13 = ("Le ");
            } else if (random == 1) {
                det13 = ("Un ");
            } else if (random == 2) {
                det13 = ("Mon ");
            } else if (random == 3) {
                det13 = ("Ton ");
            } else if (random == 4) {
                det13 = ("Son ");
            } else if (random == 5) {
                det13 = ("Notre ");
            } else if (random == 6) {
                det13 = ("Votre ");
            } else if (random == 7) {
                det13 = ("Leur ");
            } else {
                det13 = ("DETERMINANT InvGen -> Mas ");
            }
        } else {
            random = rand() % 8;
            if (random == 0) {
                det13 = ("La ");
            } else if (random == 1) {
                det13 = ("Une ");
            } else if (random == 2) {
                det13 = ("Ma ");
            } else if (random == 3) {
                det13 = ("Ta ");
            } else if (random == 4) {
                det13 = ("Sa ");
            } else if (random == 5) {
                det13 = ("Notre ");
            } else if (random == 6) {
                det13 = ("Votre ");
            } else if (random == 7) {
                det13 = ("Leur ");
            } else {
                det13 = ("DETERMINANT InvGen -> Fem ");
            }
        }
    }
    else if (name13.Genre == Mas) {
        random = rand() % 8;
        if (random == 0) {
            det13 = ("Le ");
        } else if (random == 1) {
            det13 = ("Un ");
        } else if (random == 2) {
            det13 = ("Mon ");
        } else if (random == 3) {
            det13 = ("Ton ");
        } else if (random == 4) {
            det13 = ("Son ");
        } else if (random == 5) {
            det13 = ("Notre ");
        } else if (random == 6) {
            det13 = ("Votre ");
        } else if (random == 7) {
            det13 = ("Leur ");
        } else {
            det13 = ("DETERMINANT InvGen -> Mas ");
        }
    }
    else if (name13.Genre == Fem) {
        random = rand() % 8;
        if (random == 0) {
            det13 = ("La ");
        } else if (random == 1) {
            det13 = ("Une ");
        } else if (random == 2) {
            det13 = ("Ma ");
        } else if (random == 3) {
            det13 = ("Ta ");
        } else if (random == 4) {
            det13 = ("Sa ");
        } else if (random == 5) {
            det13 = ("Notre ");
        } else if (random == 6) {
            det13 = ("Votre ");
        } else if (random == 7) {
            det13 = ("Leur ");
        } else {
            det13 = ("DETERMINANT InvGen -> Fem ");
        }
    }
    else {
        det13 = ("%.1f ");
    }



    t_baseFlechie bf_adj13;
    p_node pn_adj13;
    do {
        bf_adj13 = ChooseWordBase(adj);
        pn_adj13 = bf_adj13.p;

        if(pn_adj12->toto[(int) (name13.Genre + name13.Nombre - 1)][0] == 0 && ajout == 1){
            printf("La forme au ");

            char* genre;
            if(name13.Genre == Mas){
                printf("masculin ");
                genre = "Mas";
            }else if(name13.Genre == Fem){
                printf("feminin ");
                genre = "Fem";
            }else{
                printf("invariable en genre ");
                genre = "InvGen";
            }

            char* nombre;
            if(name13.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name13.Nombre == PL) {
                printf("pluriel ");
                nombre = "PL";
            }else{
                printf("invariable en nombre ");
                nombre = "InvPL";
            }


            printf("de l'adjectif \"");
            DisplayWord(bf_adj13);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_adj13->toto[(int) (name13.Genre + name13.Nombre - 1)][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tAdj:%s+%s",missingFlechie,bf_adj13.word,genre,nombre);
                fclose(file);
            }
        }
    } while (pn_adj13->toto[(int) (name13.Genre + name13.Nombre - 1)][0] == 0);
    if(name13.Genre == Fem){
        //printf("%.1f;%.1f ",name13.Genre,name13.Nombre);
    }
    bf_adj13.word = pn_adj13->toto[(int) (name13.Genre + name13.Nombre - 1)];




    t_baseFlechie bf_verb13 = ChooseWordBase(verb);
    p_node pn_verb13 = bf_verb13.p;
    do {
        if (name13.Nombre == SG) {
            random = 6 + rand() % 3;          //6 ou 7 ou 8
        } else if (name13.Nombre == PL) {
            random = 15 + rand() % 3;          //15 ou 16 ou 17
        } else if (name13.Nombre == InvPL) {
            random = rand() % 2;
            if (random == 0) {
                random = 6 + rand() % 3;          //6 ou 7 ou 8
            } else {
                random = 15 + rand() % 3;          //15 ou 16 ou 17
            }
        }

        i = 0;
        while (i < random) {
            i++;
        }
        k++;
        if(pn_verb13->toto[i][0] == 0 && ajout == 1 && no == 0){
            printf("La forme à la troisième personne du ");

            char* nombre;
            if(name13.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name13.Nombre == PL){
                printf("pluriel ");
                nombre = "PL";
            }
            char* temps;
            if(random%3 == 0){
                printf("au présent de l’indicatif ");
                temps = "IPre";
            }else if(random%3 == 1){
                printf("à l’imparfait de l’indicatif ");
                temps = "IImp";
            }else if(random%3 == 2){
                printf("au présent du subjonctif ");
                temps = "SPre";
            }

            printf("du verbe \"");
            DisplayWord(bf_verb13);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_verb13->toto[i][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tVer:%s+%s+P3",missingFlechie,bf_verb13.word,temps,nombre);
                fclose(file);
            }else{
                no = 1;
            }
        }
        if (k > 10) {
            k = 0;
            bf_verb13 = ChooseWordBase(verb);
            pn_verb13 = bf_verb13.p;
            no = 0;
        }
    } while (pn_verb13->toto[i][0] == 0);
    //printf(" random = %d;",random);

    bf_verb13.word = pn_verb13->toto[i];


    t_accords name23 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name23;
    bf_name23.word = name23.word;
    char* det23;

    if (name23.Nombre == PL) {
        random = rand() % 8;
        if (random == 0) {
            det23 = ("les ");
        } else if (random == 1) {
            det23 = ("des ");
        } else if (random == 2) {
            det23 = ("mes ");
        } else if (random == 3) {
            det23 = ("tes ");
        } else if (random == 4) {
            det23 = ("ses ");
        } else if (random == 5) {
            det23 = ("nos ");
        } else if (random == 6) {
            det23 = ("vos ");
        } else if (random == 7) {
            det23 = ("leurs ");
        } else {
            det23 = ("DETERMINANT PL");
        }
    }
    else if (name23.Genre == InvGEN) {
        random = rand() % 2;
        if (random == 0) {
            random = rand() % 8;
            if (random == 0) {
                det23 = ("le ");
            } else if (random == 1) {
                det23 = ("un ");
            } else if (random == 2) {
                det23 = ("mon ");
            } else if (random == 3) {
                det23 = ("ton ");
            } else if (random == 4) {
                det23 = ("son ");
            } else if (random == 5) {
                det23 = ("notre ");
            } else if (random == 6) {
                det23 = ("votre ");
            } else if (random == 7) {
                det23 = ("leur ");
            } else {
                det23 = ("DETERMINANT InvGen -> Mas ");
            }
        } else {
            random = rand() % 8;
            if (random == 0) {
                det23 = ("la ");
            } else if (random == 1) {
                det23 = ("une ");
            } else if (random == 2) {
                det23 = ("ma ");
            } else if (random == 3) {
                det23 = ("ta ");
            } else if (random == 4) {
                det23 = ("sa ");
            } else if (random == 5) {
                det23 = ("notre ");
            } else if (random == 6) {
                det23 = ("votre ");
            } else if (random == 7) {
                det23 = ("leur ");
            } else {
                det23 = ("DETERMINANT InvGen -> Fem ");
            }
        }
    }
    else if (name23.Genre == Mas) {
        random = rand() % 8;
        if (random == 0) {
            det23 = ("le ");
        } else if (random == 1) {
            det23 = ("un ");
        } else if (random == 2) {
            det23 = ("mon ");
        } else if (random == 3) {
            det23 = ("ton ");
        } else if (random == 4) {
            det23 = ("son ");
        } else if (random == 5) {
            det23 = ("notre ");
        } else if (random == 6) {
            det23 = ("votre ");
        } else if (random == 7) {
            det23 = ("leur ");
        } else {
            det23 = ("DETERMINANT InvGen -> Mas");
        }
    }
    else if (name23.Genre == Fem) {
        random = rand() % 8;
        if (random == 0) {
            det23 = ("la ");
        } else if (random == 1) {
            det23 = ("une ");
        } else if (random == 2) {
            det23 = ("ma ");
        } else if (random == 3) {
            det23 = ("ta ");
        } else if (random == 4) {
            det23 = ("sa ");
        } else if (random == 5) {
            det23 = ("notre ");
        } else if (random == 6) {
            det23 = ("votre ");
        } else if (random == 7) {
            det23 = ("leur ");
        } else {
            det23 = ("DETERMINANT InvGen -> Fem");
        }
    }
    else {
        det23 = ("%.1f ");
    }




    //MODELE 4    PRONOM/VERBE/ADV/NOM/ADJ




    int vNombre = -1;
    int vPersonne = -1;
    random = rand()%6;
    char* pronom14;

    if(random == 0){
        pronom14 = ("Je");
        vNombre = vSG;
        vPersonne = P1;
    }
    else if(random == 1){
        pronom14 = ("Tu");
        vNombre = vSG;
        vPersonne = P2;
    }
    else if(random == 2){
        pronom14 = ("Il");
        vNombre = vSG;
        vPersonne = P3;
    }
    else if(random == 3){
        pronom14 = ("Nous");
        vNombre = vPL;
        vPersonne = P1;
    }
    else if(random == 4){
        pronom14 = ("Vous");
        vNombre = vPL;
        vPersonne = P2;
    }
    else if(random == 5){
        pronom14 = ("Ils");
        vNombre = vPL;
        vPersonne = P3;
    }


    t_baseFlechie bf_verb14 = ChooseWordBase(verb);
    p_node pn_verb14 = bf_verb14.p;
    do {
        random = vNombre + vPersonne + rand()%3;

        i = 0;
        while (i < random) {
            i++;
        }
        k++;
        if(pn_verb14->toto[i][0] == 0 && ajout == 1 && no == 0){
            printf("La forme à la ");
            char* personne;
            if(vPersonne ==  P1){
                printf("première personne ");
                personne = "P1";
            }else if(vPersonne == P2){
                printf("deuxième personne ");
                personne = "P2";
            }else if(vPersonne == P3){
                printf("troisième personne ");
                personne = "P3";
            }

            char* nombre;
            if(vNombre ==  vSG){
                printf("du singulier ");
                nombre = "SG";
            }else if(vNombre == vPL){
                printf("du pluriel ");
                nombre = "PL";
            }

            char* temps;
            if(random%3 == 0){
                printf("au présent de l’indicatif ");
                temps = "IPre";
            }else if(random%3 == 1){
                printf("à l’imparfait de l’indicatif ");
                temps = "IImp";
            }else if(random%3 == 2){
                printf("au présent du subjonctif ");
                temps = "SPre";
            }

            printf("du verbe \"");
            DisplayWord(bf_verb14);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_verb14->toto[i][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tVer:%s+%s+%s",missingFlechie,bf_verb14.word,temps,nombre,personne);
                fclose(file);
            }else{
                no = 1;
            }
        }
        if (k > 10) {
            k = 0;
            bf_verb14 = ChooseWordBase(verb);
            pn_verb14 = bf_verb14.p;
            no = 0;
        }
    } while (pn_verb14->toto[i][0] == 0);

    bf_verb14.word = pn_verb14->toto[i];


    t_accords name14 = ChooseWordFlechie(ChooseWordBase(name));
    t_baseFlechie bf_name14;
    bf_name14.word = name14.word;
    char* det14;

    if (name14.Nombre == PL) {
        random = rand() % 8;
        if (random == 0) {
            det14 = ("les ");
        } else if (random == 1) {
            det14 = ("des ");
        } else if (random == 2) {
            det14 = ("mes ");
        } else if (random == 3) {
            det14 = ("tes ");
        } else if (random == 4) {
            det14 = ("ses ");
        } else if (random == 5) {
            det14 = ("nos ");
        } else if (random == 6) {
            det14 = ("vos ");
        } else if (random == 7) {
            det14 = ("leurs ");
        } else {
            det14 = ("DETERMINANT PL (random = %d");
        }
    }
    else if (name14.Genre == InvGEN) {
        random = rand() % 2;
        if (random == 0) {
            random = rand() % 8;
            if (random == 0) {
                det14 = ("le ");
            } else if (random == 1) {
                det14 = ("un ");
            } else if (random == 2) {
                det14 = ("mon ");
            } else if (random == 3) {
                det14 = ("ton ");
            } else if (random == 4) {
                det14 = ("son ");
            } else if (random == 5) {
                det14 = ("notre ");
            } else if (random == 6) {
                det14 = ("votre ");
            } else if (random == 7) {
                det14 = ("leur ");
            } else {
                det14 = ("DETERMINANT InvGen -> Mas");
            }
        } else {
            random = rand() % 8;
            if (random == 0) {
                det14 = ("la ");
            } else if (random == 1) {
                det14 = ("une ");
            } else if (random == 2) {
                det14 = ("ma ");
            } else if (random == 3) {
                det14 = ("ta ");
            } else if (random == 4) {
                det14 = ("sa ");
            } else if (random == 5) {
                det14 = ("notre ");
            } else if (random == 6) {
                det14 = ("votre ");
            } else if (random == 7) {
                det14 = ("leur ");
            } else {
                det14 = ("DETERMINANT InvGen -> Fem ");
            }
        }
    }
    else if (name14.Genre == Mas) {
        random = rand() % 8;
        if (random == 0) {
            det14 = ("le ");
        } else if (random == 1) {
            det14 = ("un ");
        } else if (random == 2) {
            det14 = ("mon ");
        } else if (random == 3) {
            det14 = ("ton ");
        } else if (random == 4) {
            det14 = ("son ");
        } else if (random == 5) {
            det14 = ("notre ");
        } else if (random == 6) {
            det14 = ("votre ");
        } else if (random == 7) {
            det14 = ("leur ");
        } else {
            det14 = ("DETERMINANT InvGen -> Mas ");
        }
    }
    else if (name14.Genre == Fem) {
        random = rand() % 8;
        if (random == 0) {
            det14 = ("la ");
        } else if (random == 1) {
            det14 = ("une ");
        } else if (random == 2) {
            det14 = ("ma ");
        } else if (random == 3) {
            det14 = ("ta ");
        } else if (random == 4) {
            det14 = ("sa ");
        } else if (random == 5) {
            det14 = ("notre ");
        } else if (random == 6) {
            det14 = ("votre ");
        } else if (random == 7) {
            det14 = ("leur ");
        } else {
            det14 = ("DETERMINANT InvGen -> Fem");
        }
    }
    else {
        det14 = ("%.1f ");
    }


    t_baseFlechie bf_adj14;
    p_node pn_adj14;
    do {
        bf_adj14 = ChooseWordBase(adj);
        pn_adj14 = bf_adj14.p;

        if(pn_adj12->toto[(int) (name14.Genre + name14.Nombre - 1)][0] == 0 && ajout == 1){
            printf("La forme au ");

            char* genre;
            if(name14.Genre == Mas){
                printf("masculin ");
                genre = "Mas";
            }else if(name14.Genre == Fem){
                printf("feminin ");
                genre = "Fem";
            }else{
                printf("invariable en genre ");
                genre = "InvGen";
            }

            char* nombre;
            if(name14.Nombre == SG){
                printf("singulier ");
                nombre = "SG";
            }else if(name14.Nombre == PL){
                printf("pluriel ");
                nombre = "PL";
            }else{
                printf("invariable en nombre ");
                nombre = "InvPL";
            }


            printf("de l'adjectif \"");
            DisplayWord(bf_adj14);
            printf("\" est inconue dans le dictionaire.\nShouaitez vous l'ajouter ?\n");
            char ans[10];
            char missingFlechie[50];
            fgets(ans,9, stdin);
            if(ans[0] == 'O' || ans[0] == 'o' || ans[0] == 'Y' || ans[0] == 'y' || ans[0] == '1'){
                FILE* file = fopen("dictionnaire.txt", "a");
                printf("Entrez la forme manquante :");
                fgets(missingFlechie,49, stdin);
                for (int j = 0; j < strlen(missingFlechie)-1; ++j) {
                    pn_adj14->toto[(int) (name14.Genre + name14.Nombre - 1)][j] = missingFlechie[j];
                }
                missingFlechie[strlen(missingFlechie)-1] = '\0';
                fprintf(file,"\n%s\t%s\tAdj:%s+%s",missingFlechie,bf_adj14.word,genre,nombre);
                fclose(file);
            }
        }
    } while (pn_adj14->toto[(int) (name14.Genre + name14.Nombre - 1)][0] == 0);
    if(name14.Genre == Fem){
        //printf("%.1f;%.1f ",name14.Genre,name14.Nombre);
    }
    bf_adj14.word = pn_adj14->toto[(int) (name14.Genre + name14.Nombre - 1)];

    printf("\n\nModèle 1 : %s ",det11);
    DisplayWord(bf_name11);
    printf(" | ");
    DisplayWord(bf_adj11);
    printf(" | ");
    DisplayWord(bf_verb11);
    printf(" | ");
    printf("%s ",det21);
    DisplayWord(bf_name21);
    printf("\n");

    printf("Modèle 2 : %s ",det12);
    DisplayWord(bf_name12);
    printf(" | qui | ");
    DisplayWord(bf_verb12);
    printf(" | ");
    DisplayWord(bf_verb22);
    printf(" | ");
    printf("%s ",det22);
    DisplayWord(bf_name22);
    printf(" | ");
    DisplayWord(bf_adj12);
    printf("\n");

    printf("Modèle 3 : %s ",det13);
    DisplayWord(bf_name13);
    printf(" | ");
    DisplayWord(bf_adj13);
    printf(" | ");
    DisplayWord(bf_verb13);
    printf(" | ");
    DisplayWord(ChooseWordBase(adv));
    printf(" | ");
    printf("%s ",det23);
    DisplayWord(bf_name23);
    printf("\n");

    printf("Modèle 4 : %s ",pronom14);
    DisplayWord(bf_verb14);
    printf(" | ");
    DisplayWord(ChooseWordBase(adv));
    printf(" | ");
    printf("%s ",det14);
    DisplayWord(bf_name14);
    printf(" | ");
    DisplayWord(bf_adj14);
    printf("\n");


}

/** Fonction permetant de compter toutes les formes fléchies existantes à partir d'une node. Fonction appelée dans AutoCompletion(), rechercheNiemeFlechie(), PrintFlechies()*/
int Count_flechies(p_node pn, int row){
    if(pn == NULL){
        return 0;
    }else if(pn->toto != NULL){
        int k = 0;
        for (int i = 0; i < row; ++i) {
            if(pn->toto[i][0] != 0){
                k++;
            }
        }
        return k + Count_flechies(pn->kid, row) + Count_flechies(pn->siblings, row);
    }else{
        return Count_flechies(pn->kid,row) + Count_flechies(pn->siblings, row);
    }
}

/** Fonction permetant de d'afficher toutes les formes fléchies existantes à partir d'une node. Fonction appelée dans AutoCompletion()*/
void PrintFlechies(p_node pn, int row, int cpt){
    if(pn != NULL) {
        if (pn->toto != NULL) {
            int j = 0;
            for (int i = 0; i < row; ++i) {
                if (pn->toto[i][0] != 0) {
                    printf("%d : ",cpt++);
                    while (pn->toto[i][j] != 0) {
                        printf("%c", pn->toto[i][j]);
                        j++;
                    }
                    j = 0;
                    printf("\n");
                }
            }
        }
        PrintFlechies(pn->kid, row, cpt);
        PrintFlechies(pn->siblings, row, cpt + Count_flechies(pn->kid, row));
    }
}

/** Fonction permetant de retourner la n-ième forme fléchie à partir d'une node. Fonction appelée dans AutoCompletion()*/
char* rechercheNiemeFlechie(p_node pn, int row, int n) {
    if (pn != NULL) {
        char* word = calloc(50, sizeof(char));
        if (pn->toto != NULL) {
            int j = 0;
            for (int i = 0; i < row; ++i) {
                if (pn->toto[i][0] != 0) {
                    while (pn->toto[i][j] != 0) {
                        word[j] = pn->toto[i][j];
                        j++;
                    }
                    n--;
                    if(n == 0){
                        break;
                    }
                }
            }
        }
        if (n == 0){
            return word;
            free(word);
        }else{
            if(rechercheNiemeFlechie(pn->kid, row, n) != NULL && rechercheNiemeFlechie(pn->kid, row, n)[0] != 0){
                return rechercheNiemeFlechie(pn->kid, row, n);
                free(word);
            }else{
                return rechercheNiemeFlechie(pn->siblings, row, n - Count_flechies(pn->kid, row));
                free(word);
            }
        }
    }else{
        return NULL;
    }
}

/** Fonction permetant de rechercher un mot rentrée par l'utilisateur à l'aide de la completion automatique.*/
t_baseFlechie AutoCompletion(t_tree NOM,t_tree VER,t_tree ADJ,t_tree ADV){
    char* nature = calloc(15,sizeof(char));
    t_tree ActualTree;
    int row;
    t_baseFlechie bf;
    bf.word = NULL;
    bf.p = NULL;


    printf("Quel est la nature de votre mot ? adjectives/adverbs/verbs/names\n");
    fgets(nature,14, stdin);

    while(Verif_character(nature) == 0){
        printf("Wrong input");
        printf("Quel est la nature de votre mot ? adjectives/adverbs/verbs/names\n");
        fgets(nature,14, stdin);
    }
    while(Verif_Genre(nature) != 0){
        printf("Wrong input");
        printf("Quel est la nature de votre mot ? adjectives/adverbs/verbs/names\n");
        fgets(nature,14, stdin);
    }

    if (strcmp(nature,"names\n") == 0){
        ActualTree = NOM;
        row = 9;
    }
    if (strcmp(nature,"verbs\n") == 0){
        ActualTree = VER;
        row = 19;
    }
    if (strcmp(nature,"adjectives\n") == 0){
        ActualTree = ADJ;
        row = 10;
    }
    if (strcmp(nature,"adverbs\n") == 0){
        ActualTree = ADV;
        row = 1;
    }

    p_node pn = ActualTree.root;
    char word[50];
    char useless;
    int i  = 0;

    if (pn->lettre == '0') {
        pn = pn->kid;
    }


    printf("Rentrez les lettres de votre mot une par une.\n");
    while(Count_flechies(pn,row) > 10) {
        word[i] = fgetc(stdin);
        useless = fgetc(stdin);

        if(word[i]<'a' || word[i]>'z'){
            useless = fgetc(stdin);
        }

        while (pn->lettre != word[i]) {
            if (pn->siblings != NULL) {
                pn = pn->siblings;
            }else if (pn->lettre != word[i]){
                printf("Mot non trouvé\n");
                return bf;
            }
        }
        if (pn->kid != NULL) {
            pn = pn->kid;
        }
        i++;
    }
    int k = 0;

    PrintFlechies(pn,row,1);

    int n;
    do{
        printf("Choissez le numéro du mot souhaité (entre 1 et %d)\n", Count_flechies(pn,row));
        scanf("%d",&n);
        useless = fgetc(stdin);
    }while(n <= 0 && n > Count_flechies(pn,row));


    char* chosenword = rechercheNiemeFlechie(pn, row, n);
    bf.word = chosenword;
    bf.p = pn;
    return bf;
    free(nature);


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

/** Fonction permetant de compter le nombre de siblings d'une node*/
int CountSiblings(p_node p){
    int cpt = 0;
    p_node tmp = p;
    while (tmp->siblings != NULL){
        tmp = tmp->siblings;
        cpt ++;
    }
    return cpt;
}

/** Fonction permetant d'aficher un mot*/
void DisplayWord(t_baseFlechie bf){
    int i = 0;
    if(bf.word != NULL) {
        while (bf.word[i] != 0) {
            printf("%c", bf.word[i]);
            i++;
        }
    }else{
        //printf("ATTENTION tentative de print un NULL");
    }
}

/** Fonction permetant d'initialiser un arbre ayant une node contenant 'a' comme racine */
t_tree createTree(char a){
    t_tree nouv;
    nouv.root = createNode(a);
    return nouv;
}

/** Fonction permetant d'inserer les formes fléchies dans un arbre. Fonction appelée par createTree_any()*/
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
                        pn->toto[(int) (Temps + Personne + vNombre - 1)][i] = name[i];
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

/** Fonction permetant de créer un abre a partir d'un fichier */
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

    char name[100];
    char useless[500];
    char ActualChar;

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
        //printf("Impossible d'ouvrir le dico %c.txt",&filename);
        return t;
    }
}

/** Fonction permetant de créer les différents fichiers(names, adjectives, adverbs et verbs) à partir du fichier dictionnaire */
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
        while(fgetc(dico) != EOF){
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
                while (ligne[i] != '\n' && ligne[i] != 0){
                    fputc(ligne[i], names);
                    i++;
                }
                fputc('\n', names);
            }else if (a == 'V') {
                fseek(dico, pos, SEEK_SET);
                fgets(ligne, 1000, dico);
                int i = 0;
                while (ligne[i] != '\n' && ligne[i] != 0){
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
                        while (ligne[i] != '\n' && ligne[i] != 0){
                            fputc(ligne[i], adverbs);
                            i++;
                        }
                        fputc('\n', adverbs);
                    }else if (b == 'j') {
                        fseek(dico, pos, SEEK_SET);
                        fgets(ligne, 1000, dico);
                        int i = 0;
                        while (ligne[i] != '\n' && ligne[i] != 0){
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

/** Fonction permetant de free les arbres crées par createTree() */
void freeTree(p_node pn, int row){
    if(pn != NULL){
        if(pn->kid == NULL && pn->siblings == NULL){
            if(pn->toto != NULL){
                for (int i = 0; i < row; ++i) {
                    free(pn->toto[i]);
                }
                free(pn->toto);
            }
            free(pn);
        }
        freeTree(pn->kid, row);
        freeTree(pn->siblings, row);
    }
}