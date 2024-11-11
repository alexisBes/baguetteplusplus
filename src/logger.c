#include "logger.h"
#include <stdio.h>

void erreur_MauvaisMotsCLE(const char *motcle)
{
    printf("[ERREUR] Mots cle non reconnu. Verifier que le mots cle %s est valide. \n", motcle);
}

void erreur_VariableExiste(const char* variable){
    printf("[ERREUR] La variabe %s est déja déclaré. Changez le nom de la variable. \n", variable);
}

void erreur_MauvaisOperateur( const char* operateur)
{
    printf("[ERREUR] L'operateur %s invalide. \n", operateur);
}