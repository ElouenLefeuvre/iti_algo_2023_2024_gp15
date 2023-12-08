#include<stdio.h>
#include<stdbool.h>
#include "ArbreHuffman.h"
#include "Statistiques.h"


ArbreHuffman arbrehuffman(Statistiques stat){
    ArbreHuffman arbre;
    arbre.statistiques=stat;
    fixerfilsGauche(arbre,NULL);
    fixerfilsDroit(arbre,NULL);
    return arbre;
}

ArbreHuffman fusionner(ArbreHuffman arbre1,ArbreHuffman arbre2){
    ArbreHuffman result;
    Statistiques stat ;
    stat.caracter = NULL;
    stat.ponderation = obtenirPonderation(arbre1.statistiques)+obtenirPonderation(arbre2.statistiques);
    result.statistiques= stat;
    fixerfilsGauche(result,arbre1);
    fixerfilsDroit(result,arbre2);
    return result;
}


void* fixerFilsGauche(ArbreHuffman arbre,ArbreHuffman filsGauche){
    arbre.filsGauche = filsGauche;
}

void* fixerFilsDroit(ArbreHuffman arbre,ArbreHuffman filsDroit){
    arbre.filsDroit = filsDroit;
}

ArbreHuffman obtenirFilsGauche(ArbreHuffman arbre){
    return arbre.filsGauche;
}

ArbreHuffman obtenirFilsDroit(ArbreHuffman arbre){
    return arbre.filsDroit;
}

bool estVide(ArbreHuffman arbre){
    return ((arbre.statistiques.caracter == "") && (arbre.statistiques.ponderation == 0));
}

bool estFeuille(ArbreHuffman arbre){
    return (estVide(arbre.filsDroit) && estVide(arbre.filsGauche));
}

bool estPresent(ArbreHuffman arbre, char caractere){
    if (arbre.statistiques.caracter == caractere) {
        return true;
    }
    else {
        return (estPresent(obtenirFilsDroit(arbre),caractere) || estPresent(obtenirFilsGauche(arbre),caractere));
    }
}