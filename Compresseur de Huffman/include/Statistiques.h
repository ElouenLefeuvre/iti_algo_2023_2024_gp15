#ifndef __STATISTIQUES__
#define __STATISTIQUES__
typedef struct {
    char caracter;
    int ponderation;
} Statistiques;

Statistiques S_statistique(char caracter, int ponderation);
char S_obtenirCaracter(Statistiques stat);
int S_obtenirPonderation(Statistiques stat);


#endif