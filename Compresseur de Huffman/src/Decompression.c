#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Ensemble.h"
#include"FileDePriorite.h"
#include"Statistiques.h"
#include"ArbreHuffman.h"

FILE DECOMP_decompresser(char[] nomFichierHuffman) {
    return 0;
}

FileDePriorite DECOMP_obtenirFileDePriorite(){
    return 0;
}

Ensemble DECOMP_obtenirStatistiques(char nomfichier[]){
    Ensemble ens = initialiserEnsemble(sizeof(Statistiques));
    FILE *fichier = NULL;
    char car;
    char entier;
    car = '0';
    Statistiques stat;
    fichier = fopen(nomfichier,"r");
    if (fichier != NULL){ 
        while(car != '/') {
            car = fgetc(fichier);
            if (car!='/') { // il prend le carac / si je vérifie pas de nouveau
                entier = fgetc(fichier);
                stat = statistique(car,atoi(&entier));
                ajouter(&ens,&stat);
            }
            
        }
    }
    else {
        printf("Impossible d'ouvrir le fichier  : %s\n", nomfichier);
    }

    return ens;
}

ArbreHuffman DECOMP_creerArbreHuffman(Statistiques stat) {
    return arbrehuffman(stat);
}

FileDePriorite DECOMP_insererArbre(FileDePriorite file, ArbreHuffman arbre) {
    enfiler(arbre,file);
    return file;
}

ArbreHuffman DECOMP_creerArbre(Statistiques stats) {
    return arbrehuffman(stats);
}