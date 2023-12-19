#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Ensemble.h"
#include"FileDePriorite.h"
#include"Statistiques.h"
#include"ArbreHuffman.h"
#include"TableDeCodage.h"


ArbreHuffman COMP_creerArbre(Statistiques stats){
    return AH_arbrehuffman(stats);
}

FileDePriorite COMP_insererArbre(FileDePriorite file, ArbreHuffman arbre){
    return FDP_enfiler(arbre,file);
}

int COMP_obtenirOccurences(char c){
    return S_obtenirOccurence(car);
}

Ensemble COMP_obtenirCaracteres(char nomFichier[]){
    Ensemble ens = initialiserEnsemble(sizeof(char));
    FILE *fic = NULL;
    char car;
    char entier;
    car = '0';
    fic = fopen(nomfichier,"r");
   if (fic != NULL){ 
        while(car != '/') {
            car = fgetc(fic);
            if ((car!='/') && (!(estPresent(ens, car)))) {
                entier = fgetc(fic);
                ajouter(&ens,&stat);
            }
            
        }
    }
    else {
        printf("Impossible d'ouvrir le fichier  : %s\n", nomfichier);
    }

    return ens;}


Ensemble COMP_creerStatistiques(char nomFichier[], Ensemble ensC){
    Ensemble ensStats = initialiserEnsemble(sizeof(Statistiques));
    int nbOcc;

}

FileDePriorite COMP_creerFileDePriorite(char nomFichier[]){
    FileDePriorite file;
    Ensemble ensC = initialiserEnsemble(sizeof(char));
    Ensemble ens = initialiserEnsemble(sizeof(Statistiques));
    ensC = obtenirCaracteres(nomFichier);
    ensS = creerStatistiques(nomFichier, ensC);
    file = creerFileDePriorite();
    int i;
    for(i=0; i < ensS.taille; i++){
        Statistiques stats;
        stats = &obtenirIemeElement(&ensS, i);
        enfiler(file, arbrehuffman(stats));
    }
    while ((FileDePriorite.obtenirLongueur(file)) > 1){
        nouvelleFile(file);
    }
    return file;
}


TableDeCodage COMP_creerTableDeCodage(ArbreHuffman arbre){
    return obtenirTableDeCodage(arbre);
}

fichierBinaire COMP_compresser(char nomFichier[]){
    FILE *fic = NULL;
    FILE *fc = NULL;
    char car;
    FileDePriorite file;
    TableDeCodage temp;
    TableDeCodage tab;
    ArbreHuffman ArbreHuffman;
    file = creerFileDePriorite(nomFichier);
    table = creerTableDeCodage(FDP_obtenirElement(file));
    fic = fopen(nomFichier, 'r');
    fc = fopen(nomFichier, 'w');
    if (fic != NULL){ 
            while(car != '/') {
                car = fgetc(fic);
                if ((car!='/')) {
                    temp = table;
                    ecrireOctet(fc, encoder(obtenirCodeBinaire(temp,lireCaractere(fic))))
                }
                
            }
        }
        else {
            printf("Impossible d'ouvrir le fichier  : %s\n", nomfichier);
        }

        return fc;}
