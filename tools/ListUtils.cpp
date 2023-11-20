#include "ListUtils.h"
#include <cstdlib>

Node* createNodeList(void* node)
{
	Node* nodeList = new Node();
	nodeList->content = node;
	return nodeList;
}

int listSize(Node* nodeList)
{
	int nb = 0;
	while (nodeList->nextNode != nullptr)
		nb++;
	return nb;
}

void addNode(Node* nodeList, void* node)
{
	Node* lastNode = nodeList;
	while (lastNode->nextNode != nullptr)
		lastNode = (Node*)lastNode->nextNode;
	Node* nodeToAdd = new Node();
	nodeToAdd->content = node;
	nodeToAdd->prevNode = lastNode;
	lastNode->nextNode = nodeToAdd;
	nodeList->prevNode = nodeToAdd;
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
	delete wantNode;
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
