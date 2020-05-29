cmake_minimum_required(VERSION 3.16)
project(SDLBasic)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_CXX_STANDARD 11)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(SDLBasic main.cpp Screen.cpp Screen.h)
target_link_libraries(SDLBasic ${SDL2_LIBRARY} -lSDL2)