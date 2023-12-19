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
    Ensemble ens = E_initialiserEnsemble(sizeof(char));
    FILE *fic = NULL;
    char car;
    char entier;
    car = '0';
    fic = fopen(nomfichier,"r");
   if (fic != NULL){ 
        while(car != '/') {
            car = fgetc(fic);
            if ((car!='/') && (!(E_estPresent(ens, car)))) {
                entier = fgetc(fic);
                E_ajouter(&ens,&stat);
            }
            
        }
    }
    else {
        printf("Impossible d'ouvrir le fichier  : %s\n", nomfichier);
    }

    return ens;}


Ensemble COMP_creerStatistiques(char nomFichier[], Ensemble ensC){
    Ensemble ensStats = E_initialiserEnsemble(sizeof(Statistiques));
    int nbOcc;

}

FileDePriorite COMP_creerFileDePriorite(char nomFichier[]){
    FileDePriorite file;
    Ensemble ensC = E_initialiserEnsemble(sizeof(char));
    Ensemble ens = E_initialiserEnsemble(sizeof(Statistiques));
    ensC = COMP_obtenirCaracteres(nomFichier);
    ensS = COMP_creerStatistiques(nomFichier, ensC);
    file = FDP_fileDePriorite();
    int i;
    for(i=0; i < ensS.taille; i++){
        Statistiques stats;
        stats = &E_obtenirIemeElement(&ensS, i);
        FDP_enfiler(file, AH_arbrehuffman(stats));
    }
    while ((FDP_obtenirLongueur(file)) > 1){
        FDP_nouvelleFile(file);
    }
    return file;
}


TableDeCodage COMP_creerTableDeCodage(ArbreHuffman arbre){
    return TDC_obtenirTableDeCodage(arbre);
}

fichierBinaire COMP_compresser(char nomFichier[]){
    FILE *fic = NULL;
    FILE *fc = NULL;
    char car;
    FileDePriorite file;
    TableDeCodage temp;
    TableDeCodage tab;
    ArbreHuffman ArbreHuffman;
    file = COMP_creerFileDePriorite(nomFichier);
    table = COMP_creerTableDeCodage(FDP_obtenirElement(file));
    fic = fopen(nomFichier, 'r');
    fc = fopen(nomFichier, 'w');
    if (fic != NULL){ 
            while(car != '/') {
                car = fgetc(fic);
                if ((car!='/')) {
                    temp = table;
                    FB_ecrireOctet(fc, O_encoder(CB_obtenirCodeBinaire(temp,FB_lireCaractere(fic))))
                }
                
            }
        }
        else {
            printf("Impossible d'ouvrir le fichier  : %s\n", nomfichier);
        }

        return fc;}
