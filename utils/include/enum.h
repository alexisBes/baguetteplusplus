#ifndef ENUM_H
#define ENUM_H

/**
 * Tous les types de token possible dans le code
 */
typedef enum {
 IDENTIFIANT, NOMBRE, // generique avec attribut 
 AFFECTATION, //generique sans attribut
 ADDITION, SOUSTRACTION, MULTIPLICATION, DIVISION, // mathématique
 FIN_INSTRUCTION, // structurant fin
 UNITE_LEXICAL_COUNT // FIN
} unite_type;

#endif