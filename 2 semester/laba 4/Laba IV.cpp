#include <iostream>
#include <string>
#include "stack.h"
using namespace std;
struct Node {
	int num;
	Node* next, * prev;
};
typedef Node* PNode;
struct Stack {
	PNode Head, Tail;
};
int main() {
	extern string s;
	bool stop = false;
	init();
	while (true) {
		cout << "1 - Push\n";
		cout << "2 - Pop\n";
		cout << "3 - Top\n";
		cout << "4 - View and delete stack\n";
		cout << "5 - Exit\n";
		cin >> s;
		while (!intCheck()) {
			cout << "Try again\n";
			cin >> s;
		}
		switch (atoi(s.c_str()))
		{
		case 1:
			cout << "Input number:\n";
			int temp;
			cin >> temp;
			push(temp);
			break;
		case 2:
			cout << "Top element was deleted:\n";
			cout << pop() << endl;
			break;
		case 3:
			cout << "Top element:\n";
			cout << top() << endl;
			break;
		case 4:
			cout << "Stack was deleted:\n";
			view();
			break;
		case 5:
			stop = true;
			break;
		default:
			cout << "Try again\n";
			break;
		}
		if (stop) {
			stop = false;
			break;
		}
	}
	return 0;
}
