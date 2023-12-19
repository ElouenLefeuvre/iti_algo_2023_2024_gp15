#ifndef  __ CODEBINAIRE__
#define __CODEBINAIRE__
#include <stdbool.h>;


typedef enum { BITA0, BITA1} Bit;

typedef struct {
        char* bits;
}CodeBinaire;

CodeBinaire CB_obtenirCodeBinaire();
bool CB_estVide(CodeBinaire cb);
Bit CB_obtenirIemeBit(CodeBinaire cd,int i); 
CodeBinaire CB_concat(CodeBinaire cb1, CodeBinaire cb2);
#endif