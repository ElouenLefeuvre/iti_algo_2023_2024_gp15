#include<stdio.h>
#include "TableDeCodage.h"

TableDeCodage obtenirTableDeCodage(ArbreHuffman a) {
    TableDeCodage res;
    res.noeud.car = obtenirCaractere(a.statistiques);
    res.noeud.code = obtenirCodeBinaire(res.noeud->c);
    res.noeud.listeSuivante = NULL;
    return res;
}

CodeBinaire obtenirCode(TableDeCodage tab,char c) {
    if (!(estVide(tab))) {
        if (tab.noeud->c == case) {
            return tab.noeud.code;
        }
        else {
            return obtenirCode(tab.noeud.listeSuivante);
        }

    }

}

char obtenirCarac(TableDeCodage tab,CodeBinaire code) {
    if (!(estVide(tab))) {
        if (tab.noeud.code == code) {
            return tab.noeud.car;
        }
        else {
            return obtenirCode(tab.noeud.listeSuivante);
        }

    }

}

void ajouter(TableDeCodage tab,char c,CodeBinaire code) {
    TableDeCodage temp;
    temp = tab;
    tab.noeud.car = car;
    tab.noeud.code = code;
    tab.noeud.listeSuivante = temp;
}

void supprimer(TableDeCodage tab, char c, CodeBinaire code) {
    TableDeCodage temp;
    if (!(estVide(tab.noeud.listeSuivante))) {
        if (temp.noeud.car == car) {
            temp = temp.noeud.listeSuivante;
            tab.noeud.listeSuivante = temp;
        }
        else {
            supprimer(temp.noeud.listeSuivante, car, code);
            tab.noeud.listeSuivante = temp;
        }
    }


}


int estPresent(TableDeCodage tab, char car) {
    if (estVide(tab)){
        return 0;
    }
    if ( tab.noeud.car==car) {
        return 1;
    }
    else {
        return estPresent(tab.noeud.listeSuivante, car);
    }
}
