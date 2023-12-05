#ifndef  __ ARBREDEHUFFMAN__
#define __ARBREDEHUFFMAN__

struct ArbreHuffman
{
    Statistiques statitistiques;
    ArbreDeHuffman* filsGauche;
    ArbreDeHuffman* filsDroit;
};

ArbreHuffman arbreDeHuffman(stat : Statistiques);
ArbreHuffman fusionner(ArbreHuffman ah1,ArbreHuffman ah2);
int obtenirPonderation(ArbreHuffman ah);
void* fixerFilsGauche(ArbreHuffman ah1,ArbreHuffman fg);
void* fixerFilsDroit(ArbreHuffman ah1,ArbreHuffman fd);
ArbreHuffman obtenirFilsGauche(ArbreHuffman ah1);
ArbreHuffman obtenirFilsDroit(ArbreHuffman ah1);

#endif
