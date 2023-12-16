#include<stdio.h>
#include<stdbool.h>
#include "Octet.h"
#include "CodeBinaire.h"

Octet creerOctet(){
    Octet result;
    for(int i=0;i<8;i++){
        fixerBit(result,i,0);
    }
}
void fixerBit(Octet octet, int position, Bit newBit){
    switch(position){
        case 0: octet.bit0= newBit;
        case 1: octet.bit1= newBit;
        case 2: octet.bit2= newBit;
        case 3: octet.bit3= newBit;
        case 4: octet.bit4= newBit;
        case 5: octet.bit5= newBit;
        case 6: octet.bit6= newBit;
        case 7: octet.bit7= newBit;
    }
}
Octet encoder(Octet octet,CodeBinaire cb,int startPosition){
    int j=0;
    for(int i =startPosition;i<8;i++){
        fixerBit(octet,i,cb.bits[j]);
        j++;
    }
}
Octet decoder(char* c,CodeBinaire cb);
Octet obtenirOctet(char* chaine);