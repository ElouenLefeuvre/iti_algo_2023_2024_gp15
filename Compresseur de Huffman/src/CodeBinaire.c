#include<stdio.h>
#include<stdbool.h>
#include "CodeBinaire.h"
#include "ArbreHuffman.h"
#include <string.h>

CodeBinaire CB_obtenirCodeBinaire(ArbreHuffman arbre, char car) {
    CodeBinaire res;
    if (AH_estFeuille(arbre)){
        res.bits = "0";
        return res;
    }
    else{
        return CB_obtenirCodeBinaireR(arbre,car);
    }
}

CodeBinaire CB_obtenirCodeBinaireR(ArbreHuffman arbre, char car) {
    CodeBinaire result;
    CodeBinaire one;
    CodeBinaire zero;
    Bit one= BITA1;
    Bit zero= BITA0;

    if (AH_estFeuille(arbre)) {
        result.bits= "";
        return result;
    }
    else{
        if(AH_estPresent(AH_obtenirFilsGauche(arbre),car)){
            return CB_concat(zero,CB_obtenirCodeBinaireR(AH_obtenirFilsGauche(arbre),car));
        }
        else{
            return CB_concat(one,CB_obtenirCodeBinaireR(AH_obtenirFilsDroit(arbre),car));
        }

    }
}


bool CB_estVide(CodeBinaire cb) {
    return cb.bits == "";
}

Bit CB_obtenirIemeBit(CodeBinaire cb,int i) {
    switch (cb.bits[i]){
        case '1': return BITA1;
        case '0': return BITA0;
    }
}


CodeBinaire CB_concat(CodeBinaire cb1, CodeBinaire cb2) {
    strcat(cb1.bits,cb2.bits);
    return cb1;
}

