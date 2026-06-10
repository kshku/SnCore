if(NOT TARGET sncore)
    add_library(sncore INTERFACE IMPORTED)
    set_target_properties(sncore PROPERTIES
        INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_LIST_DIR}/../../include"
    )
endif()
