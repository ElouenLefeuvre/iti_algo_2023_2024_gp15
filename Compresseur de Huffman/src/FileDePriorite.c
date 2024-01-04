#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "FileDePriorite.h"
#include "ArbreHuffman.h"

bool FDP_estVide(FileDePriorite *fp) {
    return fp->longueur==0;
}

bool FDP_estVide_LCA(ListeChaineeArbre *lca) {
    return lca==NULL;
}

FileDePriorite FDP_fileDePriorite() {
    FileDePriorite file;
    file.debut = NULL;
    file.longueur = 0;
    return file;
}

void FDP_enfiler(FileDePriorite *file, ArbreHuffman arbre) {
    struct ListeChaineeArbre *temp1;
    struct ListeChaineeArbre *temp2;
    temp1 = file->debut;
    while (AH_obtenirPonderation(arbre) > AH_obtenirPonderation(temp2->arbre)) {
        temp1 = temp1->listeSuivante;
    }
    temp1->arbre = arbre;
    temp1->listeSuivante=temp2;
    while (!(FDP_estVide_LCA(temp1->listeSuivante))) {
        temp1 = temp1->listeSuivante;
    }
    file->longueur = file->longueur+1;
}

void FDP_defiler(FileDePriorite *file) {
    ListeChaineeArbre *temp;
    file->longueur = file->longueur - 1;
}

ArbreHuffman FDP_obtenirElement(FileDePriorite file, int i) {
    struct ListeChaineeArbre *temp;
    temp = file.debut;
    for (int j=1;j<i-1;j++) {
        temp = temp->listeSuivante;
    }
    return temp->arbre;
}

void FDP_nouvelleFile(FileDePriorite *file) {
    FDP_enfiler(file,*AH_fusionner(&(),&()));
    FDP_defiler(file);
    FDP_defiler(file);
}