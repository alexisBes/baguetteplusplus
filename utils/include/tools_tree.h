#ifndef TREE_UTILS_H
#define TREE_UTILS_H

#include "bpp_types.h"

typedef struct s_Tree Tree;

struct s_Tree
{
    Tree *lNode;
    Tree *rNode;
    unite_instruction *content;
};

Tree *createTree(unite_instruction *content);

void clearTree(Tree *tree);

char addItem(Tree *tree,unite_instruction *content,const char isLeft);

char addParent(Tree *tree, unite_instruction *content, const char isLeft);

Tree *findItemInTree(Tree *tree, unite_instruction *content, char (*func)(const unite_instruction *, const unite_instruction *));

#endif