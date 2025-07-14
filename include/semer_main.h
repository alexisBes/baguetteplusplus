#ifndef SEMER_MAIN_H
#define SEMER_MAIN_H

#include "bpp_types.h"

char add_symbol(unite_type type, const char *varName);

char isSymbolExist(const char *varName);

const unite_semantique *getSymbol(const char *varName);

void cleanTable();
#endif