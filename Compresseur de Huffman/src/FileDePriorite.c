#include<stdio.h>
#include<stdbool.h>
#include "FileDePriorite.h"

FileDePriorite filedePriorite(ArbreHuffman arbre) {
    FileDePriorite file;
    file.debut.arbre = arbre;
    file.debut.listeSuivante = NULL;
    file.fin = NULL;
    file.longueur = 1;
    return file;
}

void enfiler(FileDePriorite file, ArbreHuffman arbre) {
    ListeChaineeArbre temp1;
    ListeChaineeArbre temp2;
    temp1 = file.debut;
    temp2 = file.fin;
    while obtenirOccurences(arbre) > obtenirOccurences(temp2) {
        temp1 = temp1.listeSuivante;
        temp2 = temp2.listeSuivante;
    }
    temp1.arbre = arbre;
    temp1.listeSuivante=temp2;
    while not(estVide(temp1.listeSuivante)) {
        temp1 = temp1.listeSuivante;
    }
    file.fin = temp1;
    file.longueur = file.longueur+1;
}

void defiler(FileDePriorite file) {
    ListeChaineeArbre temp;
    temp = file.fin;
    file.fin = file.fin.listeSuivante;
    file.longueur = file.longueur - 1;
    free(temp);
}

Statistiques obtenirElement(FileDePriorite file, int i) {
    temp = file.debut;
    for {j=1;j<i-1;j++} {
        temp = temp.listeSuivante;
    }
    return temp.arbre;
}

void nouvelleFile(FileDePriorite file) {
    enfiler(file,ArbreHuffman.fusionner((file.fin.arbre),(file.fin.arbre.listeSuivante)));
    defiler(file);
    defiler(file);
}