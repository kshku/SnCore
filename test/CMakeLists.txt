enable_testing()

add_executable(sn_core_test test.c)
target_link_libraries(sn_core_test PRIVATE sncore)

add_test(NAME sn_core_test COMMAND sn_core_test)
