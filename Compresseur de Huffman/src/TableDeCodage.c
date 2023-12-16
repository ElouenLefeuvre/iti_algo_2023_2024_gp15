#include<stdio.h>
#include "TableDeCodage.h"
#include<stdbool.h>

TableDeCodage obtenirTableDeCodage(ArbreHuffman a) {
    TableDeCodage res;
    res.noeud->c = obtenirCaractere(a.statistiques);
    res.noeud->code = obtenirCodeBinaire(res.noeud->c);
    res.noeud->listeSuivante = NULL;
    return res;
}

CodeBinaire obtenirCode(TableDeCodage tab,char c) {
    if (!(TCestVide(tab))) {
        if (tab.noeud->c == case) {
            return tab.noeud->code;
        }
        else {
            return obtenirCode(tab.noeud->listeSuivante,c);
        }

    }

}

char obtenirCarac(TableDeCodage tab,CodeBinaire code) {
    if (!(TCestVide(tab))) {
        //Il faut ajouter une methode equlas dans codeBinaire
        if (tab.noeud->code == code) {
            return tab.noeud->c;
        }
        else {
            return obtenirCarac(tab.noeud->listeSuivante,code);
        }

    }

}

TableDeCodage ajouter(TableDeCodage tab,char c,CodeBinaire code) {
    TableDeCodage temp;
    temp = tab;
    tab.noeud->c = c;
    tab.noeud->code = code;
    tab.noeud->listeSuivante = temp;
    return tab;
}

void supprimer(TableDeCodage tab, char c, CodeBinaire code) {
    TableDeCodage temp;
    if (!(TCestVide(tab.noeud->listeSuivante))) {
        if (temp.noeud->c == c) {
            temp = temp.noeud->listeSuivante;
            tab.noeud->listeSuivante = temp;
        }
        else {
            supprimer(temp.noeud->listeSuivante, c, code);
            tab.noeud->listeSuivante = temp;
        }
    }


}


int estPresent(TableDeCodage tab, char car) {
    if (TCestVide(tab)){
        return 0;
    }
    if ( tab.noeud->c==car) {
        return 1;
    }
    else {
        return estPresent(tab.noeud->listeSuivante, car);
    }
}

bool TCestVide(TableDeCodage tab){
    return tab.noeud == NULL;
}
