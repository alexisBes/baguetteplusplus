#ifndef LIST_UTILS_H
#define LIST_UTILS_H
#include "Types.h"

typedef struct List_S List;
struct List_S
{
    List *next;
    void *content;
};

List *createNodeList(void *node);

int listSize(List *nodeList);

void addNode(List *nodeList, void *node);

void removeNode(List *nodeList, const int index);

void clearList(List *nodeList);

List *getNode(List *nodeList, const int index);

List *getLast(List *nodeList);

List *findNodeInList(List *nodeList, void *contentToCompare, bool (*func)(void *, void *));

#endif