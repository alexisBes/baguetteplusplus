#include "parser_main.h"
#include "parser_math.h"

#include "tools_string.h"

#include <stdlib.h>
#include "bpp_types.h"
#include "lexer_main.h"

void gestionIdentifiant(Tree **current);

void parsing(Tree **arbreSyntaxique)
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
    // Si ca commence par un type, alors on a une nouvelle variables
    if (NONSIGNE <= unite && unite <= LONG_Nos)
    {
        if (NONSIGNE == unite)
        {
            unite_type secondUnite = UNITE_LEXICAL_COUNT;
            getNextToken(secondUnite, &param);
            if (OCTET <= unite && unite <= LONG_Nos)
                unite = secondUnite + 1;
            else
            {
                printf("Erreur: Type non reconnus.");
                exit(-1);
            }
        }
        
        unite_type uniteIdent = UNITE_LEXICAL_COUNT;
        getNextToken(uniteIdent, &param);
        if (IDENTIFIANT != uniteIdent)
        {
            printf("Erreur: Un identifiant est attendu.");
            exit(-1);
        }

        // et on l'ajouter a la tables des symboles.
    }
    return;
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
