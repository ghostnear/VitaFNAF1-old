#ifndef CORE_ASSETMANAGER_HPP
#define CORE_ASSETMANAGER_HPP

#include <map>
#include <string>
#include "game/types/image.hpp"
#include "game/types/audio.hpp"

namespace Engine::Game
{
    class AssetManager
    {
    private:
        std::map<std::string, Asset*> assets;

    public:
        // Loaders for specific things that return their adresses
        Assets::ImageAsset* loadImage(std::string path, std::string name, SDL_Renderer* renderer);
        Assets::AudioAsset* loadMP3(std::string path, std::string name);

        // Gets an asset
        Asset* getAsset(std::string name);
    };
};

#endif