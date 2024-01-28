#include "instructionParser.h"
#include "string.h"
#include "enum.h"
#include "constante.h"
#include "storage.h"
#include "Logger.h"
#include "stdlib.h"

short int existInVariableList(void *Allvariables, void *name);

int checkDeclarationInstruction(Node *ligne, Node *allVariables, int numLigne)
{
    int errorCount = 0;
    Node *curNode = ligne;
    Token *element = (Token *)curNode->content;
    short int isConstante = strcmp(element->value, "CONST");
    short int isVariable = strcmp(element->value, "VAR");
    if (isConstante != 0 && isVariable != 0)
    {
        errorCount++;
    }
    curNode = ligne->nextNode;
    element = (Token *)curNode->content;

    char *name = element->value;
    if (allVariables != NULL)
    {
        Node *node = findNodeInList(allVariables, name, &existInVariableList);
        if (node != NULL)
        {
            erreur_VariableExiste(numLigne, name);
            errorCount++;
        }
    }

    curNode = curNode->nextNode;
    element = (Token *)curNode->content;
    if (element->token != OPERATEUR && strlen(element->value) != 2)
    {
        erreur_MauvaisMotsCLE(numLigne, name);
        errorCount++;
    }

    if (element->value[0] == ':')
    {
        curNode = curNode->nextNode;
        const char *type = ((Token *)curNode->content)->value;

        int i = 0;
        while (i<= 6)
        {
            /* code */
        }
        
    }
    else if (element->value[0] == '=')
    {
        /* TODO implementation for variable affectation */
    }

    return errorCount;
}

int checkPourInstruction(Node *ligne, Node *allVariables, int numLigne)
{
    int errorCount = 0;
    return errorCount;
}

int checkTantQueInstruction(Node *ligne, Node *allVariables, int numLigne)
{
    int errorCount = 0;

    return errorCount;
}

int checkJusqueInstruction(Node *ligne, Node *allVariables, int numLigne)
{
    int errorCount = 0;

    return errorCount;
}

int checkSiInstruction(Node *ligne, Node *allVariables, int numLigne)
{
    int errorCount = 0;

    return errorCount;
}

int checkSelonInstruction(Node *ligne, Node *allVariables, int numLigne)
{
    int errorCount = 0;

    return errorCount;
}

int checkSampleInstruction(Node *ligne, Node *allVariables, int numLigne)
{
    int errorCount = 0;

    return errorCount;
}

/***********
 * PRIVATE FUNCTION DEFINITION
 */

short int existInVariableList(void *variable, void *name)
{
    Variable *variables = (Variable *)variable;

    int compare = strcmp(variables->name, (const char *)name);

    return compare == 0;
}