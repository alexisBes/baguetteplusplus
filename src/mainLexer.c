#include "mainLexer.h"

#include <stdlib.h>
#include <stdio.h>

#include <StringTool.h>
#include <ListUtils.h>
#include <string.h>
#include "enum.h"
#include "constante.h"
#include "tokenUtils.h"

int checkIgnorableChar(const char c);
void addToken(LexerData *output, char *token);

int tokenizeDocument(char *source, long int length, LexerData *output)
{
    char *currentTokenValue = "";
    output->tokenList = NULL;
    for (long int i = 0; i < length; i++)
    {
        char current = source[i];
        int isIgnorable = checkIgnorableChar(current);
        int type = -1;
        checkTypeToken(currentTokenValue, &type, NULL);
        if (isIgnorable == -1 || isIgnorable == 3)
        {
            printf("[ERREUR] Jeton >%c< innatendue. Erreur %d. \n", current, isIgnorable);
            return -1;
        }
        if (isIgnorable == 0)
        {
            if (type == OPERATEUR)
            {
                addToken(output, currentTokenValue);
                currentTokenValue = "";
            }
            char *tmp = currentTokenValue;
            currentTokenValue = concatanateChar(tmp, current);
        }
        else
        {
            if (type == OPERATEUR && (currentTokenValue == NULL))
            {
                printf("[ERREUR] Jeton innatendue %s%c. \n", currentTokenValue, current);
                return -1;
            }
            if (isIgnorable)
            {
                addToken(output, currentTokenValue);
                currentTokenValue = "";
            }
            if (isIgnorable == 2)
            {
                addToken(output, currentTokenValue);
                char *tmp = "";
                currentTokenValue = concatanateChar(tmp, current);
            }
        }
    }
    int type = -1, typeKeyword = -1;
    checkTypeToken(currentTokenValue, &type, &typeKeyword);
    if (type != -1)
    {
        addToken(output, currentTokenValue);
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
    printf("Les Token récupéré sont :\n");
    Node *curNode = data->tokenList;
    while (curNode != NULL)
    {
        Token *curToken = (Token *)curNode->content;
        printf("%s;%d\n", curToken->value, curToken->token);
        curNode = curNode->nextNode;
    }
    printf("\n");
}

#ifdef TESTING

void printLexerToCsv(char *result, LexerData *data)
{
    Node *curNode = data->tokenList;
    int size = strlen(result);
    char *nameOutputFile = concatanateString(result, ".lexer", size + 7);
    FILE *ouputFile = fopen(nameOutputFile, "w");
    while (curNode != NULL)
    {
        Token *curToken = (Token *)curNode->content;
        fprintf(ouputFile, "%s;%d;%d;\n", curToken->value, curToken->token, curToken->keyWord);
        curNode = curNode->nextNode;
    }
    fclose(ouputFile);
}

#endif


int checkIgnorableChar(const char c)
{
    char delimiteur[] = "\t \n";
    char operateur[] = "=-+/*<>:^;";
    int isDelimiteur = isCharExistInArray(c, delimiteur, 4);
    int isOperateur = (isCharExistInArray(c, operateur, 11));

    if (!isDelimiteur && !isOperateur && !('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z') && !('0' <= c && c <= '9'))
    {
        return -1;
    }
    isOperateur = isOperateur << 1;
    return isDelimiteur | isOperateur;
}

void addToken(LexerData *ld, char *token)
{
    if (token[0] == '\0')
    {
        return;
    }

    Token *newToken = malloc(sizeof(Token));
    int type = -1, typeKw = -1;
    checkTypeToken(token, &type, &typeKw);
    newToken->token = type;
    newToken->keyWord = typeKw;
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