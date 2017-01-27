#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <iostream>
#include <vector>

using namespace std;

typedef pair<unsigned int, unsigned int> Position;

class  Board;
// pieces -> ID:color
// I->1:cyan		J->2:blue		L->3:orange		 O->4:yellow
// S->5:green		Z->6:red		T->7:purple

class Tetramino {
	protected:
		unsigned int id;
		string color;
		
		Position referencePosition; //upper left
		unsigned int angle;
		vector< vector<Position> > positions; //4 rotations (x 4 positions of blocks)
	public:
		Tetramino();
		~Tetramino();
		static Tetramino randomTetraminoFactory();
		
		Position computePosition(unsigned int piecePart, Position& position);
		
		void removeFromBoard(Board& board);
		void addToBoard(Board& board);
		bool canRotate(Board& board);
		bool doRotate(Board& board);
		bool canTranslate(Board& board, string direction);
		bool doTranslate(Board& board,  string direction);
		bool doFall(Board& board);
		
		inline string 			getColor() 	const { return color; }
		inline unsigned int 	getId() const { return id; }
		inline Position 		getPosition(unsigned int i) 				const { return positions[angle][i]; }
		inline Position			getReferencePosition() 						const { return referencePosition; }
		inline void				setReferencePosition(Position& position) 		  { referencePosition = position; }
		
		
		
		
};

class IPiece : public Tetramino {
	public:
		IPiece();
		~IPiece(){}	
};

class JPiece : public Tetramino {
	public:
		JPiece();
		~JPiece(){}	
};

class LPiece : public Tetramino {
	public:
		LPiece();
		~LPiece(){}	
};

class OPiece : public Tetramino {
	public:
		OPiece();
		~OPiece(){}		
};

class SPiece : public Tetramino {
	public:
		SPiece();
		~SPiece(){}	
};

class ZPiece : public Tetramino {
	public:
		ZPiece();
		~ZPiece(){}		
};

class TPiece : public Tetramino {
	public:
		TPiece();
		~TPiece(){}		
};



#endif
