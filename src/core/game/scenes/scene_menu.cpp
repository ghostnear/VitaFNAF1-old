#include "scene_menu.hpp"

namespace Engine::Game::Scenes
{
    void SceneMenu::onLoad(SDL_Renderer* renderer)
    {
        // Save the renderer refference for later use
        ren = renderer;

        // Assume the assets have been passed by the previous scene

        // Set default sprite
        backgroundSprite.setSprite((Assets::ImageAsset*) man -> getAsset("menu_bg_1"), "menu_bg_1");
    }

    void SceneMenu::update(double dt)
    {
        // Update timers
        bgTimer += dt;
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
            bgTimer -= 8.0 / 100;    
        }
    }

    void SceneMenu::draw()
    {
        //Draw the background in fullscreen
        backgroundSprite.draw(ren);
    }
};