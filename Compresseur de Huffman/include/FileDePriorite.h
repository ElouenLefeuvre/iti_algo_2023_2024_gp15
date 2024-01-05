#ifndef  __FILEDEPRIORITE__
#define __FILEDEPRIORITE__
#include <stdbool.h>
#include "ArbreHuffman.h"

typedef struct Noeud {
    ArbreHuffman arbre; 
    struct Noeud* suivant;
} Noeud;

typedef struct {
    Noeud* debut;
    int longueur;
} FileDePriorite;


void FDP_nouvelleFile(FileDePriorite* file);
void FDP_defiler(FileDePriorite *fp);
ArbreHuffman FDP_obtenirElement(FileDePriorite fp, int i);
bool FDP_estVide(FileDePriorite *fp);
bool FDP_estVide_LCA(Noeud *lca);
FileDePriorite FDP_fileDePriorite();
void FDP_enfiler(FileDePriorite *file,ArbreHuffman* arbre);
Noeud* FDP_createNoeud(ArbreHuffman* arbreOfLCA);
void FDP_afficherFileDEPriorite(FileDePriorite* file);
void fixerNoeud(FileDePriorite* file,Noeud* noeud, int position);
int trouverIndicePourInsere(ArbreHuffman* arbre,FileDePriorite* file);
#endif