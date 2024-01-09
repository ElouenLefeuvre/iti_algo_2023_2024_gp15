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
#include "Compress.h"
#include "Decompression.h"


int main(){
    //COMP_compresser("file.txt");
    DECOMP_decompresser("compressedFile.huff");
    
}

