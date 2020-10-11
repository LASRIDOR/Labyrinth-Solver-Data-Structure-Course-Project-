#include "Stack.h"

Stack::Stack() { //constructor
	top = NULL;
}
Stack::~Stack() {//free memory
	MakeEmpty();
}
void Stack::MakeEmpty() {// make stack empty
	Node* temp;
	while (top != NULL) {
		temp = top;
		top = top->GetNext();
		delete temp;
	}
}
int Stack::IsEmpty() {//return 1 if empty and 0 otherwise
	return (top == NULL);
}
void Stack::Push(Type square) {
	top = new Node(square, top);
}
Type Stack::Pop(void) {
	if (IsEmpty()) {
		cout << "Error: Stack underflow\n";
		exit(1);
	}
	Node* temp = top;
	Type item = top->GetSquare();
	top = top->GetNext();
	delete temp;
	return (item);
}