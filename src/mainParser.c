#include "mainParser.h"
#include "StringTool.h"
#include "ListUtils.h"
#include "ArrayUtils.h"
#include "stddef.h"
#include "constante.h"
#include "enum.h"
#include "Logger.h"

/*********
 * Private function declaration
 */
void handleInstruction(Node *token, int *errorCount);

/*********
 * Public function definition
 */
int parsing(LexerData *output)
{
    int errorCount = 0;

    int size = listSize(output->tokenList);
    Node *token = output->tokenList;
    for (int i = 0; i < size; i++)
    {
        Token *curTok = (Token *)token->content;
        if (curTok->token == MOTCLE)
        {
            
        }
    }

    return errorCount;
}

/*********
 * Private function definition
 */
void handleInstruction(Node *token, int *errorCount)
{
}