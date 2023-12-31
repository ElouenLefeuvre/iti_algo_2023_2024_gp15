#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "CodeBinaire.h"
#include <stdlib.h>

// Fonctions de configuration et de nettoyage pour CUnit
int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

// Tests pour CB_estVide
void test_CB_estVide(void) {
    CodeBinaire code1 = CB_creerCodeBinaire(4);
    CU_ASSERT_FALSE(CB_estVide(code1));

    CodeBinaire code2 = CB_creerCodeBinaire(8);
    CU_ASSERT_FALSE(CB_estVide(code2));

    CB_libererCodeBinaire(&code1);
    CB_libererCodeBinaire(&code2);
}

// Tests pour CB_creerCodeBinaire
void test_CB_creerCodeBinaire(void) {
    CodeBinaire code = CB_creerCodeBinaire(4);
    CU_ASSERT_EQUAL(code.taille, 4);
    for (size_t i = 0; i < code.taille; ++i) {
        CU_ASSERT_EQUAL(code.bits[i], BITA0);
    }
    CB_libererCodeBinaire(&code);
}

// Tests pour CB_remplirCodeBinaire
void test_CB_remplirCodeBinaire(void) {
    CodeBinaire code;
    code.taille = 4;
    code.bits = malloc(4 * sizeof(Bit));
    const char * bits =  "1101";

    CB_remplirCodeBinaire(&code,bits);

    for (int i = 0; i < code.taille; ++i) {
        if(strcmp(&bits[i],"0"),0) CU_ASSERT_EQUAL(code.bits[i],BITA0);
        if(strcmp(&bits[i],"1"),0) CU_ASSERT_EQUAL(code.bits[i],BITA1);
    }

    CB_libererCodeBinaire(&code);
}

// Tests pour CB_obtenirIemeBit
void test_CB_obtenirIemeBit(void) {
    CodeBinaire code = CB_creerCodeBinaire(4);

    for (size_t i = 0; i < code.taille; ++i) {
        CU_ASSERT_EQUAL(CB_obtenirIemeBit(code, i), BITA0);
    }

    CB_libererCodeBinaire(&code);
}

// Tests pour CB_concatener
void test_CB_concatener(void) {
    CodeBinaire code1 = CB_creerCodeBinaire(2);
    CodeBinaire code2 = CB_creerCodeBinaire(3);

    CodeBinaire resultat = CB_concatener(&code1, &code2);

    CU_ASSERT_EQUAL(resultat.taille, code1.taille + code2.taille);

    for (size_t i = 0; i < code1.taille; ++i) {
        CU_ASSERT_EQUAL(resultat.bits[i], BITA0);
    }

    for (size_t i = 0; i < code2.taille; ++i) {
        CU_ASSERT_EQUAL(resultat.bits[code1.taille + i], BITA0);
    }

    CB_libererCodeBinaire(&code1);
    CB_libererCodeBinaire(&code2);
    CB_libererCodeBinaire(&resultat);
}

// Tests pour CB_codeBinaireToStr
void test_CB_codeBinaireToStr(void) {
    CodeBinaire code = CB_creerCodeBinaire(3);
    CU_ASSERT_STRING_EQUAL(CB_codeBinaireToStr(&code), "000");

    CB_remplirCodeBinaire(&code, "101");
    CU_ASSERT_STRING_EQUAL(CB_codeBinaireToStr(&code), "101");

    CB_libererCodeBinaire(&code);
}

int main() {
    // Initialisation de CUnit
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Ajout des suites de tests
    CU_pSuite suite_CB = CU_add_suite("Suite CodeBinaire", init_suite, clean_suite);
    CU_add_test(suite_CB, "Test CB_estVide", test_CB_estVide);
    CU_add_test(suite_CB, "Test CB_creerCodeBinaire", test_CB_creerCodeBinaire);
    CU_add_test(suite_CB, "Test CB_remplirCodeBinaire", test_CB_remplirCodeBinaire);
    CU_add_test(suite_CB, "Test CB_obtenirIemeBit", test_CB_obtenirIemeBit);
    CU_add_test(suite_CB, "Test CB_concatener", test_CB_concatener);
    CU_add_test(suite_CB, "Test CB_codeBinaireToStr", test_CB_codeBinaireToStr);

    // Exécution des tests
    CU_basic_run_tests();

    // Nettoyage de CUnit
    CU_cleanup_registry();

    return CU_get_error();
}
