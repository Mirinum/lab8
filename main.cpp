#include "func.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <limits>

using namespace std;

int main(){
	try{
		clean();
		Node L1, L2;
		char a;
		cout << "Enter L1 in one line" << endl;
		cin.get(a);
		while(a != '\n'){
			push_back(&L1, a);
			if(cin.fail()) throw 0;
			cin.get(a);
		}
		clean();
		cout << "Enter L2 in one line" << endl;
		cin.get(a);
		while(a != '\n'){
			push_back(&L2, a);
			if(cin.fail()) throw 0;
			cin.get(a);
		}
		while(true){
			clean();
			cout << "1. Append L2 to L1" << endl <<
			"2. Insert L2 in L1 after some symbol" << endl <<
			"3. Reverse L1" << endl << 
			"4. Turn 'xxxx' to 'x'" << endl <<
			"5. Write list to file" << endl <<
			"6. Show L1 and L2" << endl <<
			"99. Exit" << endl <<
			"Choose your option: ";
			int f;
			cin >> f;
			if(cin.fail()) throw 0;
			switch(f){
				default: cout << "Error, invalid option" << endl; break;
				case 1: append(L1.pNext,L2.pNext); cout << "Appended sucsessfully" << endl; break;
				case 2: 
					clean();
					cout << "Enter E to insert L2 after: ";
					TE E;
					cin >> E;
					clean();
					if(cin.fail()) throw 0;
					insert(L1.pNext,L2.pNext,E); cout << "Inserted sucsessfully" << endl; break;
				case 3:
					reverse(L1.pNext, L1.pNext);
					cout << "Reversed sucsessfully" << endl; break;
				case 4:
					nox(&L1);
					cout << "Action completed sucsessfully" << endl; break;
				case 5:
					clean();
					cout << "Choose which one list to write (it will overwrite the old file)" << endl
					<< "Write list L";
					int l;
					cin >> l;
					if(cin.fail())throw 0;
					if(l == 1)writeList(L1.pNext);
					else if (l == 2) writeList(L2.pNext);
					else cout << "List not found";
					break;
				case 6: cout << "L1: " << endl;
					printList(L1.pNext);
					cout << endl << "L2: " << endl;
					printList(L2.pNext);
					cout << endl;
					break;
				case 99: return 0;
			}
			pause();
		}
	}
	catch(int a){
		switch(a){
			case 0: cout << "Input error"; break;
			case 1: cout << "Bad index"; break;
		}
	}
	catch(...) {
		cout << "ERROR";
	}
	return 1337;
}
