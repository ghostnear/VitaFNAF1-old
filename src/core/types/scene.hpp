#ifndef CORE_SCENE_HPP
#define CORE_SCENE_HPP

#include <SDL2/SDL.h>

namespace Engine::Game
{
    class Scene
    {
    public:
        virtual void draw(SDL_Renderer* ren) = 0;
    };
};


#endif