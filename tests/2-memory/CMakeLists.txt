add_executable(02-memory-tests)
target_sources(02-memory-tests
    PRIVATE 
    2_1.cpp
    2_2.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/2-memory/ex2_1.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/2-memory/ex2_2.c
)

target_include_directories(02-memory-tests
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/2-memory
)

target_link_libraries(02-memory-tests PRIVATE gtest_main gtest)
gtest_discover_tests(02-memory-tests)