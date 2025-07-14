#include "semer_main.h"

#include "stddef.h"
#include "stdlib.h"
#include "string.h"
#include "tools_string.h"

unite_semantique *tableDesSymbole;
int size = 0;

char add_symbol(unite_type type, const char *varName)
{
    if (size == 0)
    {
        tableDesSymbole = malloc(sizeof(unite_semantique));
    }
    else
    {
        tableDesSymbole = realloc(tableDesSymbole, sizeof(unite_semantique) * size);
    }
    tableDesSymbole[size].type = type;
    strcpy(tableDesSymbole[size].name, varName);
    // la taille d'une variables dépend de sa position dans l'enum.
    // l'octet et leplus petit et le long est le plus grand.
    // donc normalement ca marche
    tableDesSymbole[size].taille = 1 << (9 - (type / 2));
    size++;
    return 1;
}

char isSymbolExist(const char *varName)
{
    int index = 0;
    while (index < size)
    {
        if (strcmp(varName, tableDesSymbole[index].name) == 0)
        {
            return 1;
        }
    }
    return 0;
}

const unite_semantique *getSymbol(const char *varName)
{

    int index = 0;
    while (index < size)
    {
        if (strcmp(varName, tableDesSymbole[index].name) == 0)
        {
            return &tableDesSymbole[index];
        }
    }
    return NULL;
}

void cleanTable()
{
    free(tableDesSymbole);
}