#ifndef  __ CODEBINAIRE__
#define __CODEBINAIRE__

typedef struct {
        char* bits;
}CodeBinaire;

CodeBinaire obtenirCodeBinaire();
bool estVide(CodeBinaire cb);
Bit obtenirIemeBit(CodeBinaire cd,int i); 
#endif