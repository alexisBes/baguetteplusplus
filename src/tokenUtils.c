#include "tokenUtils.h"

#include <stddef.h>
#include <string.h>

#include "constante.h"
#include "enum.h"

/*****
 * Private Constante
 */
const int ARRAY_INDEX_KEYWORD[] = {BPP_DEFINITION_NB, BPP_TANTQUE_NB, BPP_JUSQUE_NB, BPP_POUR_NB, BPP_SI_NB, BPP_SELON_NB, BPP_FIN_NB};

/***
 * Private declaration
 */

int checkKeyword(int index);

/***
 * public definition
 */
void checkTypeToken(char *token, int *oType, int *oTypeKW)
{
    const char *bppOperateur[] = BPP_OPERATEUR_TABLEAU;
    const char *bppMotsCle[] = BPP_MOTCLE_TABLEAU;
    const char *bppType[] = BPP_TYPE_TABLEAU;
    if (token == NULL || token[0] == '\0')
    {
        *oType = -1;
        return;
    }

    short int isFound = 0;
    for (int i = 0; i < BPP_OPERATEUR_SIZE; i++)
    {
        if (strcmp(bppOperateur[i], token) == 0)
        {
            isFound = 1;
            break;
        }
    }
    if (isFound)
    {
        *oType = OPERATEUR;
        return;
    }

    for (int i = 0; i < BPP_TYPE_NB; i++)
    {
        if (strcmp(bppType[i], token) == 0)
        {
            isFound = 1;
            break;
        }
    }
    if (isFound)
    {
        *oType = TYPE;
        return;
    }

    for (int i = 0; i < BPP_MOTCLE_NB; i++)
    {
        if (strcmp(bppMotsCle[i], token) == 0)
        {
            isFound = 1;
            if(oTypeKW != NULL)
                *oTypeKW = checkKeyword(i);
            break;
        }
    }
    if (isFound)
    {
        *oType = MOTCLE;
        return;
    }
    else
    {
        *oType = IDENTIFIANT;
        return;
    }
}

/****
 * private definition
 */

/// @brief Indique le type de mots clé récupéré par le lexer. Si pas de correspondance renvoie -1
/// @param index ou a était récupérer le mots clé
/// @return le type de mots clé définis dans TYPE_INSTRUCTION
int checkKeyword(int index)
{
    int indexMax = 0, i=0;
    while (i < BPP_DIFFERENT_KW_TYPE)
    {
        indexMax += ARRAY_INDEX_KEYWORD[i];
        if (index < indexMax)
        {
            return i;
        }
        i++;
    }
    
    return -1;
}