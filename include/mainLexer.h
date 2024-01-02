#ifndef MAIN_LEXER
#define MAIN_LEXER
#include "storage.h"

int tokenizeDocument(char* input,long int length, LigneCode *output);

void eraseLexerData(LigneCode *data);
#endif