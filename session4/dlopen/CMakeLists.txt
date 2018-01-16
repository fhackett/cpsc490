cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(dlopen VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(plugin1 SHARED plugin1.cpp)
add_library(plugin2 SHARED plugin2.cpp)

add_executable(main main.cpp plugin_api.hpp)
target_link_libraries(main ${CMAKE_DL_LIBS})

