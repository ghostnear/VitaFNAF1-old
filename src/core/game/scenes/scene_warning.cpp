#include "scene_warning.hpp"

namespace Engine::Game::Scenes
{
    void SceneWarning::onLoad(SDL_Renderer* ren)
    {
        // Load assets specific to this scene
        man -> loadImage("assets/text/WARNING.png", "text_warning", ren);
        ((Assets::ImageAsset*) man -> getAsset("text_warning")) -> setColorKey(0x5A, 0x5A, 0x5A, ren);
    }

    void SceneWarning::draw(SDL_Renderer* ren)
    {
        // Get the text image pointer
        // (don't force the conversion in real scenarios, it is going to fail if assets are not present)
        Assets::ImageAsset* textImage = (Assets::ImageAsset*) man -> getAsset("text_warning");

        // Check if the pointer exists so no crashes occur
        if(textImage != NULL)
        {
            // Do the drawing with a test rectangle
            SDL_Rect testRect = {
                SCREEN_WIDTH  * 1 / 4, 
                SCREEN_HEIGHT * 3 / 8, 
                SCREEN_WIDTH  * 1 / 2, 
                SCREEN_HEIGHT / 4 
            };

            SDL_RenderCopy(ren, textImage -> getTexture(), NULL, &testRect);
        }
    }
};