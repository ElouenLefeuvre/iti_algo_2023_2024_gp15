#ifndef  __COMPRESSION__
#define __COMPRESSION__

ArbreHuffman COMP_creerArbre(Statistiques stats);
FileDePriorite COMP_insererArbre(FileDePriorite file, ArbreHuffman arbre);
int COMP_obtenirOccurences(char c);
Ensemble COMP_obtenirCaracteres(char nomFichier[]);
Ensemble COMP_creerStatistiques(char nomFichier[], Ensemble ensC);
FileDePriorite COMP_creerFileDePriorite(char nomFichier[]);
TableDeCodage COMP_creerTableDeCodage(ArbreHuffman arbre);
fichierBinaire COMP_compresser(char nomFichier[])


#endif