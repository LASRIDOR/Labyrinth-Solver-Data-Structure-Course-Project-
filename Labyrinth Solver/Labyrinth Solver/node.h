#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <stdlib.h>
using namespace std;
#pragma warning (disable: 4996)

#include "Square.h"

class Node {
public:
	Node() = default;
	Node(Square square,Node* next);
	~Node();

	void SetSquare(int row, int col);
	void SetCurr_next(Node* next);

	Square GetSquare();
	Node* GetNext();

private:
	Square m_square;
	Node* next;
};

#endif // !__NODE_H