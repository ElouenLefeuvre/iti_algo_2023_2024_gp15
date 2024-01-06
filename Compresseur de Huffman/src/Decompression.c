#include <string.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include"Ensemble.h"
#include"FileDePriorite.h"
#include"Statistiques.h"
#include"ArbreHuffman.h"


ArbreHuffman* DECOMP_creerArbreHuffman(Statistiques stat) {
    return AH_arbreDeHuffman(stat);
}

FileDePriorite DECOMP_insererArbre(FileDePriorite* file, ArbreHuffman* arbre) {
    FDP_enfiler(file,arbre);
    return *file;
}


Ensemble DECOMP_obtenirStatistiques(char nomfichier[]){
    Ensemble ens = E_initialiserEnsemble(sizeof(Statistiques));
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
                stat = S_statistique(car,atoi(&entier));
                E_ajouter(&ens,&stat);
            }
            
        }
    }
    else {
        printf("Impossible d'ouvrir le fichier  : %s\n", nomfichier);
    }
    int err = fclose(fichier);
    if (err!=0) {
        printf("Erreur de fermeture de fichier");  
        }
    return ens;
}

FileDePriorite DECOMP_obtenirFileDePriorite(Ensemble stats){
    FileDePriorite file;
    Ensemble ens = E_initialiserEnsemble(sizeof(ArbreHuffman));

    file = FDP_fileDePriorite();
    for (size_t i=1;i<stats.taille;i++) {
        E_ajouter(&ens, DECOMP_creerArbreHuffman(*(Statistiques*)stats.elements[i]));
    }
    for (size_t i=1;i<ens.taille;i++) {
        FDP_enfiler(&file,ens.elements[i]);
    }
    while(file.longueur>1) {
        FDP_nouvelleFile(&file);
    }
    return file;
}


FILE* DECOMP_decompresser(char nomFichierHuffman[]) {
    Ensemble stats_fic = E_initialiserEnsemble(sizeof(Statistiques));
    FileDePriorite file;
    ArbreHuffman arbre;
    ArbreHuffman* temp;
    char digit;
    FILE *fictexte=NULL;
    FILE *fichier_h=NULL;

    stats_fic = DECOMP_obtenirStatistiques(nomFichierHuffman);
    file = DECOMP_obtenirFileDePriorite(stats_fic);
    arbre = FDP_obtenirElement(file,1);
    while(fscanf(fichier_h, "%c", &digit) != EOF) {
        fichier_h = fopen(nomFichierHuffman, "r");
        temp = &arbre;
        while(!(AH_estFeuille(*temp))) {
            digit = fgetc(fichier_h);
            if (digit== '0') {
                temp = AH_obtenirFilsGauche(temp);
                }
            else {
                temp = AH_obtenirFilsDroit(temp);
            }
        
        }
        int err = fclose(fichier_h);
        if (err!=0) {
        printf("Erreur de fermeture du fichier_h");
        return NULL;
        }

        fictexte = fopen(nomFichierHuffman,"a");
        fputc(S_obtenirCaractere(temp->statistiques), fictexte);

        int err2 = fclose(fictexte);
        if (err2!=0) {
        printf("Erreur de fermeture du fichier texte");  
        return NULL;
        }
    }
    return fictexte;
}

