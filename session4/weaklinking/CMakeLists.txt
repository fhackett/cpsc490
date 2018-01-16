cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(weaklinking VERSION 0.1 LANGUAGES CXX)

add_library(common1 SHARED common1.cpp common.hpp)
add_library(common2 SHARED common2.cpp common.hpp)

# link against new lib
add_executable(main1 main.cpp)
target_link_libraries(main1 common1)

# link against old lib, same code still works
add_executable(main2 main.cpp)
target_link_libraries(main2 common2)

