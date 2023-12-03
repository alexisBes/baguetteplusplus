#ifndef STORAGE_H
#define STORAGE_H
#include "ListUtils.h"

typedef struct {
    char* value;
    int token;
}Token;


typedef struct
{
    Node **tokenList;
    long int sizeTokenList; 
} LexerData;
 #endif