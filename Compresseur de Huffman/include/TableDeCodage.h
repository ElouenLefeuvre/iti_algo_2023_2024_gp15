#ifndef __TABLEDECODAGE__
#define __TABLEDECODAGE__

#include "CodeBinaire.h"

typedef struct Noeud{
        CodeBinaire code ;
        char c;
        TableDeCodage listeSuivante;
};

typedef struct {
    Noeud* noeud;
}TableDeCodage;


TableDeCodage obtenirTableDeCodage();
CodeBinaire obtenirCodeBinaire(TableDeCodage tdc,char c);
char obtenirCaracter(TableDeCodage tdc,CodeBinaire c);
TableDeCodage ajouter(TableDeCodage tdc,char c,CodeBinaire cb);
TableDeCodage retirer(TableDeCodage tdc, char c);
bool estPresent(TableDeCodage tdc,char c);
#endif