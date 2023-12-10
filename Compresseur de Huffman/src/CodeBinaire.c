#include<stdio.h>
#include<stdbool.h>
#include "CodeBinaire.h"
#include "ArbreHuffman.h"

CodeBinaire obtenirCodeBinaire(ArbreHuffman arbre, char car){
    CodeBinaire result;
    if (estFeuille(arbre)) {
        result.bits= "";
        return result;
    }
    else{
        if(estPresent(obtenirFilsGauche(arbre),car){
            return "1" + obtenirCodeBinaire()

        })

    }
    

}
bool estVide(CodeBinaire cb);
void ajouterbit(CodeBinaire cd, int n, int bit);
void supprimerBit(CodeBinaire cd, int n);
int obtenirIemeBit(CodeBinaire cd,int i); 