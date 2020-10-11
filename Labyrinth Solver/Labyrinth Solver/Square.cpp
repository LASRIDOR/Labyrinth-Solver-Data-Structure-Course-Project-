#include "Square.h"

Square::Square(int row, int col) {
	curr_col = col;
	curr_row = row;
}

void Square::SetCurrRow(int row) {
	curr_row = row;
}
void Square::SetCurrCol(int col) {
	curr_col = col;
}

int Square::GetCurrRow() {
	return curr_row;
}
int Square::GetCurrCol() {
	return curr_col;
}