#include "mainLexer.h"

#include <stdlib.h>

#include <StringTool.h>
#include <ListUtils.h>
#include <string.h>
#include "enum.h"
#include "constante.h"


int checkTypeToken(char *token);

int tokenizeDocument(char *source, long int length, LigneCode *output)
{
    const char delimChar[] = DELIM_CHAR_TABLEAU;
    int nbRline = countCharInString(source, length, '\n');

    output->tokenList = (Node **)malloc(sizeof(Node *) * nbRline);
    output->sizeTokenList = length;

    char *str;
    int currentLine = 0;
    short int isNewLine = 1;
    for (long int i = 0; i < length; i++)
    {
        char current = source[i];
        short int isDelimiteur = isCharExistInArray(current, delimChar, DELIM_CHAR_NB);
        if (isDelimiteur && str != NULL)
        {
            Token newToken;
            newToken.value = str;
            newToken.token = checkTypeToken(str);
            if (isNewLine)
            {
                output->tokenList[currentLine] = createNodeList(&newToken);
                isNewLine = 0;
            }
            else
            {
                addNode(output->tokenList[currentLine], &newToken);
            }
            str = NULL;
        }
        else
        {
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
        if (current == '\n')
        {
            isNewLine = 1;
            currentLine++;
        }
    }

    return 0;
}

void eraseLexerData(LigneCode *data)
{
    for (size_t i = 0; i < data->sizeTokenList; i++)
    {
        clearList(data->tokenList[i]);
    }
    free(data->tokenList);
}

int checkTypeToken(char *token)
{
    const char *bppOperateur[] = BPP_OPERATEUR_TABLEAU;
    const char *bppMotsCle[] = BPP_MOTCLE_TABLEAU;
    if (token == NULL)
    {
        return -1;
    }

    short int isFound = 0;
    for (int i = 0; i < BPP_MOTCLE; i++)
    {
        if (strcmp(bppOperateur[i], token) == NULL)
        {
            isFound = 1;
            break;
        }
    }
    if (isFound)
        return OPERATEUR;

    for (int i = 0; i < BPP_OPERATEUR_SIZE; i++)
    {
        if (strcmp(bppMotsCle[i], token) == NULL)
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