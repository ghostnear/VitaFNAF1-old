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
        imagesToLoad.push(std::make_pair("assets/text/GAME_TITLE.png", "text_game_title"));
        imagesToLoad.push(std::make_pair("assets/menu/1.png", "menu_bg_1"));
        imagesToLoad.push(std::make_pair("assets/menu/2.png", "menu_bg_2"));
        imagesToLoad.push(std::make_pair("assets/menu/3.png", "menu_bg_3"));
        imagesToLoad.push(std::make_pair("assets/menu/4.png", "menu_bg_4"));
        imagesToLoad.push(std::make_pair("assets/gui/static/1.png", "static_1"));
        imagesToLoad.push(std::make_pair("assets/gui/static/2.png", "static_2"));
        imagesToLoad.push(std::make_pair("assets/gui/static/3.png", "static_3"));
        imagesToLoad.push(std::make_pair("assets/gui/static/4.png", "static_4"));
        imagesToLoad.push(std::make_pair("assets/gui/static/5.png", "static_5"));
        imagesToLoad.push(std::make_pair("assets/gui/static/6.png", "static_6"));
        imagesToLoad.push(std::make_pair("assets/gui/static/7.png", "static_7"));
        imagesToLoad.push(std::make_pair("assets/gui/static/8.png", "static_8"));

        audioToLoad.push(std::make_pair("assets/audio/static2.wav", "menu_static"));
        audioToLoad.push(std::make_pair("assets/audio/darkness_music.wav", "menu_loop"));
        
        // Loader rectangle
        loadRect = {
            SCREEN_WIDTH  * 4 / 5, 
            SCREEN_HEIGHT - 3 * (SCREEN_WIDTH  * 1 / 10) / 2, 
            SCREEN_WIDTH  * 1 / 10, 
            SCREEN_WIDTH  * 1 / 10
        };
        loadingSprite.updateRect(&loadRect);
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
        // TODO: make this better
        loadRect.x = parent -> getWindow() -> getSize().first  * 4 / 5;
        loadRect.y = parent -> getWindow() -> getSize().second - 3 * (parent -> getWindow() -> getSize().first * 1.0 / 10) / 2;
        loadRect.w = parent -> getWindow() -> getSize().first  * 1 / 10;
        loadRect.h = parent -> getWindow() -> getSize().first  * 1 / 10;

        // TODO: this should be put on another thread

        // Check for images
        if(!imagesToLoad.empty())
        {
            auto x = imagesToLoad.front();
            imagesToLoad.pop();

            // Load the asset
            currentImagePointer = man -> loadImage(x.first, x.second, ren);

            // Only images that need to be color key'd (TODO: find a better way to do this)
            if(x.second == "gui_loader" || x.second.substr(0, 5) == "text_")
                currentImagePointer -> setColorKey(0x5A, 0x5A, 0x5A, ren);
        }
        // Check for MP3s
        else if(!audioToLoad.empty())
        {
            auto x = audioToLoad.front();
            audioToLoad.pop();

            // Load the asset
            currentAudioPointer = man -> loadMP3(x.first, x.second);
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
            // Update the warning sprite to have the correct pointer
            loadingSprite.setSprite(currentImagePointer);

            // Do the text drawing
            loadingSprite.draw(ren);
        }
    }
};