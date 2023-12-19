#ifndef __TABLEDECODAGE__
#define __TABLEDECODAGE__

#include "CodeBinaire.h"
#include "ArbreHuffman.h"

typedef struct {
        CodeBinaire code ;
        char c;
        TableDeCodage listeSuivante;
}Noeud;

typedef struct {
    Noeud* noeud;
}TableDeCodage;


TableDeCodage TDC_obtenirTableDeCodage(ArbreHuffman a);
CodeBinaire TDC_obtenirCode(TableDeCodage tab,char c);
char TDC_obtenirCarac(TableDeCodage tab,CodeBinaire code);
void TDC_ajouter(TableDeCodage tab,char c,CodeBinaire code);
void TDC_supprimer(TableDeCodage tab, char c, CodeBinaire code);
bool TDC_estPresent(TableDeCodage tab,char c);
bool TDC_estVide(TableDeCodage tab);
#endif