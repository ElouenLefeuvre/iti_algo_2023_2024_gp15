#ifndef __OCTET__
#define __OCTET__
#include "CodeBinaire.h";
typedef struct {
    Bit bit7;
    Bit bit6;
    Bit bit5;
    Bit bit4;
    Bit bit3;
    Bit bit2;
    Bit bit1;
    Bit bit0;
}Octet;

Octet creerOctet();
Octet ajouter(Octet o, CodeBinaire cd);
Octet supprimer(Octet o, CodeBinaire cd);
char* encoder(Octet o,CodeBinaire cb);
Octet decoder(char* c,CodeBinaire cb);
Octet obtenirOctet(char* chaine);


#endif