#include "scene_manager.hpp"

namespace Engine::Game
{
    void SceneManager::push(Scene* s)
    {
        // Push the scene
        sceneQueue.push_back(s);
    }

    void SceneManager::draw(SDL_Renderer* ren)
    {
        // Go trough all the scenes and do the drawing for all of them
        for(auto x : sceneQueue)
        {
            x -> draw(ren);
        }
    }
};