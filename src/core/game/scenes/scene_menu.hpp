#ifndef SCENES_MENU_HPP
#define SCENES_MENU_HPP

#include "../../types/scene.hpp"
#include "../../scene_manager.hpp"

namespace Engine::Game::Scenes
{
    class SceneMenu : public Engine::Game::Scene
    {
    public:
        void update(double dt);
        void onLoad(SDL_Renderer* ren);
        void draw();
    };
};

#endif