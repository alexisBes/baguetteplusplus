#include "tools_stack.h"
#include "stdlib.h"
#include "string.h"
#include "tools_string.h"
stack createPile(element_pile element)
{
    stack new_stack;
    new_stack.pile = malloc(sizeof(element));

    memcpy(new_stack.pile, &element, sizeof(element));

    new_stack.size = 1;
    return new_stack;
}

void pushElement(stack *stackElement, element_pile elementToPush)
{
    if (stackElement->size == 0 || stackElement->pile == NULL)
    {
        return;
    }

    stackElement->pile = realloc(stackElement->pile, sizeof(element_pile) * (stackElement->size + 1));
    memcpy(&stackElement->pile[stackElement->size], &elementToPush, sizeof(element_pile));
    if (elementToPush.lValue.param != NULL)
        stackElement->pile[stackElement->size].lValue.param = copyString(elementToPush.lValue.param);
    if (elementToPush.lValue.param != NULL)
        stackElement->pile[stackElement->size].rValue.param = copyString(elementToPush.rValue.param);
    stackElement->size++;
}

element_pile popElement(stack *myStack)
{
    element_pile lastElem;

    if (myStack->size == 0)
    {
        lastElem.type = -1;
        return lastElem;
    }
    memcpy(&lastElem, &myStack->pile[myStack->size - 1], sizeof(element_pile));

    if (myStack->pile[myStack->size - 1].lValue.param != NULL)
    {
        lastElem.lValue.param = copyString(myStack->pile[myStack->size - 1].lValue.param);
        free(myStack->pile[myStack->size - 1].lValue.param);
    }
    if (myStack->pile[myStack->size - 1].rValue.param != NULL)
    {
        lastElem.rValue.param = copyString(myStack->pile[myStack->size - 1].rValue.param);

        free(myStack->pile[myStack->size - 1].rValue.param);
    }
    myStack->size--;
    if (myStack->size==0)
    {
        free(myStack->pile);
        myStack->pile=NULL;
    }
    else{
        myStack->pile = realloc(myStack->pile, sizeof(element_pile) * (myStack->size));
    }
    
    
    return lastElem;
}

void clearStack(stack *myStack)
{
    for (int i = 0; i < myStack->size; i++)
    {
        if (myStack->pile[i].lValue.param != NULL)
            free(myStack->pile[i].lValue.param);

        if (myStack->pile[i].rValue.param != NULL)
            free(myStack->pile[i].rValue.param);
    }
    free(myStack->pile);

    myStack->pile = NULL;
    myStack->size = 0;
}