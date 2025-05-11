#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include "bpp_types.h"

typedef struct s_Tree Tree;

struct s_Tree
{
    Tree *lNode;
    Tree *rNode;
    unite_type *content;
    int size;
};

Tree *createTree(void *content, const long size);

void clearTree(Tree *tree);

char addItem(Tree *tree,void *content, const long size,const char isLeft);

char addParent(Tree *tree, void *content, const long size, const char isLeft);

Tree *findItemInTree(Tree *tree, void *content, char (*func)(const void *, const void *));

#endif