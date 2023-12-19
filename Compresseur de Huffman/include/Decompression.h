#ifndef  __DECOMPRESSION__
#define __DECOMPRESSION__

FILE DECOMP_decompresser(char[] nomFichierHuffman);
FileDePriorite DECOMP_obtenirFileDePriorite();
Ensemble DECOMP_obtenirStatistiques(char nomfichier[]);
ArbreHuffman DECOMP_creerArbreHuffman(Statistiques stat);
FileDePriorite DECOMP_insererArbre(FileDePriorite file, ArbreHuffman arbre);
ArbreHuffman DECOMP_creerArbre(Statistiques stats);

#endif