#ifndef  __COMPRESSION__
#define __COMPRESSION__

#include <stdbool.h>
#include <stdio.h>
#include "ArbreHuffman.h"
#include "FileDePriorite.h"
#include "Statistiques.h"
#include "TableDeCodage.h"

// /**
//  * \fn COMP_creerArbre(Statistiques stats)
//  * \brief Fonction qui crée un arbre à partir de statistiques
//  *
//  * \param stats : statistiques de l'arbre créé
//  * \return ArbreHuffman
//  */
// ArbreHuffman COMP_creerArbre(Statistiques stats);


// /**
//  * \fn COMP_insererArbre(FileDePriorite file, ArbreHuffman arbre)
//  * \brief Fonction qui insère un arbre dans une file
//  *
//  * \param arbre : arbre à insérer
//  * \param file : file à parcourir
//  * \return FileDePriorite
//  */
// FileDePriorite COMP_insererArbre(FileDePriorite file, ArbreHuffman arbre);


// /**
//  * \fn COMP_obtenirOccurences(char c)
//  * \brief Fonction qui permet d'obtenir les occurences d'un caractère donné
//  *
//  * \param c : caractère à compter
//  * \return int
//  */
// int COMP_obtenirOccurences(char c);


// /**
//  * \fn COMP_obtenirCaracteres(char nomFichier[])
//  * \brief Fonction qui permet d'obtenir les caractères présents dans un fichier donné
//  *
//  * \param nomFichier : nom du fichier à lire
//  * \return Ensemble
//  */
// Ensemble COMP_obtenirCaracteres(char nomFichier[]);


// /**
//  * \fn COMP_creerStatistiques(char nomFichier[], Ensemble ensC)
//  * \brief Fonction qui permet de créer un ensemble de statistiques pour chaque caractère d'un fichier
//  *
//  * \param nomFichier : nom du fichier à lire
//  * \param ensC : ensemble de caractères du fichier

//  * \return Ensemble
//  */
// Ensemble COMP_creerStatistiques(char nomFichier[], Ensemble ensC);


// /**
//  * \fn COMP_creerFileDePriorite(char nomFichier[])
//  * \brief Fonction qui permet de créer une file de priorité à partir d'un fichier donné
//  *
//  * \param nomFichier : nom du fichier à lire
//  * \return FileDePriorite
//  */
// FileDePriorite COMP_creerFileDePriorite(char nomFichier[]);


// /**
//  * \fn COMP_creerTableDeCodage(ArbreHuffman arbre);
//  * \brief Fonction qui permet de créer une table de codage à partir d'un arbre de Huffman
//  * \param arbre : arbre à partir duquel est crée la table de codage
//  * \return TableDeCodage
//  */
// TableDeCodage COMP_creerTableDeCodage(ArbreHuffman arbre);


/**
 * \fn COMP_compresser(char nomFichier[]);
 * \brief Fonction qui permet de créer un fichier compressé à partir d'un fichier donné
 * \param nomFichier : fichier à compresser
 * \return FILE
 */
FILE* compresser(const char* fileName);

void COMP_null();

#endif