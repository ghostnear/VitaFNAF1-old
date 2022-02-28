#include "asset_manager.hpp"

namespace Engine::Game
{
    void AssetManager::loadImage(std::string path, std::string name, SDL_Renderer* renderer)
    {
        // Save the newly created asset here
        assets[name] = new Assets::ImageAsset(path, renderer);
    }

    Asset* AssetManager::getAsset(std::string name)
    {
        // Return the required asset pointer
        return assets[name];
    }
};