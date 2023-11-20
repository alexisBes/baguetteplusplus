#pragma once
#include "type.h"
#include <ListUtils.h>

typedef struct {
    std::string value;
    std::string token;
}Token;


typedef struct
{
    Node *tokenList; 
} DocContext;
