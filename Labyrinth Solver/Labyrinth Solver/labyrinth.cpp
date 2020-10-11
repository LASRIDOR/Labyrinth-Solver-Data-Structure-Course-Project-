#include "labyrinth.h"


Labyrinth::Labyrinth(int row, int col, bool want_to_make_a_labyrinth) { 
	SetRow(row);
	SetCol(col);
	if (want_to_make_a_labyrinth == 0) {
		m_Board = new char* [m_row];
		for (int i = 0; i < m_row; i++) {
			m_Board[i] = new char[m_col];
		}
		build_Board();
	}
}

//----------------------------------------------------------------------------------------------------

Labyrinth::Labyrinth(Labyrinth& other) {
	SetBoard(other.GetBoard(),false);
	SetRow(other.GetRow());
	SetCol(other.GetCol());
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::CopyBoard(char** board) {
	m_Board = new char* [m_row];
	for (int i = 0; i < m_row;i++) {
		m_Board[i] = new char[m_col];
		strcpy(m_Board[i], board[i]);
	}
}

//----------------------------------------------------------------------------------------------------

Labyrinth::~Labyrinth() {
	for (int i = 0; i < m_row; i++) {
		delete m_Board[i];
	}
	delete m_Board;
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::SetRow(int row) {
	m_row = row;
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::SetCol(int col) {
	m_col = col;
}

//----------------------------------------------------------------------------------------------------

int Labyrinth::GetRow() {
	return m_row;
}

//----------------------------------------------------------------------------------------------------

int Labyrinth::GetCol() {
	return m_col;
}

//----------------------------------------------------------------------------------------------------

char** Labyrinth::GetBoard() {
	return m_Board;
}

//----------------------------------------------------------------------------------------------------

Eevaluation Labyrinth::SetBoard(char** board,bool to_check){
	if (to_check == false) { // for copy cost
		CopyBoard(board);
		return GOOD_BOARD;
	}
	else {
		if (check_Board(board) == true) { // checks for valid board 
			CopyBoard(board);
			if (find_solution() == true) { // checks for solution
				printboard();
				return GOOD_BOARD;
			}
			else {
				return No_Solution;
			}
		}
		else {
			return Invlid_input;
		}
	}
}

//----------------------------------------------------------------------------------------------------

bool Labyrinth::check_Board(char** board) { // put in fins solution if find return true and then start solution in empty place to check accesabillitys
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			if (i == 0 || i == m_row - 1) {
				if (board[i][j] != '*') {
					return false;
				}
			}
			else if (j == 0 || j == m_col - 1) {
				if (i == m_row - 2 && j == m_col - 1) {
					if (board[i][j] != ' ') {
						return false;
					}
				}
				else if (i == 1 && j == 0) {
					if (board[i][j] != ' ') {
						return false;
					}
				}
				else {
					if (board[i][j] != '*') {
						return false;
					}
				}
			}
			else if (board[i][j] != ' ' && board[i][j] != '*') {
				return false;
			}
		}
	}
	return true;
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::build_Board() {
	make_default_board();
	build_Labyrinth();
	printboard();
	find_solution();
	printboard();
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::make_default_board() {
	for (int i = 0; i < m_row;i++) {
		for (int j = 0; j < m_col; j++) {
			if (i == 0 || i == m_row - 1) {
				m_Board[i][j] = '*';
			}
			else if (j == 0 || j == m_col - 1) {
				if (i == m_row - 2 && j == m_col - 1) {
					m_Board[i][j] = ' ';
				}
				else if (i == 1 && j == 0) {
					m_Board[i][j] = ' ';
				}
				else {
					m_Board[i][j] = '*';
				}
			}
			else if (j % 2 == 0) {
				m_Board[i][j] = '*';
			}
			else if (j % 2 == 1) {
				m_Board[i][j] = ' ';
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::build_Labyrinth() {
	Square temp(1, 1);
	Stack stack;
	stack.Push(temp);
	while (stack.IsEmpty() == false) {
		temp = stack.Pop();
		m_Board[temp.Square::GetCurrRow()][temp.Square::GetCurrCol()] = '?';
		check_unvisited_neighber_and_make_lottery(temp, stack);
	}
	earase_questionmark();
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::check_unvisited_neighber_and_make_lottery(Square& temp, Stack& stack) { // checks valid neighber and push only good neighber to stack let rand chose betwenn them
	int counter = 0,i;
	int box_lottery[4];
	if (valid_neighber(temp.Square::GetCurrRow() + 2,temp.Square::GetCurrCol()) == true) {
		box_lottery[counter] = 1;
		counter++;
	}
	if (valid_neighber(temp.Square::GetCurrRow() - 2, temp.Square::GetCurrCol()) == true) {
		box_lottery[counter] = 2;
		counter++;
	}
	if (valid_neighber(temp.Square::GetCurrRow(), temp.Square::GetCurrCol()+2) == true) {
		box_lottery[counter] = 3;
		counter++;
	}
	if (valid_neighber(temp.Square::GetCurrRow(), temp.Square::GetCurrCol() - 2) == true) {
		box_lottery[counter] = 4;
		counter++;
	}
	if (counter == 0) { return; }
	else { // at least one neighber is available
		stack.Push(temp);
		srand((unsigned)time(NULL));
		_sleep(7*(temp.GetCurrCol())); // in program like this rand time will always give the same value
		i = rand() % (counter);
		if (box_lottery[i] == 1) {
				m_Board[temp.Square::GetCurrRow() + 1][temp.Square::GetCurrCol()] = ' ';
				temp.SetCurrRow(temp.Square::GetCurrRow() + 2);
		}
		else if (box_lottery[i] == 2) {
			m_Board[temp.Square::GetCurrRow() - 1][temp.Square::GetCurrCol()] = ' ';
				temp.SetCurrRow(temp.Square::GetCurrRow() - 2);
		}
		else if (box_lottery[i] == 3) {
				m_Board[temp.Square::GetCurrRow()][temp.Square::GetCurrCol()+1] = ' ';
				temp.SetCurrCol(temp.Square::GetCurrCol() + 2);
		}
		else if(box_lottery[i] == 4){
				m_Board[temp.Square::GetCurrRow()][temp.Square::GetCurrCol() - 1] = ' ';
				temp.SetCurrCol(temp.Square::GetCurrCol() - 2);
		}
		stack.Push(temp);
	}
}

//----------------------------------------------------------------------------------------------------

bool Labyrinth::valid_neighber(int row,int col) {
	if (row <= 0  || row >= m_row-1) {
		return false;
	}
	if (m_Board[row][col] != ' ') {
		return false;
	}
	return true;
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::earase_questionmark() {
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
			if (m_Board[i][j] == '?') {
				m_Board[i][j] = ' ';
			}
		}
	}
}

//----------------------------------------------------------------------------------------------------

bool Labyrinth::find_solution() {
	Queue solution(m_col*m_row); // in max size of queue
	Square temp;
	temp.SetCurrRow(1);
	temp.SetCurrCol(0);
	solution.EnQueue(temp);
	while (solution.IsEmpty() == 0) {
		temp = solution.DeQueue();
		m_Board[temp.Square::GetCurrRow()][temp.Square::GetCurrCol()] = '$';
		if (temp.Square::GetCurrRow() == m_row - 2 && temp.Square::GetCurrCol() == m_col - 1) {
			return true;
		}
		else {
			if (m_Board[temp.Square::GetCurrRow()][temp.Square::GetCurrCol() + 1] == ' ') {
				temp.SetCurrCol(temp.Square::GetCurrCol() + 1);
				solution.EnQueue(temp);
				temp.SetCurrCol(temp.Square::GetCurrCol() - 1);
			}
			if (m_Board[temp.Square::GetCurrRow() +1][temp.Square::GetCurrCol()] == ' ') {
				temp.SetCurrRow(temp.Square::GetCurrRow() + 1);
				solution.EnQueue(temp);
				temp.SetCurrRow(temp.Square::GetCurrRow() - 1);
			}
			if (m_Board[temp.Square::GetCurrRow()][temp.Square::GetCurrCol() - 1] == ' ') {
				temp.SetCurrCol(temp.Square::GetCurrCol() - 1);
				solution.EnQueue(temp);
				temp.SetCurrCol(temp.Square::GetCurrCol() + 1);
			}
			if (m_Board[temp.Square::GetCurrRow() - 1][temp.Square::GetCurrCol()] == ' ') {
				temp.SetCurrRow(temp.Square::GetCurrRow() - 1);
				solution.EnQueue(temp);
				temp.SetCurrRow(temp.Square::GetCurrRow() + 1);
			}
		}
	}
	return false;
}

//----------------------------------------------------------------------------------------------------

void Labyrinth::printboard() {
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_col; j++) {
				cout << m_Board[i][j];
		}
		cout << endl;
	}
}