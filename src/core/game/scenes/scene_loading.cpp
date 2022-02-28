#include "scene_loading.hpp"

namespace Engine::Game::Scenes
{
    void SceneLoading::onLoad(SDL_Renderer* renderer)
    {
        // Save the renderer refference for later use
        ren = renderer;

        // Manually push back the assets to load
        // TODO: better way to do this
        imagesToLoad.push(std::make_pair("assets/gui/loader.png", "gui_loader"));
        imagesToLoad.push(std::make_pair("assets/text/WARNING.png", "text_warning"));

        // Loader rectangle
        loadRect = {
            SCREEN_WIDTH  * 4 / 5, 
            SCREEN_HEIGHT - 3 * (SCREEN_WIDTH  * 1 / 10) / 2, 
            SCREEN_WIDTH  * 1 / 10, 
            SCREEN_WIDTH  * 1 / 10
        };
    }

    void SceneLoading::goToWarning()
    {
        // Create menu scene in memory and remove this one
        SceneWarning* newScene = new SceneWarning();
        newScene -> changeManager(man);
        parent -> push(newScene, ren);
        parent -> pop();
    }

    void SceneLoading::update(double dt)
    {
        // TODO: this should be put on another thread

        // Check for images
        if(!imagesToLoad.empty())
        {
            auto x = imagesToLoad.front();
            imagesToLoad.pop();

            // Load assets specific to this scene
            currentImagePointer = man -> loadImage(x.first, x.second, ren);
            currentImagePointer -> setColorKey(0x5A, 0x5A, 0x5A, ren);
        }
        else
        {
            // Go to the warning
            goToWarning();
        }
    }

    void SceneLoading::draw()
    {
        // Get the text image pointer
        // (don't force the conversion in real scenarios, it is going to fail if assets are not present)
        currentImagePointer = (Assets::ImageAsset*) man -> getAsset("gui_loader");

        // Check if the pointer exists so no crashes occur
        if(currentImagePointer != NULL)
        {
            // Do the text drawing
            SDL_RenderCopy(ren, currentImagePointer -> getTexture(), NULL, &loadRect);
        }
    }
};