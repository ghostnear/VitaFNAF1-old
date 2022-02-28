#include "scene_warning.hpp"

namespace Engine::Game::Scenes
{
    void SceneWarning::onLoad(SDL_Renderer* renderer)
    {
        // Save the renderer refference for later use
        ren = renderer;

        // Load assets specific to this scene
        textImage = man -> loadImage("assets/text/WARNING.png", "text_warning", ren);
        textImage -> setColorKey(0x5A, 0x5A, 0x5A, ren);

        // Text alpha
        textAlpha = 0;
        textAlphaSpeed = 1.0 / 0.5;
        waitTimer = 1.5;
    }

    void SceneWarning::goToMenu()
    {
        // Create menu scene in memory and remove this one
        SceneMenu* newScene = new SceneMenu();
        parent -> push(newScene, ren);
        parent -> pop();
    }

    void SceneWarning::update(double dt)
    {
        // Fade in
        if(textAlpha < 1 && waitTimer == 1.5)
        {
            textAlpha += dt * textAlphaSpeed;
            if(textAlpha > 1) textAlpha = 1;
            SDL_SetTextureAlphaMod(textImage -> getTexture(), 255 * textAlpha);
        }
        // Wait a bit
        else if(textAlpha == 1 && waitTimer > 0)
        {
            waitTimer -= dt;
        }
        // Fade out
        else {
            textAlpha -= dt * textAlphaSpeed;
            if(textAlpha < 0)
            {
                textAlpha = 0;

                // Switch to the menu scene
                goToMenu();
            }
            SDL_SetTextureAlphaMod(textImage -> getTexture(), 255 * textAlpha);  
        }

    }

    void SceneWarning::draw()
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