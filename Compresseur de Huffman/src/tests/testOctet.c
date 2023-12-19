#include<stdio.h>
#include<stdbool.h>
#include <CUnit/Basic.h>
#include "Octet.h"
#include "CodeBinaire.h";
#include <string.h>

void test_creer_Octet() {
    Octet octet = O_creerOctet();
    for (int i=0;i<8;i++){
        CU_ASSERT_EQUAL(O_iemeBIt(i), BITA0);
    }  
}

void test_fixer_bit(){
    Octet octet = O_creerOctet();
    fixerBit(octet,0,BITA1);
    fixerBit(octet,7,BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(3), BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(0), BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(7), BITA1);
}

void test_encoder(){
    Octet octet = O_creerOctet();
    CodeBinaire cb1;
    CodeBinaire cb2;
    cb2.bits = "11001";
    cb1.bits = "1101";
    encoder(octet,cb1);
    char* octetInchar = O_bitsToStr(octet);
    CU_ASSERT_EQUAL(strcmp(octetInchar,"11010000"), 1);

    encoder(octet,cb2);
    octetInchar = O_bitsToStr(octet);
    CU_ASSERT_EQUAL(strcmp(octetInchar,"11011100"), 1);
    CU_ASSERT_EQUAL(strcmp(O_bitsToStr(bitRestant),"00000001"), 1);
}


void test_iemeBit(){
    Octet octet = O_creerOctet();
    fixerBit(octet,7,BITA1);
    fixerBit(octet, 0,BITA0);
    CU_ASSERT_EQUAL(O_iemeBit(octet,7), BITA1);
    CU_ASSERT_EQUAL(O_iemeBit(octet,0), BITA1);
}


void test_decaler(){
    char* octet = "11111111";
    Octet octetInBits = O_strToBits(octet);
}





