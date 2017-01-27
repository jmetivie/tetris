#include <iostream>
#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

void testPiece();

int main() {

	
	Board board(12,24);
	OPiece o;
	board.addPiece(o,make_pair(3,5));
	TPiece t;
	board.addPiece(t,make_pair(5,3));
	board.display();
	
	cout << "canRotate?" << t.canRotate(board) << endl;
	t.doRotate(board);
	board.display();
	
	cout << "canTranslate?" << t.canTranslate(board,"left") << endl;
	t.doTranslate(board,"left");
	board.display();
	
	return 0;
}


void testPiece() {
	TPiece t;
	for (int angle = 0 ; angle < 5 ; angle++) {
		Board board(4,4);
		board.addPiece(t, make_pair(0,0));
		board.display();
		t.doRotate(board);
	}
}
