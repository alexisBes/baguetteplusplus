# Introduction
Le baguette plus plus est un language de programation en français se basant sur la méthode de programmation LDA[language de description des algorithme](https://fr.wikibooks.org/wiki/Programmation_LDA) .
L'objectif est de proposer un language de programmation francais.

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
  cd build
  cmake ..
  make
```
en recupérant l'executable générer (baguetteplusplus pour linux, baguetteplusplus.exe pour window) vous pouvez compiler un fichier .bpp .

Des exemple de fichier se trouvent dans le dossier test.

# Tester le projet
## test de la lib utilitaire
Les tests de la lib utilitaire se base en utilisant CUnit, il ne sont pas compatible avec CTest, qui est intégrer "nativement" avec CMake (enfin en vrai je pourrais, mais un peu la flemme).

Le script "test.sh" va s'occuper de lancer les test unitaire avec avoir fai une compilation propre de 0 du projet.

Pour plus d'information aller dans [la partie utilitaires](utils/README.md)


# Comment contribuer
S'il vous plait, ne le faites pas.
