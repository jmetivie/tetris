#include <iostream>
#include <SDL2/SDL.h>

#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

void testPiece();

int main() {

	
	Board board(12,24);
	Tetramino t;
	
	//HERE LOOP
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return 1;
	}
	SDL_Window* gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN );
	
	board.display();
	cout << "R: UP ARROW | ARROWS:TRANSLATE | SPACE:FALL" << endl;
	
	bool gameover = false;
	bool quit = false;
	bool stuck = true;
	SDL_Event e;
	unsigned int time_last = time(NULL);
	while( !quit )  {
		 
		 if (stuck) {
			 stuck = false;
			 t = Tetramino::randomTetraminoFactory();
			 gameover = !(board.addPiece(t, make_pair((board.getWidth()/2-1),0)));
		 }
		 
		 bool res = false;
		 unsigned int time_new = time(NULL);
		 if (time_new != time_last) {
			 res = t.doTranslate(board, "down");
			 if (!res) stuck = true;
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
						if (!res) stuck = true;
						break;
					}
					case SDLK_SPACE: {
						res = t.doFall(board);
						list<unsigned int> lines = board.getCompleteLines();
						cout << "Complete: ";for (unsigned int l: lines) cout << l << " "; cout << endl;
						board.removeLines(lines);
						stuck = true;
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
		if (gameover) {
			cout << "GAME OVER !!! " << endl;
			quit = true;
			return 0;
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
