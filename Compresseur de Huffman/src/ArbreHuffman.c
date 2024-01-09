#include<stdio.h>
#include<stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "Statistiques.h"
#include "ArbreHuffman.h"


ArbreHuffman* AH_arbreDeHuffman(Statistiques stat) {
    ArbreHuffman *arbre = malloc(sizeof(ArbreHuffman));
    if (arbre != NULL) {
        arbre->statistiques = stat;
        arbre->filsGauche = NULL;
        arbre->filsDroit = NULL;
    }
    return arbre;
}

void AH_fixerStatistique(ArbreHuffman *arbre,  Statistiques stat) {
    arbre->statistiques=stat;
}

Statistiques AH_obtenirStat(ArbreHuffman arbre) {
    return arbre.statistiques;
}

int AH_obtenirPonderation(ArbreHuffman arbre) {
    return S_obtenirPonderation(AH_obtenirStat(arbre));
}

char AH_obtenirCaracter(ArbreHuffman arbre) {
    return arbre.statistiques.caracter;
}

ArbreHuffman* AH_fusionner(ArbreHuffman* arbre1,  ArbreHuffman* arbre2) {
    Statistiques stat ;
    stat.caracter = ' ';
    stat.ponderation = S_obtenirPonderation(arbre1->statistiques) + S_obtenirPonderation(arbre2->statistiques);
    ArbreHuffman* res = AH_arbreDeHuffman(stat);
    if (AH_obtenirPonderation(*arbre1)<AH_obtenirPonderation(*arbre2)) {
        AH_fixerFilsGauche(res, arbre1);
        AH_fixerFilsDroit(res, arbre2);
    }
    else {
        AH_fixerFilsGauche(res, arbre2);
        AH_fixerFilsDroit(res, arbre1);
    }
    return res;
}


void AH_fixerFilsGauche(ArbreHuffman *arbre,  ArbreHuffman *filsGauche) {
    if (arbre != NULL) {
        arbre->filsGauche = filsGauche;
    }
}

void AH_fixerFilsDroit(ArbreHuffman *arbre,  ArbreHuffman *filsDroit) {
    if (arbre != NULL) {
        arbre->filsDroit = filsDroit;
    }
}

ArbreHuffman* AH_obtenirFilsGauche(ArbreHuffman *arbre) {
    return (arbre != NULL) ? arbre->filsGauche : NULL;
}

ArbreHuffman* AH_obtenirFilsDroit(ArbreHuffman *arbre) {
    return (arbre != NULL) ? arbre->filsDroit : NULL;
}

bool AH_estVide(ArbreHuffman *arbre) {
    return arbre==NULL;
}

bool AH_estFeuille(ArbreHuffman arbre) {
    return (AH_estVide(AH_obtenirFilsGauche(&arbre)) && AH_estVide(AH_obtenirFilsDroit(&arbre)));
}

bool AH_estPresent(ArbreHuffman *arbre, char caractere) {
    if (!AH_estVide(arbre)) {
        if (arbre->statistiques.caracter == caractere) {
            return true;
        }
        else {
            return (AH_estPresent(AH_obtenirFilsDroit(arbre), caractere) || AH_estPresent(AH_obtenirFilsGauche(arbre), caractere));
        }
    }
    return false;
}

void AH_afficherArbre(ArbreHuffman *arbre) {
    if (AH_estVide(arbre)) {
        printf("L'arbre est vide.\n");
        return;
    }
    // Utilisation d'une pile pour l'itération
    typedef struct {
        ArbreHuffman *noeud;
        int niveau;
    } StackNode;
    // Initialisation de la pile
    StackNode *pile = NULL;
    int capacitePile = 10;
    int taillePile = 0;
    // Empilement du noeud racine
    StackNode racineNode = {arbre, 0};
    pile = realloc(pile, capacitePile * sizeof(StackNode));
    pile[taillePile++] = racineNode;
    while (taillePile > 0) {
        // Dépilement du noeud
        StackNode noeudCourant = pile[--taillePile];
        // Affichage du noeud
        for (int i = 0; i < noeudCourant.niveau; ++i) {
            printf("    ");
        }
        printf("%c/%d\n", AH_obtenirCaracter(*noeudCourant.noeud), AH_obtenirPonderation(*noeudCourant.noeud));
        // Empilement du fils droit si non nul
        ArbreHuffman *fd = AH_obtenirFilsDroit(noeudCourant.noeud);
        if (fd != NULL) {
            if (taillePile >= capacitePile) {
                capacitePile *= 2;
                pile = realloc(pile, capacitePile * sizeof(StackNode));
            }
            pile[taillePile++] = (StackNode) {fd, noeudCourant.niveau + 1};
        }
        // Empilement du fils gauche si non nul
        ArbreHuffman *fg = AH_obtenirFilsGauche(noeudCourant.noeud);
        if (fg != NULL) {
            if (taillePile >= capacitePile) {
                capacitePile *= 2;
                pile = realloc(pile, capacitePile * sizeof(StackNode));
            }
            pile[taillePile++] = (StackNode) {fg, noeudCourant.niveau + 1};
        }
    }
    // Libération de la mémoire de la pile
    free(pile);
}

ArbreHuffman* copierArbreHuffman(ArbreHuffman* arbre) {
    if (arbre == NULL) {
        return NULL;
    }
    // Copie récursive du noeud actuel
    Statistiques stat= S_statistique(AH_obtenirCaracter(*arbre), AH_obtenirPonderation(*arbre));
    ArbreHuffman* nouveauNoeud = AH_arbreDeHuffman(stat);
    // Appels récursifs pour copier les sous-arbres gauche et droit
    nouveauNoeud->filsGauche = copierArbreHuffman(AH_obtenirFilsGauche(arbre));
    nouveauNoeud->filsDroit = copierArbreHuffman(AH_obtenirFilsDroit(arbre));
    return nouveauNoeud;
}

