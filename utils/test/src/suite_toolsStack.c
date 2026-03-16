#include "tools_stack.h"
#include "CUnit/CUnit.h"
#include "stdlib.h"
stack commonStack;

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
    newEle.lValue.unite = ADDITION;
    newEle.lValue.param = NULL;
    newEle.rValue.unite = ADDITION;
    newEle.rValue.param = NULL;
    newEle.type = AFFECTATION;
    commonStack = createPile(newEle);

    CU_ASSERT_EQUAL(commonStack.size, 1);
}

void test_pushElement()
{
    element_pile newEle;
    newEle.lValue.unite = ADDITION;
    newEle.lValue.param = NULL;
    newEle.rValue.unite = ADDITION;
    newEle.rValue.param = NULL;
    newEle.type = AFFECTATION;

    element_pile elementWithParam;
    elementWithParam.lValue.unite = ADDITION;
    elementWithParam.lValue.param = "ADDITION";
    elementWithParam.rValue.unite = ADDITION;
    elementWithParam.rValue.param = "ADDITION";
    elementWithParam.type = AFFECTATION;

    pushElement(&commonStack, newEle);
    CU_ASSERT_EQUAL(commonStack.size, 2);

    pushElement(&commonStack, elementWithParam);
    CU_ASSERT_EQUAL(commonStack.size, 3);
}

void test_pushElement_KO()
{
    element_pile newEle;
    newEle.lValue.unite = ADDITION;
    newEle.rValue.unite = ADDITION;
    newEle.type = AFFECTATION;

    stack myStack;
    myStack.size=0;
    myStack.pile=0;
    pushElement(&myStack, newEle);

    CU_ASSERT_EQUAL(myStack.size, 0);
    CU_ASSERT_EQUAL(myStack.pile, NULL);
}

void test_popElement()
{
    element_pile elementWithParam = popElement(&commonStack);

    CU_ASSERT_EQUAL(elementWithParam.lValue.unite, ADDITION);
    CU_ASSERT_STRING_EQUAL(elementWithParam.lValue.param, "ADDITION");
    CU_ASSERT_EQUAL(elementWithParam.rValue.unite, ADDITION);
    CU_ASSERT_STRING_EQUAL(elementWithParam.rValue.param, "ADDITION");
    CU_ASSERT_EQUAL(elementWithParam.type, AFFECTATION);
    CU_ASSERT_EQUAL(commonStack.size, 2);
    free(elementWithParam.rValue.param);
    free(elementWithParam.lValue.param);

    element_pile element = popElement(&commonStack);


    CU_ASSERT_EQUAL(element.lValue.unite, ADDITION);
    CU_ASSERT_EQUAL(element.rValue.unite, ADDITION);
    CU_ASSERT_EQUAL(element.type, AFFECTATION);
    CU_ASSERT_EQUAL(commonStack.size, 1);
    
    element = popElement(&commonStack);


    CU_ASSERT_EQUAL(element.lValue.unite, ADDITION);
    CU_ASSERT_EQUAL(element.rValue.unite, ADDITION);
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