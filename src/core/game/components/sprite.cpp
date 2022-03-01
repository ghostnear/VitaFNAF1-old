#include "sprite.hpp"

namespace Engine::Game
{
    Sprite::Sprite()
    {
        alpha = 255;
    }

    void Sprite::setSprite(Assets::ImageAsset* newSprite, std::string newSpriteName)
    {
        if(newSpriteName == "" || (newSpriteName != spriteName))
        {
            sprite = newSprite;
            spriteName = newSpriteName;
        }
    }

    std::string Sprite::getName()
    {
        return spriteName;
    }

    void Sprite::setAlpha(int newAlpha)
    {
        if(alpha != newAlpha && sprite != NULL)
            SDL_SetTextureAlphaMod(sprite -> getTexture(), newAlpha); 
        alpha = newAlpha;
    }

    void Sprite::draw(SDL_Renderer* ren)
    {
        if(sprite != NULL)
            SDL_RenderCopy(ren, sprite -> getTexture(), NULL, spriteRect);
    }
    
    void Sprite::updateRect(SDL_Rect* newRect)
    {
        spriteRect = newRect;
    }
};