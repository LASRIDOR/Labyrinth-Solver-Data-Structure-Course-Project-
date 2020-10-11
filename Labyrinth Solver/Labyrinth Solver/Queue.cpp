#include "Queue.h"

Queue::Queue(int size_of_data) { // constructor
	head = 1;
	tail = 0;
	data = new Square[size_of_data];
	MAX_SIZE = size_of_data;
}
Queue::~Queue() {//destructor free memory
	delete []data;
}
int Queue::AddOne(int x) { //add one to x in a cyclic way
	return ((1 + x) % MAX_SIZE);
}
void Queue::MakeEmpty(void) {
	head = 1;
	tail = 0;
}
int Queue::IsEmpty(void) {//retur n1 if empty and 0 otherwise
	return (AddOne(tail) == head);
}
Square Queue::Front(void) {
	if (IsEmpty()) {
		cout << "Error: QUEUE EMPTY\n";
		exit(1);
	}
	return (data[head]);
}
void Queue::EnQueue(Square item) {
	if (AddOne(AddOne(tail)) == head) {
		cout << "Error: QUEUE IS FULL\n";
	}
	tail = AddOne(tail);
	data[tail] = item;
}
Square Queue::DeQueue(void) {
	if (IsEmpty()) {
		cout << "Error: QUEUE EMPTY\n";
		exit(1);
	}
	Square item = data[head];
	head = AddOne(head);
	return (item);
}