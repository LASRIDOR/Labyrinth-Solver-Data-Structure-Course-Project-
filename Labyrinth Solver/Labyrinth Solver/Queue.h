
#ifndef __QUEUE_H
#define __QUEUE_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

#include "Square.h"

class Queue {
private:
	Square *data;
	int head, tail;
	int MAX_SIZE;
	int AddOne(int x);
public:
	Queue(int size_of_data);
	~Queue();
	void MakeEmpty(void);
	int IsEmpty(void);
	Square Front(void);
	void EnQueue(Square item);
	Square DeQueue(void);
};

#endif // !__QUEUE_H