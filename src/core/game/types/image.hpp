#ifndef ASSET_TYPE_IMAGE_HPP
#define ASSET_TYPE_IMAGE_HPP

#include "asset.hpp"
#include <SDL2/SDL_image.h>

namespace Engine::Game::Assets
{
    class ImageAsset : public Asset
    {
        SDL_Surface* imageSurface;
        SDL_Texture* imageTexture;

    public:
        // Constructor
        ImageAsset(std::string path, SDL_Renderer* renderer);

        // Surface getter
        SDL_Surface* getSurface();

        // Set color key
        void setColorKey(int r, int g, int b, SDL_Renderer* renderer);
        
        // Texture getter
        SDL_Texture* getTexture();
    };
};

#endif