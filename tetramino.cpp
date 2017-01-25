#include "tetramino.hpp"

Tetramino::Tetramino() : id(9), color("gray") {
	positions = vector<Position>(4,make_pair(0,0));
}

Tetramino::~Tetramino() {
	positions.clear();
}

////////////////////////////////////////////////////////////////////////////////

IPiece::IPiece() : Tetramino() {
	id = 1; 
	color = "cyan";
}

bool
IPiece::canRotate() const {
	return false;
}

void
IPiece::doRotate() {
}

////////////////////////////////////////////////////////////////////////////////

JPiece::JPiece() : Tetramino() {
	id = 2; 
	color = "blue";
}

bool
JPiece::canRotate() const {
	return false;
}

void
JPiece::doRotate() {
}
