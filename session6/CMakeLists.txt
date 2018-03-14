cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(async_test VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost REQUIRED COMPONENTS thread)
find_package(Threads REQUIRED)

add_executable(future future.cpp)
target_link_libraries(future Boost::thread)

add_executable(basic basic.cpp)
target_link_libraries(basic ${CMAKE_THREAD_LIBS_INIT})

