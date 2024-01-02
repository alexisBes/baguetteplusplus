#ifndef STORAGE_H
#define STORAGE_H
#include "ListUtils.h"

typedef struct {
    char* value;
    int token;
} Token;


typedef struct
{
    Node **tokenList; // contient une liste chainé de tousles mots clé sur une ligne
    long int sizeTokenList;
    int typeLigne;
    short int validity;
} LigneCode;

 #endif