#include "Octet.h"
#include <stdio.h>
#include <stdlib.h>
#include "CodeBinaire.h"
#include "Statistiques.h"
#include "ArbreHuffman.h"
#include "FileDePriorite.h"
#include "TableDeCodage.h"
#define TAILLE_MAX 1000 


FileDePriorite DECOMP_fileFromFILE(FileDePriorite fp,char caracter,int ponderation){
    Statistiques stat= S_statistique(caracter,ponderation); 
    ArbreHuffman* arbre= AH_arbreDeHuffman(stat);
    FDP_enfiler(&fp,arbre);
    return fp;
}


ArbreHuffman DECOMP_arbrePrincipale(FileDePriorite fp){
    
    while(fp.longueur != 1){
        ArbreHuffman arbre1 = FDP_obtenirElement(fp, fp.longueur);
        ArbreHuffman arbre2 = FDP_obtenirElement(fp, fp.longueur - 1);
        FDP_defiler(&fp);
        FDP_defiler(&fp);
        ArbreHuffman* arbreFusionne1 = AH_fusionner(&arbre1,&arbre2);
        ArbreHuffman* copy = copierArbreHuffman(arbreFusionne1);
        FDP_enfiler(&fp, copy);
    }

    return FDP_obtenirElement(fp,0);
}


FILE* DECOMP_decompresser(const char* fileName){
    FILE *file = fopen(fileName, "r");
    char tailleStr[TAILLE_MAX] = "";
    int taille = 1;

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    
    if(fgets(tailleStr, TAILLE_MAX, file) != NULL){
        taille= atoi(tailleStr);
    }

    char c;
    FileDePriorite fp= FDP_fileDePriorite();
    while((c = fgetc(file)) != '\n'){ 
        char statCaracter = c;      
        c= fgetc(file);
        int statPonderation = atoi(&c);
        fp = DECOMP_fileFromFILE(fp,statCaracter,statPonderation);
    }

    const char *decompressed = "decompressedFile.txt";
    FILE* decompresssedFile = fopen(decompressed,"w");
    ArbreHuffman arbrePrincipale = DECOMP_arbrePrincipale(fp);
    ArbreHuffman *tmp = &arbrePrincipale;
    char car;
    while((car = fgetc(file)) != EOF){ 
        if(car== '.'){
            continue;
        }

        else{
            if(car== '0') tmp = tmp->filsGauche;
            else if (car =='1') tmp=tmp->filsDroit;
        }   
        if (AH_estFeuille(*tmp)){
            fprintf(decompresssedFile,"%c",AH_obtenirCaracter(*tmp));
            tmp = &arbrePrincipale;
        
        }
    }
    fclose(file);
    return NULL;
}




