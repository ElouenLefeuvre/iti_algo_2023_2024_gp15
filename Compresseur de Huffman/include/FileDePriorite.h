#ifndef  __ FILEDEPRIORITE__
#define __FILEDEPRIORITE__


struct FileDePriorite
{
    /* data */
};

FileDePriorite fileDePriorite();
bool estVide(FileDePriorite fp);
FileDePriorite enfiler(FileDePriorite fp,ArbreDeHuffman stat);
FileDePriorite defiler(FileDePriorite fp);
ArbreDeHuffman obtenirElement(FileDePriorite fp);
int longueur(FileDePriorite fp);
FileDePriorite nouvelleFile(FileDePriorite fp);



#endif