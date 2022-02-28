#include "engine.hpp"
#include <cstdio>
#include <SDL2/SDL.h>

using namespace Engine;

int main(int argc, char *argv[])
{
	// Init SDL stuff
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return -1;

	// Create a window
	Rendering::SDLWindow win;
	SDL_Renderer* ren = win.getRenderer();

	// Do the drawing
	SDL_Rect fillRect = { SCREEN_WIDTH  / 4, 
				SCREEN_HEIGHT / 4, 
				SCREEN_WIDTH  / 2, 
				SCREEN_HEIGHT / 2 
	};
	SDL_SetRenderDrawColor(ren, 255,0,0,255);
	SDL_RenderFillRect(ren, &fillRect );
	SDL_RenderPresent(ren);
	SDL_Delay(4000);

	Core::exit_process(0);
}