#ifndef CORE_ASSETMANAGER_HPP
#define CORE_ASSETMANAGER_HPP

#include <map>
#include <string>
#include "types/image.hpp"

namespace Engine::Game
{
    class AssetManager
    {
    private:
        std::map<std::string, Asset*> assets;

    public:
        // Loaders for specific things
        void loadImage(std::string path, std::string name);

        // Gets an asset
        Asset* getAsset(std::string name);
    };
};

#endif