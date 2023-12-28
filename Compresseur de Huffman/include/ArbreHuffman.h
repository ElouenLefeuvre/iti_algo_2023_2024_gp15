#ifndef  __ARBREDEHUFFMAN__
#define __ARBREDEHUFFMAN__

#include "Statistiques.h"

typedef struct {
    Statistiques statistiques;
    ArbreHuffman* filsGauche;
    ArbreHuffman* filsDroit;
} ArbreHuffman;

ArbreHuffman AH_arbrehuffman(Statistiques stat);
int AH_obtenirOccurences(ArbreHuffman arbre);
ArbreHuffman AH_fusionner(ArbreHuffman ah1,ArbreHuffman ah2);
void* AH_fixerFilsGauche(ArbreHuffman ah1,ArbreHuffman fg);
void* AH_fixerFilsDroit(ArbreHuffman ah1,ArbreHuffman fd);
ArbreHuffman AH_obtenirFilsGauche(ArbreHuffman ah1);
ArbreHuffman AH_obtenirFilsDroit(ArbreHuffman ah1);
bool AH_estVide(ArbreHuffman arbre);
bool AH_estFeuille(ArbreHuffman arbre);
bool AH_estPresent(ArbreHuffman arbre, char caractere);

#endif
