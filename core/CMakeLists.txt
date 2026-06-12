if(SN_CORE_BUILD_SHARED)
    add_library(sncore SHARED)
    target_compile_definitions(sncore PRIVATE SN_EXPORT)
else()
    add_library(sncore STATIC)
    target_compile_definitions(sncore PUBLIC SN_CORE_STATIC)
endif()

target_include_directories(sncore PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(sncore PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(sncore PRIVATE sn_core_configs)

add_subdirectory(src)
