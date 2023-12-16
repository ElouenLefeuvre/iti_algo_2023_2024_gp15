#include<stdio.h>
#include<stdbool.h>
#include "Octet.h"
#include "CodeBinaire.h"

Octet creerOctet(){
    Octet result;
    startPosition=0;
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
Octet encoder(Octet octet,CodeBinaire cb){
    int j=0;
    Bit bit;

    //cas ou y a des bits dans l'octet des bit restant
    // On insere autant de bit possible dans l'octet;
    for (int i=mostImportantBitRestant-1 ;i>0;i--){
        if(startPosition>7){
            Bit bit = iemeBit(bitRestant,i);
            fixerBit(octet,startPosition,bit);
            startPosition++;
            fixerBit(bitRestant,mostImportantBitRestant,bitA0);
            mostImportantBitRestant--;
        }  
    }

    //Apres On passe au bits du code binaire ,on les insere s'il reste de la place dans octet,
    //sinon on les insere dans l'octet bit restant
    for (int i=obtenirLongueur(cb)-1;i>0;i--){
        Bit bit = obtenirIemeBit(cb,i);
        if(startPosition > 7){
            fixerBit(octet,startPosition,bit);
        }
        else{
            decaler(bitRestant);
            fixerBit(bitRestant,0,bit);
        }
    }

    //Si apres avoir inserer les bit restants des appels precedants et les bits de code binaire
    // et qu'il reste plus de place dans octet on remet start position a 0 pour le prochain octet 
    //qu'on va traite
    
    if(startPosition>7){
        startPosition =0;
    }

    return octet;
}

Bit iemeBit(Octet octet, int i){
    switch(i){
            case 0: return octet.bit0;
            case 1: return octet.bit1;
            case 2: return octet.bit2;
            case 3: return octet.bit3;
            case 4: return octet.bit4;
            case 5: return octet.bit5;
            case 6: return octet.bit6;
            case 7: return octet.bit7;
        }
}

void decaler(Octet octet){
    octet.bit7=octet.bit6;
    octet.bit6=octet.bit5;
    octet.bit5=octet.bit4;
    octet.bit4=octet.bit3;
    octet.bit3=octet.bit2;
    octet.bit2 = octet.bit1;
    octet.bit1 = octet.bit0;
    octet.bit0= bitA0;
}