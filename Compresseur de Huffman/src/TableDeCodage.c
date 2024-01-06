#include<stdio.h>
#include "TableDeCodage.h"
#include "CodeBinaire.h"
#include<stdbool.h>

TableDeCodage TDC_obtenirTableDeCodage(ArbreHuffman a) {
    TableDeCodage res;
    res.noeud->c = S_obtenirCaractere(a.statistiques);
    res.noeud->code = CB_CbFromAH(&a,res.noeud->c);
    res.noeud->listeSuivante = NULL;
    return res;
}

CodeBinaire TDC_obtenirCode(TableDeCodage tab,char c) {
    if (!(TDC_estVide(tab))) {
        if (tab.noeud->c == c) {
            return tab.noeud->code;
        }
        else {
            return TDC_obtenirCode((TableDeCodage){tab.noeud->listeSuivante}, c);
        }

    }

}

char TDC_obtenirCarac(TableDeCodage tab,CodeBinaire code) {
    if (!(TDC_estVide(tab))) {
        //Il faut ajouter une methode equlas dans codeBinaire
        if (CB_codeBinaireToStr(&tab.noeud->code) == CB_codeBinaireToStr(&code)) {
            return tab.noeud->c;
        }
        else {
            return TDC_obtenirCarac((TableDeCodage){tab.noeud->listeSuivante},code);
        }

    }

}

void TDC_ajouter(TableDeCodage *tab,char *c,CodeBinaire *code) {
    TableDeCodage temp;
    temp = *tab;
    tab->noeud->c = *c;
    tab->noeud->code = *code;
    tab->noeud->listeSuivante = temp.noeud;
}

void TDC_supprimer(TableDeCodage *tab, char *c, CodeBinaire *code) {
    TableDeCodage temp, temp2;
    temp2.noeud = tab->noeud->listeSuivante;
    if (!(TDC_estVide(temp2))) {
        if (&temp.noeud->c == c) {
            temp.noeud = temp.noeud->listeSuivante;
            tab->noeud->listeSuivante = temp.noeud;
        }
        else {
            temp2.noeud = temp.noeud->listeSuivante;
            TDC_supprimer(&temp2, c, code);
            tab->noeud->listeSuivante = temp.noeud;
        }
    }


}


int TDC_estPresent(TableDeCodage tab, char car) {
    TableDeCodage temp;
    if (TDC_estVide(tab)){
        return 0;
    }
    if ( tab.noeud->c==car) {
        return 1;
    }
    else {
        temp.noeud = tab.noeud->listeSuivante;
        return TDC_estPresent(temp, car);
    }
}

bool TDC_estVide(TableDeCodage tab){
    return tab.noeud == NULL;
}
