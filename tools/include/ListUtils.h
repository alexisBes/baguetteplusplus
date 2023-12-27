#ifndef LIST_UTILS_H
#define LIST_UTILS_H

typedef struct {
	void* prevNode;
	void* nextNode;
	void* content;
} Node;

Node* createNodeList(void* node);

int listSize(Node* nodeList);

void addNode(Node* nodeList,void* node);

Node* removeNode(Node* nodeList,int index);

Node* pop(Node* nodeList);

Node* getNode(Node* nodeList, int index);

Node* clearList(Node* nodeList);
#endif