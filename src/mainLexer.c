#include "mainLexer.h"

#include <stdlib.h>

#include <StringTool.h>
#include <ListUtils.h>
#include <string.h>
#include "enum.h"
#include "constante.h"

int checkTypeToken(char *token);

int tokenizeDocument(char *source, long int length, TOKEN_LIST *output)
{
    const char delimChar[] = DELIM_CHAR_TABLEAU;

    char *str;
    short int isCommentaire = 0;
    for (long int i = 0; i < length; i++)
    {
        char current = source[i];
        short int isDelimiteur = isCharExistInArray(current, delimChar, DELIM_CHAR_NB);
        if (isDelimiteur && str != NULL)
        {
            Token newToken;
            newToken.value = str;
            newToken.token = checkTypeToken(str);
            if (output == NULL)
            {
                output = createNodeList(&newToken);
            }
            else
            {
                addNode(output, &newToken);
            }
            str = NULL;
        }
        else
        {
            if (current == COMMENTAIRE)
            {
                isCommentaire = !isCommentaire;
                continue;
            }
            if (str == NULL)
            {
                str = malloc(sizeof(char) * 2);
                str[0] = current;
                str[1] = '\0';
            }
            else
            {
                str = concatanateChar(str, current);
            }
        }
    }

    return 0;
}

void eraseLexerData(TOKEN_LIST *data)
{
    clearList(data);
}

int checkTypeToken(char *token)
{
    const char *bppOperateur[] = BPP_OPERATEUR_TABLEAU;
    const char *bppMotsCle[] = BPP_MOTCLE_TABLEAU;
    const char *bppType[] = BPP_TYPE_TABLEAU;
    if (token == NULL)
    {
        return -1;
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
        return OPERATEUR;

    for (int i = 0; i < BPP_TYPE_NB; i++)
    {
        if (strcmp(bppType[i], token) == 0)
        {
            isFound = 1;
            break;
        }
    }
    if (isFound)
        return TYPE;

    for (int i = 0; i < BPP_MOTCLE_NB; i++)
    {
        if (strcmp(bppMotsCle[i], token) == 0)
        {
            isFound = 1;
            break;
        }
    }
    if (isFound)
        return MOTCLE;
    else
        return IDENTIFIANT;
}