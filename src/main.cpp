#ifdef ENV_VITA
	#include <psp2/kernel/processmgr.h>
#endif

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

#include <cstdio>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
	// Init SDL stuff
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
		return -1;

	SDL_Window *winPointer = SDL_CreateWindow("RedRectangle",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if(winPointer == NULL)
	{
		printf("{E}: Could not create SDL window: %s!", SDL_GetError());
		return -1;
	}

	SDL_Renderer *winRenderer = SDL_CreateRenderer(winPointer, -1, 0);

	if(winRenderer == NULL)
	{
		printf("{E}: Could not create SDL renderer: %s!", SDL_GetError());
		return -1;
	}

	// Do the drawing
	SDL_Rect fillRect = { SCREEN_WIDTH  / 4, 
				SCREEN_HEIGHT / 4, 
				SCREEN_WIDTH  / 2, 
				SCREEN_HEIGHT / 2 
	};
	SDL_SetRenderDrawColor( winRenderer, 255,0,0,255);
	SDL_RenderFillRect(winRenderer, &fillRect );
	SDL_RenderPresent(winRenderer);
	SDL_Delay(4000);

	// Clean up and leave
	SDL_DestroyWindow(winPointer);
	winPointer = NULL;
	SDL_DestroyRenderer(winRenderer);
	winRenderer = NULL;

	#ifdef ENV_VITA
		sceKernelExitProcess(0);
	#endif
	
    return 0;
}