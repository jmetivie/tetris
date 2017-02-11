#include <iostream>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

void testPiece();


map<int, SDL_Surface*> bitmap_maps;

int main() {

	

	
	Board board(12,24);
	Tetramino t;
	
	//HERE LOOP
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		return 1;
	}
	SDL_Window* 	gWindow 		= SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 800, SDL_WINDOW_SHOWN );
	SDL_Surface* 	gScreenSurface 	= SDL_GetWindowSurface( gWindow );
	
	//loading image
	bitmap_maps[255] 	= IMG_Load("img/wall.bmp");
	bitmap_maps[0] 		= IMG_Load("img/black.bmp");
	bitmap_maps[1] 		= IMG_Load("img/cyan.bmp");
	bitmap_maps[2] 		= IMG_Load("img/red.bmp");
	bitmap_maps[3] 		= IMG_Load("img/blue.bmp");
	bitmap_maps[4] 		= IMG_Load("img/green.bmp");
	bitmap_maps[5] 		= IMG_Load("img/orange.bmp");
	bitmap_maps[6] 		= IMG_Load("img/yellow.bmp");
	bitmap_maps[7] 		= IMG_Load("img/purple.bmp");
	
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
						if (!res) {
							stuck = true;
						} 
						break;
					}
					case SDLK_SPACE: {
						res = t.doFall(board);
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

			//SDL_BlitSurface( bitmap_maps["wall"], NULL, gScreenSurface, NULL );
			
			for (int y = 0 ; y < board.getHeight() ; y++) {
				for (int x = 0 ; x < board.getWidth() ; x++) {
					int value = board.getValue(x,y);
					if (value == 255 || (value >= 0 && value < 8)) {
						SDL_Rect rcDest = { 30*(x+1), 30*(y+1), 0, 0 };
						SDL_BlitSurface ( bitmap_maps[value], NULL, gScreenSurface, &rcDest );
					}
				}
			}
			SDL_UpdateWindowSurface( gWindow );
			
			//SDL_Rect rcDest = { 20, 20, 0, 0 };
			//SDL_BlitSurface ( bitmap_maps["wall"], NULL, gScreenSurface, &rcDest );
			//something like SDL_UpdateRect(surface, x_pos, y_pos, image->w, image->h); is missing here
			//SDL_UpdateWindowSurface( gWindow );
			 
			 
			cout << "R: UP ARROW | ARROWS:TRANSLATE | SPACE:FALL" << endl;
		}
		if (gameover) {
			cout << "GAME OVER !!! " << endl;
			quit = true;
			return 0;
		}
		
		if (stuck == true) {
			list<unsigned int> lines = board.getCompleteLines();
			cout << "Complete: ";for (unsigned int l: lines) cout << l << " "; cout << endl;
			board.removeLines(lines);
		}
	}

	//cleaning surfaces 
	for (pair<int,SDL_Surface*> current: bitmap_maps) SDL_FreeSurface( current.second );

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