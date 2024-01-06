/**
 * \file FileDePriorite.h
 * \brief Implantation du TAD FileDePriorite pour le Compresseur d'Huffman
 * \author A. El Faïq, T. Barsot, W. Vilayvong
 *
 */

#ifndef  __FILEDEPRIORITE__
#define __FILEDEPRIORITE__
#include <stdbool.h>
#include "ArbreHuffman.h"


/**
 * \brief Le type FileDePriorite est un type qui permet de faire une file d'arbre d'Huffman pour les trier
 *
 */
typedef struct Noeud {
    ArbreHuffman arbre;     /**< L'arbre d'Huffman à la position actuel de la file*/
    struct Noeud* suivant;  /**< La structure qui permet d'acceder à la partie suivante de la file*/
} Noeud;

typedef struct {
    Noeud* debut; /**< Début de la file*/
    int longueur; /**< Taille de la file */
} FileDePriorite;


/**
 * \fn void FDP_nouvelleFile(FileDePriorite* file)
 * \brief Fonction qui creer une nouvelle file
 *
 * \param file : file que l'on va initialiser
 */
void FDP_nouvelleFile(FileDePriorite* file);

/**
 * \fn void FDP_defiler(FileDePriorite *fp)
 * \brief Fonction qui va défiler une file
 *
 * \param fp : file que l'on va defiler
 */
void FDP_defiler(FileDePriorite *fp);

/**
 * \fn ArbreHuffman FDP_obtenirElement(FileDePriorite fp, int i)
 * \brief Fonction qui va permettre d'obtenir l'ieme element d'une file
 *
 * \param fp : la file
 * \param i : la position de l'element que l'on souhaite obtenir
 * \return ArbreHuffman
 */
ArbreHuffman FDP_obtenirElement(FileDePriorite fp, int i);

/**
 * \fn bool FDP_estVide(FileDePriorite *fp)
 * \brief Fonction qui va permettre de verifier si une file est vide ou non
 *
 * \param fp : la file
 * \return bool
 */
bool FDP_estVide(FileDePriorite *fp);

/**
 * \fn bool FDP_estVide_LCA(Noeud *lca)
 * \brief ?
 * \param lca : ?
 * \return bool
 */
bool FDP_estVide_LCA(Noeud *lca);

/**
 * \fn ArbreHuffman FDP_obtenirElement(FileDePriorite fp, int i)
 * \brief Fonction qui va permettre d'obtenir l'ieme element d'une file
 *
 * \return FileDePriorite
 */
FileDePriorite FDP_fileDePriorite();
void FDP_enfiler(FileDePriorite *file,ArbreHuffman* arbre);
Noeud* FDP_createNoeud(ArbreHuffman* arbreOfLCA);
void FDP_afficherFileDEPriorite(FileDePriorite* file);
void fixerNoeud(FileDePriorite* file,Noeud* noeud, int position);
int trouverIndicePourInsere(ArbreHuffman* arbre,FileDePriorite* file);
#endif