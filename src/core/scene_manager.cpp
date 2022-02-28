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

    void SceneManager::clear()
    {
        while(getStateCount() != 0)
            sceneQueue.pop_front();
    }

    int SceneManager::getStateCount()
    {
        return sceneQueue.size();
    }
};