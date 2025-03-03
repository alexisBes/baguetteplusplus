#ifndef TREE_UTILS_H
#define TREE_UTILS_H

typedef struct s_Tree Tree;

struct s_Tree
{
    Tree *lNode;
    Tree *rNode;
    void *content;
};

Tree *createTree(void *content);

void clearTree(Tree *tree);

char addItem(Tree *tree,void *content, const char isLeft);

char addParent(Tree *tree, void *content, const char isLeft);

Tree *findItemInTree(Tree *tree, void *content, char (*func)(const void *, const void *));

#endif