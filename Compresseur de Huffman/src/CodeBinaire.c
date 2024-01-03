#include <stdio.h>
#include <stdbool.h>
#include "CodeBinaire.h"
#include <stdlib.h>
#include <string.h>
#include "ArbreHuffman.h"



bool CB_estVide(CodeBinaire cb) {
    int  taille = cb.taille;
    return taille == 0;
}

CodeBinaire CB_creerCodeBinaire(int taille) {
    CodeBinaire code;
    code.bits = malloc(taille * sizeof(Bit));
    code.taille = taille;
    for (size_t i = 0; i < 4; ++i) {
        code.bits[i] = BITA0;
    }
    return code;
}

void CB_remplirCodeBinaire(CodeBinaire* code, const char* chaine) {
    int longueurChaine = strlen(chaine);


    if (longueurChaine != code->taille) {
        fprintf(stderr, "Erreur : La longueur de la chaîne ne correspond pas à la taille du CodeBinaire.\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < code->taille; ++i) {
        code->bits[i] = (chaine[i] == '0') ? BITA0 : BITA1;
    }
}


void CB_libererCodeBinaire(CodeBinaire* code) {
    free(code->bits);
    code->taille = 0;
}

Bit CB_obtenirIemeBit(CodeBinaire code,int i) {
    if (i < code.taille) {
        return code.bits[i];
    } else {
        fprintf(stderr, "Erreur : Indice hors limites.\n");
        exit(EXIT_FAILURE);
    }
}


CodeBinaire CB_concatener(const CodeBinaire* code1, const CodeBinaire* code2) {
    CodeBinaire resultat;
    resultat.taille = code1->taille + code2->taille;
    resultat.bits = malloc(resultat.taille * sizeof(Bit));

    for (size_t i = 0; i < code1->taille; ++i) {
        resultat.bits[i] = code1->bits[i];
    }

    for (size_t i = 0; i < code2->taille; ++i) {
        resultat.bits[code1->taille + i] = code2->bits[i];
    }

    return resultat;
}

char* CB_codeBinaireToStr(const CodeBinaire* code) {
    char* str = malloc((code->taille + 1) * sizeof(char));  
    for (int i = 0; i < code->taille; ++i) {
        str[i] = (code->bits[i] == BITA0) ? '0' : '1';
    }
    str[code->taille] = '\0'; 
    return str;
}

CodeBinaire CB_cbOfCaracFromAH(ArbreHuffman arbre, char car){
    //JE manipule en CDC et puis je met tout en CodeBinaire
    char * cb = CB_cbOfCarac(arbre, car);
    int longueur = strlen(cb);
    CodeBinaire result = CB_creerCodeBinaire(longueur);
    CB_remplirCodeBinaire(&result,cb);
    return result;

}
char* CB_cbOfCarac(ArbreHuffman arbre, char car){
    
    if(AH_estFeuille(arbre)){
        return "0";
    }
    return obtenirCodeBinaireR(arbre,car);
}


char* obtenirCodeBinaireR(ArbreHuffman arbre,char car){
    if(AH_estFeuille(arbre)){
        return "";
    }
    if(AH_estPresent(AH_obtenirFilsGauche(&arbre),car) ){
        return strcat("0",obtenirCodeBinaireR(*AH_obtenirFilsGauche(&arbre),car));
    }
    else{
        return strcat("1",obtenirCodeBinaireR(*AH_obtenirFilsDroit(&arbre),car));
    }
}