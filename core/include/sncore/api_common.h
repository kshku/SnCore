#pragma once

#include "sncore/platform.h"

#if defined(SN_STATIC)
    #define SN_API_HELPER_EXPORT
    #define SN_API_HELPER_IMPORT
#elif defined(SN_EXPORT)
    #if defined(SN_OS_WINDOWS)
        #define SN_API_HELPER_EXPORT __declspec(dllexport)
    #else
        #define SN_API_HELPER_EXPORT __attribute__((visibility("default")))
    #endif
    #define SN_API_HELPER_IMPORT
#else
    #if defined(SN_OS_WINDOWS)
        #define SN_API_HELPER_IMPORT __declspec(dllimport)
    #else
        #define SN_API_HELPER_IMPORT
    #endif
    #define SN_API_HELPER_EXPORT
#endif
