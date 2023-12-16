#include<stdio.h>
#include<stdbool.h>
#include "ArbreHuffman.h"
#include "Statistiques.h"


ArbreHuffman arbrehuffman(Statistiques stat) {
    ArbreHuffman arbre;
    arbre.statistiques=stat;
    fixerfilsGauche(arbre,NULL);
    fixerfilsDroit(arbre,NULL);
    return arbre;
}

int obtenirOccurences(ArbreHuffman arbre){
    return arbre.statistiques.ponderation
}

ArbreHuffman fusionner(ArbreHuffman arbre1,ArbreHuffman arbre2) {
    ArbreHuffman res;
    Statistiques stat ;
    stat.caracter = NULL;
    stat.ponderation = obtenirPonderation(arbre1.statistiques)+obtenirPonderation(arbre2.statistiques);
    res.statistiques= stat;
    if (obtenirOccurences(arbre1)<obtenirOccurences(arbre2)){
    fixerfilsGauche(res,arbre1);
    fixerfilsDroit(res,arbre2);
    }
    else {
        fixerfilsGauche(res,arbre2);
        fixerfilsDroit(res,arbre1);
    }
    return res;
}


void* fixerFilsGauche(ArbreHuffman arbre,ArbreHuffman filsGauche) {
    arbre.filsGauche = filsGauche;
}

void* fixerFilsDroit(ArbreHuffman arbre,ArbreHuffman filsDroit) {
    arbre.filsDroit = filsDroit;
}

ArbreHuffman obtenirFilsGauche(ArbreHuffman arbre) {
    return arbre.filsGauche;
}

ArbreHuffman obtenirFilsDroit(ArbreHuffman arbre) {
    return arbre.filsDroit;
}

bool estVide(ArbreHuffman arbre) {
    return ((arbre.statistiques.caracter == "") && (arbre.statistiques.ponderation == 0));
}

bool estFeuille(ArbreHuffman arbre) {
    return (estVide(arbre.filsDroit) && estVide(arbre.filsGauche));
}

bool estPresent(ArbreHuffman arbre, char caractere) {
    if (arbre.statistiques.caracter == caractere) {
        return true;
    }
    else {
        return (estPresent(obtenirFilsDroit(arbre),caractere) || estPresent(obtenirFilsGauche(arbre),caractere));
    }
}