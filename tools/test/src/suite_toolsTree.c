#include "stdlib.h"
#include "tools_tree.h"
#include <CUnit/CUnit.h>



Tree *commonTree = NULL;

int Init_ToolsTree_CreateDestruct()
{
    return 0;
}

int Init_ToolsTree()
{
    //commonTree = createTree(&commonInitContent, sizeof(commonInitContent));
    return 0;
}

int Clean_ToolsTree_CreateDestruct()
{
    return 0;
}

int Clean_ToolsTree()
{
    clearTree(commonTree);
    return 0;
}


void test_CreateTree_struct()
{

    unite_instruction content;
    content.unite = 4;
    content.param = malloc(sizeof(char) * 15);
    memcpy(content.param,"jeSuisunchaine", sizeof(char) * 15);

    Tree *myTree = createTree(&content,sizeof(content));
    unite_instruction *treeContent =(unite_instruction *)myTree->content; 
    CU_ASSERT(treeContent->unite == content.unite);
    CU_ASSERT(memcmp(treeContent->param,content.param,sizeof(char)* 15) == 0);
    free(content.param);
    CU_ASSERT(strcmp(treeContent->param,"jeSuisunchaine") == 0);
    CU_ASSERT(myTree->lNode == NULL);
    CU_ASSERT(myTree->rNode == NULL);

    clearTree(myTree);
}

void test_CreateTree_pointer()
{
}

void test_clearTree()
{
}

void test_ClearTree_struct()
{
}

void test_ClearTree_pointer()
{
}