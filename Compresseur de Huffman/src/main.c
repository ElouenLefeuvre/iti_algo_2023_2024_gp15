#include "Octet.h"
#include "FileDePriorite.h"


#include "octet.h"
#include <stdio.h>
#include <stdlib.h>
#include "CodeBinaire.h"
#include "Statistiques.h"
#include "ArbreHuffman.h"
#include "FileDePriorite.h"
#include "TableDeCodage.h"




FILE* compresser(const char* fileName){
    
    FILE* file = fopen(fileName,"r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }
    FileDePriorite fp= FDP_fileDePriorite();

    int occurrences[256] = {0};
    int caracteresSansRepetition[256] = {0};
    int nbCaracteresSansRepetition = 0;
    

    int caractere;
    while ((caractere = fgetc(file)) != EOF) {
        occurrences[caractere]++;
        if (occurrences[caractere] == 1) {
            caracteresSansRepetition[nbCaracteresSansRepetition++] = caractere;
        }
    }

    for (int i = 0; i < nbCaracteresSansRepetition; i++) {
        Statistiques stat = S_statistique(caracteresSansRepetition[i],occurrences[caracteresSansRepetition[i]]);
        ArbreHuffman* arbre = AH_arbreDeHuffman(stat);
        FDP_enfiler(&fp,arbre);
    }
    
    while(fp.longueur != 1){
        ArbreHuffman arbre1 = FDP_obtenirElement(fp, fp.longueur);
        ArbreHuffman arbre2 = FDP_obtenirElement(fp, fp.longueur - 1);
        FDP_defiler(&fp);
        FDP_defiler(&fp);
        ArbreHuffman* arbreFusionne1 = AH_fusionner(&arbre1,&arbre2);
        ArbreHuffman* copy = copierArbreHuffman(arbreFusionne1);
        FDP_enfiler(&fp, copy);
    }


    ArbreHuffman ArbreFinal = FDP_obtenirElement(fp,0);
    TableDeCodage* tableDeCodageFinale = TDC_obtenirTableDeCodage();
    for (int i=0 ; i<nbCaracteresSansRepetition;i++){
        char c = caracteresSansRepetition[i];
        CodeBinaire cb = CB_CbFromAH(&ArbreFinal,c);
        TDC_ajouter(tableDeCodageFinale,c,&cb);
    }
    
    const char *filename = "compressedFile.txt";
    FILE *compressedFile = fopen(filename, "w");
    if (compressedFile == NULL) {
        fprintf(stderr, "Impossible d'ouvrir le fichier %s en écriture.\n", filename);
    }


    fseek(file, 0, SEEK_SET);
    Octet firstOctet = O_creerOctet();
    char car;
    while ((car = fgetc(file)) != EOF) {
        if(!O_currentisFull()){
            CodeBinaire* code = TDC_obtenirCode(*tableDeCodageFinale,car);
            firstOctet = O_encoder(firstOctet,*code);
            
        }
        else{
            printf("octet is is %s\n", O_octetToStr(&firstOctet));
            fprintf(compressedFile,"%s.",O_octetToStr(&firstOctet));
            firstOctet = O_creerOctet();
            printf("J'ai creer un nv octet\n");
            CodeBinaire* code = TDC_obtenirCode(*tableDeCodageFinale,car);
            firstOctet =O_encoder(firstOctet,*code);
        }
    }
    printf("octet is is %s\n", O_octetToStr(&firstOctet));
    fprintf(compressedFile,"%s",O_octetToStr(&firstOctet));
    fclose(file);   

    return compressedFile;

}



int main(){
    compresser("src/file.txt");
}


