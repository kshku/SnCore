cmake_minimum_required(VERSION 3.15...3.31)

project(SnCore VERSION 0.0.0 DESCRIPTION "Core foundation for Sn* projects" LANGUAGES C)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

add_library(sncore INTERFACE)

target_include_directories(sncore INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(sncore INTERFACE SN_DEBUG)
endif()

set(gcc_clang_comp "$<COMPILE_LANG_AND_ID:C,Clang,GNU>")

target_compile_options(sncore INTERFACE "$<${gcc_clang_comp}:-Wall;-Wextra;-Wformat;-Wuninitialized;-Wpedantic>")
target_compile_options(sncore INTERFACE "$<${gcc_clang_comp}:-fvisibility=hidden>")

# Install
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(DIRECTORY include/sncore DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/SnCoreConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/SnCoreConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/SnCoreConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sncore
)
