#ifndef GAME_SPRITE_HPP
#define GAME_SPRITE_HPP

#include "../types/types.hpp"
#include <string>

namespace Engine::Game
{
    class Sprite
    {
        Assets::ImageAsset* sprite;
        SDL_Rect* spriteRect;
        std::string spriteName;
        int alpha;

    public:
        // Constructor
        Sprite();

        // Sets sprite to a pointer
        void setSprite(Assets::ImageAsset* newSprite, std::string newSpriteName = "");

        // Sets sprite alpha
        void setAlpha(int newAlpha);

        // Draws the sprite
        void draw(SDL_Renderer* ren);

        // Updates the drawing rectangle
        void updateRect(SDL_Rect* newRect);

        // Gets the sprite name
        std::string getName();
    };
};

#endif