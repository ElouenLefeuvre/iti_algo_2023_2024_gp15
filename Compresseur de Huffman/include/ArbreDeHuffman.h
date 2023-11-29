#ifndef  __ ARBREDEHUFFMAN__
#define __ARBREDEHUFFMAN__

struct ArbreDeHuffman
{
    Statistiques statitistiques;
    ArbreDeHuffman* filsGauche;
    ArbreDeHuffman* fixerFilsDroit;
};

ArbreDeHuffman arbreDeHuffman(Statistiques stat);
ArbreDeHuffman fusionner(ArbreDeHuffman ah1,ArbreDeHuffman ah2);
int obtenirPonderation(ArbreDeHuffman ah);
void* fixerFilsGauche(ArbreDeHuffman ah1,ArbreDeHuffman fg);
void* fixerFilsDroit(ArbreDeHuffman ah1,ArbreDeHuffman fd);
ArbreDeHuffman obtenirFilsGauche(ArbreDeHuffman ah1,ArbreDeHuffman fg);
ArbreDeHuffman obtenirFilsDroit(ArbreDeHuffman ah1,ArbreDeHuffman fd);

#endif
