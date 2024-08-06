#include "ListUtils.h"
#include <stdlib.h>


/****
 * PRIVATE FUNCTION DECLARATION
*/

/*****
 * PUBLIC FUNCTION DEFINITION
*/

List* createNodeList(void* node)
{
    List* nodeList = (List*) malloc( sizeof(List));
    nodeList->content = node;
    nodeList->nextNode = NULL;
    nodeList->prevNode = NULL;
    return nodeList;
}

int listSize(List* nodeList)
{
    List* tempNode = nodeList;
    int nb = 1;
    while (tempNode->nextNode != NULL)
    {
        nb++;
        tempNode = tempNode->nextNode;
    }
    return nb;

}

void addNode(List* nodeList, void* node)
{
    List* lastNode = nodeList;
    while (lastNode->nextNode != NULL)
        lastNode = (List*)lastNode->nextNode;
    List* nodeToAdd =(List*) malloc( sizeof(List));
    nodeToAdd->content = node;
    nodeToAdd->prevNode = lastNode;
    nodeToAdd->nextNode = NULL;
    lastNode->nextNode = nodeToAdd;
}

void removeNode(List* nodeList, int index)
{
    List* wantNode = nodeList;
    int i =0;
    while (i < index && wantNode->nextNode != NULL)
    {
        wantNode = (List*)wantNode->nextNode;
        i++;
    }
    List* prevNode =(List*) wantNode->prevNode;
    List* nexNode = (List*)wantNode->nextNode;
    prevNode->nextNode = nexNode;
    if(nexNode != NULL)
        nexNode->prevNode = prevNode;
    free(wantNode);
}

List* pop(List* nodeList)
{
    List* nodeToRemove =(List *) nodeList->prevNode;
    List* prevNode = (List*)nodeToRemove->prevNode;
    nodeList->prevNode = prevNode;
    prevNode->nextNode = nodeList;
    
    return nodeToRemove;
}

List* getNode(List* nodeList, int index)
{
    List* wantNode = nodeList;
    int i=0;
    while (i < index && nodeList->nextNode != NULL)
    {
        wantNode = (List*)wantNode->nextNode;
        i++;
    }
    return wantNode;
}

void clearList(List *nodeList)
{
    List* curNode = nodeList;
    while (curNode->nextNode != NULL)
    {
        List *tempNode = curNode->nextNode;
        free(curNode);
        curNode = tempNode;
    }
    curNode= NULL;
}

List* getLast(List *nodeList)
{
    return getNode(nodeList, listSize(nodeList));
}

List* findNodeInList(List* nodeList, void* contentToCompare,short int (*func)(void*, void*))
{
    List *curNode = nodeList;
    while (curNode->nextNode != NULL)
    {
        short int isFound = func(curNode->content, contentToCompare);
        if(isFound == 1)
        {
            return curNode;
        }
        curNode = (List*) curNode->nextNode;
    }
    return NULL;
}

/***********
 * PRIVATE FUNCTION DEFINITION
*/