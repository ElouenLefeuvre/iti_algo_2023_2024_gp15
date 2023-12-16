#include <stdio.h>
#include <CUnit/Basic.h>
#include "ArbreHuffman.h" 
#include "Statistiques.h" 

void test_creation_arbreHuffman(){
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    CU_ASSERT_EQUAL(obtenirOccurences(arbre),5);
    CU_ASSERT_PTR_NULL(obtenirFilsDroit(arbre));
    CU_ASSERT_PTR_NULL(obtenirFilsGauche(arbre));

}

void test_obtenirOccurences() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    int occurences = obtenirOccurences(arbre);
    CU_ASSERT_EQUAL(occurences, obtenirPonderation(stat));
}

void test_fusionner(){
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    Statistiques stat2 = statistique('E',2);
    ArbreHuffman arbre2 = arbrehuffman(stat2);
    arbreF = fusionner(arbre1,arbre2);
    CU_ASSERT_EQUAL(obtenirOccurences(arbreF),obtenirPonderation(arbre1.statistiques)+obtenirPonderation(arbre2.statistiques)); 
    CU_ASSERT_EQUAL(obtenirFilsDroit(arbreF),arbre1);
    CU_ASSERT_EQUAL(obtenirFilsGauche(arbreF),arbre2);
}

void test_fixerFilsGauche_et_obtenirFilsGauche() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    Statistiques statFils = statistique('T',6);
    ArbreHuffman filsGauche = arbrehuffman(statFils);
    fixerFilsGauche(arbre, filsGauche);
    ArbreHuffman obtenu = obtenirFilsGauche(arbre);
    CU_ASSERT_PTR_EQUAL(obtenu, filsGauche);
}

void test_fixerFilsDroit_et_obtenirFilsDroit() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    Statistiques statFils = statistique('T',6);
    ArbreHuffman filsDroit = arbrehuffman(statFils);
    fixerFilsDroit(arbre, filsDroit);
    ArbreHuffman obtenu = obtenirFilsDroit(arbre);
    CU_ASSERT_PTR_EQUAL(obtenu, filsDroit);
}

void test_estVide() {
    Statistiques stat = statistique('',0);
    ArbreHuffman arbre = arbrehuffman(stat);
    CU_ASSERT_TRUE(estVide(arbre));
}

void test_estFeuille() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    CU_ASSERT_TRUE(estFeuille(arbre));
}

void test_estPresent_caractere_present_a_la_racine() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    char caractere = 'A';

    CU_ASSERT_TRUE(estPresent(arbre, caractere)); 
}

void test_estPresent_caractere_present_sous_arbre_gauche() {
    Statistiques stat = statistique('C',7);
    ArbreHuffman arbre = arbrehuffman(stat);
    Statistiques statFils = statistique('A',5);
    ArbreHuffman arbreFils = arbrehuffman(statFils);
    char caractere = 'A';
    fixerFilsGauche(arbre,arbreFils)
    CU_ASSERT_TRUE(estPresent(arbre, caractere));
}

void test_estPresent_caractere_present_sous_arbre_droit() {
    Statistiques stat = statistique('C',7);
    ArbreHuffman arbre = arbrehuffman(stat);
    Statistiques statFils = statistique('A',5);
    ArbreHuffman arbreFils = arbrehuffman(statFils);
    char caractere = 'A';
    fixerFilsDroit(arbre,arbreFils)
    CU_ASSERT_TRUE(estPresent(arbre, caractere));
}

void test_estPresent_caractere_absent() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman arbre = arbrehuffman(stat);
    char caractere = 'B';
    
    CU_ASSERT_FALSE(estPresent(arbre, caractere)); 
}

int main() {
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Tests ArbreHuffman", NULL, NULL);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(pSuite, "Test création ArbreHuffman", test_arbrehuffman_creation))
        || (NULL == CU_add_test(pSuite, "Test obtenirOccurences", test_obtenirOccurences))
        || (NULL == CU_add_test(pSuite, "Test fusionner", test_fusionner))
        || (NULL == CU_add_test(pSuite, "Test fixerFilsGauche et obtenirFilsGauche", test_fixerFilsGauche_et_obtenirFilsGauche))
        || (NULL == CU_add_test(pSuite, "Test fixerFilsDroit et obtenirFilsDroit", test_fixerFilsDroit_et_obtenirFilsDroit))
        || (NULL == CU_add_test(pSuite, "Test estVide", test_estVide))
        || (NULL == CU_add_test(pSuite, "Test estFeuille", test_estFeuille))
        || (NULL == CU_add_test(pSuite, "Test caractère présent à la racine", test_estPresent_caractere_present_a_la_racine))
        || (NULL == CU_add_test(pSuite, "Test caractère présent sous arbre gauche", test_estPresent_caractere_present_sous_arbre_gauche))
        || (NULL == CU_add_test(pSuite, "Test caractère présent sous arbre droit", test_estPresent_caractere_present_sous_arbre_droit))
        || (NULL == CU_add_test(pSuite, "Test caractère absent", test_estPresent_caractere_absent))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    printf("\n");
    CU_basic_show_failures(CU_get_failure_list());
    printf("\n\n");

    CU_cleanup_registry();
    return CU_get_error();
}
