cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(returnzero VERSION 0.1 LANGUAGES CXX)

add_library(adder adder.cpp adder.hpp)
target_include_directories(adder PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

add_executable(main main.cpp)
target_link_libraries(main adder)

