#ifndef SCENES_MENU_HPP
#define SCENES_MENU_HPP

#include <cstdlib>
#include "../types/types.hpp"
#include "../../scene_manager.hpp"
#include "../components/components.hpp"

namespace Engine::Game::Scenes
{
    class SceneMenu : public Engine::Game::Scene
    {
        double bgTimer;
        Sprite backgroundSprite;

    public:
        void update(double dt);
        void onLoad(SDL_Renderer* ren);
        void draw();
    };
};

#endif