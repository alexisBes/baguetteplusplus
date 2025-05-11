#ifndef MAIN_LEXER
#define MAIN_LEXER
#include "enum.h"
#include "stdio.h"

/// @brief initialisation du lexer. A appelé qu'une seul fois. Prépare la lecture du fichier
/// @param path chemin vers le fichier source
void initLexer(const char *path);

/// @brief Recupere une unité lexical. Doit etre utilisé par le parser.
/// @return out_TypeLexique : le token qui vient d'etre récupére
/// @return param : un parametre, NULL sauf pour NUOMBRE et IDENTIFIANT
void getNextToken(unite_type *out_TypeLexique, char **param);

/// @brief Fermeture du fichier sources.
void closeLexer();
#endif