#include "parser_math.h"
#include <stdlib.h>

#include "enum.h"
#include "bpp_types.h"
#include "lexer_main.h"


/*
 gestion d'une unité mathématique
  il va gérer les instruction unique de type 
  IDENTIFIANT|NOMBRE OPERATEUR IDENTIFIANT|NOMBRE
*/
void gestionUniteMathematique(Tree** currentTree);

/*
    gestion d'un ensemble d'instruction mathématique
    il s'attend a avoir en entrée un début d'instruction de type 
    "IDENTIFIER|NOMBRE OPERATEUR IDENTIFIANT|NOMBRE OPERATEUR [.....] ;"
*/
void gestionMathematique(Tree** currentTree);

Tree* mainMath()
{
    Tree* mathTree = NULL;
    gestionMathematique(&mathTree);
    return mathTree;
}

void gestionMathematique(Tree** currentTree)
{
    uniteSyntaxique *currentSyntaxe = malloc(sizeof(uniteSyntaxique));
    currentSyntaxe->param = NULL;
    getNextToken(&currentSyntaxe->unite,&currentSyntaxe->param);
    if (currentSyntaxe->unite == IDENTIFIANT || currentSyntaxe->unite == NOMBRE)
    {
        if(*currentTree == NULL)*currentTree= createTree(currentSyntaxe,sizeof(uniteSyntaxique));
        else addItem(*currentTree, currentSyntaxe,sizeof(uniteSyntaxique) ,1);
        gestionUniteMathematique(currentTree);
        return;
    }else if (currentSyntaxe->unite == FIN_INSTRUCTION)
    {
        free(currentSyntaxe);
        return;
    }
}

void gestionUniteMathematique(Tree** currentTree)
{
    uniteSyntaxique *currentSyntaxe = malloc(sizeof(uniteSyntaxique));
    currentSyntaxe->param = NULL;
    getNextToken(&currentSyntaxe->unite,&currentSyntaxe->param);
    if (currentSyntaxe->unite >= ADDITION && currentSyntaxe->unite<= DIVISION)
    {
        addParent(*currentTree, currentSyntaxe,sizeof(uniteSyntaxique), 1);
        gestionMathematique((Tree**)&((*currentTree)->rNode));
    }
    return;

}