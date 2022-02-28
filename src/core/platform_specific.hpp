#ifndef CORE_PLATFORM_SPECIFIC_HPP
#define CORE_PLATFORM_SPECIFIC_HPP

#include <cstdlib>

// Include PSVita stubs
#ifdef ENV_VITA
	#include <psp2/kernel/processmgr.h>
#endif

/// THIS FILE CONTAINS WRAPPERS FOR DIFFERENT FUNCTIONS DEPENDING ON THE BUILD PLATFORM
namespace Engine::Core
{
    // Close the app
    void exit_process(int32_t value);
};

#endif