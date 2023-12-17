#include "ListUtils.h"
#include <stdlib.h>

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
	int nb = 0;
	while (nodeList->nextNode != NULL)
		nb++;
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

	lastNode->nextNode = nodeToAdd;;
}

void removeNode(Node* nodeList, int index)
{
	Node* wantNode = nodeList;
	for (int i = 0; i < index; i++)
	{
		wantNode = (Node*)wantNode->nextNode;
	}
	Node* prevNode =(Node*) wantNode->prevNode;
	Node* nexNode = (Node*)wantNode->nextNode;
	prevNode->nextNode = nexNode;
	nexNode->prevNode = prevNode;
	free(wantNode->content);
	free(wantNode);
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
	for (int i = 0; i < index; i++)
	{
		wantNode = (Node*)wantNode->nextNode;
	}
	return wantNode;
}
