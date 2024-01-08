# ITI_ALGO_2023_2024_GP15
# Compresseur de Huffman

Un programme en C pour la compression et la décompression de fichiers en utilisant l'algorithme de codage Huffman.

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

Pour compresser un fichier :

./bin/CompDecomp -c fichier_source.txt fichier_compressé.bin

Pour décompresser un fichier :

./bin/CompDecomp -d fichier_compressé.bin fichier_restaure.txt