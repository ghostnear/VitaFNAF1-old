#ifndef CORE_DELTA_TIMER_HPP
#define CORE_DELTA_TIMER_HPP

#include <SDL2/SDL.h>

namespace Engine::Core
{
    class DeltaTimer
    {
        uint64_t now, last;
        double deltaTime;

    public:
        // Constructor
        DeltaTimer();

        // Update the timer
        void update();

        // Get the delta time
        double getDelta();
    };
};

#endif