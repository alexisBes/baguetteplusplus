#include "mainParser.h"
#include "StringTool.h"
#include "ListUtils.h"
#include "ArrayUtils.h"
#include "stddef.h"
#include "constante.h"
#include "enum.h"
#include "Logger.h"
#include "instructionParser.h"

Node *variables = NULL;

int (*checkFunctions[typeLigne_COUNT])(Node*, Node*) = {
    checkDeclarationInstruction,
    checkPourInstruction,
    checkTantQueInstruction,
    checkJusqueInstruction,
    checkSiInstruction,
    checkSelonInstruction,
    checkSampleInstruction
};

/*********
 * Private function declaration
 */
int checkLine(Node *line, const int ligne);
int checkKeyWordLine(const char *keyword);

/*********
 * Public function definition
 */
int parsing(LigneCode *output)
{
    int errorCount = 0;
    for (int i = 0; i < output->sizeTokenList; i++)
    {
        checkLine(output->tokenList[i], i);
    }

    return errorCount;
}

/**********
 * Private function definition
 */

int checkLine(Node *data, const int ligne)
{
    int errorCount = 0;
    Token *content = (Token *)data->content;
    int type = content->token;
    int typeLine = checkKeyWordLine(content->value);
    if (typeLine >= typeLigne_COUNT || typeLine < 0)
    {
        erreur_MauvaisMotsCLE(ligne, content->value);
        errorCount += 1;
    }
    else
    {
        errorCount += (*checkFunctions[typeLine])(data, variables); 
    }
    return errorCount;
}

int checkKeyWordLine(const char *keyword)
{
    short int isInArray = 0;
    const char *definitionKW[] = {BPP_DEFINITION_TABLEAU};
    isInArray = findInArray(definitionKW, BPP_DEFINITION_NB, keyword);
    if (isInArray == 1)
        return DECLARATION;

    const char *pourKW[] = {BPP_POUR_TABLEAU};
    isInArray = findInArray(definitionKW, BPP_POUR_NB, keyword);
    if (isInArray == 1)
        return POUR;

    const char *tantQueKW[] = {BPP_TANTQUE_TABLEAU};
    isInArray = findInArray(definitionKW, BPP_TANTQUE_NB, keyword);
    if (isInArray == 1)
        return TANT;

    const char *jusqueKW[] = {BPP_JUSQUE_TABLEAU};
    isInArray = findInArray(definitionKW, BPP_JUSQUE_NB, keyword);
    if (isInArray == 1)
        return JUSQUE;

    const char *selonKW[] = {BPP_SELON_TABLEAU};
    isInArray = findInArray(definitionKW, BPP_SELON_NB, keyword);
    if (isInArray == 1)
        return SELON;

    const char *siKW[] = {BPP_SI_TABLEAU};
    isInArray = findInArray(definitionKW, BPP_SI_NB, keyword);
    if (isInArray == 1)
        return SI;

    if (isInArray == 0)
        return INSTRUCTION;
}