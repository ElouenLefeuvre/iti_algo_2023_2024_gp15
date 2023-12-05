#include<stdio.h>
#include "ArbreDeHuffman.h"
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
    stat.ponderation = obtenirPonderation(arbre1)+obtenirPonderation(arbre2);
    result.statistiques= stat;
    fixerfilsGauche(result,arbre1);
    fixerfilsDroit(result,arbre2);
    return result;
}

int obtenirPonderation(ArbreHuffman arbre){
    return arbre.statistiques.ponderation;
}


void* fixerFilsGauche(ArbreHuffman arbre,ArbreHuffman filsGauche){
    arbre.*filsGauche = filsGauche;
}

void* fixerFilsDroit(ArbreHuffman arbre,ArbreHuffman filsDroit){
    arbre.*filsDroit = filsDroit;
}

ArbreHuffman obtenirFilsGauche(ArbreHuffman arbre){
    return arbre.*filsGauche;
}

ArbreHuffman obtenirFilsDroit(ArbreHuffman arbre){
    return arbre.*filsDroit;
}

Boolean estVide(ArbreHuffman arbre){
    return ((arbre.statistiques.caracter == '') && (arbre.statistiques.ponderation == 0));
}

Boolean estFeuille(ArbreHuffman arbre){
    return (estVide(arbre.*filsDroit) && estVide(arbre.*filsGauche));
}

Boolean estPresent(ArbreHuffman arbre, char caractere){
    if (arbre.statistiques.caracter == caractere) {
        return True;
    }
    else {
        return (estPresent(obtenirFilsDroit(arbre)) || estPresent(obtenirFilsGauche(arbre)))
    }
}