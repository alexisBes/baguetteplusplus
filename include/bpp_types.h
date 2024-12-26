#ifndef BPP_TYPES_H
#define BPP_TYPES_H

typedef struct
{
    char* name;
    unsigned char bConstante;
    int type;
} Variables;

typedef struct
{
    char* Instruction;
    char registre[3];
    int type;
} Instruction;


#endif