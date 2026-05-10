#include "tools_stack.h"
#include "stdlib.h"
#include "string.h"

Stack createPile(element_pile element)
{
    Stack new_stack;
    new_stack.pile = malloc(sizeof(element));

    memcpy(new_stack.pile, &element, sizeof(element));

    new_stack.size = 1;
    return new_stack;
}

void pushElement(Stack *stackElement, element_pile elementToPush)
{
    if (stackElement->size == 0 || stackElement->pile == NULL)
    {
        return;
    }

    stackElement->pile = realloc(stackElement->pile, sizeof(element_pile) * (stackElement->size + 1));
    memcpy(&stackElement->pile[stackElement->size], &elementToPush, sizeof(element_pile));
    stackElement->size++;
}

element_pile popElement(Stack *myStack)
{
    element_pile lastElem;

    if (myStack->size == 0)
    {
        lastElem.type = -1;
        return lastElem;
    }
    memcpy(&lastElem, &myStack->pile[myStack->size - 1], sizeof(element_pile));

    myStack->size--;
    if (myStack->size == 0)
    {
        free(myStack->pile);
        myStack->pile = NULL;
    }
    else
    {
        myStack->pile = realloc(myStack->pile, sizeof(element_pile) * (myStack->size));
    }

    return lastElem;
}

void clearStack(Stack *myStack)
{
    free(myStack->pile);

    myStack->pile = NULL;
    myStack->size = 0;
}

/**
    DEBUG ONLY
*/
#include "stdio.h"
void printStack(Stack *myStack)
{
    for (int i = 0; i < myStack->size; i++)
    {
        element_pile element = myStack->pile[i];
        printf("Idx: %d,lvalue: %d, rvalue: %d, type: %d", i, element.lValue.type, element.rValue.type, element.type);
    }
    
}