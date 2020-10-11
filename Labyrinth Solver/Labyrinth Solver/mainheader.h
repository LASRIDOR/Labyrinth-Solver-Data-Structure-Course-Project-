#ifndef __mainheader_H
#define __mainheader_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

#pragma warning (disable: 4996)

#define MAX_NUM_OF_ROWS 24
#define MAX_NUM_OF_COLS 80

bool checker_board(int row,int col);
void get_input_from_user(int* row,int* col,bool* want_to_make_a_labyrinth);
char** make_board(int row, int col);
void cleanbuffer();
void free_board(char** board, int row, int col);

enum Eevaluation {No_Solution,Invlid_input,GOOD_BOARD}; // evaluation for the board user entered

#endif // !__mainheader_H