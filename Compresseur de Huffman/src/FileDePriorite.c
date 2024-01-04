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
    ListeChaineeArbre *temp;
    ListeChaineeArbre *temp2;
    FileDePriorite *file_temp;
    temp = file->debut;
    if (FDP_estVide_LCA(temp->listeSuivante)) {
        temp->listeSuivante = malloc(sizeof(ListeChaineeArbre));
        temp->listeSuivante->arbre = arbre;
        temp->listeSuivante->listeSuivante = NULL;
        file->longueur = file->longueur+1;
    }
        else {
            if (AH_obtenirPonderation(arbre) < AH_obtenirPonderation(temp->arbre)) {
            file_temp = file;
            file_temp->debut = file_temp->debut->listeSuivante;
            FDP_enfiler(file_temp,arbre);
            file->debut->listeSuivante=file_temp->debut;
            }
                else {
                    temp2 = malloc(sizeof(ListeChaineeArbre));
                    temp2 = temp;
                    temp->arbre = arbre;
                    temp->listeSuivante=temp2;
                    file->longueur = file->longueur+1;
                }
        }
}

void FDP_defiler(FileDePriorite *file) {
    ListeChaineeArbre *temp = file->debut;
    int i = 0;
    file->longueur = file->longueur - 1;
    while(i<file->longueur-1){
        i++;
        temp = temp->listeSuivante;
    }
    free(temp);


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
    ListeChaineeArbre *temp = file->debut;
    while(!(temp->listeSuivante->listeSuivante!=NULL)){
        temp = temp->listeSuivante;
    }
    FDP_enfiler(file,*AH_fusionner(&(temp->arbre),&(temp->listeSuivante->arbre)));
    FDP_defiler(file);
    FDP_defiler(file);
    free(temp);
}