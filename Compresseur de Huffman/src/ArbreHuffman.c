#include<stdio.h>
#include<stdbool.h>
#include "ArbreHuffman.h"
#include "Statistiques.h"


ArbreHuffman AH_arbrehuffman(Statistiques stat) {
    ArbreHuffman arbre;
    arbre.statistiques=stat;
    AH_fixerfilsGauche(arbre,NULL);
    AH_fixerfilsDroit(arbre,NULL);
    return arbre;
}

int AH_obtenirOccurences(ArbreHuffman arbre){
    return arbre.statistiques.ponderation;
}

ArbreHuffman AH_fusionner(ArbreHuffman arbre1,ArbreHuffman arbre2) {
    ArbreHuffman res;
    Statistiques stat ;
    stat.caracter = NULL;
    stat.ponderation = S_obtenirPonderation(arbre1.statistiques)+S_btenirPonderation(arbre2.statistiques);
    res.statistiques= stat;
    if (AH_obtenirOccurences(arbre1)<AH_obtenirOccurences(arbre2)){
    AH_fixerfilsGauche(res,arbre1);
    AH_fixerfilsDroit(res,arbre2);
    }
    else {
        AH_fixerfilsGauche(res,arbre2);
        AH_fixerfilsDroit(res,arbre1);
    }
    return res;
}


void* AH_fixerFilsGauche(ArbreHuffman arbre,ArbreHuffman filsGauche) {
    arbre.filsGauche = filsGauche;
}

void* AH_fixerFilsDroit(ArbreHuffman arbre,ArbreHuffman filsDroit) {
    arbre.filsDroit = filsDroit;
}

ArbreHuffman AH_obtenirFilsGauche(ArbreHuffman arbre) {
    return arbre.filsGauche;
}

ArbreHuffman AH_obtenirFilsDroit(ArbreHuffman arbre) {
    return arbre.filsDroit;
}

bool AH_estVide(ArbreHuffman arbre) {
    return ((arbre.statistiques.caracter == "") && (arbre.statistiques.ponderation == 0));
}

bool AH_estFeuille(ArbreHuffman arbre) {
    return (AH_estVide(arbre.filsDroit) && AH_estVide(arbre.filsGauche));
}

bool AH_estPresent(ArbreHuffman arbre, char caractere) {
    if (arbre.statistiques.caracter == caractere) {
        return true;
    }
    else {
        return (AH_estPresent(AH_obtenirFilsDroit(arbre),caractere) || AH_estPresent(AH_obtenirFilsGauche(arbre),caractere));
    }
}