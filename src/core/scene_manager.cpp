#include "scene_manager.hpp"

namespace Engine::Game
{
    void SceneManager::push(Scene* s)
    {
        // Push the scene
        sceneQueue.push(s);
    }
};