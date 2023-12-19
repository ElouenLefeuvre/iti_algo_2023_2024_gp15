#ifndef  __ENSEMBLE__
#define __ENSEMBLE__

typedef struct {
    void  **elements;
    size_t tailleElement;
    size_t taille;
} Ensemble;

Ensemble E_initialiserEnsemble(size_t tailleElement);
void E_ajouter(Ensemble *ens, void *element);
void E_supprimer(Ensemble *ens, void *element);
void *E_obtenirIemeElement(const Ensemble *ens, size_t index);
void E_libererEnsemble(Ensemble *ens);

#endif