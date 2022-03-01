#include "scene_menu.hpp"

namespace Engine::Game::Scenes
{
    void SceneMenu::onLoad(SDL_Renderer* renderer)
    {
        // Save the renderer refference for later use
        ren = renderer;

        // Assume the assets have been passed by the previous scene

        // Set default values for timers
        bgTimer = staticTimer = 0;

        // Do another random generator reset just to be sure
        srand(time(NULL));

        // Set default coords
        fnafTextRect = {
            SCREEN_WIDTH  * 110 / 960, 
            SCREEN_HEIGHT * 50 / 540, 
            SCREEN_WIDTH  * 180 / 960, 
            SCREEN_HEIGHT  * 180 / 540
        };

        // Set default sprites
        fnafText.updateRect(&fnafTextRect);
        fnafText.setSprite((Assets::ImageAsset*) man -> getAsset("text_game_title"));
        staticSprite.setAlpha(50 + rand() % 100);
        staticSprite.setSprite((Assets::ImageAsset*) man -> getAsset("static_1"), "static_1");
        backgroundSprite.setAlpha(rand() % 255);
        backgroundSprite.setSprite((Assets::ImageAsset*) man -> getAsset("menu_bg_1"), "menu_bg_1");

        // Start the music
        ((Assets::AudioAsset*)(man -> getAsset("menu_static"))) -> play();
        ((Assets::AudioAsset*)(man -> getAsset("menu_loop"))) -> setLoops(-1);
    }

    void SceneMenu::update(double dt)
    {
        // TODO: do this better
        fnafTextRect.x = parent -> getWindow() -> getSize().first * 110 / 960;
        fnafTextRect.y = parent -> getWindow() -> getSize().second * 50 / 540;
        fnafTextRect.w = parent -> getWindow() -> getSize().first * 180 / 960;
        fnafTextRect.h = parent -> getWindow() -> getSize().second * 180 / 540;

        // Update timers
        bgTimer += dt;
        staticTimer += dt;
        timer60HZ += dt;
        if(bgTimer >= 8.0 / 100)
        {
            // Make it twitch
            switch(rand() % 100)
            {
                case 99:
                    backgroundSprite.setSprite((Assets::ImageAsset*) man -> getAsset("menu_bg_4"), "menu_bg_4");
                    break;
                case 98:
                    backgroundSprite.setSprite((Assets::ImageAsset*) man -> getAsset("menu_bg_3"), "menu_bg_3");
                    break;
                case 97:
                    backgroundSprite.setSprite((Assets::ImageAsset*) man -> getAsset("menu_bg_2"), "menu_bg_2");
                    break;
                default:
                    backgroundSprite.setSprite((Assets::ImageAsset*) man -> getAsset("menu_bg_1"), "menu_bg_1");
                    break;
            }
            backgroundSprite.setAlpha(rand() % 255);
            bgTimer -= 8.0 / 100;    
        }

        if(staticTimer >= 9.0 / 100)
        {
            staticSprite.setAlpha(50 + rand() % 100);
            staticTimer -= 9.0 / 100;
        }

        if(timer60HZ >= 1.0 / 60)
        {
            staticIndex = rand() % 8 + 1;
            staticSprite.setSprite((Assets::ImageAsset*) man -> getAsset("static_" + std::to_string(staticIndex)));

            timer60HZ -= 1.0 / 60;
        }
    }

    void SceneMenu::draw()
    {
        //Draw the background in fullscreen
        backgroundSprite.draw(ren);

        // Draw the static over it
        staticSprite.draw(ren);

        // Draw the title
        fnafText.draw(ren);
    }
};