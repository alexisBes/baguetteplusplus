#include "mainLexer.h"

#include <stdlib.h>

#include <StringTool.h>
#include <ListUtils.h>
#include <string.h>
#include "enum.h"
#include "constanteLexer.h"

#define NB_DELIM_CHAR 10
const char delimChar[] = "<- =/*+-\t";

int checkTypeToken(char *token);

int tokenizeDocument(char *source, long int length, LexerData *output)
{
    int nbRline = countCharInString(source, length, '\n');

    output->tokenList = (Node **)malloc(sizeof(Node *) * nbRline);
    output->sizeTokenList = length;

    char *str;
    int currentLine = 0;
    short int isNewLine = 1;
    for (long int i = 0; i < length; i++)
    {
        char current = source[i];
        short int isDelimiteur = isCharExistInArray(current, delimChar, NB_DELIM_CHAR);
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

void eraseLexerData(LexerData *data)
{
    for (size_t i = 0; i < data->sizeTokenList; i++)
    {
        clearList(data->tokenList[i]);
    }
    free(data->tokenList);
}

int checkTypeToken(char *token)
{
    if (token == NULL)
    {
        return -1;
    }

    short int isFound = 0;
    for (int i = 0; i < BPP_MOTCLE; i++)
    {
        if (strcmp(bppOperateur[i], token))
        {
            isFound = 1;
            break;
        }
    }
    if (isFound)
        return OPERATEUR;

    for (int i = 0; i < BPP_OPERATEUR_SIZE; i++)
    {
        if (strcmp(bppMotsCle[i], token))
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