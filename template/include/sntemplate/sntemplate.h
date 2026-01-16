#pragma once

#include "sntemplate/defines.h"

#if defined(SN_TEMPLATE_STATIC)
    #define SN_API
#else
    #ifdef SN_EXPORT
        #if defined(SN_OS_LINUX) || defined(SN_OS_MAC)
            #define SN_API __attribute__((visibility("default")))
        #elif defined(SN_OS_WINDOWS)
            #define SN_API __declspec(dllexport)
        #else
            #error "Should not reach here!"
        #endif
    #else
        #if defined(SN_OS_LINUX) || defined(SN_OS_MAC)
            #define SN_API
        #elif defined(SN_OS_WINDOWS)
            #define SN_API __declspec(dllimport)
        #else
            #error "Should not reach here!"
        #endif
    #endif
#endif

SN_API void print_from_template();

#undef SN_API
