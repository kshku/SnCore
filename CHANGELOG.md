# Changelog

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
