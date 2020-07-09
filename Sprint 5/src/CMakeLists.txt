cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(beer-game)

set (CMAKE_BINARY_DIR ../)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(client)
add_subdirectory(server)


