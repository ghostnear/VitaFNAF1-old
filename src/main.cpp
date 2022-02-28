#include "engine.hpp"
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace Engine;
using namespace Engine::Game;

// Create a window and get the pointer to the renderer
Rendering::SDLWindow *win = new Rendering::SDLWindow();
SDL_Renderer* ren = win -> getRenderer();

// Create the scene manager
Game::SceneManager man;

int main(int argc, char *argv[])
{
	// Init SDL stuff
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return -1;

	// Push first scene
	man.push(new Game::Scenes::SceneWarning());

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

	// Exit the process
	Core::exit_process(0);
}