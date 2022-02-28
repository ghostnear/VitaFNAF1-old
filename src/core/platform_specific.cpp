#include "platform_specific.hpp"

namespace Engine::Core
{
    void exit_process(int32_t value)
    {
	#ifdef ENV_VITA
		sceKernelExitProcess(value);
	#else
        exit(0);
    #endif
    }
};