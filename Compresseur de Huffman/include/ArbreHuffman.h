#ifndef __ARBREDEHUFFMAN__
#define __ARBREDEHUFFMAN__
#include <stdbool.h>
#include "Statistiques.h"

typedef struct ArbreHuffman ArbreHuffman;

ArbreHuffman* AH_arbreDeHuffman(Statistiques stat);
int AH_obtenirPonderation(ArbreHuffman arbre);
ArbreHuffman AH_fusionner(ArbreHuffman ah1, ArbreHuffman ah2);
void AH_fixerFilsGauche(ArbreHuffman *ah1, ArbreHuffman *fg);
void AH_fixerFilsDroit(ArbreHuffman *ah1, ArbreHuffman *fd);
ArbreHuffman *AH_obtenirFilsGauche(ArbreHuffman *ah1);
ArbreHuffman *AH_obtenirFilsDroit(ArbreHuffman *ah1);
bool AH_estVide(ArbreHuffman *arbre);
bool AH_estFeuille(ArbreHuffman arbre);
bool AH_estPresent(ArbreHuffman *arbre, char caractere);
Statistiques AH_obtenirStat(ArbreHuffman arbre);
char AH_obtenirCaracter(ArbreHuffman arbre);
void AH_afficherArbre(ArbreHuffman *arbre);
void AH_fixerStatistique(ArbreHuffman *arbre,Statistiques stat);

struct ArbreHuffman {
    Statistiques statistiques;
    ArbreHuffman *filsGauche;
    ArbreHuffman *filsDroit;
};

#endif
