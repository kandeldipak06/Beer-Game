cmake_minimum_required(VERSION 3.5)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set (CMAKE_BINARY_DIR ../)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# add_executable(tests tests.cpp)
add_executable(beergame-tests
    ${COMMON_SOURCE_FILES}
    tests_game_logics.cpp
    tests.cpp
)

target_link_libraries(beergame-tests PRIVATE Qt5::Widgets Qt5::Network ${GTEST_LIBRARIES} pthread)
