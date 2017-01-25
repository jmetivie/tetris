#include <iostream>
#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

void testIPiece();

int main() {

	testIPiece();
	return 0;
	
	Board board(12,24);
	board.display();
	
	
	for (int i = 0 ; i < 1 ; i++) {
		//~ Tetramino t = Tetramino::randomTetraminoFactory();
		JPiece t;
		t.doRotate();
		cout << "Adding piece id:" << t.getId() << endl;
		Position position = make_pair(5,15);
		board.addPiece(t, position);
		board.display();
	}
	return 0;
}


void testIPiece() {
	TPiece t;
	for (int angle = 0 ; angle < 5 ; angle++) {
		Board board(4,4);
		board.addPiece(t, make_pair(0,0));
		board.display();
		t.doRotate();
	}
}
