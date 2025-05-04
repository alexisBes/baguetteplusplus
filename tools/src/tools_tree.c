#include "tools_tree.h"

#include <stdlib.h>
#include "string.h"
/****
 * PRIVATE DECLARATION
 */
Tree * _allocItem(Tree *dest, void *content, const long size);

/****
 * PUBLIC DEFINITION
 */
Tree *createTree(void *content, const long size)
{
    Tree *newTree = malloc(sizeof(Tree));
    newTree->content = malloc(size);
    memcpy(newTree->content,content, size);
    newTree->size = size;
    newTree->lNode = NULL;
    newTree->rNode = NULL;
    return newTree;
}

void clearTree(Tree *tree)
{
    if ( tree->lNode != NULL)
    {
        clearTree(tree->lNode);
    }
    if (tree->rNode != NULL)
    {
        clearTree(tree->rNode);
    }
    free(tree);
    return;
}

char addItem(Tree *tree, void *content, const long size,const char isLeft)
{
    if (isLeft)
    {
        tree->lNode= _allocItem(tree->lNode, content, size);
        return tree->lNode != NULL;
    }
    else
    {
        tree->rNode= _allocItem(tree->rNode, content, size);
        return tree->rNode != NULL;
    }
}

char addParent(Tree *tree, void *content, const long size,const char isLeft)
{
    void* tmp_content = tree->content;
    int old_size = tree->size;
    tree->content = malloc(size);
    memcpy(tree->content, content, size);
    tree->size=size;
    Tree* lTree = tree->lNode;
    tree->lNode = NULL;
    Tree* rTree = tree->rNode;
    tree->rNode = NULL;
    if (isLeft)
    {
        addItem(tree,tmp_content, old_size,1);
        tree->lNode->lNode =lTree;
        tree->lNode->rNode = rTree;
    }
    else
    {
        addItem(tree,tmp_content,old_size,0);
        tree->rNode->lNode =lTree;
        tree->rNode->rNode = rTree;
    }
    return tree != NULL;
}

Tree *findItemInTree(Tree *tree, void *content, char (*func)(const void *,const void *))
{
    if (func(tree->content, content))
    {
        return tree;
    }
    else
    {
        Tree* tmpTree = NULL;
        if(tree->lNode != NULL){
            tmpTree = findItemInTree(tree->lNode, content, func);
        }
        if(tmpTree != NULL) return tmpTree;
        if (tree->rNode != NULL)
        {
            tmpTree = findItemInTree(tree->rNode, content, func);
        }
        if(tmpTree != NULL) return tmpTree;
        else return NULL;
    }
    
    
}

/****
 * PRIVATE DEFINITION
 */
Tree * _allocItem(Tree *tree, void *content, const long size)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(Tree));
        tree->lNode = NULL;
        tree->rNode = NULL;
        tree->content = malloc(size);
        memcpy(tree->content,content, size);
        tree->size = size;
        return tree;
    }
    return NULL;
}