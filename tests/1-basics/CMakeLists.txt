add_executable(01-basics-tests)
target_sources(01-basics-tests
    PRIVATE 
    1_5.cpp
    1_6.cpp
    1_7.cpp
    1_8.cpp
    1_9.cpp
    1_12.cpp
    1_13.cpp
    1_14.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_05.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_06.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_07.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_08.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_09.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_12.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_13.c
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics/ex1_14.c
)

target_include_directories(01-basics-tests
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/../../exercises/1-basics
)

target_link_libraries(01-basics-tests PRIVATE gtest_main gtest)
gtest_discover_tests(01-basics-tests)