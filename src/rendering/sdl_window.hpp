#ifndef RENDERING_WINDOW_HPP
#define RENDERING_WINDOW_HPP

#include <SDL2/SDL.h>
#include "../core/core.hpp"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 540

namespace Engine::Rendering
{
    class SDLWindow
    {
        SDL_Window* window;
        SDL_Renderer* renderer;

    public:
        // Constructor
        SDLWindow();

        // Destructor
        ~SDLWindow();

        // Get window pointer
        SDL_Window* getWindow();

        // Get renderer pointer
        SDL_Renderer* getRenderer();
    };
};

#endif