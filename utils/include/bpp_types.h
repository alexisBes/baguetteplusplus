#ifndef BPP_TYPES_H
#define BPP_TYPES_H
#include "enum.h"

/**
 * Unite lexical du code.
 * Contient les information nécéssaire pour une unité de code
 */
typedef struct
{
    unite_type unite; /** le type de l'instruction (cf enum.h) */
    char *param;      /** parametre qui contient un parametre (utilie pour garder en mémoire la valeur des nombres et identifiant) */
} unite_instruction;

/**
 * Unite semantique du code.
 * Contient les information nécéssaire pour un identifiant
 */
typedef struct
{
    unite_type type;
    int taille;
    char *name;
} unite_semantique;

typedef struct
{
    int idx; // identifiant; 0-n, soit pour la table des symbole, soit poour les registre.
    asm_type type;
} unite_asm;

typedef struct
{
    unite_type type;
    unite_asm lValue;
    unite_asm rValue;
} element_pile;

#endif