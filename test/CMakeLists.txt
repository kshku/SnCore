set(SRCS
    test.c
)

add_executable(sn_template_test)
target_sources(sn_template_test PRIVATE ${SRCS})
target_link_libraries(sn_template_test PRIVATE sntemplate)

if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND SN_TEMPLATE_BUILD_SHARED)
    add_custom_target(copy_dlls ALL
        COMMENT "Copy the dlls"
        COMMAND ${CMAKE_COMMAND} -E copy_if_different "$<TARGET_RUNTIME_DLLS:sn_template_test>" "$<TARGET_FILE_DIR:sn_template_test>"
        COMMAND_EXPAND_LISTS
    )

    add_dependencies(copy_dlls sn_template_test)
endif()

