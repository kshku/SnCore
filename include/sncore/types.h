#pragma once

#include <stddef.h>
#include <stdint.h>

typedef void *(*SnMemoryAllocateFn)(size_t size, void *user_data);
typedef void *(*SnMemoryReallocateFn)(void *ptr, size_t new_size, void *user_data);
typedef void  (*SnMemoryFreeFn)(void *ptr, void *user_data);
typedef void  (*SnLockFn)(void *user_data);
typedef void  (*SnUnlockFn)(void *user_data);
typedef uint64_t (*SnTimeNowFn)(void *user_data);
typedef uint64_t (*SnThreadIdFn)(void *user_data);
