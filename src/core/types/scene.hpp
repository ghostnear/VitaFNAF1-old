#ifndef CORE_SCENE_HPP
#define CORE_SCENE_HPP

#include <SDL2/SDL.h>
#include "../asset_manager.hpp"

namespace Engine::Game
{
    // Forward declaration to parent
    class SceneManager;

    class Scene
    {
    protected:
        AssetManager* man = new AssetManager();

    public:
        SceneManager* parent;
        SDL_Renderer* ren;
        virtual void update(double dt) = 0;
        virtual void onLoad(SDL_Renderer* ren) = 0;
        virtual void draw() = 0;
    };
};


#endif