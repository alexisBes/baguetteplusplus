#ifndef STORAGE_H
#define STORAGE_H
#include "ListUtils.h"

typedef struct {
    char* value;
    int token;
} Token;

typedef struct
{
    short int isVariable;
    int typeVariable;
    char* name;
} Variable;

typedef Node TOKEN_LIST;

 #endif