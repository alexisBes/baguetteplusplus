#ifndef IDENT_LEXER
#define IDENT_LEXER
#include "enum.h"
#include "stdio.h"

/***
 * @brief Vérifie le type de l'identifiant récupérer
* @param ident : l'identifiant
* @return : le type d'identifiant.
*/
unite_type checkIdentifiant(const char *ident);

#endif