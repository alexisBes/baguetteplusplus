#include "parser_math.h"
#include <stdlib.h>

#include "enum.h"
#include "bpp_types.h"
#include "lexer_main.h"



void gestionUniteMathematique(Tree* currentTree);
void gestionMathematique(Tree* currentTree);

Tree* mainMath()
{
    Tree* mathTree = NULL;
    gestionMathematique(mathTree);
    return mathTree;
}

void gestionMathematique(Tree* currentTree)
{
    uniteSyntaxique *currentSyntaxe = malloc(sizeof(uniteSyntaxique));
    currentSyntaxe->param = NULL;
    getNextToken(&currentSyntaxe->unite,&currentSyntaxe->param);
    if (currentSyntaxe->unite == IDENTIFIANT || currentSyntaxe->unite == NOMBRE)
    {
        if(currentTree == NULL)currentTree= createTree(currentSyntaxe);
        else addItem(currentTree, currentSyntaxe, 1);
        gestionUniteMathematique(currentTree);
        return;
    }else if (currentSyntaxe->unite == FIN_INSTRUCTION)
    {
        free(currentSyntaxe);
        return;
    }
}

void gestionUniteMathematique(Tree* currentTree)
{
    uniteSyntaxique *currentSyntaxe = malloc(sizeof(uniteSyntaxique));
    currentSyntaxe->param = NULL;
    getNextToken(&currentSyntaxe->unite,&currentSyntaxe->param);
    if (currentSyntaxe->unite >= ADDITION && currentSyntaxe->unite<= DIVISION)
    {
        addParent(currentTree, currentSyntaxe, 1);
        gestionMathematique((Tree*)currentTree->lNode);
    }
    return;

}