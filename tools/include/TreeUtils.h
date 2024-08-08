#ifndef TREE_UTILS_H
#define TREE_UTILS_H
#include "Types.h"

typedef struct s_Tree Tree;

struct s_Tree
{
    Tree *lNode;
    Tree *rNode;
    void *content;
};

Tree *createTree(void *content);

void clearTree(Tree *tree);

bool addItem(Tree *tree,void *content, const bool isLeft);

Tree *findItemInTree(Tree *tree, void *content, bool (*func)(const void *, const void *));

#endif