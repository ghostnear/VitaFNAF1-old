#ifndef SCENES_LOADING_HPP
#define SCENES_LOADING_HPP

#include "../types/types.hpp"
#include "../../scene_manager.hpp"
#include "../components/components.hpp"
#include <queue>

namespace Engine::Game::Scenes
{
    class SceneLoading : public Engine::Game::Scene
    {
        std::queue<std::pair<std::string, std::string>> imagesToLoad, audioToLoad;
        Assets::ImageAsset* currentImagePointer;
        Assets::AudioAsset* currentAudioPointer;
        Sprite loadingSprite;
        SDL_Rect loadRect;

        void goToWarning();

    public:
        void update(double dt);
        void onLoad(SDL_Renderer* ren);
        void draw();
    };
};

#endif