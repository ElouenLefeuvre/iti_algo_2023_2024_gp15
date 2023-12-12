#ifndef  __ FILEDEPRIORITE__
#define __FILEDEPRIORITE__
#include "ArbreHuffman.h";


typedef struct{

}FileDePriorite;

FileDePriorite fileDePriorite();
bool estVide(FileDePriorite fp);
FileDePriorite enfiler(FileDePriorite fp,ArbreHuffman stat);
FileDePriorite defiler(FileDePriorite fp);
ArbreHuffman obtenirElement(FileDePriorite fp);
int longueur(FileDePriorite fp);
FileDePriorite nouvelleFile(FileDePriorite fp);



#endif