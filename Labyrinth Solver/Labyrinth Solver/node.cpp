#include "node.h"

Node::Node(Square square, Node* nextnode) {
	m_square.SetCurrCol(square.GetCurrCol());
	m_square.SetCurrRow(square.GetCurrRow());
	next = nextnode;
}
Node::~Node() {

}

void Node::SetSquare(int row, int col) {
	m_square.SetCurrRow(row);
	m_square.SetCurrCol(col);
}
void Node::SetCurr_next(Node* nextnode) {
	next = nextnode;
}

Square Node::GetSquare() {
	return m_square;
}
Node* Node::GetNext() {
	return next;
}