#include <iostream>
#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

int main() {
	
	Board board(12,24);
	board.display();
	
	
	for (int i = 0 ; i < 1 ; i++) {
		//~ Tetramino t = Tetramino::randomTetraminoFactory();
		OPiece t;
		cout << "Adding piece id:" << t.getId() << endl;
		board.addPiece(t);
		board.display();
	}
	return 0;
}
