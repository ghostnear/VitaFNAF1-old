#include "scene_manager.hpp"

namespace Engine::Game
{
    SceneManager::SceneManager(SDLWindow* assWin)
    {
        win = assWin;
    }

    SDLWindow* SceneManager::getWindow()
    {
        return win;
    }

    void SceneManager::push(Scene* s, SDL_Renderer* ren)
    {
        // Push the scene
        s -> parent = this;
        sceneQueue.push_back(s);
        s -> onLoad(ren);
    }

    void SceneManager::pop()
    {
        Scene* s = sceneQueue.front();

        // Delete it do something

        sceneQueue.pop_front();
    }

    void SceneManager::update(double dt)
    {
        // Go trough all the scenes and update them
        for(auto x : sceneQueue)
            x -> update(dt);
    }

    void SceneManager::draw()
    {
        // Go trough all the scenes and do the drawing for all of them
        for(auto x : sceneQueue)
            x -> draw();
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