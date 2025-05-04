#include "tools_tree.h"
#include <CUnit/CUnit.h>

Tree *commonTree = NULL;
int commonInitContent = 654616876;

int Init_ToolsTree()
{
    commonTree = createTree(&commonInitContent, sizeof(commonInitContent));
    return 0;
}

int Clean_ToolsTree(){
    clearTree(commonTree);
    return 0;
}

void test_CreateTree()
{
    int content = 4253698;

    Tree* myTree = createTree(&content, sizeof(content));
    CU_ASSERT( (*((int*)myTree->content)) == content);
    CU_ASSERT(myTree->lNode == NULL);
    CU_ASSERT(myTree->rNode == NULL);

    clearTree(myTree);
}

