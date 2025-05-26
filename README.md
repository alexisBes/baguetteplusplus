# Introduction
Le baguette plus plus est un language de programation en français se basant sur le [language de description des algorithme](https://fr.wikibooks.org/wiki/Programmation_LDA) .
L'objectif est de proposer un language de programmation français et d'apprendre des trucs en même temps.

# Pré requis
## Pour un développeur
 - Cmake
 - Gcc
 - Ninja, optionel si non existent, utilisera make
 - CUnit
 - de la patience
## Pour un utilisateur
 - un pc
### compatibilité
Il y en aura.

# Lancement du projet
 Apres aoir cloné le projet, utilisé CMake via les commandes suivantes:
```sh
mkdir build
cmake -B build -S . -G "Unix Makefiles"
cmake --build ./build --target all --config Debug
```
en recupérant l'executable générer (baguetteplusplus pour linux, baguetteplusplus.exe pour window) vous pouvez compiler un fichier .bpp .

Des exemple de fichier se trouvent dans le dossier test.

# Tester le projet
## test de la lib utilitaire
Les tests de la lib utilitaire utilisent CUnit, ils ne sont pas compatible avec CTes, qui est intégrer "nativement" avec CMake (enfin en vrai je pourrais, mais un peu la flemme).

Le script "test.sh" va s'occuper de lancer les test unitaire après avoir fait une compilation propre du projet.

Pour plus d'information aller dans [la partie utilitaires](utils/README.md)

## test de l'analyse lexical
Le test de l'analiseur se base sur CTest. Il attend un fichier avec des unités de code et un fichier avec les résultats attendue.

Pour plus d'information aller dans la partie  [test de l'anayse lexical](/test/lexer/README.MD)

# Comment contribuer
S'il vous plait, ne le faites pas.
