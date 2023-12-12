#include<stdio.h>
#include "Statistiques.h"

Statistiques statistique(char c, int n) {
    Statistiques res;
    res.caracter = c;
    res.ponderation = n ;
    return res;
}

int obtenirPonderation(Statistiques stat) {
    return stat.ponderation;
}

char obtenirCaractere(Statistiques stat) {
    return stat.caracter;
}
