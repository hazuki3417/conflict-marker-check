cmake_minimum_required(VERSION 3.14.4)
project(conflict-marker-check 
    VERSION 1.0.0
    DESCRIPTION "git conflict marker check command"
    LANGUAGES CXX)

file(GLOB MAIN_SOURCE main.cpp)
file(GLOB LIB_SOURCE classes/*.cpp)

include_directories(classes)

# build
add_executable(main ${MAIN_SOURCE} ${LIB_SOURCE})
