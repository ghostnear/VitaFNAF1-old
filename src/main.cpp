#include "engine.hpp"
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace Engine;
using namespace Engine::Game;

int main(int argc, char* argv[])
{
	// Init SDL stuff
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return -1;

	// Create the window and get the renderer pointer
	Rendering::SDLWindow* win = new Rendering::SDLWindow();
	SDL_Renderer* ren = win -> getRenderer();
	win -> renameWindow("Five Nights at Freddy's");
	
	// Create the scene manager with a new scene
	Game::SceneManager man;
	man.push(new Game::Scenes::SceneWarning());

	// Do a test draw
	man.draw(ren);

	// Update 
	SDL_RenderPresent(ren);
	SDL_Delay(4000);

	// Exit the process
	Core::exit_process(0);
}