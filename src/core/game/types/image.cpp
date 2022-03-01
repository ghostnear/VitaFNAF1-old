#include "image.hpp"

namespace Engine::Game::Assets
{
    ImageAsset::ImageAsset(std::string path, SDL_Renderer* renderer)
    {
        imageSurface = IMG_Load(path.c_str());
        imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);

        // ! Compressed PNGs don't work without this !
        SDL_SetTextureBlendMode(imageTexture, SDL_BLENDMODE_BLEND);
    }

    SDL_Surface* ImageAsset::getSurface()
    {
        return imageSurface;
    }

    void ImageAsset::setColorKey(int r, int g, int b, SDL_Renderer* renderer)
    {
        // Set the mapping and rebuild the texture
        SDL_SetColorKey(imageSurface, SDL_TRUE, SDL_MapRGB(imageSurface -> format, r, g, b));

        SDL_DestroyTexture(imageTexture);
        imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    }
    
    SDL_Texture* ImageAsset::getTexture()
    {
        return imageTexture;
    }
};