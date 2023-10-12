#pragma once

typedef struct {
	void* prevNode = nullptr;
	void* nextNode = nullptr;
	void* content = nullptr;
} Node;

Node* createNodeList(void* node);

int listSize(Node* nodeList);

void addNode(Node* nodeList,void* node);

void removeNode(Node* nodeList,int index);

Node* pop(Node* nodeList);

Node* getNode(Node* nodeList, int index);

