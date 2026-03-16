#ifndef SUITE_TOOLS_STACK_H
#define SUITE_TOOLS_STACK_H

int Init_ToolsStack();
int Clean_ToolsStack();

void test_CreateStack();


void test_pushElement();
void test_pushElement_KO();

void test_popElement();
void test_popElement_KO();

void test_clearStack();
#endif