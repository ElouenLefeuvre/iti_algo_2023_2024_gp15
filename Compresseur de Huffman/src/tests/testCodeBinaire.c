#include <stdio.h>
#include <CUnit/Basic.h>
#include "CodeBinaire.h" 
#include "ArbreHuffman.h"

void test_obtenirCodeBinaire_feuille() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman feuille = arbrehuffman(stat);
    CodeBinaire code = obtenirCodeBinaire(feuille, 'A'); 
    CU_ASSERT_STRING_EQUAL(code.bits, "");
}

void test_estVide() {
    Statistiques stat = statistique('A',5);
    ArbreHuffman feuille = arbrehuffman(stat);
    CodeBinaire cb1 = obtenirCodeBinaire(feuille, 'A'); 
    CU_ASSERT_TRUE(estVide(cb1));
}
