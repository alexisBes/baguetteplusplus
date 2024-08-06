#include "mainLexer.h"

#include <stdlib.h>
#include <stdio.h>

#include <StringTool.h>
#include <ListUtils.h>
#include <string.h>
#include "enum.h"
#include "constante.h"
#include "tokenUtils.h"

/*********
 * Private function declaration
 */
int checkIgnorableChar(const char c);
void addToken(LexerData *output, char *token);
int checkTwoCharOperator(LexerData *output, char *source, int i);

/*********
 * Public function definition
 */
int tokenizeDocument(char *source, long int length, LexerData *output)
{
    char *currentTokenValue = "";
    output->tokenList = NULL;
    for (long int i = 0; i < length; i++)
    {
        char current = source[i];
        int isIgnorable = checkIgnorableChar(current);
        if (isIgnorable == -1 || isIgnorable == 3)
        {
            printf("[ERREUR] Jeton >%c< innatendue. Erreur %d. \n", current, isIgnorable);
            return -1;
        }
        int type = -1;
        char *currentStr = concatanateChar(currentTokenValue, current);
        checkTypeToken(currentStr, &type, NULL);
        if (isIgnorable == 0)
        {
            char *tmp = currentTokenValue;
            currentTokenValue = concatanateChar(tmp, current);
        }
        else
        {
            if (type == -1 || currentTokenValue == NULL)
            {
                printf("[ERREUR] Jeton innatendue %s%c. \n", currentTokenValue, current);
                return -1;
            }
            if (isIgnorable == 1)
            {
                addToken(output, currentTokenValue);
                currentTokenValue = "";
            }
            if (isIgnorable == 2)
            {
                addToken(output, currentTokenValue);
                currentTokenValue = "";
                int tmpIndex = checkTwoCharOperator(output, source, i);
                if (tmpIndex != i)
                {
                    currentTokenValue = "";
                    i = tmpIndex;
                }
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
    List *curNode = data->tokenList;
    while (curNode != NULL)
    {
        Token *curToken = (Token *)curNode->content;
        printf("%s;%d\n", curToken->value, curToken->token);
        if (!curNode->nextNode)
            curNode = NULL;
        else
            curNode = curNode->nextNode;
    }
    printf("\n");
}

#ifdef TESTING

void printLexerToCsv(char *result, LexerData *data)
{
    List *curNode = data->tokenList;
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

/*********
 * Private function definition
 */
int checkIgnorableChar(const char c)
{
    char delimiteur[] = "\t \n";
    char operateur[] = "=-<>:^;+/*";
    int isDelimiteur = isCharExistInArray(c, delimiteur, 4);
    int isOperateur = isCharExistInArray(c, operateur, 11);

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

int checkTwoCharOperator(LexerData *output, char *source, int i)
{
    char tmp[3] = {source[i], source[i + 1], '\0'};
    int type = -1, typeKw = -1;
    checkTypeToken(tmp, &type, &typeKw);
    if (type == OPERATEUR)
    {
        char *newStr = malloc(sizeof(char) * 3);
        memcpy(newStr,tmp,sizeof(char) * 3);
        addToken(output, newStr);
        return i + 1;
    }
    else
    {
        tmp[1]= '\0';
        char *newStr = malloc(sizeof(char) * 2);
        memcpy(newStr, tmp,sizeof(char) * 2);
        addToken(output, newStr);
        return i;
    }
}