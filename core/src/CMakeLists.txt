set(HEADERFILES
    api_common.h
    defines.h
    platform.h
    types.h
    utf.h
)

set(SPECIFIC_SRCS
    utf.c
)

set(INCLUDE_BASE "${PROJECT_SOURCE_DIR}/core/include/sncore")

set(SUBDIRS
    win32
    nix
)

list(TRANSFORM HEADERFILES PREPEND "${INCLUDE_BASE}/")

target_sources(sncore PRIVATE ${HEADERFILES})

foreach(dir IN LISTS SUBDIRS)
    foreach(src IN LISTS SPECIFIC_SRCS)
        target_sources(sncore PRIVATE "${dir}/${src}")
    endforeach()
endforeach()
