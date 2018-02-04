cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(hw3 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(tests_main tests_main.cpp)

add_executable(tests_sum tests_sum.cpp)
target_link_libraries(tests_sum tests_main)

add_executable(tests_product tests_product.cpp)
target_link_libraries(tests_product tests_main)

add_executable(tests_pipe tests_pipe.cpp)
target_link_libraries(tests_pipe tests_main)

enable_testing()

add_test(tests_sum tests_sum)
add_test(tests_product tests_product)
add_test(tests_pipe tests_pipe)

