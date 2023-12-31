#include<stdio.h>
#include<stdbool.h>
#include "FileDePriorite.h"

FileDePriorite FDP_filedePriorite() {
    FileDePriorite file;
    file.debut.arbre = NULL;
    file.debut.listeSuivante = NULL;
    file.fin = NULL;
    file.longueur = 0;
    return file;
}

void FDP_enfiler(FileDePriorite file, ArbreHuffman arbre) {
    ListeChaineeArbre temp1;
    ListeChaineeArbre temp2;
    temp1 = file.debut;
    temp2 = file.fin;
    while (AH_obtenirOccurences(arbre) > AH_obtenirOccurences(temp2)) {
        temp1 = temp1.listeSuivante;
        temp2 = temp2.listeSuivante;
    }
    temp1.arbre = arbre;
    temp1.listeSuivante=temp2;
    while (not(FDP_estVide(temp1.listeSuivante))) {
        temp1 = temp1.listeSuivante;
    }
    file.fin = temp1;
    file.longueur = file.longueur+1;
}

void FDP_defiler(FileDePriorite file) {
    ListeChaineeArbre temp;
    temp = file.fin;
    file.fin = file.fin.listeSuivante;
    file.longueur = file.longueur - 1;
    free(temp);
}

Statistiques FDP_obtenirElement(FileDePriorite file, int i) {
    temp = file.debut;
    for {j=1;j<i-1;j++} {
        temp = temp.listeSuivante;
    }
    return temp.arbre;
}

void FDP_nouvelleFile(FileDePriorite file) {
    FDP_enfiler(file,AH_fusionner((file.fin.arbre),(file.fin.arbre.listeSuivante)));
    FDP_defiler(file);
    FDP_defiler(file);
}