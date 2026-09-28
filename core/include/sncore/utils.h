#pragma once

#include "sncore/defines.h"

/**
 * @brief Write a value as a variable length integer, terminator last.
 *
 * The first byte is always written at ptr, and every following byte steps away
 * from it, so the terminator, the only byte without the high bit set, ends up
 * farthest from ptr.
 *
 * @param ptr     Where to write the first byte.
 * @param value   The value to encode.
 * @param reverse true to step backwards, false to step forwards.
 *
 * @note The caller has to leave room for the encoded length in that direction,
 *       and has to read the value back with the same reverse.
 */
SN_INLINE void sn_write_to_bytes(void *ptr, uint64_t value, bool reverse) {
    uint8_t *p = (uint8_t *)ptr;
    int8_t inc = reverse ? -1 : 1;
    do {
        *p = value % 0x80;
        value >>= 7;
        if (!value) return;
        *p |= 0x80;
        p += inc;
    } while (value);
}

/**
 * @brief Read a variable length integer written by sn_write_to_bytes.
 *
 * Reads at ptr, then steps in the same direction the value was written in,
 * until it reaches the terminator.
 *
 * @param ptr     The ptr that was passed to sn_write_to_bytes.
 * @param reverse Has to match the reverse the value was written with.
 *
 * @return The decoded value.
 */
SN_INLINE uint64_t sn_read_from_bytes(void *ptr, bool reverse) {
    uint8_t *p = (uint8_t *)ptr;
    int8_t inc = reverse ? -1 : 1;
    uint64_t value = 0;
    uint64_t i = 0;

    while (*p & 0x80) {
        value |= (uint64_t)(*p & ~0x80) << i;
        i += 7;
        p += inc;
    }

    value |= (uint64_t)(*p) << i;

    return value;
}
