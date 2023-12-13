#ifndef  __ FILEDEPRIORITE__
#define __FILEDEPRIORITE__
#include "ArbreHuffman.h";


typedef struct {
    ArbreHuffman arbre;
    ListeChaineeArbre listeSuivante;
}ListeChaineeArbre;

typedef struct {
    ListeChaineeArbre debut;
    ListeChaineeArbre fin;
    int longueur;
}FileDePriorite;


FileDePriorite fileDePriorite();
bool estVide(FileDePriorite fp);
FileDePriorite enfiler(FileDePriorite fp,ArbreHuffman stat);
FileDePriorite defiler(FileDePriorite fp);
ArbreHuffman obtenirElement(FileDePriorite fp);
FileDePriorite nouvelleFile(FileDePriorite fp);



#endif