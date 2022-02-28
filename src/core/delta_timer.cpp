#include "delta_timer.hpp"

namespace Engine::Core
{
    DeltaTimer::DeltaTimer()
    {
        // Default values
        now = SDL_GetPerformanceCounter();
        last = 0;
        deltaTime = 0;
    };

    void DeltaTimer::update()
    {
        // Update last timer and current timer
        last = now;
        now = SDL_GetPerformanceCounter();

        // Calculate the delta timer based on the new values (in seconds)
        deltaTime = (now - last) * 1.0 / SDL_GetPerformanceFrequency();
    }

    double DeltaTimer::getDelta()
    {
        // Returns the time delay in seconds
        return deltaTime;
    }
}