# Test de l'analyse lexical
Cette partie s'occupe du test de l'analyse lexical. Les sources correspondants à la politique de test se trouvent dans le dossier src.

L'objectif est de tester tous les unités de code présent dans le fichier [enuméré](../../utils/include/enum.h)

Le fichier source doit contenir tous les identifiants possible en éssayant de varier les éspacements entre chaque token. 
Le fichier avec les résultat attendue est un ficheir de type csv qui contient:  
1. Le numéro correspondant au type de l'analyseur attendue ([cf le fichier enum](../../utils/include/enum.h) )
2. Le paramettre attendue, vide si le token n'attend pas de parametre