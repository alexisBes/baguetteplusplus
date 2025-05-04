#include "tools_tree.h"
#include <CUnit/CUnit.h>

int Init_ToolsTree(){
    return 0;
}

int Clean_ToolsTree(){
    return 0;
}

void test_CreateTree()
{
    int content = 4253698;
    Tree* myTree = createTree(&content);
    CU_ASSERT( (*((int*)myTree->content)) == content);
    CU_ASSERT(myTree->lNode ==  NULL);
    CU_ASSERT(myTree->rNode ==  NULL);
}

