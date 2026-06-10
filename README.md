# SnCore

Core foundation for Sn* projects. Header-only C17 library providing platform detection,
utility macros, API export/import helpers, and shared callback type definitions.

## Contents

- **platform.h** — Compiler, OS, architecture, and endian detection
- **defines.h** — Utility macros (inline, assert, min/max, bit flags, alignment, stringify, byte arrays)
- **api_common.h** — Shared `SN_API_HELPER_EXPORT` / `SN_API_HELPER_IMPORT` macros
- **types.h** — Common callback type definitions (`SnMemoryAllocateFn`, `SnLockFn`, `SnTimeNowFn`, etc.)

## Usage

```c
#include <sncore/platform.h>
#include <sncore/defines.h>
#include <stdio.h>

int main(void) {
#if defined(SN_OS_LINUX)
    printf("Running on Linux\n");
#elif defined(SN_OS_WINDOWS)
    printf("Running on Windows\n");
#endif

    // Alignment helper
    uint64_t unaligned = 0x1003;
    uint64_t aligned = SN_GET_ALIGNED(unaligned, 8);
    printf("Aligned: %llu\n", (unsigned long long)aligned);  // 0x1008

    return 0;
}
```

## Adding to your project

```cmake
include(FetchContent)
FetchContent_Declare(sncore
    GIT_REPOSITORY https://github.com/kshku/SnCore.git
    GIT_TAG main
)
FetchContent_MakeAvailable(sncore)

target_link_libraries(myapp PRIVATE sncore)
```

## Dependencies

- None. SnCore is a header-only interface library with no external dependencies.
