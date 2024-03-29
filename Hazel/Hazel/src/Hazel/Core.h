#pragma once

#ifdef HZ_PLATFORM_WINDOWS
    #ifdef HZ_BUILD_DLL
        #define HAZEL_API __declspec(dllexport)
    #else
        #define HAZEL_API __declspec(dllimport)
    #endif
#else
    #error Hazel only supports Windows!
#endif // HZ_PLATRFORM_WINDOWS

#ifdef HZ_DEBUG
    #define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
    #define HZ_ASSERT(x, ...) do{ if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }while(0)
    #define HZ_CORE_ASSERT(x, ...) do{ if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }while(0)
#else
    #define HZ_ASSERT(x, ...)
    #define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)