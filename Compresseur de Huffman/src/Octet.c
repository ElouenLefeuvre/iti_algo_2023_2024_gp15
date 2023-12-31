#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include "Octet.h"
#include "CodeBinaire.h"

Octet O_creerOctet(){
    Octet result;
    startPosition=0;
    for(int i=0;i<8;i++){
        O_fixerBit(result,i,0);
    }
}
void O_fixerBit(Octet octet, int position, Bit newBit){
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
Octet O_encoder(Octet octet,CodeBinaire cb){
    int j=0;
    Bit bit;

    //cas ou y a des bits dans l'octet des bit restant
    // On insere autant de bit possible dans l'octet;
    for (int i=mostImportantBitRestant-1 ;i>0;i--){
        if(startPosition<8){
            Bit bit = O_iemeBit(bitRestant,i);
            O_fixerBit(octet,startPosition,bit);
            startPosition++;
            O_fixerBit(bitRestant,mostImportantBitRestant,BITA0);
            mostImportantBitRestant--;
        }  
    }

    //Apres On passe au bits du code binaire ,on les insere s'il reste de la place dans octet,
    //sinon on les insere dans l'octet bit restant
    for (int i=4-1;i>0;i--){
        Bit bit = CB_obtenirIemeBit(cb,i);
        if(startPosition < 8){
            O_fixerBit(octet,startPosition,bit);
        }
        else{
            O_decaler(bitRestant);
            O_fixerBit(bitRestant,0,bit);
        }
    }

    //Si apres avoir inserer les bit restants des appels precedants et les bits de code binaire
    // et qu'il reste plus de place dans octet on remet start position a 0 pour le prochain octet 
    //qu'on va traite
    
    if(startPosition >7){
        startPosition =0;
    }

    return octet;
}

Bit O_iemeBit(Octet octet, int i){
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

void O_decaler(Octet octet){
    octet.bit7=octet.bit6;
    octet.bit6=octet.bit5;
    octet.bit5=octet.bit4;
    octet.bit4=octet.bit3;
    octet.bit3=octet.bit2;
    octet.bit2 = octet.bit1;
    octet.bit1 = octet.bit0;
    octet.bit0= BITA0;
}

char* O_bitsToStr(Octet octet){
    char* result = "";
    for(int i=0;i<8;i++){
        Bit bitToAdd = O_iemeBit(octet,i);
        switch(bitToAdd){
            case BITA0: strcat(result,'0');
            case BITA1: strcat(result,'1');
        }
    }
    return result;
}

Octet O_strToBits(char* octet){
    Octet result; 
    for(int i=0; i<8;i++){
        char bit =octet[i];
        O_fixerBit(result,7-i,bit);
    }
    return result;
    
}




