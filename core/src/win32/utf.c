#include "sncore/utf.h"

#if defined(SN_OS_WINDOWS)

    #include <windows.h>

size_t sn_utf8_to_utf16(const char *utf8, wchar_t *utf16, size_t utf16_count) {
    int needed = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, NULL, 0);
    if (needed <= 0) return (size_t)-1;

    if (utf16 && utf16_count > 0) {
        if ((size_t)needed > utf16_count) return (size_t)-1;
        int written = MultiByteToWideChar(CP_UTF8, 0, utf8, -1, utf16, (int)utf16_count);
        if (written <= 0) return (size_t)-1;
        return (size_t)(written - 1);
    }

    return (size_t)(needed - 1);
}

size_t sn_utf16_to_utf8(const wchar_t *utf16, char *utf8, size_t utf8_count) {
    int needed = WideCharToMultiByte(CP_UTF8, 0, utf16, -1, NULL, 0, NULL, NULL);
    if (needed <= 0) return (size_t)-1;

    if (utf8 && utf8_count > 0) {
        if ((size_t)needed > utf8_count) return (size_t)-1;
        int written = WideCharToMultiByte(CP_UTF8, 0, utf16, -1, utf8, (int)utf8_count, NULL, NULL);
        if (written <= 0) return (size_t)-1;
        return (size_t)(written - 1);
    }

    return (size_t)(needed - 1);
}

#endif
