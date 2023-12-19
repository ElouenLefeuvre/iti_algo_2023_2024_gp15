#ifndef  __ CODEBINAIRE__
#define __CODEBINAIRE__
#include <stdbool.h>;
#include "ArbreHuffman.h"


typedef enum { BITA0, BITA1} Bit;

typedef struct {
        char* bits;
}CodeBinaire;

CodeBinaire obtenirCodeBinaire(ArbreHuffman arbre, char car);
bool estVide(CodeBinaire cb);
Bit obtenirIemeBit(CodeBinaire cd,int i); 
#endif
