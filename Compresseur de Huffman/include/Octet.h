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
static Octet bitRestant;
static int mostImportantBitRestant;
static int startPosition;

Bit O_iemeBit(Octet octet,int i);
<<<<<<< HEAD
Octet creerOctet();
Octet encoder(Octet octet,CodeBinaire cb);
void decaler(Octet octet);
void fixerBit(Octet octet, int position, Bit newBit);
char* O_bitsToStr(Octet octet);
Octet O_strToBits(char* octet);
=======
Octet O_creerOctet();
Octet O_encoder(Octet octet,CodeBinaire cb);
void O_decaler(Octet octet);
void O_fixerBit(Octet octet, int position, Bit newBit);
>>>>>>> 7f4e5630962b882de0b347ecbc5ac9cc785ce7db


#endif