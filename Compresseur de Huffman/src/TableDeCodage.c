#include<stdio.h>
#include "TableDeCodage.h"

TableDeCodage obtenirTableDeCodage(ArbreHuffman a) {
    TableDeCodage res;
    res.car = obtenirCaractere(a.statistiques);
    res.code = obtenirCodeBinaire(res.car);
    res.listeSuivante = NULL;
    return res;
}

CodeBinaire obtenirCode(TableDeCodage tab,char c) {
    if (!(estVide(tab))) {
        if (tab.car == car) {
            return tab.code;
        }
        else {
            return obtenirCode(tab.listeSuivante);
        }

    }

}

char obtenirCarac(TableDeCodage tab,CodeBinaire code) {
    if (!(estVide(tab))) {
        if (tab.code == code) {
            return tab.car;
        }
        else {
            return obtenirCode(tab.listeSuivante);
        }

    }

}

void ajouter(TableDeCodage tab,char c,CodeBinaire code) {
    TableDeCodage temp;
    temp = tab;
    tab.car = car;
    tab.code = code;
    tab.listeSuivante = temp;
}


