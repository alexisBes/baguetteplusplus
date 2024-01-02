#include "mainParser.h"
#include "StringTool.h"
#include "ListUtils.h"
#include "ArrayUtils.h"
#include "stddef.h"
#include "constante.h"
#include "enum.h"
#include "Logger.h"

Node *variables;
const char *bppMotsCle[] = BPP_MOTCLE_TABLEAU;

/*********
 * Private function declaration
 */
int checkLine(Node *line, const int ligne);

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
    // verification de la ligne
    Node *dataCheck = data;
    while (dataCheck->nextNode != NULL)
    {
        Token *content = (Token *)dataCheck->content;
        int type = content->token;
        if (type != MOTCLE)
        {
            int index = findInStringArray(bppMotsCle, BPP_MOTCLE, content->value);
            if (index == NULL)
            {
                erreur_MauvaisMotsCLE(ligne, content->value);
                errorCount += 1;
            }
            
        }
        else
        {
            erreur_MauvaisMotsCLE(ligne, content->value);
            errorCount += 1;
        }
    }
    return errorCount;
}
