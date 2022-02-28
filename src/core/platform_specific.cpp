#include "platform_specific.hpp"

namespace Engine::Core
{
    void exit_process(int value)
    {
	#ifdef ENV_VITA
		sceKernelExitProcess(value);
	#else
        exit(0);
    #endif
    }
};