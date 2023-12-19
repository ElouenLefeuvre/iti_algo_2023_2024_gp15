#include<stdio.h>
#include<stdbool.h>
#include <CUnit/Basic.h>
#include "Octet.h"

void test_creer_Octet() {
    Octet octet = creerOctet();
    for (int i=0;i<8;i++){
        CU_ASSERT_EQUAL(O_iemeBIt(i), BITA0);
    }  
}

void test_fixer_bit(){
    Octet octet = creerOctet();
    fixerBit(octet,0,BITA1);
    fixerBit(octet,7,BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(3), BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(0), BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(7), BITA1);
}

void test_encoder(){
    Octet octet = creerOctet();
    fixerBit(octet,0,BITA1);
    fixerBit(octet,7,BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(3), BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(0), BITA1);
    CU_ASSERT_EQUAL(O_iemeBIt(7), BITA1);
}





