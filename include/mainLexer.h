#ifndef MAIN_LEXER
#define MAIN_LEXER
#include "storage.h"

int tokenizeDocument(char* input,long int length, LexerData *output);

void eraseLexerData(LexerData *data);

void printLexer(LexerData *data);
#endif