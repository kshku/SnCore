set(HEADERFILES
    platform.h
    defines.h
    sntemplate.h
)

set(SRCS
    sntemplate.c
)

set(INCLUDE_BASE "${PROJECT_SOURCE_DIR}/template/include/sntemplate")

list(TRANSFORM HEADERFILES PREPEND "${INCLUDE_BASE}/")

target_sources(sntemplate PRIVATE ${HEADERFILES} ${SRCS})
