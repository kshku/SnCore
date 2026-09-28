#pragma once

#include <stddef.h>
#include <stdint.h>

typedef void *(*SnMemoryAllocateFn)(void *data, uint64_t size, uint64_t align);
typedef void *(*SnMemoryReallocateFn)(void *data, void *ptr, uint64_t new_size, uint64_t align);
typedef void (*SnMemoryFreeFn)(void *data, void *ptr);

typedef struct SnMemoryAllocator {
    SnMemoryAllocateFn alloc;
    SnMemoryReallocateFn realloc;
    SnMemoryFreeFn free;
    void *data;
} SnMemoryAllocator;

typedef void (*SnLockFn)(void *data);
typedef void (*SnUnlockFn)(void *data);

typedef uint64_t (*SnTimeNowFn)(void *data);
typedef uint64_t (*SnThreadIdFn)(void *data);
