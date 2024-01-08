#include<stdio.h>
#include "TableDeCodage.h"
#include<stdbool.h>
#include <stdlib.h>

TableDeCodage* TDC_obtenirTableDeCodage() {
    TableDeCodage* table = malloc(sizeof(TableDeCodage));
    if (table != NULL) {
        table->ligne = NULL;
    }
    return table;
}

CodeBinaire* TDC_obtenirCode(TableDeCodage tab,char c) {
    Ligne* current = tab.ligne;
    while (current != NULL) {
        if (current->c == c) {
            return &current->code;
        }
        current = current->listeSuivante;
    }
    return NULL;  // Le caractère n'a pas été trouvé dans la table.
}

char TDC_obtenirCarac(TableDeCodage tab,CodeBinaire code) {
    if (!(TDC_estVide(tab))) {
        //Il faut ajouter une methode equlas dans codeBinaire
        if (CB_codeBinaireToStr(&tab.ligne->code) == CB_codeBinaireToStr(&code)) {
            return tab.ligne->c;
        }
        else {
            return TDC_obtenirCarac((TableDeCodage){tab.ligne->listeSuivante},code);
        }

    }
    return 'c';
}

void TDC_ajouter(TableDeCodage *tab,char c,CodeBinaire *code) {
    Ligne* nouvelleLigne = malloc(sizeof(Ligne));
    if (nouvelleLigne != NULL) {
        nouvelleLigne->code = *code;
        nouvelleLigne->c = c;
        nouvelleLigne->listeSuivante = tab->ligne;
        tab->ligne = nouvelleLigne;
    }
}

void TDC_supprimer(TableDeCodage *tab, char *c, CodeBinaire *code) {
    TableDeCodage temp, temp2;
    temp2.ligne = tab->ligne->listeSuivante;
    if (!(TDC_estVide(temp2))) {
        if (&temp.ligne->c == c) {
            temp.ligne = temp.ligne->listeSuivante;
            tab->ligne->listeSuivante = temp.ligne;
        }
        else {
            temp2.ligne = temp.ligne->listeSuivante;
            TDC_supprimer(&temp2, c, code);
            tab->ligne->listeSuivante = temp.ligne;
        }
    }
}


int TDC_estPresent(TableDeCodage tab, char car) {
    TableDeCodage temp;
    if (TDC_estVide(tab)){
        return 0;
    }
    if ( tab.ligne->c==car) {
        return 1;
    }
    else {
        temp.ligne = tab.ligne->listeSuivante;
        return TDC_estPresent(temp, car);
    }
}

bool TDC_estVide(TableDeCodage tab){
    return tab.ligne == NULL;
}


char* TDC_afficherTdc(TableDeCodage* tdc){
    Ligne *actuel = tdc->ligne;
    printf("la table de codage est: \n");
    while (actuel != NULL) {
        printf(" | Caracter is: %c  ,CodeBinaire is: %s |\n", actuel->c,CB_codeBinaireToStr(&actuel->code));
        actuel = actuel->listeSuivante;
    }
    return NULL;
}