#include "tools_stack.h"
#include "CUnit/CUnit.h"
#include "stdlib.h"
Stack commonStack;

int Init_ToolsStack()
{
    return 0;
}
int Clean_ToolsStack()
{
    return 0;
}

void test_CreateStack()
{
    element_pile newEle;
    newEle.lValue.type = DSS;
    newEle.lValue.idx = -1;
    newEle.rValue.type = DSS;
    newEle.rValue.idx = -1;
    newEle.type = AFFECTATION;
    commonStack = createPile(newEle);

    CU_ASSERT_EQUAL(commonStack.size, 1);
}

void test_pushElement()
{
    element_pile newEle;
    newEle.lValue.type = DSS;
    newEle.lValue.idx = -1;
    newEle.rValue.type = DSS;
    newEle.rValue.idx = -1;
    newEle.type = AFFECTATION;

    element_pile elementWithidx;
    elementWithidx.lValue.type = DSS;
    elementWithidx.lValue.idx = 3;
    elementWithidx.rValue.type = DSS;
    elementWithidx.rValue.idx = 3;
    elementWithidx.type = AFFECTATION;

    pushElement(&commonStack, newEle);
    CU_ASSERT_EQUAL(commonStack.size, 2);

    pushElement(&commonStack, elementWithidx);
    CU_ASSERT_EQUAL(commonStack.size, 3);
}

void test_pushElement_KO()
{
    element_pile newEle;
    newEle.lValue.type = DSS;
    newEle.rValue.type = DSS;
    newEle.type = AFFECTATION;

    Stack myStack;
    myStack.size=0;
    myStack.pile=0;
    pushElement(&myStack, newEle);

    CU_ASSERT_EQUAL(myStack.size, 0);
    CU_ASSERT_EQUAL(myStack.pile, NULL);
}

void test_popElement()
{
    element_pile elementWithidx = popElement(&commonStack);

    CU_ASSERT_EQUAL(elementWithidx.lValue.type, DSS);
    CU_ASSERT_EQUAL(elementWithidx.lValue.idx, 3);
    CU_ASSERT_EQUAL(elementWithidx.rValue.type, DSS);
    CU_ASSERT_EQUAL(elementWithidx.rValue.idx, 3);
    CU_ASSERT_EQUAL(elementWithidx.type, AFFECTATION);
    CU_ASSERT_EQUAL(commonStack.size, 2);
    
    element_pile element = popElement(&commonStack);


    CU_ASSERT_EQUAL(element.lValue.type, DSS);
    CU_ASSERT_EQUAL(element.rValue.type, DSS);
    CU_ASSERT_EQUAL(element.type, AFFECTATION);
    CU_ASSERT_EQUAL(commonStack.size, 1);
    
    element = popElement(&commonStack);


    CU_ASSERT_EQUAL(element.lValue.type, DSS);
    CU_ASSERT_EQUAL(element.rValue.type, DSS);
    CU_ASSERT_EQUAL(element.type, AFFECTATION);
    CU_ASSERT_EQUAL(commonStack.size, 0);
}

void test_popElement_KO()
{
    element_pile element = popElement(&commonStack);
    CU_ASSERT_EQUAL(element.type, -1);
}

void test_clearStack()
{
    clearStack(&commonStack);
    CU_ASSERT_EQUAL(commonStack.size,0);
    CU_ASSERT_EQUAL(commonStack.pile,NULL);
}