#pragma once

#include "sncore/defines.h"

SN_INLINE void sn_write_to_bytes(void *ptr, uint64_t value, bool reverse) {
    uint8_t *p = (uint8_t *)ptr;
    uint8_t inc = reverse ? -1 : 1;
    do {
        *p = value % 0x80;
        value >>= 7;
        if (!value) return;
        *p |= 0x80;
        p += inc;
    } while (value);
}

SN_INLINE uint64_t sn_read_from_bytes(void *ptr, bool reverse) {
    uint8_t *p = (uint8_t *)ptr;
    uint8_t inc = reverse ? -1 : 1;
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
