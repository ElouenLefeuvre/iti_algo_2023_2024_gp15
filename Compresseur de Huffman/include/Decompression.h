#ifndef  __DECOMPRESSION__
#define __DECOMPRESSION__

#include <stdio.h>
#include <stdbool.h>
#include "ArbreHuffman.h"
#include "FileDePriorite.h"
#include "Ensemble.h"
#include "Statistiques.h"


FILE DECOMP_decompresser(char nomFichierHuffman[]);
FileDePriorite DECOMP_obtenirFileDePriorite();
Ensemble DECOMP_obtenirStatistiques(char nomfichier[]);
ArbreHuffman DECOMP_creerArbreHuffman(Statistiques stat);
FileDePriorite DECOMP_insererArbre(FileDePriorite file, ArbreHuffman arbre);
ArbreHuffman DECOMP_creerArbre(Statistiques stats);

#endif