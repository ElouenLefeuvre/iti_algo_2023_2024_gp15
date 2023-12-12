#ifndef  __ CODEBINAIRE__
#define __CODEBINAIRE__

typedef struct {
        char* bits;
}CodeBinaire;

CodeBinaire obtenirCodeBinaire();
bool estVide(CodeBinaire cb);
int obtenirIemeBit(CodeBinaire cd,int i); 
#endif