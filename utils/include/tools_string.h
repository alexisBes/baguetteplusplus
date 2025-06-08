#ifndef STRING_TOOLS
#define STRING_TOOLS

#include "string.h"

/**
 * @name countCharInString
 * @brief Fonctione permettant de compter le nombre de caractere c dans une chaine s donnée 
 * @param s la chaine de caractere d'entrée
 * @param length la taille de al chaine de caractere
 * @param c le caractere a recherché
 * @return le nombre de caractere, en cas d'erreur retourne -1 
 */
int countCharInString(const char* s, const int length, const char c);

/**
 * @name isCharExistInArray
 * @brief Fonction permettant de vérifier si un caractere c existe ou non dans la chaine 
 * @param c le caractere a chercher
 * @param array la chaine de caractere ou rechercher
 * @param length la taille de la chaine de caractere
 * @return return 1 si il existe, 0 sinon. En cas d'erreur, retourne -1
 */
char isCharExistInArray(const char c, const char* array, const int length);

/**
 * @name get_IndexCharInArray
 * @brief Fonctioner permettant de récupérer l'idex de la chaine de caractere dans un tableau.
 * @param s le caractere a chercher
 * @param array la chaine de caractere ou rechercher
 * @param length la taille de la chaine de caractere
 * @return return l'indice du tableau ,retourne -1 s'il n'existe pas.
 */
int getIndexStringInArray(const char *s, const char** array, const int length);

/**
 * @name copyString
 * @brief Copie la chaine de caractere de ori vers la sortie /!\ c'est a vous de libérer a la fois ori et la sortie
 * @param ori la chaine de caractere d'origine
 * @return return  un pointeur vers la chaine copier. En cas d'erreur, retourne NULL
 */
char* copyString(char* ori);

#endif

