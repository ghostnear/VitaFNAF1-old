#include "asset_manager.hpp"

namespace Engine::Game
{
    void AssetManager::loadImage(std::string path, std::string name)
    {
        
    }

    Asset* AssetManager::getAsset(std::string name)
    {
        // Return the required asset pointer
        return assets[name];
    }
};