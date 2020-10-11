#ifndef __STACK_H
#define __STACK_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

#include "node.h"
typedef Square Type;

class Stack {
public:
	Stack();
	~Stack();
	void MakeEmpty(void);
	int IsEmpty();
	void Push(Type square);
	Type Pop(void);
	Type Top(void);
private:
	Node* top;
};


#endif // !__STACK_H