#ifndef STORAGE_H
#define STORAGE_H
#include "type.h"
#include "ListUtils.h"

typedef struct {
    char* value;
    char* token;
}Token;


typedef struct
{
    Node *tokenList; 
} DocContext;
 #endif