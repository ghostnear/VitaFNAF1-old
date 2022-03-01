#ifndef CORE_SCENEMANAGER_HPP
#define CORE_SCENEMANAGER_HPP

#include <deque>
#include "../rendering/sdl_window.hpp"

namespace Engine::Game
{
    class SDLWindow;

    class SceneManager
    {
        SDLWindow* win;
        std::deque<Scene*> sceneQueue;

    public:
        // Constructor
        SceneManager(SDLWindow* assWin);

        // Gets the window
        SDLWindow* getWindow();

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