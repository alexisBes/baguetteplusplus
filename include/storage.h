#ifndef STORAGE_H
#define STORAGE_H
#include "ListUtils.h"
typedef List Token_List;
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
    Token_List* tokenList;
} LexerData;


#endif