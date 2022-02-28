#include "scene_warning.hpp"

namespace Engine::Game::Scenes
{
    void SceneWarning::draw(SDL_Renderer* ren)
    {
        // Do the drawing
        SDL_Rect fillRect = {
            SCREEN_WIDTH  / 4, 
            SCREEN_HEIGHT / 4, 
            SCREEN_WIDTH  / 2, 
            SCREEN_HEIGHT / 2 
        };
        SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
        SDL_RenderFillRect(ren, &fillRect );
    }
};