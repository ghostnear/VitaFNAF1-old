#ifndef CORE_SCENE_HPP
#define CORE_SCENE_HPP

#include <SDL2/SDL.h>
#include "../asset_manager.hpp"

namespace Engine::Game
{
    class Scene
    {
    protected:
        AssetManager* man;

    public:
        virtual void draw(SDL_Renderer* ren) = 0;
    };
};


#endif