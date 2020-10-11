#include "mainheader.h"

bool checker_board(int row, int col) { // checks for valid input on the limits of the game
	if (col >= MAX_NUM_OF_COLS || row >= MAX_NUM_OF_ROWS || row <= 2 || col <= 2 || row % 2 == 0 || col % 2 == 0) {
		cout << "invalid input";
		exit(1);
	}

	else {
		return true;
	}
}

void get_input_from_user(int* row, int* col,bool* want_to_make_a_labyrinth) {// get from user
	cout << "Program:please enter 0/1 acoording to your answer\nDo you want to make your own labyrinth (1)\nor Do you want me to make that for you (0)\n(pay attention max column size is 80 and max row size is 25)?" << endl;
	cin >> *want_to_make_a_labyrinth;
	cout << "Enter Num of Row:";
	cin >> *row;
	cout << '\n' << "Enter Num of Col:";
	cin >> *col;
	cout << '\n';
}

char** make_board(int row, int col) { //get the board from the user
	char** board;
	board = new char* [row];
	for (int i = 0; i < row;i++) {
		cout << '\n' << "Row Num: " << i + 1 << '\n';
		board[i] = new char[col];
		cleanbuffer();
		cin.get(board[i], col);
	}
	return board;
}

void cleanbuffer() { // clean buffer for get function
	int c;
	do {
		c = getchar();
		if (c != EOF && c != '\n') {
			cout << "invalid input" << endl;
			exit(1);
		}
	} while (c!= EOF && c != '\n');
}

void free_board(char** board,int row ,int col) { // free memory
	for (int i = 0; i < row; i++) {
		delete board[i];
	}
	delete []board;
}