#include <iostream>
#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

void testPiece();

int main() {

	
	Board board(12,24);
	Tetramino t = Tetramino::randomTetraminoFactory();
	board.addPiece(t, make_pair(6,0));
	
	while(true) {
		board.display();
		cout << "R: ROTATE | G,D,B:TRANSLATE | F:FALL" << endl;
		char pressed = ' ';
		cin >> pressed;
		bool res = false;
		switch (pressed) {
			case 'R':
				res = t.doRotate(board);
				break;
			case 'G':
				res = t.doTranslate(board, "left");
				break;
			case 'D':
				res = t.doTranslate(board, "right");
				break;
			case 'B':
				res = t.doTranslate(board, "down");
				break;
			case 'F':
				res = t.doFall(board);
				t = Tetramino::randomTetraminoFactory();
				board.addPiece(t, make_pair(6,0));
				break;
			default : 
				cout << "oupsy" << endl;
		}
		if (!res) cout << "no move was down" << endl;
	}
	
	
	
	/*
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
	*/
	
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
