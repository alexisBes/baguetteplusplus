#ifndef ENUM_H
#define ENUM_H

typedef enum {
 IDENTIFIANT, NOMBRE, // generique avec attribut 
 AFFECTATION, //generique sans attribut
 ADDITION, SOUSTRACTION, MULTIPLICATION, DIVISION, // mathématique
 UNITE_LEXICAL_COUNT // FIN
} uniteLexical;

#endif