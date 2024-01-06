/**
 * \file ArbreHuffman.h
 * \brief Implantation du TAD Arbre Huffman pour le Compresseur d'Huffman
 * \author A. El Faïq, T. Barsot, W. Vilayvong
 *
 */
#ifndef  __ ARBREDEHUFFMAN__
#define __ARBREDEHUFFMAN__

#include "Statistiques.h";

/**
 * \brief Le type ArbreHuffman permet de stocker et de ranger les statistiques
 *
 */

typedef struct {
    Statistiques statistiques;  /**< la statistique contenue dans l'arbre */
    ArbreHuffman* filsGauche;  /**< le fils gauche de l'arbre actuel */
    ArbreHuffman* filsDroit;    /**< le fils droit de l'arbre actuel */
}ArbreHuffman;

/**
 * \fn ArbreHuffman AH_arbreDeHuffman(Statistiques stat)
 * \brief Fonction de création d'un arbre d'huffman (vide)
 *
 * \param stat : Statistique contenue dans l'arbre
 * \return ArbreHuffman
 */
ArbreHuffman AH_arbreDeHuffman(Statistiques stat);

/**
 * \fn int AH_obtenirOccurences(ArbreHuffman arbre)
 * \brief Fonction qui permet d'obtenir le nombre d'occurences de la statistique contenue dans l'arbre
 *
 * \param arbre : L'arbre dont on veut connaître le nombre d'occurences
 * \return int
 */
int AH_obtenirOccurences(ArbreHuffman arbre);

/**
 * \fn ArbreHuffman AH_fusionner(ArbreHuffman ah1,ArbreHuffman ah2)
 * \brief Fonction qui permet de fusionner 2 arbres d'Huffman
 *
 * \param ah1 : 1er arbre à fusionner
 * \param ah2 : 2eme arbre à fusionner

 * \return ArbreHuffman
 */
ArbreHuffman AH_fusionner(ArbreHuffman ah1,ArbreHuffman ah2);

/**
 * \fn AH_fixerFilsGauche(ArbreHuffman ah1,ArbreHuffman fg)
 * \brief Fonction qui permet de fixer le fils gauche d'un arbre d'Huffman
 *
 * \param ah1 : arbre dont le fils gauche va être modifier
 * \param fg : arbre qui va remplacer le fils gauche de ah1

 */
void* AH_fixerFilsGauche(ArbreHuffman ah1,ArbreHuffman fg);

/**
 * \fn AH_fixerFilsDroit(ArbreHuffman ah1,ArbreHuffman fd)
 * \brief Fonction qui permet de fixer le fils droit d'un arbre d'Huffman
 *
 * \param ah1 : arbre dont le fils droit va être modifier
 * \param fd : arbre qui va remplacer le fils droit de ah1

 */
void* AH_fixerFilsDroit(ArbreHuffman ah1,ArbreHuffman fd);

/**
 * \fn ArbreHuffman AH_obtenirFilsGauche(ArbreHuffman ah1)
 * \brief Fonction qui permet d'obtenir le fils gauche d'un arbre d'Huffman
 * \param ah1 : arbre dont le fils gauche va être obtenu
 * \return ArbreHuffman
 */
ArbreHuffman AH_obtenirFilsGauche(ArbreHuffman ah1);

/**
 * \fn ArbreHuffman AH_obtenirFilsDroit(ArbreHuffman ah1)
 * \brief Fonction qui permet d'obtenir le fils droit d'un arbre d'Huffman
 * \param ah1 : arbre dont le fils droit va être obtenu
 * \return ArbreHuffman
 */
ArbreHuffman AH_obtenirFilsDroit(ArbreHuffman ah1);

/**
 * \fn bool AH_estVide(ArbreHuffman arbre)
 * \brief Fonction qui permet de savoir si un arbre est vide
 * \param arbre : l'arbre 
 * \return bool
 */
bool AH_estVide(ArbreHuffman arbre);

/**
 * \fn bool AH_estFeuille(ArbreHuffman arbre)
 * \brief Fonction qui permet de savoir si un arbre est une feuille
 * \param arbre : l'arbre 
 * \return bool
 */
bool AH_estFeuille(ArbreHuffman arbre);

/**
 * \fn AH_estPresent(ArbreHuffman arbre, char caractere)
 * \brief Fonction qui permet de savoir si un caractère est present dans un arbre
 * \param arbre : l'arbre 
 * \param char : le caractère dont l'on cherche la présence
 * \return bool
 */
bool AH_estPresent(ArbreHuffman arbre, char caractere);

#endif
