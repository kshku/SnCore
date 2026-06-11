#include "sncore/utf.h"

#if !defined(SN_OS_WINDOWS)

    #include <stddef.h>

size_t sn_utf8_to_utf16(const char *utf8, wchar_t *utf16, size_t utf16_count) {
    (void)utf8;
    (void)utf16;
    (void)utf16_count;
    return (size_t)-1;
}

size_t sn_utf16_to_utf8(const wchar_t *utf16, char *utf8, size_t utf8_count) {
    (void)utf16;
    (void)utf8;
    (void)utf8_count;
    return (size_t)-1;
}

#endif
