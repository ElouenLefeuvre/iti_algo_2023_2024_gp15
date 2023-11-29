#ifndef __STATISTIQUES__
#define __STATISTIQUES__
struct Statistiques
{
    char caracter;
    int ponderation;
};

Statistiques statistiques(char caracter, int ponderation);
char obtenirCaracter(Statistiques stat);
int obtenirPonderation(Statistiques stat);


#endif