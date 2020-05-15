#include <string>
#include <iostream>
using namespace std;
struct Node {
	int num;
	Node* next, * prev;
};
typedef Node* PNode;
struct Stack {
	PNode Head, Tail;
};
Stack S;
string s;
bool intCheck() {
	bool flag = true;
	if (s[0] == '-') {
		if (s.size() > 11) flag = false;
		else {
			for (int i = 1; i < s.size(); i++) {
				if (s[i] < '0' || s[i]>'9') {
					flag = false;
					break;
				}
			}
		}
	}
	else
	{
		if (s.size() > 10) flag = false;
		else {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] < '0' || s[i]>'9') {
					flag = false;
					break;
				}
			}
		}
	}
	return flag;
}
void init() {
	S.Head = NULL;
	S.Tail = NULL;
}
void push(int x) {
	PNode NewNode;
	NewNode = new Node; 
	NewNode->num = x;
	NewNode->next = S.Head;
	NewNode->prev = NULL;
	if (S.Head) 
		S.Head->prev = NewNode;
	S.Head = NewNode;
	if (!S.Tail) S.Tail = S.Head;
}
int pop()
{
	PNode TopNode = S.Head;
	int x;
	if (!TopNode)
		return NULL; 
	x = TopNode->num;
	S.Head = TopNode->next;
	if (S.Head) S.Head->prev = NULL; 
	else S.Tail = NULL;
	delete TopNode; 
	return x;
}
int top() {
	PNode TopNode = S.Head;
	if (TopNode == NULL) return 0;
	return TopNode->num;
}
void view() {
	int x;
	do {
		x = pop();
		cout << x << endl;
	} while (x != NULL);
}
