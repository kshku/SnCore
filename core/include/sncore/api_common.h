#pragma once

#include "sncore/platform.h"

/* SN_EXPORT is set privately by whichever library is being built as a shared
   library. When it is not set we are either static or consuming somebody
   else's shared library, and that library's own api.h decides which. */
#if defined(SN_EXPORT)
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
