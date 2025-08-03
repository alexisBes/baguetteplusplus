#include "generateur_main.h"
#include "bpp_types.h"
#include "stdio.h"

void generate(Tree* arbreInstruction)
{
    unite_instruction* unite = (unite_instruction*) arbreInstruction->content;
    printf("%d", unite->unite);
}