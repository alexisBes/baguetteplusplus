#ifndef TOOLS_STACK_H
#define TOOLS_STACK_H

#include "bpp_types.h"

typedef struct
{
    int size;
    element_pile *pile;
} stack;

stack createPile(element_pile newElement);

void pushElement(stack *stackElement, element_pile elementToPush);

element_pile popElement(stack *stackElement);

void clearStack(stack *mystack);

#endif