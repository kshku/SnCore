if(NOT TARGET sncore)
    add_library(sncore STATIC IMPORTED)
    set_target_properties(sncore PROPERTIES
        IMPORTED_LOCATION "${CMAKE_CURRENT_LIST_DIR}/../../lib/${CMAKE_STATIC_LIBRARY_PREFIX}sncore${CMAKE_STATIC_LIBRARY_SUFFIX}"
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/../../core/include"
    )
endif()
