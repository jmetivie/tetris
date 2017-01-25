#include "board.hpp"

Board::Board() : width(1), height(1) {
	init_board();
}

Board::Board(unsigned int _width, unsigned int _height) : width(_width), height(_height) {
	init_board();
}

Board::~Board() {
	for (vector<unsigned int>& line: board) line.clear();
	board.clear();
}

void 
Board::init_board() {
	board.reserve(height);
	for (unsigned int h = 0 ; h < height ; h++) board.push_back(vector<unsigned int>(width,0));
}


void
Board::display() const {
	for (int y = height-1 ; y >= 0 ; y--) {
		cout << y << "\t "; cout.flush();
		for (int x = 0 ; x < width ; x++) {
			cout << getValue(x,y);
		}
		cout << endl;
	}
}

bool 
Board::addPiece(Tetramino& piece) {
	
	/*unsigned int min_x = width;
	unsigned int max_x = 0;
	unsigned int min_y = height;
	unsigned int max_y = 0;*/
	
	for (unsigned int i = 0 ; i < 4 ; i++) {
		Position position = piece.getPosition(i);
		board[position.second][position.first] = piece.getId();
	}
	
	return true;
	
}
