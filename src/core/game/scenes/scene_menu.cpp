#include "scene_menu.hpp"

namespace Engine::Game::Scenes
{
    void SceneMenu::onLoad(SDL_Renderer* renderer)
    {
        // Save the renderer refference for later use
        ren = renderer;
    }

    void SceneMenu::update(double dt)
    {

    }

    void SceneMenu::draw()
    {
        // See that we moved scenes
        SDL_SetRenderDrawColor(ren, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(ren);
    }
};