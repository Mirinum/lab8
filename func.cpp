#include "func.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

void reverse(Node *&head, Node *&current)
{
    Node* pred = 0;
 
    while (current != NULL)
    {
        Node* next = current->pNext;
        current->pNext = pred;
        pred = current;
        current = next;
    }
      
    head = pred;
}


/*

Node *reverse(Node *lp)
{
    Node *cur, *prev, *tmp;
 
    prev = NULL;
    for(cur = lp; cur != NULL; prev = cur, cur = tmp) {
        tmp = cur->pNext;
        cur->pNext = prev;
    }
    return prev;
}


void reverse(Node* head){
	Node* current = head->pNext;
    head->pNext = nullptr;
    while (current != nullptr)
    {
		Node *next = current->pNext;
		current->pNext = head->pNext;
		head->pNext = current;
		current = next;
    }
    
}

void reverse(Node* L1){
	Node* prev=L1;
	Node* lastrev;
	Node* lastnonrev = L1;
	while(lastnonrev->pNext->pNext!=nullptr){
		lastnonrev=lastnonrev->pNext;
	}
	Node* last = lastnonrev->pNext;
	lastnonrev->pNext->pNext=lastnonrev;
	lastrev=lastnonrev->pNext->pNext;
	while(lastnonrev!=L1){
	while(prev->pNext!=lastnonrev){
		prev=prev->pNext;
	}
	lastnonrev->pNext=prev;
	lastrev=lastnonrev;
	lastnonrev=prev;
	prev=L1;
	}
	L1->pNext->pNext=L1;
	L1->pNext=nullptr;
	*L1=*last;
}


Node reverse(Node* L1){
	Node* last;
	TE waslast;
	Node* prelast;
	Node* lastch;
	Node* curr=L1;
	while(curr->pNext!=nullptr){
		prelast = curr;
		curr=curr->pNext;
	}
	last = curr;
	curr->pNext = prelast;
	lastch = curr;
	curr=L1;
	while(prelast->pNext!=L1){
		while(curr->pNext!=lastch){
			prelast = curr;
			curr = curr->pNext;
		}
		curr->pNext = prelast;
		lastch=curr;
		curr = L1;
	}
	L1->pNext->pNext = L1;
	L1->pNext=nullptr;
	Node tmp (last->data, last->pNext);
	return tmp;
}


Node reverse(Node* L1){
	Node* p = nullptr;
	Node* n = nullptr;
	Node* h = L1;
	for(; h; ) {
		n = h->pNext;
		h->pNext = p;
		p = h;
		h = n;
	}
	return *p;
}


void reverse(Node* head){
	Node* new_head = head->pNext;
	Node* temp = head;
	temp->pNext = nullptr;
	Node* prev = nullptr;
	while(new_head->pNext){
		prev = new_head;
		new_head = new_head->pNext;
		prev->pNext = temp;
		temp = prev;
	}
	new_head->pNext = prev;
	head = new_head;
}

int count(Node* L1){
	int cnt=0;
	while(L1!=nullptr){
		cnt++;
		L1=L1->pNext;
	}
	return cnt;
}


void reverse(Node* L1){
	int a = count(L1);
	Node* list [a];
	Node* l1 = L1->pNext;
	for(int i=0; l1!=nullptr; i++){
		list[i]=l1;
		l1=l1->pNext;
	}
	for(int i=a-1; L1!=nullptr; i--){
		L1->pNext=list[i];
		L1=L1->pNext;
	}
}


Node reverse(Node* head){
	Node* p = nullptr;
	Node* n = nullptr;
	Node* h = head;
	for(; h; ) {
		n = h->pNext;
		h->pNext = p;
		p = h;
		h = n;
	}
	return *p;
} 
*/

void nox(Node* L1){
	TE a = L1->data;
	Node* temp;
	while(L1->pNext!=nullptr){
		if(L1->pNext->data == a){
			temp = L1->pNext->pNext;
			delete L1->pNext;
			L1->pNext=temp;
			continue;
		}
		else a = L1->pNext->data;
		L1=L1->pNext;
	}
}


void insert(Node* L1, Node* L2, TE E){
	while(L1!=nullptr){
		if(L1->data==E){
			Node* temp = L1->pNext;
			while(L2!=nullptr){
				L1->pNext = new Node(L2->data);
				L2=L2->pNext;
				L1=L1->pNext;
			}
			L1->pNext=temp;
		}
		L1=L1->pNext;
	}
}

void push_back(Node* head, TE data){
	//if(!head->data) head->data = data;
	//else{
		while(head->pNext!=nullptr){
			head = head->pNext;
		}
		Node *temp = new Node(data);
		head->pNext = temp;
//	}
}

TE getData(Node* head, int index){
	if(index<0) throw 1;
	Node* temp = head;
	int i=0;
	while(i<index){
		if(temp->pNext!= nullptr){
			temp = temp->pNext;
			i++;
		}
		else throw 1;
	}
	return temp->data;
}

void append(Node* L1, Node* L2){
	while(L2!=nullptr){
		push_back(L1, L2->data);
		L2=L2->pNext;
	}
}

void printList(Node* L1){
	while(L1->pNext!=nullptr){
		cout << L1->data;
		L1=L1->pNext;
	}
	cout << L1->data;
}

void writeList(Node* L1){
	system("cls");
	char a[100];
	cout << "Enter new file name: ";
	cin >> a;
	if(cin.fail()) throw 0;
	ofstream out;
	out.open(a);
	while(L1->pNext!=nullptr){
		out << L1->data;
		L1=L1->pNext;
	}
	out << L1->data;
	out.close();
}
