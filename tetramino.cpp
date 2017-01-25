#include "tetramino.hpp"

Tetramino::Tetramino() : id(9), color("gray") {
	positions = vector<Position>(4,make_pair(0,0));
}

Tetramino::~Tetramino() {
	positions.clear();
}

Tetramino 
Tetramino::randomTetraminoFactory() {
	unsigned int randomId = rand() % 7 + 1;
	switch (randomId) {
		case 1 : return IPiece();
		case 2 : return JPiece();
		case 3 : return LPiece();
		case 4 : return OPiece();
		case 5 : return SPiece();
		case 6 : return ZPiece();
		case 7 : return TPiece();
		default: 
			cout << "Unknown piece id ["<<randomId <<"]" << endl;
			break;
	}
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

////////////////////////////////////////////////////////////////////////////////

LPiece::LPiece() : Tetramino() {
	id = 3; 
	color = "orange";
}

bool
LPiece::canRotate() const {
	return false;
}

void
LPiece::doRotate() {
}

////////////////////////////////////////////////////////////////////////////////
// 0 1 -> 3 0
// 3 2    2 1

OPiece::OPiece() : Tetramino() {
	id = 4; 
	color = "yellow";
	
	positions[0] = make_pair(0,0);
	positions[1] = make_pair(1,0);
	positions[2] = make_pair(1,1);
	positions[3] = make_pair(0,1);
}

bool
OPiece::canRotate() const {
	return true;
}

void
OPiece::doRotate() {
	Position save = positions[0];
	positions[0] = positions[3];
	positions[3] = positions[2];
	positions[2] = positions[1];
	positions[1] = save;	
}

////////////////////////////////////////////////////////////////////////////////

SPiece::SPiece() : Tetramino() {
	id = 5; 
	color = "green";
}

bool
SPiece::canRotate() const {
	return false;
}

void
SPiece::doRotate() {
}

////////////////////////////////////////////////////////////////////////////////

ZPiece::ZPiece() : Tetramino() {
	id = 6; 
	color = "red";
}

bool
ZPiece::canRotate() const {
	return false;
}

void
ZPiece::doRotate() {
}

////////////////////////////////////////////////////////////////////////////////

TPiece::TPiece() : Tetramino() {
	id = 7; 
	color = "purple";
}

bool
TPiece::canRotate() const {
	return false;
}

void
TPiece::doRotate() {
}
