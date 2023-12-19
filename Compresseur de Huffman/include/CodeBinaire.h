#ifndef  __ CODEBINAIRE__
#define __CODEBINAIRE__
#include <stdbool.h>;


typedef enum { BITA0, BITA1} Bit;

typedef struct {
        char* bits;
}CodeBinaire;

CodeBinaire obtenirCodeBinaire();
bool estVide(CodeBinaire cb);
Bit obtenirIemeBit(CodeBinaire cd,int i); 
#endif
