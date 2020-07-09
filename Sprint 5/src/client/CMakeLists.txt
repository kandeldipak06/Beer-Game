cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(beer-game)

find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Network Charts)

set (CMAKE_BINARY_DIR ../../)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})


add_executable(beergame-players
    main.cpp
    clientinterface.cpp
    clientinterface.h
    ClientInterface.ui
    playerclient.cpp
    playerclient.h
    #showgraph.cpp
    #showgraph.h
    #showgraph.ui
)

target_link_libraries(beergame-players PRIVATE Qt5::Widgets Qt5::Network Qt5::Core Qt5::Gui Qt5::Charts)

