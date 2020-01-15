#ifndef FUNC_H
#define FUNC_H
#include <cstddef>

typedef char TE;

struct Node{
		Node *pNext;
		TE data;
		Node(TE data = TE(), Node *pNext = nullptr){
		this->data = data;
		this->pNext = pNext;
		}
};


void push_back(Node* head,TE data);
TE getData(Node* head, int index);
void append(Node* L1, Node* L2);
void printList(Node* L1);
void insert(Node* L1, Node* L2, TE E);
void reverse(Node *&head, Node *&current);
void nox(Node* L1);
void writeList(Node* L1);
void clean();
void pause();

#endif
