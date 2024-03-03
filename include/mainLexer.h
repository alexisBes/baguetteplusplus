#ifndef MAIN_LEXER
#define MAIN_LEXER
#include "storage.h"

int tokenizeDocument(char* input,long int length, TOKEN_LIST *output);

void eraseLexerData(TOKEN_LIST *data);
#endif