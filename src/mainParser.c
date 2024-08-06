#include "mainParser.h"
#include "constante.h"
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
void handleInstruction(List *token, int *errorCount);

/*********
 * Public function definition
 */
int parsing(LexerData *output)
{
    int errorCount = 0;

    List *token = output->tokenList;
    while (token != NULL)
    {
        Token *curTok = (Token *)token->content;
        if (curTok->token == MOTCLE)
        {
            if (curTok->keyWord == DEFINITION)
            {
                // do VARIABLE logic
            }
            else
            {
                // do INSTRUCTION logic
            }



        }
    }

    return errorCount;
}

/*********
 * Private function definition
 */
void handleInstruction(List *token, int *errorCount)
{
}
