#ifndef  __FILEDEPRIORITE__
#define __FILEDEPRIORITE__
#include <stdbool.h>
#include "ArbreHuffman.h"

typedef struct ListeChaineeArbre{
    ArbreHuffman arbre;
    struct ListeChaineeArbre *listeSuivante;
} ListeChaineeArbre;

typedef struct {
    struct ListeChaineeArbre *debut;
    struct ListeChaineeArbre *fin;
    int longueur;
} FileDePriorite;


FileDePriorite FDP_fileDePriorite();
bool FDP_estVide(FileDePriorite *fp);
bool FDP_estVide_LCA(ListeChaineeArbre *lca);
void FDP_enfiler(FileDePriorite *fp,ArbreHuffman arbre);
void FDP_defiler(FileDePriorite *fp);
ArbreHuffman FDP_obtenirElement(FileDePriorite fp, int i);
void FDP_nouvelleFile(FileDePriorite *fp);



#endif