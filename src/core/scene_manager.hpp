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

        // Pop the front scene
        void pop();

        // Push the scene to the back of the queue
        void push(Scene* s, SDL_Renderer* ren);

        // Update the scenes
        void update(double dt);

        // Draw the scenes
        void draw();

        // Get state count
        int getStateCount();
    };
};

#endif