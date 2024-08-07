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
    nodeList->next = NULL;
    return nodeList;
}

int listSize(List* nodeList)
{
    List* tempNode = nodeList;
    int nb = 1;
    while (tempNode->next != NULL)
    {
        nb++;
        tempNode = tempNode->next;
    }
    return nb;

}

void addNode(List* nodeList, void* node)
{
    List* lastNode = nodeList;
    while (lastNode->next != NULL)
        lastNode = (List*)lastNode->next;
    List* nodeToAdd =(List*) malloc( sizeof(List));
    nodeToAdd->content = node;
    nodeToAdd->next = NULL;
    lastNode->next = nodeToAdd;
}

void removeNode(List* nodeList, int index)
{
    List* wantNode = nodeList;
    int i =0;
    while (i < index -1 && wantNode->next != NULL)
    {
        wantNode = (List*)wantNode->next;
        i++;
    }
    List* nextNode = wantNode->next;
    if(nextNode != NULL)
        wantNode->next = nextNode->next;
    else wantNode->next = NULL;
    free(wantNode->next);
}

List* getNode(List* nodeList, int index)
{
    List* wantNode = nodeList;
    int i=0;
    while (i < index && nodeList->next != NULL)
    {
        wantNode = (List*)wantNode->next;
        i++;
    }
    return wantNode;
}

void clearList(List *nodeList)
{
    List* curNode = nodeList;
    while (curNode->next != NULL)
    {
        List *tempNode = curNode->next;
        free(curNode);
        curNode = tempNode;
    }
    curNode= NULL;
}

List* getLast(List *nodeList)
{
    return getNode(nodeList, listSize(nodeList));
}

List* findNodeInList(List* nodeList, void* contentToCompare,bool (*func)(void*, void*))
{
    List *curNode = nodeList;
    while (curNode->next != NULL)
    {
        bool isFound = func(curNode->content, contentToCompare);
        if(isFound == 1)
        {
            return curNode;
        }
        curNode = (List*) curNode->next;
    }
    return NULL;
}

/***********
 * PRIVATE FUNCTION DEFINITION
*/