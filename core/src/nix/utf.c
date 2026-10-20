#include "sncore/utf.h"

#include "sncore/defines.h"

#if !defined(SN_OS_WINDOWS)

    #include <stddef.h>

size_t sn_utf8_to_utf16(const char *utf8, wchar_t *utf16, size_t utf16_count) {
    SN_UNUSED(utf8);
    SN_UNUSED(utf16);
    SN_UNUSED(utf16_count);
    return (size_t)-1;
}

size_t sn_utf16_to_utf8(const wchar_t *utf16, char *utf8, size_t utf8_count) {
    SN_UNUSED(utf16);
    SN_UNUSED(utf8);
    SN_UNUSED(utf8_count);
    return (size_t)-1;
}

#endif
