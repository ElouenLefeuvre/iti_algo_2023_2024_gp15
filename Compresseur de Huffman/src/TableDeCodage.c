#include<stdio.h>
#include "TableDeCodage.h"
#include<stdbool.h>

TableDeCodage TDC_obtenirTableDeCodage(ArbreHuffman a) {
    TableDeCodage res;
    res.noeud->c = S_obtenirCaractere(a.statistiques);
    res.noeud->code = CB_obtenirCodeBinaire(res.noeud->c);
    res.noeud->listeSuivante = NULL;
    return res;
}

CodeBinaire TDC_obtenirCode(TableDeCodage tab,char c) {
    if (!(TDC_estVide(tab))) {
        if (tab.noeud->c == case) {
            return tab.noeud->code;
        }
        else {
            return TDC_obtenirCode(tab.noeud->listeSuivante,c);
        }

    }

}

char TDC_obtenirCarac(TableDeCodage tab,CodeBinaire code) {
    if (!(TDC_estVide(tab))) {
        //Il faut ajouter une methode equlas dans codeBinaire
        if (tab.noeud->code == code) {
            return tab.noeud->c;
        }
        else {
            return TDC_obtenirCarac(tab.noeud->listeSuivante,code);
        }

    }

}

TableDeCodage TDC_ajouter(TableDeCodage tab,char c,CodeBinaire code) {
    TableDeCodage temp;
    temp = tab;
    tab.noeud->c = c;
    tab.noeud->code = code;
    tab.noeud->listeSuivante = temp;
    return tab;
}

void TDC_supprimer(TableDeCodage tab, char c, CodeBinaire code) {
    TableDeCodage temp;
    if (!(TDC_estVide(tab.noeud->listeSuivante))) {
        if (temp.noeud->c == c) {
            temp = temp.noeud->listeSuivante;
            tab.noeud->listeSuivante = temp;
        }
        else {
            TDC_supprimer(temp.noeud->listeSuivante, c, code);
            tab.noeud->listeSuivante = temp;
        }
    }


}


int TDC_estPresent(TableDeCodage tab, char car) {
    if (TDC_estVide(tab)){
        return 0;
    }
    if ( tab.noeud->c==car) {
        return 1;
    }
    else {
        return TDC_estPresent(tab.noeud->listeSuivante, car);
    }
}

bool TDC_estVide(TableDeCodage tab){
    return tab.noeud == NULL;
}
