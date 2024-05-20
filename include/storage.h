#ifndef STORAGE_H
#define STORAGE_H
#include "ListUtils.h"

typedef struct {
    char* value;
    int token;
    int keyWord;
} Token;

typedef struct
{
    short int isVariable;
    int typeVariable;
    char* name;
} Variable;

typedef struct
{
    Node* tokenList;
} LexerData;


#endif