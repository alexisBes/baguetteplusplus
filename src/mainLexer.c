#include "mainLexer.h"

#include <stdlib.h>

#include <StringTool.h>
#include <ListUtils.h>
#include "constanteLexer.h"
#include "type.h"

const char delimChar[] = "<- =/*+-";

int tokenizeDocument(char *source, long int length, LexerData *output)
{
    long int nbRline = countCharInString(source, length, '\n');
    long int currentLine = 0;
    output->tokenList = (Node **)malloc(sizeof(Node *));
    output->sizeTokenList = length;

    for (long int i = 0; i < length; i++)
    {
        char *str = source[i];
        while (source[i] != '\n')
        {

        }

        output->tokenList[currentLine] = createNodeList("zer");
    }

    return 0;
}