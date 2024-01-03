#ifndef __OCTET__
#define __OCTET__
#include "CodeBinaire.h"

typedef struct {
    Bit bits[8];  // Tableau de 8 bits
} Octet;

Bit O_iemeBit(Octet octet,int i);
Octet O_creerOctet();
Octet O_encoder(Octet octet,CodeBinaire cb);
void O_decaler(Octet octet);
void O_fixerBit(Octet* octet, int position, Bit valeur);
char* O_bitsToStr(const Octet* octet);
Octet O_strToBits(const char* chaine);
bool O_estVide(const Octet* octet);
void O_incrementStartPosition();
int O_obtenirStartPosition();
Octet O_obtenirBitRestants();
#endif
