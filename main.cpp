#include <iostream>
#include <SDL2/SDL.h>

#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

void testPiece();

int main() {

	
	Board board(12,24);
	Tetramino t = Tetramino::randomTetraminoFactory();
	board.addPiece(t, make_pair((board.getWidth()/2-1),0));
	
	//HERE LOOP
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return 1;
	}
	SDL_Window* gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );
	
	board.display();
	cout << "R: UP ARROW | ARROWS:TRANSLATE | SPACE:FALL" << endl;
	
	bool quit = false;
	SDL_Event e;
	unsigned int time_last = time(NULL);
	while( !quit )  {
		 
		 bool res = false;
		 unsigned int time_new = time(NULL);
		 if (time_new != time_last) {
			 res = t.doTranslate(board, "down");
			 time_last = time_new;
		 }
		 
		 while( SDL_PollEvent( &e ) != 0 ) {
						
			if( e.type == SDL_QUIT ) quit = true;
			if( e.type == SDL_KEYDOWN ) {
				
				switch( e.key.keysym.sym ) {
					case SDLK_UP: {
						res = t.doRotate(board);
						break;
					}
					case SDLK_LEFT: {
						res = t.doTranslate(board, "left");
						break;
					}
					case SDLK_RIGHT: {
						res = t.doTranslate(board, "right");
						break;
					}
					case SDLK_DOWN: {
						res = t.doTranslate(board, "down");
						break;
					}
					case SDLK_SPACE: {
						res = t.doFall(board);
						list<unsigned int> lines = board.getCompleteLines();
						cout << "Complete: ";for (unsigned int l: lines) cout << l << " "; cout << endl;
						board.removeLines(lines);
						t = Tetramino::randomTetraminoFactory();
						board.addPiece(t, make_pair((board.getWidth()/2-1),0));
						break;
					}
					default:
						cout << "WHAT !!! " << endl;
						break;
				 }
			 }
		 }
		 
		 if (res) {
			 board.display();
			cout << "R: UP ARROW | ARROWS:TRANSLATE | SPACE:FALL" << endl;
		}
	}

	return 0;
}


void testPiece() {
	TPiece t;
	for (int angle = 0 ; angle < 5 ; angle++) {
		Board board(4,4);
		board.addPiece(t, make_pair(0,0));
		board.display();
		t.doRotate(board);
	}
}
