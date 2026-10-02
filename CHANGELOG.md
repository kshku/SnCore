# Changelog

## [0.3.2] - 2026-10-02

### Changed
- -Wconversion and -Wsign-conversion are on for gcc and clang. The code was
  already clean of both

## [0.3.1] - 2026-09-28

### Fixed
- Fix the step used by sn_write_to_bytes and sn_read_from_bytes when writing
  backwards. As an uint8_t, -1 is 255, so the pointer walked 255 bytes forwards
  instead of one byte backwards. Values that need more than one byte were
  written out of bounds and read back wrong
- Fix the export macros in api_common.h, which branched on SN_STATIC, a macro no
  library defines. Static builds on Windows were getting __declspec(dllimport) on
  their own symbols
- Export sn_utf8_to_utf16 and sn_utf16_to_utf8, which were declared with no
  export macro at all, so a shared build could not be linked against

### Added
- Add sncore/api.h, the SN_CORE_API macro, matching the api.h every other Sn*
  library has
- List utils.h in the header sources, it was the one public header CMake did
  not know about
- Build the tests against a shared library in CI, which is what catches a
  symbol that is missing an export macro

## [0.3.0] - 2026-09-28

### Removed
- Remove sn_std_allocator, which now lives in SnMemory. SnCore keeps the
  SnMemoryAllocator type and the callback typedefs, so the vtable contract
  stays where every Sn* library already includes it.

## [0.2.0] - 2026-06-12

### Added
- Add SnMemoryAllocator type
- Add sn_std_allocator which uses standard library allocator functions (malloc family functions)
- Reorder the parameters of the allocator functions
- Add sn_read_from_bytes and sn_write_to_bytes functions

## [0.1.0] - 2026-06-11

- First release. See [0.0.0] section in CHANGELOG.md for full changelog.

## [0.0.0] - 2025-12-21

### Added
- Platform detection macros (compiler, OS, architecture)
- `SN_API` export/import helpers for shared/static builds
- UTF-8 to UTF-16 and UTF-16 to UTF-8 conversion
- `SN_DEBUG` / `SN_ASSERT` debug assertion support
- `.clang-format` CI enforcement
