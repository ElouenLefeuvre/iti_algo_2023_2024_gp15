#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Ensemble.h"

FILE decompresser(char[] nomFichierHuffman) {
    return 0;
}

FileDePriorite obtenirFileDePriorite(){
    return 0;
}

Ensemble obtenirStatistiques(char nomfichier[]){
    Ensemble ens = initialiserEnsemble(sizeof(Statistiques));
    FILE *fichier = NULL;
    char car;
    char entier;
    fichier = fopen(nomfichier,"r");
    if (fichier != NULL){ 
    }
    else {
        printf("Impossible d'ouvrir le fichier  : %s\n", nomfichier);
    }
    while(not(EOF) | car = "/") {
            car = fgetc(fichier);
            entier = fgetc(fichier);
            ajouter(&ens,&(statistique(car,entier)));
    }

    return ens;
}

ArbreHuffman creerArbreHuffman(Statistiques stat) {
    return arbrehuffman(stat);
}

FileDePriorite insererArbre(FileDePriorite file, ArbreHuffman arbre) {
    enfiler(arbre,file);
    return file;
}

ArbreHuffman creerArbre(Statistiques stats) {
    return arbrehuffman(stats);
}