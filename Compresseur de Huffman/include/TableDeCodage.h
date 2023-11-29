#ifndef __TABLEDECODAGE__
#define __TABLEDECODAGE__

struct TableDeCodage{};

TableDeCodage obtenirTableDeCodage();
CodeBinaire obtenirCodeBinaire(TableDeCodage tdc,char c);
char obtenirCaracter(TableDeCodage tdc,CodeBinaire c);
TableDeCodage ajouter(TableDeCodage tdc,char c,CodeBinaire cb);
TableDeCodage retirer(TableDeCodage tdc, char c);
bool estPresent(TableDeCodage tdc,char c);
#endif