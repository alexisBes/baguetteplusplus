#ifndef SUITE_TOOLS_TREE_H
#define SUITE_TOOLS_TREE_H

int Init_ToolsTree_CreateDestruct();
int Init_ToolsTree();

int Clean_ToolsTree_CreateDestruct();
int Clean_ToolsTree();

void test_CreateTree();
void test_CreateTree_const();
void test_CreateTree_struct();
void test_CreateTree_pointer();

void test_clearTree();
void test_ClearTree_const();
void test_ClearTree_struct();
void test_ClearTree_pointer();


#endif