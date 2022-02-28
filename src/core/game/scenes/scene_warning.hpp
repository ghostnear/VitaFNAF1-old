#ifndef SCENES_WARNING_HPP
#define SCENES_WARNING_HPP

#include "../../types/scene.hpp"
#include "../../scene_manager.hpp"

namespace Engine::Game::Scenes
{
    class SceneWarning : public Engine::Game::Scene
    {
    public:
        void onLoad(SDL_Renderer* ren);
        void draw(SDL_Renderer* ren);
    };
};

#endif