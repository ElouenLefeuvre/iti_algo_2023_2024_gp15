#ifndef  __CODEBINAIRE__
#define __CODEBINAIRE__
#include <stdbool.h>
#include "ArbreHuffman.h"


typedef enum { BITA0, BITA1} Bit;

typedef struct {
    Bit* bits;         // Pointeur vers le tableau de bits
    int taille;     // Taille du tableau (nombre de bits)
} CodeBinaire;

bool CB_estVide(CodeBinaire cb);
CodeBinaire CB_creerCodeBinaire(int taille); 
void CB_libererCodeBinaire(CodeBinaire* code);
Bit CB_obtenirIemeBit(CodeBinaire code,int i);
CodeBinaire CB_concatener(const CodeBinaire* code1, const CodeBinaire* code2);
char* CB_codeBinaireToStr(const CodeBinaire* code);
void CB_remplirCodeBinaire(CodeBinaire* code, const char* chaine);
CodeBinaire CB_cbOfCaracFromAH(ArbreHuffman arbre, char car);
char* CB_cbOfCarac(ArbreHuffman arbre, char car);
char* obtenirCodeBinaireR(ArbreHuffman arbre,char car);
#endif
