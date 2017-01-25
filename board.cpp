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
	for (int y = 0 ; y < height ; y++) {
		cout << y << "\t "; cout.flush();
		for (int x = 0 ; x < width ; x++) {
			int id = getValue(x,y);
			switch (id) {
				case 0: cout << "\033[040m \033[0m";
					break;
				case 1: cout << "\033[046m\033[036mX\033[0m";
					break;
				case 2: cout << "\033[044m\033[034mX\033[0m";
					break;
				case 3: cout << "\033[047m\033[037mX\033[0m";
					break;
				case 4: cout << "\033[043m\033[033mX\033[0m";
					break;
				case 5: cout << "\033[042m\033[032mX\033[0m";
					break;
				case 6: cout << "\033[041m\033[031mX\033[0m";
					break;
				case 7: cout << "\033[045m\033[035mX\033[0m";
					break;
				default: cout << "X";
					break;
			}
			
		}
		cout << endl;
	}
}

bool 
Board::addPiece(Tetramino& piece, Position position) {
	
	/*unsigned int min_x = width;
	unsigned int max_x = 0;
	unsigned int min_y = height;
	unsigned int max_y = 0;*/
	
	cout << "Placing piece " << piece.getId() << " at position " << position.first << "," << position.second << endl;
	Position position_0 = piece.computePosition(0,position);
	Position position_1 = piece.computePosition(1,position);
	Position position_2 = piece.computePosition(2,position);
	Position position_3 = piece.computePosition(3,position);
	
	for (unsigned int i = 0 ; i < 4 ; i++) {
		Position position_piece = piece.getPosition(i);
		board[position_piece.second+position.second][position_piece.first+position.first] = piece.getId();
	}
	
	return true;
	
}
