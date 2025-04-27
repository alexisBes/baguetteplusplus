#include "generateur_main.h"
#include "bpp_types.h"
#include "stdio.h"

void generate(Tree* arbreInstruction)
{
    uniteSyntaxique* unite = (uniteSyntaxique*) arbreInstruction->content;
    printf("%d", unite->unite);
}