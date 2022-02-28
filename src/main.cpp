#include "engine.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

using namespace Engine;
using namespace Engine::Game;

int main(int argc, char* argv[])
{
	// Init SDL stuff
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		Core::exit_process(-1);
	if(IMG_Init(IMG_INIT_PNG) < 0)
		Core::exit_process(-1);

	// Create the window and get the renderer pointer
	Rendering::SDLWindow* win = new Rendering::SDLWindow();
	SDL_Renderer* ren = win -> getRenderer();
	win -> renameWindow("Five Nights at Freddy's");
	
	// Create the scene manager with the base scene
	Game::SceneManager man;
	man.push(new Game::Scenes::SceneWarning(), ren);

	// Events polling
	SDL_Event e;

	// While not fully exited
	while(man.getStateCount() >= 1)
	{
		// Handle queue events
		while(SDL_PollEvent(&e))
		{
			// Quit event has been sent
			if(e.type == SDL_QUIT)
			{
				// Clear all states from memory so the game can stop
				man.clear();
			}
		}

		// Do the draw event and update the screen
		man.draw(ren);
		SDL_RenderPresent(ren);

		SDL_Delay(5);
	}

	// Exit the process
	Core::exit_process(0);
}