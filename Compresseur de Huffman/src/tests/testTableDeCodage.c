#include "TableDeCodage.h"
#include <stdio.h>
#include <CUnit/Basic.h>
#include "ArbreHuffman.h"
#include "Statistiques.h"

void test_obtenirTableDeCodage() {
    ArbreHuffman a;
    Statistiques stat;
    CodeBinaire cb=CB_creerCodeBinaire(1);
    CB_remplirCodeBinaire(&cb,'0');
    stat = S_statistique('c',5);
    a = *AH_arbreDeHuffman(stat);
    TableDeCodage table = TDC_obtenirTableDeCodage(a);
    CU_ASSERT_STRING_EQUAL(table.noeud->c ,'c');
    CU_ASSERT_STRING_EQUAL(CB_codeBinaireToStr(&table.noeud->code),CB_codeBinaireToStr(&cb));
    CU_ASSERT_EQUAL(table.noeud->listeSuivante,NULL);
}

void test_TDC_obtenirCode() {
    TableDeCodage table1, table2, table3;
    CodeBinaire cb=CB_creerCodeBinaire(3);
    table1.noeud->c = 'A';
    CB_remplirCodeBinaire(&cb,'001');
    table1.noeud->code = cb;
    table2.noeud->c = 'B';
    CB_remplirCodeBinaire(&cb,'010');
    table2.noeud->code =  cb;
    table3.noeud->c = 'C';
    CB_remplirCodeBinaire(&cb,'011');
    table3.noeud->code = cb;
    table1.noeud->listeSuivante = &table2;
    table2.noeud->listeSuivante = &table3;

    CodeBinaire res = TDC_obtenirCode(table1,'B');

    CU_ASSERT_STRING_EQUAL(CB_codeBinaireToStr(&res), "010");
    
}


void test_TDC_obtenirCarac() {
    TableDeCodage table1, table2, table3;
    CodeBinaire cb=CB_creerCodeBinaire(3);
    CodeBinaire cbres= CB_creerCodeBinaire(3);
    table1.noeud->c = 'A';
    CB_remplirCodeBinaire(&cb,'001');
    table1.noeud->code = cb;
    table2.noeud->c = 'B';
    CB_remplirCodeBinaire(&cb,'010');
    table2.noeud->code =  cb;
    table3.noeud->c = 'C';
    CB_remplirCodeBinaire(&cb,'011');
    table3.noeud->code = cb;
    table1.noeud->listeSuivante = &table2;
    table2.noeud->listeSuivante = &table3;
    CB_remplirCodeBinaire(&cbres,'010');
    char res = TDC_obtenirCarac(table1,cbres);
    CU_ASSERT_EQUAL(res, 'B');

}

void test_TDC_ajouter(){
    TableDeCodage table = {NULL};
    CodeBinaire cbres= CB_creerCodeBinaire(3);
    CB_remplirCodeBinaire(&cbres,'001');
    TDC_ajouter(&table,'A',&cbres);
    CU_ASSERT_EQUAL(table.noeud->c,'A');
    CU_ASSERT_STRING_EQUAL(CB_codeBinaireToStr(&table.noeud->code),'001')
    CU_ASSERT_EQUAL(table.noeud->listeSuivante,NULL);

}
void test_TDC_supprimer(){
    TableDeCodage table1, table2, table3;
    CodeBinaire cb=CB_creerCodeBinaire(3);
    table1.noeud->c = 'A';
    CB_remplirCodeBinaire(&cb,'001');
    table1.noeud->code = cb;
    table2.noeud->c = 'B';
    CB_remplirCodeBinaire(&cb,'010');
    table2.noeud->code =  cb;
    table3.noeud->c = 'C';
    CB_remplirCodeBinaire(&cb,'011');
    table3.noeud->code = cb;
    table1.noeud->listeSuivante = &table2;
    table2.noeud->listeSuivante = &table3;

    CB_remplirCodeBinaire(&cb,'010');

    TDC_supprimer(&table1,'B',&cb);
    CB_remplirCodeBinaire(&cb,'011');

    CU_ASSERT_PTR_NOT_NULL(&table_test.noeud);
    CU_ASSERT_PTR_NOT_NULL(&table_test.noeud->listeSuivante);
    CU_ASSERT_EQUAL(table1.noeud->listeSuivante->c,'C');
    CU_ASSERT_EQUAL(table1.noeud->listeSuivante->code,cb);
}

void test_TDC_estPresent(){

    TableDeCodage table1, table2, table3;
    CodeBinaire cb=CB_creerCodeBinaire(3);
    table1.noeud->c = 'A';
    CB_remplirCodeBinaire(&cb,'001');
    table1.noeud->code = cb;
    table2.noeud->c = 'B';
    CB_remplirCodeBinaire(&cb,'010');
    table2.noeud->code =  cb;
    table3.noeud->c = 'C';
    CB_remplirCodeBinaire(&cb,'011');
    table3.noeud->code = cb;
    table1.noeud->listeSuivante = &table2;
    table2.noeud->listeSuivante = &table3;

    int res_present = TDC_estPresent(table1, 'B');
    int res_non_present = TDC_estPresent(table1, 'D');
    
    CU_ASSERT_EQUAL(res_present,1);
    CU_ASSERT_EQUAL(res_non_present,0);
}

void test_TDC_estVide() {

    TableDeCodage table ={NULL};
    CodeBinaire cb=CB_creerCodeBinaire(3);
    CU_ASSERT_TRUE(TDC_estVide(table));
    table.noeud->c = 'A';
    CB_remplirCodeBinaire(&cb,'001');
    table.noeud->code = cb;
    CU_ASSERT_FALSE(TDC_estVide(table));

}


int main() {
    // Initialiser le framework CUnit
    CU_initialize_registry();

    // Ajouter la suite de tests
    CU_pSuite suite = CU_add_suite("Suite_de_tests", NULL, NULL);
    CU_add_test(suite, "test_obtenirTableDeCodage", test_obtenirTableDeCodage);
    CU_add_test(suite, "test_TDC_obtenirCode", test_TDC_obtenirCode);
    CU_add_test(suite, "test_TDC_obtenirCarac", test_TDC_obtenirCarac);
    CU_add_test(suite, "test_TDC_ajouter", test_TDC_ajouter);
    CU_add_test(suite, "test_TDC_supprimer", test_TDC_supprimer);
    CU_add_test(suite, "test_TDC_estPresent", test_TDC_estPresent);
    CU_add_test(suite, "test_TDC_estVide", test_TDC_estVide);

    // Exécuter les tests
    CU_basic_run_tests();

    // Nettoyer le framework CUnit
    CU_cleanup_registry();

    return CU_get_error();
}