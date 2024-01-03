#include<stdio.h>
#include<stdbool.h>
#include <CUnit/Basic.h>
#include "FileDePriorite.h"
#include "ArbreHuffman.h"
#include "Statistiques.h"

void test_creation_file() {
    FileDePriorite file;
    file = FDP_fileDePriorite();
    CU_ASSERT_PTR_NULL(file.listeSuivante.arbre);
    CU_ASSERT_PTR_NULL(file.fin);
    CU_ASSERT_EQUAL(file.longueur,0);
    CU_ASSERT_EQUAL(file.debut.arbre,NULL);
}

void testEnfiler_milieu() {
    FileDePriorite file1; 
    FileDePriorite file2;
    file1 = FDP_fileDePriorite();
    file2 = FDP_fileDePriorite();
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file1.fin = NULL;

    file2.longueur = file1.longueur-1;
    file2.debut.arbre=AH_arbrehuffman(stat1);
    file2.debut.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file2.fin=NULL;
    FDP_enfiler(file2,AH_arbrehuffman(stat2));

    CU_ASSERT_PTR_EQUAL(file1.debut.arbre,file2.debut.arbre);
    CU_ASSERT_PTR_EQUAL(file1.debut.listeSuivante.arbre,file2.listeSuivante.arbre);
    CU_ASSERT_EQUAL(file1.longueur,file2.longueur);
}

void testEnfiler_debut() {
    FileDePriorite file1; 
    FileDePriorite file2;
    file1 = FDP_fileDePriorite();
    file2 = FDP_fileDePriorite();
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file1.fin = NULL;

    file2.longueur = file1.longueur-1;
    file2.debut.arbre=AH_arbrehuffman(stat2);
    file2.debut.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file2.fin=NULL;
    FDP_enfiler(file2,AH_arbrehuffman(stat1));

    CU_ASSERT_PTR_EQUAL(file1,file2);
}

void testEnfiler_fin() {
    FileDePriorite file1; 
    FileDePriorite file2;
    file1 = FDP_fileDePriorite();
    file2 = FDP_fileDePriorite();
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file1.fin = NULL;

    file2.longueur = file1.longueur-1;
    file2.debut.arbre=AH_arbrehuffman(stat1);
    file2.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file2.fin= NULL;
    FDP_enfiler(file2,AH_arbrehuffman(stat3));

    CU_ASSERT_PTR_EQUAL(file1,file2);
}

void testDefiler() {
    FileDePriorite file1; 
    FileDePriorite file2;
    file1 = FDP_fileDePriorite();
    file2 = FDP_fileDePriorite();
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);

    file1.longueur = 3;
    file1.debut.arbre = AH_arbrehuffman(stat1);
    file1.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file1.fin = NULL;

    file2.longueur = file1.longueur+1;
    file2.debut.arbre=AH_arbrehuffman(stat1);
    file2.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file2.fin=NULL;
    FDP_defiler(file2);

    CU_ASSERT_PTR_EQUAL(file1,file2);
}

void test_obtenirIElement_debut() {
    FileDePriorite file; 
    file = FDP_fileDePriorite();
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);

    file.longueur = 3;
    file.debut.arbre = AH_arbrehuffman(stat1);
    file.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file.debut.listeSuivante.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file.fin = NULL;

    CU_ASSERT_EQUAL(FDP_obtenirElement(file,1),AH_arbrehuffman(stat1));
}

void test_obtenirIElement_milieu() {
    FileDePriorite file; 
    file = FDP_fileDePriorite();
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);

    file.longueur = 3;
    file.debut.arbre = AH_arbrehuffman(stat1);
    file.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file.debut.listeSuivante.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file.fin = NULL;

    CU_ASSERT_EQUAL(FDP_obtenirElement(file,2),AH_arbrehuffman(stat2));
}

void test_obtenirIElement_fin() {
    FileDePriorite file;
    file = FDP_fileDePriorite();
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);

    file.longueur = 3;
    file.debut.arbre = AH_arbrehuffman(stat1);
    file.debut.listeSuivante.arbre = AH_arbrehuffman(stat2);
    file.debut.listeSuivante.listeSuivante.arbre = AH_arbrehuffman(stat3);
    file.fin = NULL;

    CU_ASSERT_EQUAL(FDP_obtenirElement(file,3),AH_arbrehuffman(stat3));
}

void test_nouvellefile() {
    FileDePriorite file; 
    FileDePriorite file_f; 
    Statistiques stat1 = S_statistique('a', 3);
    Statistiques stat2 = S_statistique('b', 4);
    Statistiques stat3 = S_statistique('c', 7);
    Statistiques stat4 = S_statistique(' ',7);
    ArbreHuffman arbre1 = AH_arbrehuffman(stat1);
    ArbreHuffman arbre2 = AH_arbrehuffman(stat2);
    ArbreHuffman arbre3 = AH_arbrehuffman(stat3);
    ArbreHuffman arbre_f = AH_arbrehuffman(stat4);
    AH_fixerFilsGauche(arbre_f, arbre1);
    AH_fixerFilsDroit(arbre_f, arbre2);

    file = FDP_fileDePriorite();
    FDP_enfiler(file,arbre1); 
    FDP_enfiler(file,arbre2);
    FDP_enfiler(file,arbre3);

    file_f = FDP_fileDePriorite();
    FDP_enfiler(file_f,arbre3);
    FDP_enfiler(file_f,arbre_f);

    FDP_nouvelleFile(file);

    CU_ASSERT_PTR_EQUAL(file,file_f);
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

    if ((NULL == CU_add_test(pSuite, "Test création File", test_creation_file)
        || (NULL == CU_add_test(pSuite, "Test enfiler milieu", testEnfiler_milieu))
        || (NULL == CU_add_test(pSuite, "Test enfiler début", testEnfiler_debut))
        || (NULL == CU_add_test(pSuite, "Test enfiler fin", testEnfiler_fin))
        || (NULL == CU_add_test(pSuite, "Test défiler", testDefiler))
        || (NULL == CU_add_test(pSuite, "Test obtenirElement début", test_obtenirIElement_debut))
        || (NULL == CU_add_test(pSuite, "Test obtenirElement milieu", test_obtenirIElement_milieu))
        || (NULL == CU_add_test(pSuite, "Test obtenirElement fin", test_obtenirIElement_fin))
        || (NULL == CU_add_test(pSuite, "Test nouvelleFile", test_nouvellefile)))) {
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