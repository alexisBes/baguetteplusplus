#include "Logger.h"
#include <stdio.h>

void erreur_MauvaisMotsCLE(const int ligne, const char *motcle)
{
    printf("ERREUR : Mots cle non reconnu a la ligne %d. Verifier que le mots cle %s est valide. \n", ligne, motcle);
}

void erreur_VariableExiste(const int ligne, const char* variable){
    printf("ERREUR : La variabe %s est déja déclaré. Changez le nom de la variable a la ligne %d. \n", variable, ligne);
}

void erreur_MauvaisOperateur(const int ligne, const char* operateur)
{
    printf("ERREUR : L'operateur %s invalide a la ligne %d. \n", operateur, ligne);
}