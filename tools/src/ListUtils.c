#include "ListUtils.h"
#include <stdlib.h>


/****
 * PRIVATE FUNCTION DECLARATION
*/
Node * gotoTop(Node* nodeList);

/*****
 * PUBLIC FUNCTION DEFINITION
*/

Node* createNodeList(void* node)
{
    Node* nodeList = (Node*) malloc( sizeof(Node));
    nodeList->content = node;
    nodeList->nextNode = NULL;
    nodeList->prevNode = NULL;
    return nodeList;
}

int listSize(Node* nodeList)
{
    Node* tempNode = nodeList;
    int nb = 1;
    while (tempNode->nextNode != NULL)
    {
        nb++;
        tempNode = tempNode->nextNode;
    }
    return nb;
}

void addNode(Node* nodeList, void* node)
{
    Node* lastNode = nodeList;
    while (lastNode->nextNode != NULL)
        lastNode = (Node*)lastNode->nextNode;
    Node* nodeToAdd =(Node*) malloc( sizeof(Node));
    nodeToAdd->content = node;
    nodeToAdd->prevNode = lastNode;
    nodeToAdd->nextNode = NULL;
    lastNode->nextNode = nodeToAdd;
}

Node* removeNode(Node* nodeList, int index)
{
    Node* wantNode = nodeList;
    int i =0;
    while (i < index && wantNode->nextNode != NULL)
    {
        wantNode = (Node*)wantNode->nextNode;
        i++;
    }
    Node* prevNode =(Node*) wantNode->prevNode;
    Node* nexNode = (Node*)wantNode->nextNode;
    prevNode->nextNode = nexNode;
    if(nexNode != NULL)
        nexNode->prevNode = prevNode;
    free(wantNode);
    if (prevNode ==NULL && nexNode == NULL )
    {
        return NULL;
    }
    Node* returnNode = gotoTop(nexNode);
    if(returnNode == NULL) returnNode = gotoTop(prevNode);
    return returnNode;
}

Node* pop(Node* nodeList)
{
    Node* nodeToRemove =(Node *) nodeList->prevNode;
    Node* prevNode = (Node*)nodeToRemove->prevNode;
    nodeList->prevNode = prevNode;
    prevNode->nextNode = nodeList;
    
    return nodeToRemove;
}

Node* getNode(Node* nodeList, int index)
{
    Node* wantNode = nodeList;
    int i=0;
    while (i < index && nodeList->nextNode != NULL)
    {
        wantNode = (Node*)wantNode->nextNode;
        i++;
    }
    return wantNode;
}

Node* clearList(Node *nodeList)
{
    Node* curNode = nodeList;
    while (curNode->nextNode != NULL)
    {
        Node *tempNode = curNode->nextNode;
        free(curNode);
        curNode = tempNode;
    }
    return NULL;
}

Node* getLast(Node *nodeList)
{
    return getNode(nodeList, listSize(nodeList));
}

Node* findNodeInList(Node* nodeList, void* contentToCompare,short int (*func)(void*, void*))
{
    Node *curNode = nodeList;
    while (curNode->nextNode != NULL)
    {
        short int isFound = func(curNode->content, contentToCompare);
        if(isFound == 1)
        {
            return curNode;
        }
        curNode = (Node*) curNode->nextNode;
    }
    return NULL;
}

/***********
 * PRIVATE FUNCTION DEFINITION
*/
Node * gotoTop(Node* nodeList){
    if(nodeList == NULL)
        return NULL;
    Node*tempNode = nodeList;
    while (tempNode->prevNode != NULL)
    {
        tempNode = tempNode->prevNode;
    }
    return tempNode;
}