#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <iostream>
#include <vector>

using namespace std;

typedef pair<unsigned int, unsigned int> Position;

// pieces -> ID:color
// I->1:cyan		J->2:blue		L->3:orange		 O->4:yellow
// S->5:green		Z->6:red		T->7:purple

class Tetramino {
	protected:
		//~ static unsigned int id;
		//~ static string color;
		unsigned int id;
		string color;
		vector<Position> positions;
	public:
		Tetramino();
		~Tetramino();
		
		virtual bool canRotate() const {return false;}
		virtual void doRotate() {};
		
		inline string getColor() 	const { return color; }
		inline unsigned int getId() const { return id; }
		inline Position getPosition(unsigned int i) const { return positions[i]; }
		
		static Tetramino randomTetraminoFactory();
};

class IPiece : public Tetramino {
	public:
		IPiece();
		~IPiece(){}
		
		bool canRotate() const;
		void doRotate();		
};

class JPiece : public Tetramino {
	public:
		JPiece();
		~JPiece(){}
		
		bool canRotate() const;
		void doRotate();		
};

class LPiece : public Tetramino {
	public:
		LPiece();
		~LPiece(){}
		
		bool canRotate() const;
		void doRotate();		
};

class OPiece : public Tetramino {
	public:
		OPiece();
		~OPiece(){}
		
		bool canRotate() const;
		void doRotate();		
};

class SPiece : public Tetramino {
	public:
		SPiece();
		~SPiece(){}
		
		bool canRotate() const;
		void doRotate();		
};

class ZPiece : public Tetramino {
	public:
		ZPiece();
		~ZPiece(){}
		
		bool canRotate() const;
		void doRotate();		
};

class TPiece : public Tetramino {
	public:
		TPiece();
		~TPiece(){}
		
		bool canRotate() const;
		void doRotate();		
};



#endif
