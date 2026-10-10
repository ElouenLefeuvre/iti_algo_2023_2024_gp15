# Compresseur de Huffman

## 📋 Description

Un programme complet développé en C capable de compresser et décompresser des fichiers texte et PDF en utilisant l'**algorithme de codage Huffman**. Ce projet implémente une solution efficace de compression de données avec génération automatique de tables de codage optimisées.

## 👥 Auteurs

- LEFEUVRE Elouen
- BARSOT Thomas
- EL FAIQ Achraf
- VILAYVONG Woody

**Date :** Janvier 2024

## 🎯 Fonctionnalités principales

- ✅ Compression de fichiers texte et PDF en fichier binaire
- ✅ Décompression de fichiers compressés avec récupération exacte
- ✅ Calcul automatique de l'arbre de Huffman optimal
- ✅ Génération de tables de codage pour chaque fichier
- ✅ Stockage des statistiques du fichier original dans le fichier compressé
- ✅ Tests unitaires complets avec CUnit
- ✅ Documentation automatique avec Doxygen
- ✅ Rapport de conception détaillée et préliminaire

## 📋 Prérequis

- Compilateur C (gcc recommandé)
- Make
- Bibliothèque CUnit (pour les tests unitaires)
- Doxygen (pour générer la documentation)
- LaTeX (pour générer le rapport PDF)

## 🚀 Installation et Compilation

1. **Clonez le dépôt :**
   ```bash
   git clone <url-du-repo>
   cd iti_algo_2023_2024_gp15
   ```

2. **Compilez le projet :**
   ```bash
   cd programme
   make
   ```

3. **Exécutez les tests unitaires :**
   ```bash
   make tests
   ```

4. **Générez la documentation :**
   ```bash
   make doc
   ```

5. **Générez le rapport en PDF :**
   ```bash
   make rapport
   ```

6. **Nettoyage du projet :**
   ```bash
   make clean                    # Nettoie les fichiers compilés
   make clean DOC=true          # Nettoie également la documentation
   ```

## 💻 Utilisation

### Compression d'un fichier

```bash
./bin/CompDecomp -c fichier_source.txt fichier_compressé.bin
```

### Décompression d'un fichier

```bash
./bin/CompDecomp -d fichier_compressé.bin fichier_restaure.txt
```

## 📁 Structure du Projet

```
iti_algo_2023_2024_gp15/
├── programme/                      # Code source du projet
│   ├── src/                        # Fichiers sources en C
│   │   ├── ArbreHuffman.c
│   │   ├── Compression.c
│   │   ├── Decompression.c
│   │   ├── Statistiques.c
│   │   ├── TableDeCodage.c
│   │   ├── FileDePriorite.c
│   │   ├── CodeBinaire.c
│   │   ├── Octet.c
│   │   ├── main.c
│   │   └── tests/                 # Tests unitaires
│   ├── include/                   # Fichiers d'en-tête
│   ├── bin/                       # Exécutables générés
│   ├── doc/                       # Documentation Doxygen
│   ├── Doxyfile                   # Configuration Doxygen
│   └── makefile                   # Instructions de compilation
├── rapport/                        # Rapport de projet
│   ├── Rapport.tex                # Rapport principal
│   ├── TAD.tex                    # Types abstraits de données
│   ├── Conception détaillée/      # Documents de conception détaillée
│   ├── Conception Préliminaire/   # Documents de conception préliminaire
│   └── images/                    # Images du rapport
└── README.md                      # Ce fichier
```

## 🏗️ Architecture du Projet

Le projet est organisé en plusieurs modules :

- **ArbreHuffman** : Construction et manipulation de l'arbre de Huffman
- **TableDeCodage** : Génération de la table de correspondance des codes
- **Compression** : Algorithme principal de compression
- **Decompression** : Algorithme de décompression
- **FileDePriorite** : Structure de file de priorité pour la construction de l'arbre
- **Statistiques** : Analyse statistique des fichiers
- **CodeBinaire** : Manipulation des données binaires
- **Octet** : Gestion des octets

## 📚 Documentation

La documentation complète du code source est disponible après l'exécution de :
```bash
make doc
```

Les fichiers HTML générés se trouvent dans [programme/doc/html/](programme/doc/html/index.html).

## 🧪 Tests

Le projet inclut une suite de tests unitaires. Pour les exécuter :
```bash
make tests
```

## 📖 Rapport du Projet

Un rapport détaillé couvrant :
- La conception préliminaire
- La conception détaillée
- Les types abstraits de données (TAD)
- L'implémentation et les résultats

Est disponible en PDF après compilation LaTeX.

## 📝 Licence

Ce projet a été réalisé dans le cadre d'un cursus académique (ITI 2023-2024).

## 💡 Notes Importantes

- Le rapport utilise les conventions éducatives avec pseudocode et TAD
- La compression est optimale pour chaque fichier (table de codage personnalisée)
- Les fichiers compressés conservent les statistiques originales pour validation
- La décompression restaure exactement le fichier original (compression sans perte)

---

Pour plus d'informations sur le développement et la conception, consultez les fichiers dans le dossier [rapport/](rapport/).
