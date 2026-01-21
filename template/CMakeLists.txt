if(SN_TEMPLATE_BUILD_SHARED)
    add_library(sntemplate SHARED)
    target_compile_definitions(sntemplate PRIVATE SN_EXPORT)
else()
    add_library(sntemplate STATIC)
    target_compile_definitions(sntemplate PUBLIC SN_TEMPLATE_STATIC)
endif()

target_include_directories(sntemplate PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(sntemplate PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(sntemplate PRIVATE sn_template_configs)

add_subdirectory(src)
