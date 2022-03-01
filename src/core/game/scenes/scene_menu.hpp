#ifndef SCENES_MENU_HPP
#define SCENES_MENU_HPP

#include <cstdlib>
#include <string>
#include "../types/types.hpp"
#include "../../scene_manager.hpp"
#include "../components/components.hpp"

namespace Engine::Game::Scenes
{
    class SceneMenu : public Engine::Game::Scene
    {
        double bgTimer, staticTimer;
        double timer60HZ;
        int staticIndex = 1;
        Sprite backgroundSprite, staticSprite;

    public:
        void update(double dt);
        void onLoad(SDL_Renderer* ren);
        void draw();
    };
};

#endif