#include<stdio.h>
#include "Statistiques.h"

Statistiques statistique(char c, int n) {
    Statistiques result;
    result.caracter = c;
    result.ponderation = n ;
    return result;
}

int obtenirPonderation(Statistiques stat) {
    return stat.ponderation;
}

char obtenirCaractere(Statistiques stat) {
    return stat.caracter;
}
