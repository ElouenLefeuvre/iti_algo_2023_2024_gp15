#include<stdio.h>
#include<stdbool.h>
#include <CUnit/Basic.h>
#include "FileDePriorite.h"
#include "ArbreHuffman.h"
#include "Statistiques.h"

void test_creation_file() {
    FileDePriorite file; 
    stat = S_statistique('a', 3);
    arbre = AH_arbrehuffman(stat);
    file = FDP_filedePriorite(arbre);
    CU_ASSERT_PTR_NULL(file.listeSuivante);
    CU_ASSERT_PTR_NULL(file.fin);
    CU_ASSERT_EQUAL(file.longueur,1);
    CU_ASSERT_EQUAL(file.debut.arbre,arbre);
}

void testEnfiler_milieu() {
    FileDePriorite file1; 
    FileDePriorite file2;
    stat1 = S_statistique('a', 3);
    stat2 = S_statistique('b', 4);
    stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante = AH_arbrehuffman(stat3);
    file1.fin = NULL;

    file2.longueur = file1.longueur-1;
    file2.debut.arbre=AH_arbrehuffman(stat1)
    file2.debut.listeSuivante = AH_arbrehuffman(stat3);
    file2.fin=NULL;
    FDP_enfiler(file2,AH_arbrehuffman(stat2));

    CU_ASSERT_PTR_EQUAL(file1,file2);
}

void testEnfiler_debut() {
    FileDePriorite file1; 
    FileDePriorite file2;
    stat1 = S_statistique('a', 3);
    stat2 = S_statistique('b', 4);
    stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante = AH_arbrehuffman(stat3);
    file1.fin = NULL;

    file2.longueur = file1.longueur-1;
    file2.debut.arbre=AH_arbrehuffman(stat2)
    file2.debut.listeSuivante = AH_arbrehuffman(stat3);
    file2.fin=NULL;
    FDP_enfiler(file2,AH_arbrehuffman(stat1));

    CU_ASSERT_PTR_EQUAL(file1,file2);
}

void testEnfiler_fin() {
    FileDePriorite file1; 
    FileDePriorite file2;
    stat1 = S_statistique('a', 3);
    stat2 = S_statistique('b', 4);
    stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante = AH_arbrehuffman(stat3);
    file1.fin = NULL;

    file2.longueur = file1.longueur-1;
    file2.debut.arbre=AH_arbrehuffman(stat1);
    file2.debut.listeSuivante = AH_arbrehuffman(stat2);
    file2.fin=NULL;
    FDP_enfiler(file2,AH_arbrehuffman(stat3));

    CU_ASSERT_PTR_EQUAL(file1,file2);
}

void testDefiler() {
    FileDePriorite file1; 
    FileDePriorite file2;
    stat1 = S_statistique('a', 3);
    stat2 = S_statistique('b', 4);
    stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante = AH_arbrehuffman(stat2);
    file1.fin = NULL;

    file2.longueur = file1.longueur+1
    file2.debut.arbre=AH_arbrehuffman(stat1);
    file2.debut.listeSuivante = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante = AH_arbrehuffman(stat3);
    file2.fin=NULL;
    FDP_defiler(file2);

    CU_ASSERT_PTR_EQUAL(file1,file2);
}

void test_obtenirIElement_debut() {
    FileDePriorite file; 
    stat1 = S_statistique('a', 3);
    stat2 = S_statistique('b', 4);
    stat3 = S_statistique('c', 7);

    file.longueur = 3;
    file.debut.arbre = AH_arbrehuffman(stat1);
    file.debut.listeSuivante = AH_arbrehuffman(stat2);
    file.debut.listeSuivante.listeSuivante = AH_arbrehuffman(stat3);
    file.fin = NULL;

    CU_ASSERT_EQUAL(obtenirIemeElement(file,1),stat1);
}

void test_obtenirIElement_milieu() {
    FileDePriorite file; 
    stat1 = S_statistique('a', 3);
    stat2 = S_statistique('b', 4);
    stat3 = S_statistique('c', 7);

    file.longueur = 3;
    file.debut.arbre = AH_arbrehuffman(stat1);
    file.debut.listeSuivante = AH_arbrehuffman(stat2);
    file.debut.listeSuivante.listeSuivante = AH_arbrehuffman(stat3);
    file.fin = NULL;

    CU_ASSERT_EQUAL(obtenirIemeElement(file,2),stat2);
}

void test_obtenirIElement_fin() {
    FileDePriorite file; 
    stat1 = S_statistique('a', 3);
    stat2 = S_statistique('b', 4);
    stat3 = S_statistique('c', 7);

    file.longueur = 3;
    file.debut.arbre = AH_arbrehuffman(stat1);
    file.debut.listeSuivante = AH_arbrehuffman(stat2);
    file.debut.listeSuivante.listeSuivante = AH_arbrehuffman(stat3);
    file.fin = NULL;

    CU_ASSERT_EQUAL(obtenirIemeElement(file,3),stat3);
}

int main (int argc, char** argv) {
    int main() {
    CU_pSuite pSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    pSuite = CU_add_suite("Tests FileDePriorite", NULL, NULL);
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

}