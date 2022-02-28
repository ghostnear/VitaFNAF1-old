#ifndef CORE_SCENEMANAGER_HPP
#define CORE_SCENEMANAGER_HPP

#include <deque>
#include "../rendering/rendering.hpp"

namespace Engine::Game
{
    class SceneManager
    {
        std::deque<Scene*> sceneQueue;

    public:
        // Clear the scene queue
        void clear();

        // Push the scene to the back of the queue
        void push(Scene* s, SDL_Renderer* ren);

        // Draw the scenes
        void draw(SDL_Renderer* ren);

        // Get state count
        int getStateCount();
    };
};

#endif