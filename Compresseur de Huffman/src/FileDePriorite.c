#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "FileDePriorite.h"
#include "ArbreHuffman.h"

bool FDP_estVide(FileDePriorite *fp) {
    return fp->longueur==0;
}

bool FDP_estVide_LCA(Noeud *lca) {
    return lca==NULL;
}

FileDePriorite FDP_fileDePriorite() {
    FileDePriorite file;
    file.debut = NULL;
        file.longueur = 0;
    return file;
}

void FDP_enfiler(FileDePriorite *file,ArbreHuffman* arbre) {
    Noeud* noeud = FDP_createNoeud(arbre);
    if (FDP_estVide(file)) {  
        file->debut=noeud;
        noeud->suivant=NULL;
        file->longueur++;
    }
    else {
        int positionToInsert = trouverIndicePourInsere(arbre, file);
        if (positionToInsert == 0) {
            noeud->suivant = file->debut;
            file->debut = noeud;
        } else {
            Noeud *tmp = file->debut;
            for (int i = 0; i < positionToInsert - 1; i++) {
                tmp = tmp->suivant;
            }
            noeud->suivant = tmp->suivant;
            tmp->suivant = noeud;
        }
        file->longueur++;
    }
}

Noeud* FDP_createNoeud(ArbreHuffman* arbreOfLCA){
    Noeud* noeud = malloc(sizeof(Noeud));
    noeud->arbre=*arbreOfLCA;
    noeud->suivant=NULL;
    return noeud;
}

void FDP_afficherFileDEPriorite(FileDePriorite* file) {
    Noeud *actuel = file->debut;
    printf("la liste est: \n");
    
    while (actuel != NULL) {
        AH_afficherArbre(&actuel->arbre);
        printf("->");
        actuel = actuel->suivant;
    }
    if(actuel == NULL) printf("NULL");
}

//void fixerNoeud(FileDePriorite* file,Noeud* noeud, int position){
//    Noeud* tmp= file->debut;
//    for(int i=0;i<position-1;i++){       
//        tmp= tmp->suivant;
//    }
//    Noeud* tmp1= tmp->suivant;
//    tmp->suivant=noeud;
//    noeud->suivant=tmp1;
//}

int trouverIndicePourInsere(ArbreHuffman* arbre,FileDePriorite* file){
    Noeud *tmp = file->debut;
    int ponderationArbre = AH_obtenirPonderation(*arbre);
    int result = 0;

    while (tmp != NULL && AH_obtenirPonderation(tmp->arbre) > ponderationArbre) {
        tmp = tmp->suivant;
        result++;
    }

    return result;
}

void FDP_defiler(FileDePriorite *file){
        if (!FDP_estVide(file)) {
        Noeud *noeudActuel = file->debut;
        Noeud *noeudPrecedent = NULL;

        // Parcourir la file jusqu'au dernier élément
        while (noeudActuel->suivant != NULL) {
            noeudPrecedent = noeudActuel;
            noeudActuel = noeudActuel->suivant;
        }

        // Si la file contient plus d'un élément
        if (noeudPrecedent != NULL) {
            noeudPrecedent->suivant = NULL;
        } else {
            // Si la file ne contient qu'un seul élément
            file->debut = NULL;
        }

        free(noeudActuel);
        file->longueur--;
    }
}

// void FDP_defilerR(FileDePriorite *file) {
//     ListeChaineeArbre *temp = file->debut; 
//     if (FDP_estVide_LCA(temp->listeSuivante)){
//         free(temp);
//         file->debut = NULL;
//     }
//     else{
//         file->debut = temp->listeSuivante;
//         free(temp);
//         FDP_defilerR(file);
//     }
// }
// void FDP_defiler(FileDePriorite *file){
//     FDP_defilerR(file);
//     file->longueur = file->longueur-1;
// }

ArbreHuffman FDP_obtenirElement(FileDePriorite file, int i) {
    Noeud* temp;
    temp = file.debut;
    for (int j=1;j<i;j++) {
         temp = temp->suivant;
     }
    return temp->arbre;
} 

void FDP_nouvelleFile(FileDePriorite* file) {
   if (file->longueur < 2) {
        return;
    }
    int i = file->longueur;
    ArbreHuffman arbre1 = FDP_obtenirElement(*file, i);
    ArbreHuffman arbre2 = FDP_obtenirElement(*file, i - 1);
    
    FDP_defiler(file);
    FDP_defiler(file);

    FDP_enfiler(file, AH_fusionner(&arbre1, &arbre2));
}