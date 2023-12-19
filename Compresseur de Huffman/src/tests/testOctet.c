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
    O_decaler(octetInBits);
    CU_ASSERT_EQUAL(strcmp(O_bitsToStr(octetInBits),"11111110"), 1);
}

void test_str_to_bits(){
    char* octetInstr = "11110011";
    Octet octetInBits= O_strToBits(octetInstr);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,7), BITA1);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,6), BITA1);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,5), BITA1);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,4), BITA1);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,3), BITA0);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,2), BITA0);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,1), BITA1);
    CU_ASSERT_EQUAL(O_iemeBit(octetInBits,0), BITA1);
}

void test_bits_to_str(){
    Octet octet = O_creerOctet();
    fixerBit(octet,7,BITA1);
    fixerBit(octet,6,BITA0);
    fixerBit(octet,5,BITA1);
    fixerBit(octet,4,BITA0);
    fixerBit(octet,3,BITA1);
    fixerBit(octet,2,BITA0);
    fixerBit(octet,1,BITA1);
    fixerBit(octet,0,BITA0);
    char* octetInstr= O_bitsToStr(octet);
    CU_ASSERT_EQUAL(strcmp(octetInstr,"10101010"), 1);

}





