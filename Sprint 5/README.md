# se-05-team-29

![Built with C++](https://img.shields.io/badge/Built%20with-C%2B%2B-blue)
[![GitHub release](https://img.shields.io/github/release/Naereen/StrapDown.js.svg)](https://GitHub.com/Naereen/StrapDown.js/releases/)
![Platforms](https://img.shields.io/badge/platform-linux--64%20%7C%20win--32%20%7C%20osx--64%20%7C%20win--64-lightgrey)

#   Beer Game 🍻

## Table of Contents

* [About the Project](#about-the-project)
    * [Built with](#built-with)
* [Screenshots](#screenshots)
* [Getting Started](#getting-started)
    * [Prerequisites](#prerequisites)
    * [Installation](#installation)
    * [Run the app](#run-the-app)
    * [Run the tests](#run-the-tests)
* [Current UI Guide](#current-ui-guide)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)
* [Credits](#credits)

## About the Project
The beer game is an online game intended for students to better understand how supply chain works in a real world situation, applying the theory learned in class and practicing decision making. Therefore it is a functional type of game. This project simulates the way beer is being ordered and delivered from production and factory, going to distributor, then wholesaler and then to retailer and consumer. Each of these stages can be played by the students who, order enough beer stock in the position they hold, taking into consideration shipment times, delays, backorders, inventory such that, every partner in this chain doesn’t suffer any losses.

### Built with
* [C++](http://www.cplusplus.com)
* [Qt Creator](https://www.qt.io/download)
* [CMake](https://cmake.org/cmake-tutorial)
* [Doxygen](http://www.doxygen.nl/manual/starting.html)
* [Google Test](https://github.com/janoszen/clion-project-stub/blob/master/gtests/googletest/docs/Primer.md)

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

## Getting started

What things you need to install the software and how to install them

### Prerequisites
* Qt5 SDK
```sh
brew install qt5
```
* GTest

Installion on Linux
```sh
sudo apt-get install libgtest-dev
```

Installation on Mac
```sh
brew install libgtest-dev
```

### Installation
Clone the repo
```sh
git clone https://github.com/iuliacornea99/se-05-team-29
```

### Run the app (server/instructor)
```sh
cd build
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix qt5)
make
./beergame
```
### Run the app (client/players)
```sh
cd build
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix qt5)
make
./beergame-players
```

### Run the tests
```sh
cd build
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix qt5)
make
./beergame-tests
```

You have to set your Qt location in CMakeLists if it doesn't work via set(CMAKE_PREFIX_PATH PATH_TO_QT)

and then the documentation can be found in the directory `doc`.
        
## Improvements in Sprint 5
- [x] Implemented Server-Client socket threads so that this game can be played on multiple machines by connecting to a local server
- [x] Added some missing testcases
- [x] Fixed Doxygen generation issues and added more documentation


