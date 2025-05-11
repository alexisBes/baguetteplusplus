#include "tools_tree.h"

#include <stdlib.h>
#include "string.h"
#include "tools_string.h"
/****
 * PRIVATE DECLARATION
 */
Tree * _allocItem(Tree *dest, unite_instruction *content);

/****
 * PUBLIC DEFINITION
 */
Tree *createTree(unite_instruction *content)
{
    Tree *newTree = malloc(sizeof(Tree));
    newTree->content = malloc(sizeof(unite_instruction));
    memcpy(newTree->content,content, sizeof(unite_instruction));
    newTree->content->param = copyString(content->param);
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
    if(tree->content->param != NULL)free(tree->content->param);
    free(tree->content);
    free(tree);
    return;
}

char addItem(Tree *tree, unite_instruction *content,const char isLeft)
{
    if (isLeft)
    {
        tree->lNode= _allocItem(tree->lNode, content);
        return tree->lNode != NULL;
    }
    else
    {
        tree->rNode= _allocItem(tree->rNode, content);
        return tree->rNode != NULL;
    }
}

char addParent(Tree *tree, unite_instruction *content,const char isLeft)
{
    void* tmp_content = tree->content;
    tree->content = malloc(sizeof(unite_instruction));
    memcpy(tree->content, content,sizeof(unite_instruction));
    Tree* lTree = tree->lNode;
    tree->lNode = NULL;
    Tree* rTree = tree->rNode;
    tree->rNode = NULL;
    if (isLeft)
    {
        addItem(tree,tmp_content,1);
        tree->lNode->lNode =lTree;
        tree->lNode->rNode = rTree;
    }
    else
    {
        addItem(tree,tmp_content,0);
        tree->rNode->lNode =lTree;
        tree->rNode->rNode = rTree;
    }
    return tree != NULL;
}

Tree *findItemInTree(Tree *tree, unite_instruction *content, char (*func)(const unite_instruction *,const unite_instruction *))
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
Tree * _allocItem(Tree *tree, unite_instruction *content)
{
    if (tree == NULL)
    {
        tree = malloc(sizeof(Tree));
        tree->lNode = NULL;
        tree->rNode = NULL;
        tree->content = malloc(sizeof(unite_instruction));
        memcpy(tree->content,content,sizeof(unite_instruction));
        tree->content->param = copyString(content->param);
        return tree;
    }
    return NULL;
}