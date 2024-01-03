#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stddef.h>
#include<stdlib.h>
#include "Statistiques.h"
#include "Ensemble.h"

void E_libererEnsemble(Ensemble *ens) {
   free(ens->elements);
    ens->elements = NULL;
    ens->tailleElement = 0;
    ens->taille = 0;
}

void E_ajouter(Ensemble *ens, void *element) {
    // Vérifier si l'élément est déjà présent dans l'ensemble
    for (size_t i = 0; i < ens->taille; i++) {
        if (memcmp((char *)ens->elements + i * ens->tailleElement, element, ens->tailleElement) == 0) {
            return; // L'élément est déjà dans l'ensemble
        }
    }

    // Agrandir le tableau dynamique pour accueillir le nouvel élément
    ens->elements = realloc(ens->elements, (ens->taille + 1) * ens->tailleElement);
    if (ens->elements == NULL) {
        fprintf(stderr, "Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }

    // Copier le nouvel élément dans le tableau
    memcpy((char *)ens->elements + ens->taille * ens->tailleElement, element, ens->tailleElement);

    // Mettre à jour la taille de l'ensemble
    ens->taille++;
}

void E_supprimer(Ensemble *ens, void *element) {
     for (size_t i = 0; i < ens->taille; i++) {
        if (memcmp((char *)ens->elements + i * ens->tailleElement, element, ens->tailleElement) == 0) {
            // Déplacer les éléments suivants pour remplir l'espace
            for (size_t j = i; j < ens->taille - 1; j++) {
                memcpy((char *)ens->elements + j * ens->tailleElement,
                       (char *)ens->elements + (j + 1) * ens->tailleElement, ens->tailleElement);
            }

            // Réduire la taille du tableau dynamique
            ens->elements = realloc(ens->elements, (ens->taille - 1) * ens->tailleElement);

            // Mettre à jour la taille de l'ensemble
            ens->taille--;

            return; // Élément trouvé et supprimé
        }
    }
}

void *E_obtenirIemeElement(const Ensemble *ens, size_t index) {
    if (index < ens->taille) {
        return (char *)ens->elements + index * ens->tailleElement;
    } else {
        fprintf(stderr, "Indice hors de la taille de l'ensemble\n");
        exit(EXIT_FAILURE);
    }
}

Ensemble E_initialiserEnsemble(size_t tailleElement) {
    Ensemble ens;
    ens.elements = NULL;
    ens.tailleElement = tailleElement;
    ens.taille = 0;
    return ens;
}

void E_afficherEnsemble(const Ensemble *ens, void (*E_afficherElement)(const void *)) {
    for (size_t i = 0; i < ens->taille; i++) {
        const void *currentElement = (const char *)ens->elements + i * ens->tailleElement;
        E_afficherElement(currentElement);
    }
}

void E_afficherStatistique(const void *element) {
    const Statistiques *stats = (const Statistiques *)element;
    printf("char : %c, entier : %i\n", stats->caracter, stats->ponderation);
}