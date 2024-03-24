#include "mainLexer.h"

#include <stdlib.h>
#include <stdio.h>

#include <StringTool.h>
#include <ListUtils.h>
#include <string.h>
#include "enum.h"
#include "constante.h"

int checkTypeToken(char *token);
int checkIgnorableChar(const char c);
void addToken(LexerData *output, char *token);

int tokenizeDocument(char *source, long int length, LexerData *output)
{
    char *currentTokenValue;
    output->tokenList = NULL;
    short int isCommentaire = 0;
    for (long int i = 0; i < length; i++)
    {
        char current = source[i];
        int isIgnorable = checkIgnorableChar(current);
        if (isIgnorable == -1 || isIgnorable == 3)
        {
            printf("[ERREUR] Jeton >%c< innatendue Error %d.", current, isIgnorable);
            return -1;
        }
        if (isIgnorable == 0)
        {
            char *tmp = currentTokenValue;
            currentTokenValue = concatanateChar(tmp, current);
        }
        else
        {
            int type = checkTypeToken(currentTokenValue);
            if (type == OPERATEUR && (currentTokenValue == NULL || strlen(currentTokenValue) > 1))
            {
                printf("[ERREUR] Jeton innatendue %s%c.", currentTokenValue, current);
                return -1;
            }
            addToken(output, currentTokenValue);
            if (isIgnorable == 2)
            {
                char *tmp = currentTokenValue;
                currentTokenValue = concatanateChar(tmp, current);
            }
            else
            {
                currentTokenValue = "";
            }
        }
    }
    return 0;
}

void eraseLexerData(LexerData *data)
{
    if (data->tokenList != NULL)
    {
        clearList(data->tokenList);
    }
}

void printLexer(LexerData *data)
{
    printf("Les Token récupéré sont ");
    Node *curNode = data->tokenList;
    while (curNode != NULL)
    {
        Token *curToken = (Token *)curNode->content;
        printf("%s %d;", curToken->value, curToken->token);
        curNode = curNode->nextNode;
    }
    printf("\n");
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

int checkIgnorableChar(const char c)
{
    char delimiteur[] = "\t \n;!";
    char operateur[] = "=-+/*<>:^";
    int isDelimiteur = isCharExistInArray(c, delimiteur, 6);
    int isOperateur = (isCharExistInArray(c, operateur, 10) << 1);

    if (!isDelimiteur && !isOperateur && !('a' <= c && c >= 'z') && !('A' <= c && c >= 'Z') && !('0' <= c && c >= '9'))
    {
        return -1;
    }
    return isDelimiteur | isOperateur;
}

void addToken(LexerData *ld, char *token)
{
    Token *newToken = malloc(sizeof(Token));
    newToken->token = checkTypeToken(token);
    newToken->value = token;
    if (ld->tokenList == NULL)
    {
        ld->tokenList = createNodeList(newToken);
    }
    else
    {
        addNode(ld->tokenList, newToken);
    }
}