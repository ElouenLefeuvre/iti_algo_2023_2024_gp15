#include<stdio.h>
#include<stdbool.h>
#include "FileDePriorite.h"
#include "ArbreHuffman.h"
#include "Statistiques.h"

int testEnfiler(FileDePriorite file1, FileDePriorite file2) {
    stat1 = statistiques('a', 3)
    stat2 = statistiques('b', 4)
    stat3 = statistiques('c', 7)

    file1.longueur = 3;
    file1.debut.arbre = arbrehuffman(stat1);
    file1.debut.listeSuivante = arbrehuffman(stat2);
    file1.debut.listeSuivante.listeSuivante = arbrehuffman(stat3);
    file1.fin = NULL;

    file2.longueur = file1.longueur-1;
    file2.debut.arbre=arbrehuffman(stat1)
    file2.debut.listeSuivante = arbrehuffman(stat3);
    file2.fin=NULL;
    enfiler(file2,arbrehuffman(stat3));

    return file1=file2;
}

int main (int argc, char** argv) {
    FileDePriorite file1;
    FileDePriorite file2;
    print("Test insertion : %i",testEnfiler(file1,file2))
}