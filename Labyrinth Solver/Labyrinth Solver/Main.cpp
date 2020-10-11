#include "labyrinth.h"
#include "mainheader.h"


int main() {
	Labyrinth* lab;

	char** board;
	int row , col;
	bool want_to_make_a_labyrinth;
	Eevaluation invalid_input = No_Solution;

	get_input_from_user(&row,&col,&want_to_make_a_labyrinth);
	checker_board(row,col);

	if (want_to_make_a_labyrinth == 0) {
		lab = new Labyrinth(row, col, want_to_make_a_labyrinth);
	}
	else {//want_to_make_a_labyrinth == 1
		do {
  			if (invalid_input == (Eevaluation)invalid_input) {
				cout << "invalid input";
				exit(1);
			}
			if (invalid_input == (Eevaluation)No_Solution) {
				cout << "No_solution";
				exit(1);
			}
			board = make_board(row, col);
			lab = new Labyrinth(row, col, want_to_make_a_labyrinth);
			invalid_input = lab->SetBoard(board);
			if (invalid_input == GOOD_BOARD) {
				free_board(board,row,col);
			}
		} while (invalid_input == false);
	}
}