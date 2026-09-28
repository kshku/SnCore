#pragma once

#include <sncore/api_common.h>

#if defined(SN_CORE_STATIC)
    #define SN_CORE_API
#elif defined(SN_EXPORT)
    #define SN_CORE_API SN_API_HELPER_EXPORT
#else
    #define SN_CORE_API SN_API_HELPER_IMPORT
#endif
