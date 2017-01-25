#include "tetramino.hpp"

Tetramino::Tetramino() : id(9), color("gray") {
	positions.reserve(4);
	angle = 0;
	referencePosition = make_pair(0,0);
}

Tetramino::~Tetramino() {
	positions.clear();
	cout << "Tetramino::~Tetramino() | need to be completed." << endl;
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

Position 
Tetramino::computePosition(unsigned int piecePart, Position& position) {
	//~ cout << "ComputePosition of part " << piecePart << " (" << getPosition(piecePart).first <<  "," << getPosition(piecePart).second<< ") at (" << position.first << "," << position.second << ")" << endl;
	Position delta_position = getPosition(piecePart);
	unsigned int new_x = position.first + delta_position.first;
	unsigned int new_y = position.second + delta_position.second;
	//~ cout << "x = " << position.first << "+" << delta_position.first << " = " << new_x << endl;
	//~ cout << "y = " << position.second << "+" << delta_position.second << " = " << new_y << endl;
	Position result = make_pair(new_x,new_y);
	return result;
}

////////////////////////////////////////////////////////////////////////////////
IPiece::IPiece() : Tetramino() {
	id = 1; 
	color = "cyan";
	
	vector<Position> position_1;
	position_1.reserve(4);
	position_1.push_back(make_pair(0,1));
	position_1.push_back(make_pair(1,1));
	position_1.push_back(make_pair(2,1));
	position_1.push_back(make_pair(3,1));
	positions.push_back(position_1);
	vector<Position> position_2;
	position_2.reserve(4);
	position_2.push_back(make_pair(2,0));
	position_2.push_back(make_pair(2,1));
	position_2.push_back(make_pair(2,2));
	position_2.push_back(make_pair(2,3));
	positions.push_back(position_2);
	vector<Position> position_3;
	position_3.reserve(4);
	position_3.push_back(make_pair(3,2));
	position_3.push_back(make_pair(2,2));
	position_3.push_back(make_pair(1,2));
	position_3.push_back(make_pair(0,2));
	positions.push_back(position_3);
	vector<Position> position_4;
	position_4.reserve(4);
	position_4.push_back(make_pair(1,3));
	position_4.push_back(make_pair(1,2));
	position_4.push_back(make_pair(1,1));
	position_4.push_back(make_pair(1,0));
	positions.push_back(position_4);
	
}

////////////////////////////////////////////////////////////////////////////////
JPiece::JPiece() : Tetramino() {
	id = 2; 
	color = "blue";
	
	vector<Position> position_1;
	position_1.reserve(4);
	position_1.push_back(make_pair(0,0));
	position_1.push_back(make_pair(0,1));
	position_1.push_back(make_pair(1,1));
	position_1.push_back(make_pair(2,1));
	positions.push_back(position_1);
	vector<Position> position_2;
	position_2.reserve(4);
	position_2.push_back(make_pair(2,0));
	position_2.push_back(make_pair(1,0));
	position_2.push_back(make_pair(1,1));
	position_2.push_back(make_pair(1,2));
	positions.push_back(position_2);
	vector<Position> position_3;
	position_3.reserve(4);
	position_3.push_back(make_pair(2,2));
	position_3.push_back(make_pair(2,1));
	position_3.push_back(make_pair(1,1));
	position_3.push_back(make_pair(0,1));
	positions.push_back(position_3);
	vector<Position> position_4;
	position_4.reserve(4);
	position_4.push_back(make_pair(0,2));
	position_4.push_back(make_pair(1,2));
	position_4.push_back(make_pair(1,1));
	position_4.push_back(make_pair(1,0));
	positions.push_back(position_4);
}

////////////////////////////////////////////////////////////////////////////////
LPiece::LPiece() : Tetramino() {
	id = 3; 
	color = "orange";
	
	vector<Position> position_1;
	position_1.reserve(4);
	position_1.push_back(make_pair(2,0));
	position_1.push_back(make_pair(2,1));
	position_1.push_back(make_pair(1,1));
	position_1.push_back(make_pair(0,1));
	positions.push_back(position_1);
	vector<Position> position_2;
	position_2.reserve(4);
	position_2.push_back(make_pair(2,2));
	position_2.push_back(make_pair(1,2));
	position_2.push_back(make_pair(1,1));
	position_2.push_back(make_pair(1,0));
	positions.push_back(position_2);
	vector<Position> position_3;
	position_3.reserve(4);
	position_3.push_back(make_pair(0,2));
	position_3.push_back(make_pair(0,1));
	position_3.push_back(make_pair(1,1));
	position_3.push_back(make_pair(2,1));
	positions.push_back(position_3);
	vector<Position> position_4;
	position_4.reserve(4);
	position_4.push_back(make_pair(0,0));
	position_4.push_back(make_pair(1,0));
	position_4.push_back(make_pair(1,1));
	position_4.push_back(make_pair(1,2));
	positions.push_back(position_4);
}

////////////////////////////////////////////////////////////////////////////////
OPiece::OPiece() : Tetramino() {
	id = 4; 
	color = "yellow";
	
	vector<Position> position_1;
	position_1.reserve(4);
	position_1.push_back(make_pair(1,0));
	position_1.push_back(make_pair(2,0));
	position_1.push_back(make_pair(2,1));
	position_1.push_back(make_pair(1,1));
	positions.push_back(position_1);
	vector<Position> position_2;
	position_2.reserve(4);
	position_2.push_back(make_pair(1,1));
	position_2.push_back(make_pair(1,0));
	position_2.push_back(make_pair(2,0));
	position_2.push_back(make_pair(2,1));
	positions.push_back(position_2);
	vector<Position> position_3;
	position_3.reserve(4);
	position_3.push_back(make_pair(2,1));
	position_3.push_back(make_pair(1,1));
	position_3.push_back(make_pair(1,0));
	position_3.push_back(make_pair(2,0));
	positions.push_back(position_3);
	vector<Position> position_4;
	position_4.reserve(4);
	position_4.push_back(make_pair(2,0));
	position_4.push_back(make_pair(2,1));
	position_4.push_back(make_pair(1,1));
	position_4.push_back(make_pair(1,0));
	positions.push_back(position_4);
	
	
}

////////////////////////////////////////////////////////////////////////////////
SPiece::SPiece() : Tetramino() {
	id = 5; 
	color = "green";
	
	vector<Position> position_1;
	position_1.reserve(4);
	position_1.push_back(make_pair(0,1));
	position_1.push_back(make_pair(1,1));
	position_1.push_back(make_pair(1,0));
	position_1.push_back(make_pair(2,0));
	positions.push_back(position_1);
	vector<Position> position_2;
	position_2.reserve(4);
	position_2.push_back(make_pair(1,0));
	position_2.push_back(make_pair(1,1));
	position_2.push_back(make_pair(2,1));
	position_2.push_back(make_pair(2,2));
	positions.push_back(position_2);
	vector<Position> position_3;
	position_3.reserve(4);
	position_3.push_back(make_pair(2,1));
	position_3.push_back(make_pair(1,1));
	position_3.push_back(make_pair(1,2));
	position_3.push_back(make_pair(0,2));
	positions.push_back(position_3);
	vector<Position> position_4;
	position_4.reserve(4);
	position_4.push_back(make_pair(1,2));
	position_4.push_back(make_pair(1,1));
	position_4.push_back(make_pair(0,1));
	position_4.push_back(make_pair(0,0));
	positions.push_back(position_4);
}

////////////////////////////////////////////////////////////////////////////////
ZPiece::ZPiece() : Tetramino() {
	id = 6; 
	color = "red";
	
	vector<Position> position_1;
	position_1.reserve(4);
	position_1.push_back(make_pair(0,0));
	position_1.push_back(make_pair(1,0));
	position_1.push_back(make_pair(1,1));
	position_1.push_back(make_pair(2,1));
	positions.push_back(position_1);
	vector<Position> position_2;
	position_2.reserve(4);
	position_2.push_back(make_pair(2,0));
	position_2.push_back(make_pair(2,1));
	position_2.push_back(make_pair(1,1));
	position_2.push_back(make_pair(1,2));
	positions.push_back(position_2);
	vector<Position> position_3;
	position_3.reserve(4);
	position_3.push_back(make_pair(2,2));
	position_3.push_back(make_pair(1,2));
	position_3.push_back(make_pair(1,1));
	position_3.push_back(make_pair(0,1));
	positions.push_back(position_3);
	vector<Position> position_4;
	position_4.reserve(4);
	position_4.push_back(make_pair(0,2));
	position_4.push_back(make_pair(0,1));
	position_4.push_back(make_pair(1,1));
	position_4.push_back(make_pair(1,0));
	positions.push_back(position_4);
}

////////////////////////////////////////////////////////////////////////////////
TPiece::TPiece() : Tetramino() {
	id = 7; 
	color = "purple";
	
	vector<Position> position_1;
	position_1.reserve(4);
	position_1.push_back(make_pair(0,1));
	position_1.push_back(make_pair(1,1));
	position_1.push_back(make_pair(1,0));
	position_1.push_back(make_pair(2,1));
	positions.push_back(position_1);
	vector<Position> position_2;
	position_2.reserve(4);
	position_2.push_back(make_pair(1,0));
	position_2.push_back(make_pair(1,1));
	position_2.push_back(make_pair(2,1));
	position_2.push_back(make_pair(1,2));
	positions.push_back(position_2);
	vector<Position> position_3;
	position_3.reserve(4);
	position_3.push_back(make_pair(2,1));
	position_3.push_back(make_pair(1,1));
	position_3.push_back(make_pair(1,2));
	position_3.push_back(make_pair(0,1));
	positions.push_back(position_3);
	vector<Position> position_4;
	position_4.reserve(4);
	position_4.push_back(make_pair(1,2));
	position_4.push_back(make_pair(1,1));
	position_4.push_back(make_pair(0,1));
	position_4.push_back(make_pair(1,0));
	positions.push_back(position_4);
}

