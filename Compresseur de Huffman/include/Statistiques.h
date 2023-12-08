#ifndef __STATISTIQUES__
#define __STATISTIQUES__
typedef struct {
    char caracter;
    int ponderation;
}Statistiques;

Statistiques statistiques(char caracter, int ponderation);
char obtenirCaracter(Statistiques stat);
int obtenirPonderation(Statistiques stat);


#endif