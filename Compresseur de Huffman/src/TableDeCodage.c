#include<stdio.h>
#include "TableDeCodage.h"
#include<stdbool.h>
#include <stdlib.h>
#include <string.h>

TableDeCodage* TDC_obtenirTableDeCodage() {
    TableDeCodage* table = malloc(sizeof(TableDeCodage));
    if (table != NULL) {
        table->ligne = NULL;
    }
    return table;
}

CodeBinaire* TDC_obtenirCode(TableDeCodage tab, char c) {
    Ligne* current = tab.ligne;
    while (current != NULL) {
        if (current->c == c) {
            return &current->code;
        }
        current = current->listeSuivante;
    }
    return NULL;  // Le caractère n'a pas été trouvé dans la table.
}

void TDC_ajouter(TableDeCodage *tab, char c, CodeBinaire *code) {
    Ligne* nouvelleLigne = malloc(sizeof(Ligne));
    if (nouvelleLigne != NULL) {
        nouvelleLigne->code = *code;
        nouvelleLigne->c = c;
        nouvelleLigne->listeSuivante = tab->ligne;
        tab->ligne = nouvelleLigne;
    }
}

int TDC_estPresent(TableDeCodage tab, char car) {
    TableDeCodage temp;
    if (TDC_estVide(tab)){
        return 0;
    }
    if ( tab.ligne->c == car) {
        return 1;
    }
    else {
        temp.ligne = tab.ligne->listeSuivante;
        return TDC_estPresent(temp, car);
    }
}

bool TDC_estVide(TableDeCodage tab) {
    return tab.ligne == NULL;
}

char* TDC_afficherTdc(TableDeCodage* tdc) {
    Ligne *actuel = tdc->ligne;
    printf("la table de codage est: \n");
    while (actuel != NULL) {
        printf(" | Caracter is: %c  ,CodeBinaire is: %s |\n", actuel->c,CB_codeBinaireToStr(&actuel->code));
        actuel = actuel->listeSuivante;
    }
    return NULL;
}