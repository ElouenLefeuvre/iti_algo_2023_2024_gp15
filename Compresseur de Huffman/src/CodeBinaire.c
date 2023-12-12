#include<stdio.h>
#include<stdbool.h>
#include "CodeBinaire.h"
#include "ArbreHuffman.h"
#include <string.h>

CodeBinaire obtenirCodeBinaire(ArbreHuffman arbre, char car) {
    CodeBinaire result;
    CodeBinaire one;
    CodeBinaire zero;
    one.bits="1";
    zero.bits= "0";

    if (estFeuille(arbre)) {
        result.bits= "";
        return result;
    }
    else{
        if(estPresent(obtenirFilsGauche(arbre),car)){
            return concat(zero,obtenirCodeBinaire(obtenirFilsGauche(arbre),car));
        }
        else{
            return concat(one,obtenirCodeBinaire(obtenirFilsDroit(arbre),car));
        }

    }
}


bool estVide(CodeBinaire cb) {
    return cb.bits == "";
}

int obtenirIemeBit(CodeBinaire cb,int i) {
    return cb.bits[i];
}


CodeBinaire concat(CodeBinaire cb1, CodeBinaire cb2) {
    strcat(cb1.bits,cb2.bits);
    return cb1;
}

void ajouterbit(CodeBinaire cb, int n, int bit);
void supprimerBit(CodeBinaire cb, int n);

