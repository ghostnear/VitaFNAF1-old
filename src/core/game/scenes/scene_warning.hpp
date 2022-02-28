#ifndef SCENES_WARNING_HPP
#define SCENES_WARNING_HPP

#include "../../types/scene.hpp"
#include "../../scene_manager.hpp"
#include "scene_menu.hpp"

namespace Engine::Game::Scenes
{
    class SceneWarning : public Engine::Game::Scene
    {
        double textAlpha, textAlphaSpeed, waitTimer;
        Assets::ImageAsset* textImage;

        void goToMenu();

    public:
        void update(double dt);
        void onLoad(SDL_Renderer* ren);
        void draw();
    };
};

#endif