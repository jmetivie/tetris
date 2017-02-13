#include <iostream>
#include <map>
#include <chrono>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "board.hpp"
#include "tetramino.hpp"

using namespace std;

map<int, SDL_Surface*> loadImages();




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
	map<int, SDL_Surface*> bitmap_maps = loadImages();
	
	cout << "R: UP ARROW | ARROWS:TRANSLATE | SPACE:FALL" << endl;
	
	unsigned int nbLines = 0;
	unsigned int base_speed = 1000;
	unsigned int speed 		= 1000;
	bool gameover = false;
	bool quit = false;
	bool stuck = true;
	SDL_Event e;
	
	
	unsigned int time_last = time(NULL);
	long long int time_ms_last = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
	//cout << "Time in Milliseconds =" <<  chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count() << std::endl;


	
	
	while( !quit )  {
		 bool res = false;
		 //~ unsigned int time_new = time(NULL);
		 //~ if (time_new != time_last) {
			 //~ res = t.doTranslate(board, "down");
			 //~ if (!res) stuck = true;
			 //~ time_last = time_new;
			 //~ 
		 //~ }
		long long int time_ms_new = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
		 if (time_ms_new - time_ms_last >= speed) {	
			 res = t.doTranslate(board, "down");
			 if (!res) stuck = true;
			 time_ms_last = time_ms_new;
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
		 
		 if (stuck == true) {
			list<unsigned int> lines = board.getCompleteLines();
			if (!lines.empty()) { 
				nbLines += lines.size();
				board.removeLines(lines);
				speed = base_speed * pow(0.9,nbLines/10);
				cout << "Complete: ";for (unsigned int l: lines) cout << l << " "; cout << " #lines:" << nbLines << " speed:" << speed << endl;
				
				
				
			}
						
			 stuck = false;
			 t = Tetramino::randomTetraminoFactory();
			 gameover = !(board.addPiece(t, make_pair((board.getWidth()/2-1),0)));
		}
		 
		 if (res) {
			//board.display();			
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
			 

		}
		if (gameover) {
			cout << "GAME OVER !!! " << endl;
			quit = true;
			return 0;
		}
		
		
	}

	//cleaning surfaces 
	for (pair<int,SDL_Surface*> current: bitmap_maps) SDL_FreeSurface( current.second );

	return 0;
}


map<int, SDL_Surface*> loadImages() {
	map<int, SDL_Surface*> bitmap_maps;
	bitmap_maps[255] 	= IMG_Load("img/wall.bmp");
	bitmap_maps[0] 		= IMG_Load("img/black.bmp");
	bitmap_maps[1] 		= IMG_Load("img/cyan.bmp");
	bitmap_maps[2] 		= IMG_Load("img/red.bmp");
	bitmap_maps[3] 		= IMG_Load("img/blue.bmp");
	bitmap_maps[4] 		= IMG_Load("img/green.bmp");
	bitmap_maps[5] 		= IMG_Load("img/orange.bmp");
	bitmap_maps[6] 		= IMG_Load("img/yellow.bmp");
	bitmap_maps[7] 		= IMG_Load("img/purple.bmp");
	return bitmap_maps;
}
