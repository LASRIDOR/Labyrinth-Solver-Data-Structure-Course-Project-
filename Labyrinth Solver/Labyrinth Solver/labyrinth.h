#ifndef __LABYRINTH_H
#define __LABYRINTH_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dos.h>
using namespace std;

#pragma warning (disable: 4996)

#include "Queue.h"
#include "Stack.h"
#include "mainheader.h"

class Labyrinth {
private:
	char** m_Board;
	int m_row;
	int m_col;
public:
	Labyrinth() = default;
	Labyrinth(int row = 0,int col = 0,bool want_to_make_a_labyrinth = 1);
	Labyrinth(Labyrinth& other);
	~Labyrinth();

	void SetRow(int row);
	void SetCol(int col);
	Eevaluation SetBoard(char** board, bool to_check = true);
	int GetRow();
	int GetCol();
	char** GetBoard();

private:
	void CopyBoard(char** board); // for copy const;
	bool check_Board(char** board);
	void build_Board();
	void make_default_board();
	void build_Labyrinth();
	void check_unvisited_neighber_and_make_lottery(Square& temp,Stack& stack);
	bool valid_neighber(int row, int col);
	void earase_questionmark();
	bool find_solution();
	void printboard();
};



#endif // !__LABYRINTH_H
