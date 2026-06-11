cmake_minimum_required(VERSION 3.15...3.31)

project(SnCore VERSION 0.1.0 DESCRIPTION "Core foundation for Sn* projects" LANGUAGES C)

set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 17)

option(SN_CORE_BUILD_SHARED "Build shared library" OFF)
option(SN_CORE_BUILD_TEST "Build tests" OFF)

if(SN_CORE_BUILD_SHARED)
    add_library(sncore SHARED)
    target_compile_definitions(sncore PRIVATE SN_EXPORT)
else()
    add_library(sncore STATIC)
    target_compile_definitions(sncore PUBLIC SN_CORE_STATIC)
endif()

add_subdirectory(core/src)

target_include_directories(sncore PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/core/include>"
    "$<INSTALL_INTERFACE:include>"
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(sncore PUBLIC SN_DEBUG)
endif()

set(gcc_clang_comp "$<COMPILE_LANG_AND_ID:C,Clang,GNU>")

target_compile_options(sncore PRIVATE "$<${gcc_clang_comp}:-Wall;-Wextra;-Wformat;-Wuninitialized;-Wpedantic>")
target_compile_options(sncore PRIVATE "$<${gcc_clang_comp}:-fvisibility=hidden>")

add_subdirectory(docs)

if(SN_CORE_BUILD_TEST)
    add_subdirectory("test")
else()
    message(STATUS "Building test is disabled")
endif()

# Install
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS sncore
    EXPORT SnCoreTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY core/include/sncore DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

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

install(EXPORT SnCoreTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/sncore
)
