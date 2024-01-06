/**
 * \file Ensemble.h
 * \brief Implantation du TAD Ensemble pour le Compresseur d'Huffman
 * \author A. El Faïq, T. Barsot, W. Vilayvong, E. Lefeuvre
 *
 */

#ifndef  __ENSEMBLE__
#define __ENSEMBLE__
#include <stddef.h>

/**
 * \brief Le type Ensemble permet d'implementer plusieurs fonctions  nécessaire dans compresser et décompresser
 *
 */
typedef struct {
    void  **elements;   /**< Pointeur vers un element (generique ici pour pouvoir etre utiliser dans plusieurs cas differents) */
    size_t tailleElement;   /**< Taille de l'élément dont l'on a besoin */
    size_t taille;    /**< Nombre d'elements dans l'ensemble  */
} Ensemble;

/**
 * \fn Ensemble E_initialiserEnsemble(size_t tailleElement)
 * \brief Fonction qui permet d'initialiser un ensemble
 *
 * \param tailleElement : taille de l'element qui va être utilisé
 * \return Ensemble
 */
Ensemble E_initialiserEnsemble(size_t tailleElement);

/**
 * \fn void E_ajouter(Ensemble *ens, void *element)
 * \brief Fonction qui permet d'ajouter un element dans un ensemble
 * \param ens : l'ensemble 
 * \param element : l'element à ajouter

 */
void E_ajouter(Ensemble *ens, void *element);

/**
 * \fn void E_supprimer(Ensemble *ens, void *element)
 * \brief Fonction qui permet de supprimer un element dans un ensemble
 * \param ens : l'ensemble 
 * \param element : l'element à supprimer

 */
void E_supprimer(Ensemble *ens, void *element);

/**
 * \fn void *E_obtenirIemeElement(const Ensemble *ens, size_t index)
 * \brief Fonction qui permet d'obtenir l'ieme element d'un ensemble
 * \param ens : l'ensemble 
 * \param index : la position de l'element que l'on cherche

 */
void *E_obtenirIemeElement(const Ensemble *ens, size_t index);

/**
 * \fn void E_libererEnsemble(Ensemble *ens)
 * \brief Fonction qui permet de libérer un ensemble
 * \param ens : l'ensemble 

 */
void E_libererEnsemble(Ensemble *ens);

#endif