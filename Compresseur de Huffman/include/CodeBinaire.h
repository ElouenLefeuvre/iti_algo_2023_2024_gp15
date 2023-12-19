#ifndef  __ CODEBINAIRE__
#define __CODEBINAIRE__
#include <stdbool.h>;
#include "ArbreHuffman.h"


typedef enum { BITA0, BITA1} Bit;

typedef struct {
        char* bits;
}CodeBinaire;

<<<<<<< HEAD
CodeBinaire obtenirCodeBinaire(ArbreHuffman arbre, char car);
bool estVide(CodeBinaire cb);
Bit obtenirIemeBit(CodeBinaire cd,int i); 
#endif
=======
CodeBinaire CB_obtenirCodeBinaire();
bool CB_estVide(CodeBinaire cb);
Bit CB_obtenirIemeBit(CodeBinaire cd,int i); 
CodeBinaire CB_concat(CodeBinaire cb1, CodeBinaire cb2);
#endif
>>>>>>> 7f4e5630962b882de0b347ecbc5ac9cc785ce7db
