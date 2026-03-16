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
 NONSIGNE,// n'est utile que pour le lexer
 OCTET, OCTET_Nos, COURT, COURT_Nos,
 ENTIER , ENTIER_Nos, LONG, LONG_Nos, 
 UNITE_LEXICAL_COUNT // FIN
} unite_type;

typedef enum {
    REGISTRE,
    DSS
} unite_asm;

#endif