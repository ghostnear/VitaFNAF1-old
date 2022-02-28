#include "scene_manager.hpp"

namespace Engine::Game
{
    void SceneManager::push(Scene* s, SDL_Renderer* ren)
    {
        // Push the scene
        sceneQueue.push_back(s);
        s -> onLoad(ren);
    }

    void SceneManager::update(double dt)
    {
        // Go trough all the scenes and update them
        for(auto x : sceneQueue)
            x -> update(dt);
    }

    void SceneManager::draw(SDL_Renderer* ren)
    {
        // Go trough all the scenes and do the drawing for all of them
        for(auto x : sceneQueue)
            x -> draw(ren);
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