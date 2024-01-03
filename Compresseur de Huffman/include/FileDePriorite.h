#ifndef  __FILEDEPRIORITE__
#define __FILEDEPRIORITE__
#include <stdbool.h>
#include "ArbreHuffman.h"

typedef struct ListeChaineeArbre{
    ArbreHuffman arbre;
    struct ListeChaineeArbre *listeSuivante;
} ListeChaineeArbre;

typedef struct {
    ListeChaineeArbre debut;
    ListeChaineeArbre fin;
    int longueur;
} FileDePriorite;


FileDePriorite FDP_fileDePriorite();
bool FDP_estVide(FileDePriorite fp);
FileDePriorite FDP_enfiler(FileDePriorite fp,ArbreHuffman arbre);
FileDePriorite FDP_defiler(FileDePriorite fp);
ArbreHuffman FDP_obtenirElement(FileDePriorite fp, int i);
FileDePriorite FDP_nouvelleFile(FileDePriorite fp);



#endif