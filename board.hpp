#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <list>

#include "tetramino.hpp"

using namespace std;

class Board {
	protected:
		unsigned int width;
		unsigned int height;
		vector< vector<unsigned int> > board;
	public:
		Board();
		Board(unsigned int _width, unsigned int _height);
		~Board();
		
		void init_board();
		void display() const;
		
		list<unsigned int> getCompleteLines() const;		
		
		inline unsigned int	getWidth() const { return width; }
		inline unsigned int	getHeight() const { return height; }
		inline unsigned int	getValue(unsigned int x, unsigned int y) const { return board[y][x]; }
		inline void			setValue(unsigned int x, unsigned int y, unsigned int value) { board[y][x] = value; }	
		
		bool addPiece(Tetramino& piece);
		
		
};

#endif
