#ifndef __TABLEDECODAGE__
#define __TABLEDECODAGE__

#include "CodeBinaire.h"
#include "ArbreHuffman.h"

typedef struct Noeud{
        CodeBinaire code ;
        char c;
        TableDeCodage listeSuivante;
};

typedef struct {
    Noeud* noeud;
}TableDeCodage;


TableDeCodage obtenirTableDeCodage(ArbreHuffman a);
CodeBinaire obtenirCode(TableDeCodage tab,char c);
char obtenirCarac(TableDeCodage tab,CodeBinaire code);
void ajouter(TableDeCodage tab,char c,CodeBinaire code);
void supprimer(TableDeCodage tab, char c);
bool estPresent(TableDeCodage tab,char c);
#endif