#include "parser_main.h"
#include "parser_math.h"

#include "tools_string.h"

#include <stdlib.h>
#include "bpp_types.h"
#include "lexer_main.h"

void gestionIdentifiant(Tree **current);

void parsing(Tree** arbreSyntaxique)
{
    unite_type unite = UNITE_LEXICAL_COUNT;
    char *param = NULL;
    getNextToken(&unite, &param);
    // gestion d'une instruction mathématique
    if (IDENTIFIANT == unite)
    {
        unite_instruction *currentSyntaxe = malloc(sizeof(unite_instruction));

        currentSyntaxe->param = copyString(param);
        currentSyntaxe->unite = unite;
        *arbreSyntaxique = createTree(currentSyntaxe);

        gestionIdentifiant(arbreSyntaxique);
    }
    else
    {
        free(param);
        printf("Pas encore implementé, mais bientot ;)\n");
        return;
    }
}

void gestionIdentifiant(Tree **current)
{
    unite_instruction *currentSyntaxe = malloc(sizeof(unite_instruction));
    currentSyntaxe->param = NULL;
    getNextToken(&currentSyntaxe->unite, &currentSyntaxe->param);
    if (AFFECTATION == currentSyntaxe->unite)
    {
        addParent(*current, currentSyntaxe, 1);
        (*current)->rNode = mainMath();
    }
}
