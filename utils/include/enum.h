#ifndef ENUM_H
#define ENUM_H

typedef enum {
 IDENTIFIANT, NOMBRE, // generique avec attribut 
 AFFECTATION, //generique sans attribut
 ADDITION, SOUSTRACTION, MULTIPLICATION, DIVISION, // mathématique
 FIN_INSTRUCTION, // structurant fin
 UNITE_LEXICAL_COUNT // FIN
} unite_type;

#endif