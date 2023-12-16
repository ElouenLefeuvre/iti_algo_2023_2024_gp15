#ifndef  __ ARBREDEHUFFMAN__
#define __ARBREDEHUFFMAN__

#include "Statistiques.h";

typedef struct {
    Statistiques statistiques;
    ArbreHuffman* filsGauche;
    ArbreHuffman* filsDroit;
}ArbreHuffman;

ArbreHuffman arbreDeHuffman(Statistiques stat);
int obtenirOccurences(ArbreHuffman arbre);
ArbreHuffman fusionner(ArbreHuffman ah1,ArbreHuffman ah2);
void* fixerFilsGauche(ArbreHuffman ah1,ArbreHuffman fg);
void* fixerFilsDroit(ArbreHuffman ah1,ArbreHuffman fd);
ArbreHuffman obtenirFilsGauche(ArbreHuffman ah1);
ArbreHuffman obtenirFilsDroit(ArbreHuffman ah1);
bool estVide(ArbreHuffman arbre);
bool estFeuille(ArbreHuffman arbre);
bool estPresent(ArbreHuffman arbre, char caractere);

#endif
