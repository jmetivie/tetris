CFLAG= -c -std=c++0x

all: tetris

tetramino.o: tetramino.hpp tetramino.cpp
	g++ tetramino.cpp $(CFLAG)

board.o: tetramino.o board.hpp board.cpp
	g++ board.cpp $(CFLAG)
	
main.o: tetramino.o board.o main.cpp
	g++ main.cpp $(CFLAG)

tetris: tetramino.o board.o main.o
	g++ *.o -o tetris -lSDL2 -lSDL2_image -lSDL2_ttf

clean: 
	rm tetris
	rm *.o
