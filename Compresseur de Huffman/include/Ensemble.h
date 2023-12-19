#ifndef  __ENSEMBLE__
#define __ENSEMBLE__

typedef struct {
    void  **elements;
    size_t tailleElement;
    size_t taille;
} Ensemble;

Ensemble initialiserEnsemble(size_t tailleElement);
void ajouter(Ensemble *ens, void *element);
void supprimer(Ensemble *ens, void *element);
void *obtenirIemeElement(const Ensemble *ens, size_t index);
void libererEnsemble(Ensemble *ens);

#endif