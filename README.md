# ITI_ALGO_2023_2024_GP15

# Compresseur de Huffman

**Auteurs:** [LEFEUVRE Elouen - BARSOT Thomas - EL FAIQ Achraf - VILAYVONG Woody]
**Date:** [09/01/2024]

# Description

Un programme en C capable de compresser un fichier texte en fichier binaire, et inversement en utilisant l'algorithme de codage Huffman.

## Prérequis

- Compilateur C (gcc recommandé)
- Bibliothèque CUnit (pour les tests unitaires)

## Instructions d'Installation

1. Clonez le dépôt.
2. Compilez le projet en exécutant `make`.
3. Exécutez les tests unitaires avec `make tests`.
4. Créer la documentation avec `make doc`.
5. Créer le rapport sous format pdf avec `make rapport`.
6. Nettoyez le projet avant de le reconstruire avec `make clean`.

## Structure du Projet

- `src/`: Fichiers sources
- `include/`: Fichiers d'en-tête
- `tests/`: Tests unitaires
- `bin/`: Exécutables
- `doc/`: Documentation générée par Doxygen
- `Conception détaillée/`: Contient les .tex de la CD
- `Conception préliminaire/`: Contient les .tex de la CP

## Utilisation

- Pour compresser un fichier :

./bin/CompDecomp -c fichier_source.txt fichier_compressé.bin

- Pour décompresser un fichier :

./bin/CompDecomp -d fichier_compressé.bin fichier_restaure.txt

## Fonctionnalités principales

- Permet de compresser un fichier texte ou un pdf en fichier binaire Huffman comportant la longueur, les statistiques du fichier original ainsi que le code compressé.

- Permet de décompresser un fichier binaire Huffman en ce même fichier texte original.

## Évaluation et Performances

Avec un fichier texte de 38..., nous obtenons un fichier compressé de ..., ce qui correspond à un fichier ... moins volumineux.

## Limitations et Améliorations Possibles

Notre principale limitation et piste d'amélioration et de rendre notre programme universel vis à vis du type de fichier, et de rendre cette compression plus efficace.

## Conclusions

Ce projet algorithmique a permis de ...

## Références
- si vous avez des réf a mettre c'est ici


- **Version 1.0.0 (09/01/2024)**