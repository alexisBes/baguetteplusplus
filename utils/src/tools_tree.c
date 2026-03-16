#include "tools_tree.h"

#include <stdlib.h>
#include "string.h"
#include "tools_string.h"
/****
 * PRIVATE DECLARATION
 */

 /**
  * @name _allocItem
  * @brief fonction générique pour l'ajout d'un nouveau noeud
  * @param dest : un pointeur vers le nouveau noeud a ajouter non initialisé
  * @param content : le contenue du noeud
  * @return un pointeur vers le nouveau noeud
  */
Tree * _allocItem(Tree *dest, unite_instruction *content);

 /**
  * @name _printTree
  * @brief fonction técursive d'affichage d'un arbre
  * @param tree : un pointeur vers l'element courant a afficher
  * @param margin : a initialiser a 0
  */
void _printTree(Tree *tree, int margin);

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
    if(tree->content->param != NULL)
        free(tree->content->param);
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
    unite_instruction *tmp_content = malloc(sizeof(unite_instruction));
    tmp_content->unite = tree->content->unite;
    tmp_content->param = copyString(tree->content->param);
    
    // libération de l'ancienne valeur de parametre
    free(tree->content->param);
    
    tree->content->unite = content->unite;
    tree->content->param = copyString(content->param);

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
    free(tmp_content->param);
    free(tmp_content);
    return tree != NULL;
}

#include "stdio.h"
void printTree(Tree *tree)
{
    printf("o");
    _printTree(tree, 0);
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

void _printTree(Tree *tree, int margin)
{
    int newMargin=margin +1;
    for (int i = 0; i < margin; i++)
        printf("    ");
    printf("%d\n", tree->content->unite);
    if (tree->lNode != NULL)
    {
        printf("l");
        _printTree(tree->lNode, newMargin);
    }
    if (tree->rNode != NULL)
    {
        printf("r");
        _printTree(tree->rNode, newMargin);
    }
    if (tree->rNode == NULL && tree->lNode == NULL)
        return;
}