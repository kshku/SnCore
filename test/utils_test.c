#include <sncore/utils.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SENTINEL 0xCC
#define BUF_SIZE 32

#define CHECK(x)                                                             \
    do {                                                                     \
        if (!(x)) {                                                          \
            fprintf(stderr, "FAILED: %s (%s:%d)\n", #x, __FILE__, __LINE__); \
            return 1;                                                        \
        }                                                                    \
    } while (0)

static size_t varint_length(uint64_t value) {
    size_t length = 1;
    while (value >= 0x80) {
        value >>= 7;
        length++;
    }
    return length;
}

static const uint64_t values[]
    = {0, 1, 2, 127, 128, 129, 255, 256, 16383, 16384, 16385, 2097151, 2097152, (uint64_t)1 << 32, (uint64_t)1 << 40, (uint64_t)1 << 55, UINT64_MAX};

static int test_forward_writes_forwards(void) {
    for (size_t i = 0; i < SN_ARRAY_LENGTH(values); ++i) {
        uint8_t buf[BUF_SIZE];
        memset(buf, SENTINEL, sizeof(buf));
        uint8_t *start = buf + BUF_SIZE / 2;

        sn_write_to_bytes(start, values[i], false);

        size_t length = varint_length(values[i]);

        // bytes run from start forwards, terminator last
        for (size_t k = 0; k < length; ++k) CHECK(start[k] != SENTINEL);
        CHECK(start[length] == SENTINEL);

        // nothing written before start
        for (size_t k = 0; k < BUF_SIZE / 2; ++k) CHECK(buf[k] == SENTINEL);
    }
    return 0;
}

static int test_reverse_writes_backwards(void) {
    for (size_t i = 0; i < SN_ARRAY_LENGTH(values); ++i) {
        uint8_t buf[BUF_SIZE];
        memset(buf, SENTINEL, sizeof(buf));
        uint8_t *start = buf + BUF_SIZE / 2;

        sn_write_to_bytes(start, values[i], true);

        size_t length = varint_length(values[i]);

        // first byte is still on start, the rest step back, terminator furthest
        for (size_t k = 0; k < length; ++k) CHECK(start[-(int)k] != SENTINEL);
        CHECK(start[-(int)length] == SENTINEL);

        // nothing written after the first byte
        for (size_t k = 1; k < BUF_SIZE - BUF_SIZE / 2; ++k) CHECK(start[k] == SENTINEL);
    }
    return 0;
}

static int test_round_trip_both_directions(void) {
    for (size_t i = 0; i < SN_ARRAY_LENGTH(values); ++i) {
        uint8_t buf[BUF_SIZE];
        memset(buf, SENTINEL, sizeof(buf));
        uint8_t *middle = buf + BUF_SIZE / 2;

        sn_write_to_bytes(middle, values[i], false);
        CHECK(sn_read_from_bytes(middle, false) == values[i]);

        sn_write_to_bytes(middle, values[i], true);
        CHECK(sn_read_from_bytes(middle, true) == values[i]);
    }
    return 0;
}

// A backwards varint has to be readable from the same address a forwards one
// is, which is what lets the byte before a pointer hold a value
static int test_directions_are_mirrored(void) {
    for (size_t i = 0; i < SN_ARRAY_LENGTH(values); ++i) {
        uint8_t forward[BUF_SIZE];
        uint8_t reverse[BUF_SIZE];
        memset(forward, SENTINEL, sizeof(forward));
        memset(reverse, SENTINEL, sizeof(reverse));

        sn_write_to_bytes(forward + BUF_SIZE / 2, values[i], false);
        sn_write_to_bytes(reverse + BUF_SIZE / 2, values[i], true);

        size_t length = varint_length(values[i]);
        for (size_t k = 0; k < length; ++k) {
            CHECK(forward[BUF_SIZE / 2 + k] == reverse[BUF_SIZE / 2 - k]);
        }
    }
    return 0;
}

int main(void) {
    struct {
        const char *name;
        int (*fn)(void);
    } tests[] = {
        {"forward_writes_forwards",    test_forward_writes_forwards   },
        {"reverse_writes_backwards",   test_reverse_writes_backwards  },
        {"round_trip_both_directions", test_round_trip_both_directions},
        {"directions_are_mirrored",    test_directions_are_mirrored   },
    };

    int failed = 0;
    for (size_t i = 0; i < SN_ARRAY_LENGTH(tests); ++i) {
        printf("  %s... ", tests[i].name);
        fflush(stdout);
        if (tests[i].fn() == 0) {
            printf("passed\n");
        } else {
            printf("FAILED\n");
            failed++;
        }
    }

    printf("%zu/%zu tests passed\n", SN_ARRAY_LENGTH(tests) - (size_t)failed, SN_ARRAY_LENGTH(tests));
    return failed == 0 ? 0 : 1;
}
