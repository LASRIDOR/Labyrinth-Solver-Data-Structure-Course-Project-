#ifndef __SQUARE_H
#define __SQUARE_H

#include <iostream>
#include <stdlib.h>
using namespace std;

#pragma warning (disable: 4996)

class Square {
public:
	Square() = default;
	Square(int row, int col);
	~Square() = default;

	void SetCurrRow(int row);
	void SetCurrCol(int col);

	int GetCurrRow();
	int GetCurrCol();

private:
	int curr_row;
	int curr_col;
};

#endif // !__SQUARE_H