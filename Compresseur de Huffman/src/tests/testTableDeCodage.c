#include "TableDeCodage.h"
#include <stdio.h>
#include <CUnit/Basic.h>
#include "ArbreHuffman.h"
#include "Statistiques.h"

TableDeCodage testObtenirTableDeCodage() {
    ArbreHuffman a;
    Statistiques stat;
    stat = S_statistique('c',5);
    a = arbreDeHuffman(stat);
    TableDeCodage table = obtenirTableDeCodage(a);
    CU_ASSERT_EQUAL(table.noeud->c ,'c')
    CU_ASSERT_EQUAL()



}