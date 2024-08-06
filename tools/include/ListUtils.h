#ifndef LIST_UTILS_H
#define LIST_UTILS_H

typedef struct {
    void* prevNode;
    void* nextNode;
    void* content;
} List;

List* createNodeList(void* node);

int listSize(List* nodeList);

void addNode(List* nodeList,void* node);

void removeNode(List* nodeList,const int index);

void clearList(List* nodeList);

List* pop(List* nodeList);

List* getNode(List* nodeList, const int index);

List* getLast(List* nodeList);

List* findNodeInList(List* nodeList, void* contentToCompare,short int (*func)(void*, void*));

#endif