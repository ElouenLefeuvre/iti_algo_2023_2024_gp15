#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include "octet.h"
#include "CodeBinaire.h"
#include <stdlib.h>
static int startPosition=0;
static bool currentisFull;
static Octet bitRestant;
static int mostImportantBitRestant=8;

Octet O_obtenirBitRestants(){
    //printf("bit restant : %s\n", O_octetToStr(&bitRestant));
    return bitRestant;
}

void O_incrementStartPosition(){
    startPosition++;
}

int O_obtenirStartPosition(){
    return startPosition;
}

Octet O_creerOctet(){
    Octet result;
    startPosition=0;
    currentisFull = false;
    for (size_t i = 0; i < 8; ++i) {
        result.bits[i] = BITA0;
    }
    return result;
}

Octet O_fixerBit(Octet* octet, int position, Bit valeur) {
    if (position < 8) {
        octet->bits[position] = valeur;
    } else {
        fprintf(stderr, "Erreur : Position hors limites.\n");
    }
    return *octet;
}


Bit O_iemeBit(Octet octet, int i){
    return octet.bits[i];
}


//decale a gauche pou libere un bit pour insertion dans bitRestant
Octet O_decaler(Octet octet){
    for(int i=0 ;i<7;i++){
        octet.bits[i]=octet.bits[i+1];
    }
    octet.bits[7]= BITA0;
    return octet;
}


char* O_octetToStr(const Octet* octet) {
    char* str = malloc(9 * sizeof(char));  // +1 pour le caractère nul
    for (int i = 0; i < 8; ++i) {
        str[i] = (octet->bits[i] == BITA0) ? '0' : '1';
    }
    str[8] = '\0';  // Terminer la chaîne avec le caractère nul
    return str;
}


Octet O_strToBits(const char* chaine){
    Octet octet = O_creerOctet();
    
    int longueurChaine = strlen(chaine);
    for (int i = 0; i < longueurChaine; ++i) {
        octet.bits[i] = (chaine[i] == '0') ? BITA0 : BITA1;
        O_incrementStartPosition();
    }
    

    return octet;
    
}

//01010100
//00000001
//00000000
Octet O_encoder(Octet octet,CodeBinaire cb){

    
    
    int j=0;
    Bit bit;
    //printf("je ne suis pas encore dans une condition\n");
    //cas ou y a des bits dans l'octet des bit restant
    // On insere autant de bit possible dans l'octet;
    if (mostImportantBitRestant<=7 && !currentisFull) {
        for (int i=mostImportantBitRestant ;i<8;i++){     
            Bit bit = O_iemeBit(bitRestant,i);
            octet=O_fixerBit(&octet,startPosition,bit);
            startPosition++;
            bitRestant = O_fixerBit(&bitRestant,mostImportantBitRestant,BITA0);
            mostImportantBitRestant++;  
        }
    }
    //printf("je suis dans la deuxieme condition\n");
    //Apres On passe au bits du code binaire ,on les insere s'il reste de la place dans octet,
    //sinon on les insere dans l'octet bitRestant
    for (int i=0;i< cb.taille;i++){
        Bit bit = CB_obtenirIemeBit(cb,i);
        //printf("start position after strtobits is : %d\n",O_obtenirStartPosition());
        if(!currentisFull /*ca veut dire il reste de la place dans l'octet principale*/){
            //printf("Je ne dois pas inserer dans l'Octet bitRestants\n");
            octet = O_fixerBit(&octet,startPosition,bit);
            startPosition++;
        }
        else{/*Cad il ne reste pas de la place */
            //printf("Je dois inserer dans l'octet bitRestant\n");
            bitRestant = O_decaler(bitRestant);
            //printf("Octet avant insertion decaler : %s\n", O_octetToStr(&bitRestant));
            bitRestant = O_fixerBit(&bitRestant,7,bit);
            //printf("Octet decaler : %s\n", O_octetToStr(&bitRestant));
            mostImportantBitRestant--;
        }
        if(startPosition >7) {
            currentisFull =true;
            //quand y a plus de place dans l'octet on prend un autre donc start position est remis a 0;
            // startPosition =0;
        }
    }
    

    

    //Si apres avoir inserer les bit restants des appels precedants et les bits de code binaire
    // et qu'il reste plus de place dans octet on remet start position a 0 pour le prochain octet 
    //qu'on va traite
    
    if(startPosition >7) {
        currentisFull =true;
        //quand y a plus de place dans l'octet on prend un autre donc start position est remis a 0;
        // startPosition =0;
    }
    return octet;
}

bool O_estVide(const Octet* octet) {
    for (size_t i = 0; i < 8; ++i) {
        if (octet->bits[i] != BITA0) {
            return false;
        }
    }
    return true;
}






