# SnCore

Core foundation for Sn* projects. Header-only C17 library providing platform detection,
utility macros, API export/import helpers, and shared callback type definitions.

## Contents

- **platform.h** — Compiler, OS, architecture, and endian detection
- **defines.h** — Utility macros (inline, assert, min/max, bit flags, alignment, stringify, byte arrays)
- **api_common.h** — Shared SN_API_HELPER_EXPORT / SN_API_HELPER_IMPORT macros
- **types.h** — Common callback type definitions (SnMemoryAllocateFn, SnLockFn, SnTimeNowFn, etc.)

## Usage

```cmake
# Via FetchContent
FetchContent_Declare(sncore GIT_REPOSITORY https://github.com/kshku/SnCore.git GIT_TAG main)
FetchContent_MakeAvailable(sncore)

target_link_libraries(myapp PRIVATE sncore)
```
