#pragma once

#include "sncore/platform.h"

#include <stddef.h>

/**
 * @brief Convert UTF-8 to UTF-16 (snprintf-like API).
 *
 * Query mode: pass NULL for utf16 to get the required number of wchar_t (excluding null
 * terminator). Write mode: pass a buffer and its capacity in wchar_t.
 *
 * @param utf8       Null-terminated UTF-8 input string.
 * @param utf16      Output buffer, or NULL to query required size.
 * @param utf16_count Capacity of utf16 in wchar_t elements.
 *
 * @return On success: number of wchar_t written (excluding null terminator).
 *         On error: (size_t)-1.
 */
size_t sn_utf8_to_utf16(const char *utf8, wchar_t *utf16, size_t utf16_count);

/**
 * @brief Convert UTF-16 to UTF-8 (snprintf-like API).
 *
 * Query mode: pass NULL for utf8 to get the required number of chars (excluding null terminator).
 * Write mode: pass a buffer and its capacity in chars.
 *
 * @param utf16     Null-terminated UTF-16 input string.
 * @param utf8      Output buffer, or NULL to query required size.
 * @param utf8_count Capacity of utf8 in chars.
 *
 * @return On success: number of chars written (excluding null terminator).
 *         On error: (size_t)-1.
 */
size_t sn_utf16_to_utf8(const wchar_t *utf16, char *utf8, size_t utf8_count);
