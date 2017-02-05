#include "board.hpp"

Board::Board() : width(0+2), height(1) {
	init_board();
}

Board::Board(unsigned int _width, unsigned int _height) : width(_width+2), height(_height+1) {
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
	
	for (unsigned int h = 0 ; h < height ; h++) {
		board[h][0] 		= 255;
		board[h][width-1] 	= 255;
	}
	for (unsigned int w = 0 ; w < width ; w++) {
		board[height-1][w] = 255;
	}
}


void
Board::display() const {
	for (int x = 0 ; x < width ; x++) cout << (x%10); cout << endl;
	for (int y = 0 ; y < height ; y++) {
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
		cout << " " << y << endl;
	}
	for (int x = 0 ; x < width ; x++) cout << (x%10); cout << endl;
}

bool 
Board::addPiece(Tetramino& piece, Position position) {
	
	bool allfree = true;
	cout << "Placing piece " << piece.getId() << " at position " << position.first << "," << position.second << endl;
	
	for (unsigned int i = 0 ; i < 4 ; i++) {
		piece.computePosition(0,position);
		Position position_piece = piece.getPosition(i);
		unsigned int x = position_piece.first+position.first;
		unsigned int y = position_piece.second+position.second;
		if (getValue(x,y) != 0) allfree = false;
		board[y][x] = piece.getId();
	}
	
	piece.setReferencePosition(position);
	
	return allfree;
	
}

list<unsigned int> 
Board::getCompleteLines() const {
	list<unsigned int> completeLines;
	for (unsigned int h = 0 ; h < height-1 ; h++) {
		bool complete = true;
		for (unsigned int w = 1; w < width-1 ; w++) {
			if (getValue(w,h) == 0) {
				complete = false;
				break;
			}
		}
		if (complete) completeLines.push_back(h);
	}
	return completeLines;
}

void 				
Board::removeLines(list<unsigned int>& lines) {
	for (unsigned int line : lines) {
		//remove line
		for (int w = 1 ; w < width-1 ; w++) {
			setValue(w,line,0);
		}
		//make it drop !!!!
		for (int h = line; h > 0 ; h--) {
			for (int w = 1 ; w < width-1 ; w++) {
				setValue(w,h,getValue(w,h-1));
			}
		}
		//complete first line
		for (int w = 1 ; w < width-1 ; w++) {
			setValue(w,0,0);
		}
	}
}
