#include "func.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <limits>

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
	clean();
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

void clean(){
	#ifdef _WIN32
	system("cls");
	#endif
	#ifdef linux
	system("clear");
	#endif
}

void pause(){
	#ifdef _WIN32
	system("pause");
	#endif
	#ifdef linux
	cout << endl << "Press enter to countinue";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	#endif
}