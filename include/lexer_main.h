#ifndef MAIN_LEXER
#define MAIN_LEXER
#include "enum.h"
#include "stdio.h"

// valeur a vrai si repère la fin d'une instruction (soit caractere ';')
unsigned char getNextToken(FILE *codeFile ,char *out_token);

unsigned char getNToken(FILE* codeFile, char *out_token[],const int size);
#endif