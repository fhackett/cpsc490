cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(hw2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_library(plugin1 SHARED plugin1.cpp)
add_library(plugin2 SHARED plugin2.cpp)
add_library(plugin3 SHARED plugin3.cpp)
add_library(plugin4 SHARED plugin4.cpp)
add_library(plugin5 SHARED plugin5.cpp)
# add_library(plugin6 SHARED plugin6.cpp)
# add_library(plugin7 SHARED plugin7.cpp)

add_library(plugin_files INTERFACE)
target_compile_definitions(plugin_files
    INTERFACE PLUGIN1_FILE="$<TARGET_FILE:plugin1>"
    INTERFACE PLUGIN2_FILE="$<TARGET_FILE:plugin2>"
    INTERFACE PLUGIN3_FILE="$<TARGET_FILE:plugin3>"
    INTERFACE PLUGIN4_FILE="$<TARGET_FILE:plugin4>"
    INTERFACE PLUGIN5_FILE="$<TARGET_FILE:plugin5>"
    # INTERFACE PLUGIN6_FILE="$<TARGET_FILE:plugin6>"
    # INTERFACE PLUGIN7_FILE="$<TARGET_FILE:plugin7>"
    )

add_executable(test1 test1.cpp)
target_link_libraries(test1 ${CMAKE_DL_LIBS} plugin_files)

add_executable(test2 test2.cpp)
target_link_libraries(test2 ${CMAKE_DL_LIBS} plugin_files)

add_executable(test3 test3.cpp)
target_link_libraries(test3 ${CMAKE_DL_LIBS} plugin_files)

add_executable(test4 test4.cpp)
target_link_libraries(test4 ${CMAKE_DL_LIBS} plugin_files)

add_executable(test5 test5.cpp)
target_link_libraries(test5 ${CMAKE_DL_LIBS} plugin_files)

add_executable(test6 test6.cpp)
target_link_libraries(test6 ${CMAKE_DL_LIBS} plugin_files)

# add_executable(test7 test7.cpp)
# target_link_libraries(test7 ${CMAKE_DL_LIBS} plugin_files)

# add_executable(test8 test8.cpp)
# target_link_libraries(test8 ${CMAKE_DL_LIBS} plugin_files)

enable_testing()

add_test(test1 test1)
add_test(test2 test2)
add_test(test3 test3)
add_test(test4 test4)
add_test(test5 test5)
add_test(test6 test6)
# add_test(test7 test7)
# add_test(test8 test8)

