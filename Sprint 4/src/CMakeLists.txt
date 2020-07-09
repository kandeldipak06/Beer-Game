#
# /src/CMakeLists.txt --
#

cmake_minimum_required(VERSION 3.1.0)

include_directories(${PROJECT_BINARY_DIR}/src)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)

# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTORCC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)
qt5_add_resources(resource.qrc)

# Populate a CMake variable with the sources
set(BeerGame_SRCS
    game.cpp
    instructor.cpp
    main.cpp
    mainwindow.cpp
    order.cpp
    player.cpp
    playerEvent.cpp
    shipment.cpp
    mainwindow.ui 
    include/game.h 
    include/instructor.h 
    include/mainwindow.h 
    include/order.h 
    include/player.h 
    include/playerEvent.h 
    include/shipment.h 
    resource.qrc 
)

# Tell CMake to create the helloworld executable
add_executable(beergame ${BeerGame_SRCS})
set_target_properties(beergame PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# Use the Widgets module from Qt 5
target_link_libraries(beergame Qt5::Widgets)
