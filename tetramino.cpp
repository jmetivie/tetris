#include "tetramino.hpp"
#include "board.hpp"

////////////////////////////////////////////////////////////////////////
// TETRAMINOES 
////////////////////////////////////////////////////////////////////////

// CONSTRUCTORS, DESTRUCTORS, AND FACTORIES ////////////////////////////

/// Default Contructor
Tetramino::Tetramino() : id(9), color("gray") {
	positions.reserve(4);
	angle = 0;
	referencePosition = make_pair(0,0);
}

/// DESTRUCTOR
Tetramino::~Tetramino() {
	positions.clear();
	cout << "Tetramino::~Tetramino() | need to be completed." << endl;
}

/// FACTORY
/// \return a random tetramino
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
			return OPiece();
			break;
	}
}

// POSITION COMPUTATION ////////////////////////////////////////////////

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

// MOVEMENT FUNCTIONS //////////////////////////////////////////////////

///This function remove subpieces of a piece without destroying it
///\param board					the board to impact
void 
Tetramino::removeFromBoard(Board& board) {
	for (unsigned int piece = 0 ; piece < 4 ; piece++) {
		Position position = computePosition(piece, referencePosition);
		board.setValue(position.first, position.second, 0);
	}
}

///This function "re-add" subpieces of a piece without creating it
///\param board					the board to impact
void 
Tetramino::addToBoard(Board& board) {
	for (unsigned int piece = 0 ; piece < 4 ; piece++) {
		Position position = computePosition(piece, referencePosition);
		board.setValue(position.first, position.second, id);
	}
}

bool 
Tetramino::canRotate(Board& board) {
	bool isOk = true;
	
	removeFromBoard(board);
	
	//do hypotetical rotation
	angle = (angle + 1) % 4;
	
	//compute position avalibility
	for (unsigned int piece = 0 ; piece < 4 ; piece++) {
		Position futurPosition = computePosition(piece, referencePosition);
		int value = board.getValue(futurPosition.first, futurPosition.second);
		//~ cout << futurPosition.first << " " << futurPosition.second << " => " << value << endl;
		if (value != 0) {
			isOk = false;
			break;
		}
	}
	
	//undo hypotetical rotation
	angle = (angle - 1) % 4;
	
	addToBoard(board);
	
	return isOk;
}

bool
Tetramino::doRotate(Board& board) {
	if (canRotate(board)) {

		removeFromBoard(board);
		
		//rotate
		angle = (angle + 1)%4;
		
		addToBoard(board);
		
		return true;
	}
	return false;
}

bool 
Tetramino::canTranslate(Board& board, string direction) {
	bool isOk = true;
	
	int deltaX = 0;
	int deltaY = 0;
	if (direction == "down")  deltaY =  1;
	if (direction == "left")  deltaX = -1;
	if (direction == "right") deltaX =  1;
	
	removeFromBoard(board);
	
	//do hypotetical translate
	referencePosition.first  += deltaX;
	referencePosition.second += deltaY;
	
	//compute position avalibility
	for (unsigned int piece = 0 ; piece < 4 ; piece++) {
		Position futurPosition = computePosition(piece, referencePosition);
		int value = board.getValue(futurPosition.first, futurPosition.second);
		//~ cout << futurPosition.first << " " << futurPosition.second << " => " << value << endl;
		if (value != 0) {
			isOk = false;
			break;
		}
	}
	
	//undo hypotetical translate
	referencePosition.first  -= deltaX;
	referencePosition.second -= deltaY;
	
	addToBoard(board);
	
	return isOk;
}

bool
Tetramino::doTranslate(Board& board, string direction) {
	if (canTranslate(board, direction)) {

		int deltaX = 0;
		int deltaY = 0;
		if (direction == "down")  deltaY =  1;
		if (direction == "left")  deltaX = -1;
		if (direction == "right") deltaX =  1;
	
		removeFromBoard(board);
	
		//translate
		referencePosition.first  += deltaX;
		referencePosition.second += deltaY;
		
		addToBoard(board);
		
		return true;
	}
	return false;
}


bool 
Tetramino::doFall(Board& board) {
	bool keep_going = true;
	while (keep_going) {
		keep_going = doTranslate(board, "down");
	}
	return true;
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

