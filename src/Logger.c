#include "Logger.h"
#include <stdio.h>

void erreur_MauvaisMotsCLE(const int ligne, const char *motcle)
{
    printf("ERREUR : Mots cle non reconnu a la ligne %d. Verifier que le mots cle %s est valide. \n", ligne, motcle);
}