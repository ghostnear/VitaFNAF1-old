#include "scene_warning.hpp"

namespace Engine::Game::Scenes
{
    void SceneWarning::onLoad(SDL_Renderer* renderer)
    {
        // Save the renderer refference for later use
        ren = renderer;

        // Text alpha
        textAlpha = 0;
        textAlphaSpeed = 1.0 / 0.5;
        waitTimer = 1.5;

        // Text rectangle
        textRect = {
            SCREEN_WIDTH  * 1 / 4, 
            SCREEN_HEIGHT * 3 / 8, 
            SCREEN_WIDTH  * 1 / 2, 
            SCREEN_HEIGHT / 4 
        };
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
        }
        // Wait a bit
        else if(textAlpha == 1 && waitTimer > 0)
        {
            waitTimer -= dt;
        }
        // Fade out
        else
        {
            textAlpha -= dt * textAlphaSpeed;
            if(textAlpha < 0)
            {
                textAlpha = 0;

                // Switch to the menu scene
                goToMenu();
            }
             
        }

        // Update text alpha
        SDL_SetTextureAlphaMod(textImage -> getTexture(), 255 * textAlpha); 
    }

    void SceneWarning::draw()
    {
        // Get the text image pointer
        // (don't force the conversion in real scenarios, it is going to fail if assets are not present)
        textImage = (Assets::ImageAsset*) man -> getAsset("text_warning");

        // Check if the pointer exists so no crashes occur
        if(textImage != NULL)
        {
            // Do the text drawing
            SDL_RenderCopy(ren, textImage -> getTexture(), NULL, &textRect);
        }
    }
};