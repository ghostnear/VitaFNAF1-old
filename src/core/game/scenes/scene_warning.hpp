#ifndef SCENES_WARNING_HPP
#define SCENES_WARNING_HPP

#include "../types/types.hpp"
#include "../../scene_manager.hpp"
#include "../components/components.hpp"
#include "scene_menu.hpp"

namespace Engine::Game::Scenes
{
    class SceneWarning : public Engine::Game::Scene
    {
        double textAlpha, textAlphaSpeed, waitTimer;
        Assets::ImageAsset* textImage;
        Sprite warningSprite;
        SDL_Rect textRect;

        void goToMenu();

    public:
        void update(double dt);
        void onLoad(SDL_Renderer* ren);
        void draw();
    };
};

#endif