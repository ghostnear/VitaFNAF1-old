#ifndef CORE_SCENEMANAGER_HPP
#define CORE_SCENEMANAGER_HPP

#include <queue>

namespace Engine::Game
{
    class SceneManager
    {
        std::queue<Scene*> sceneQueue;

    public:
        // Push the scene to the back of the queue
        void push(Scene* s);
    };
};

#endif