#include "semer_main.h"
#include "bpp_types.h"

#include "stdlib.h"
// PRIVATE FUNCTION  DEFINITION
void genericFunction(Tree *, Stack *);
void generateAffectation(Tree *arbreInstruction, Stack *curStack);
unite_asm handleLRValue(unite_instruction unite);

typedef void (*generatefunc)(Tree *arbre, Stack *curStack);

const generatefunc all_Function[UNITE_LEXICAL_COUNT] =
    {
        genericFunction,     // IDENTIFIANT
        genericFunction,     // NOMBRE
        generateAffectation, // AFFECTATION
        genericFunction,     // ADDITION
        genericFunction,     // SOUSTRACTION
        genericFunction,     // MULTIPLICATION
        genericFunction,     // DIVISION
        genericFunction,     // FIN_INSTRUCTION
        genericFunction,     // ne devrais pas arriver
        genericFunction,     // OCTET
        genericFunction,     // OCTET non signe
        genericFunction,     // COURT
        genericFunction,     // COURT signe
        genericFunction,     // ENTIER
        genericFunction,     // ENTIER non signe
        genericFunction,     // LONG
        genericFunction      // LONG non signe

};

void generateOneInstruction(Tree *arbreInstruction, Stack *curStack);

void generate(Tree *arbreInstruction, Stack *curStack)
{
    printTree(arbreInstruction);

    generateOneInstruction(arbreInstruction, curStack);
}

void generateOneInstruction(Tree *arbreInstruction, Stack *curStack)
{
    all_Function[arbreInstruction->content->unite](arbreInstruction, curStack);
    if (arbreInstruction->lNode != NULL)
    {
        generateOneInstruction(arbreInstruction->lNode, curStack);
    }

    if (arbreInstruction->rNode != NULL)
    {
        generateOneInstruction(arbreInstruction->rNode, curStack);
    }
}

// PRIVATE FUNCTION DECLARATION
void genericFunction(Tree *tree, Stack *s)
{
    printf("%d\n", tree->content->unite);
    return;
}

void generateAffectation(Tree *arbreInstruction, Stack *curStack)
{
    if (arbreInstruction->lNode->content->unite != IDENTIFIANT)
    {
        printf("Erreur : La valeur est constante, elle ne peut pas etre une déstination d'affectation.");
        return;
    }

    Tree *rValue = arbreInstruction->rNode;
    Tree *lValue = arbreInstruction->lNode;
    element_pile element;
    element.rValue= handleLRValue(*rValue->content);
    element.lValue= handleLRValue(*lValue->content);
    element.type = AFFECTATION;

    if( curStack->size == 0)
    {
        *curStack = createPile(element);
    }else
    {
        pushElement(curStack,element);
    }
    
}

unite_asm handleLRValue(unite_instruction unite)
{
    unite_asm asm_return;
    if (unite.unite == IDENTIFIANT)
    {
        asm_return.idx = 0;    // a terme on cherchera dans la table de symbole
        asm_return.type = DSS; // une variable, on vérifiera en cas de constante
    }
    else if (unite.unite== NOMBRE)
    {
        asm_return.idx = -1;   // c'est un nombre
        asm_return.type = RAW; // brut ;)
    }
    else
    {
        asm_return.idx = 1; // franchement la je piffe
        asm_return.type = REGISTRE;
    }
    return asm_return;
}