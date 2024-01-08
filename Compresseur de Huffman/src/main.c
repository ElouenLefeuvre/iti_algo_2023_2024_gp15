#include "Octet.h"
#include "FileDePriorite.h"
#include "Octet.h"
#include <stdio.h>
#include <stdlib.h>
#include "CodeBinaire.h"
#include "Statistiques.h"
#include "ArbreHuffman.h"
#include "FileDePriorite.h"
#include "TableDeCodage.h"
#include "Compression.h"
#include "Decompression.h"

int main(){
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <-c ou -d> <fichier original>\n", argv[0]);
        return 1;
    }
    if argv[1]="-c" {
        compresser(argv[2]);
        return 0;
    }
    else {
        if argv[1]="-d" {
        decompresser(argv[2]);
        return 0;
        }
        else {
            fprintf(stderr, "Usage: %s <-c ou -d> <fichier original>\n", argv[0]);
            return 1;
            }
    }
}

