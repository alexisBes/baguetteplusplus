#ifndef TOOLS_STACK_H
#define TOOLS_STACK_H

#include "bpp_types.h"

typedef struct
{
    int size;
    element_pile *pile;
} Stack;

Stack createPile(element_pile newElement);

void pushElement(Stack *stackElement, element_pile elementToPush);

element_pile popElement(Stack *stackElement);

void clearStack(Stack *mystack);

void printStack(Stack *myStack);
#endif