cmake_minimum_required(VERSION 3.20)
project(RentACar)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SFML_INCLUDE_DIR "/home/rewieer/Libraries/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib")
set(SFML_DIR "/home/rewieer/Libraries/SFML-2.5.1/lib/cmake/SFML")


link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)
include_directories(Backtracking)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

if(SFML_FOUND)
    message(STATUS "SFML_INCLUDE_DIR: ${SFML_INCLUDE_DIR}")
    message(STATUS "SFML_LIBRARIES: ${SFML_LIBRARIES}")
    message(STATUS "SFML_VERSION: ${SFML_VERSION}")
endif()

add_executable(RentACar GUI/main.cpp GUI/RCWindow.cpp GUI/RCWindow.h Backtracking/NodeLogistic.cpp Backtracking/NodeLogistic.h Backtracking/Graph.cpp Backtracking/Graph.h GUI/NodeGUI.cpp GUI/NodeGUI.h GUI/ConnectionsGUI.cpp GUI/ConnectionsGUI.h)
target_link_libraries (RentACar sfml-graphics sfml-window sfml-system sfml-network)
