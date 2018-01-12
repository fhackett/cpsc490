# Fun note: without changing this file, CMake can also generate
# Visual Studio solution files, generating the appropriate
# Visual C++ compiler settings

# Ensure that older CMakes die before trying to run commands for
# newer versions
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

# Declares project name, version, language(s) used
project(returnzero VERSION 0.1 LANGUAGES CXX)

# Declares a library, doesn't specify static or shared
add_library(adder adder.cpp adder.hpp)
# Adds a property to the library describing which include
# directories to add.
# This corresponds to gcc -I<the_path>
# If you then write:
# #include <something>
# then in addition to standard paths it will look
# in <the_path>.
target_include_directories(adder PUBLIC
    # When building locally, include the source directory
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    # When installed it should be in e.g /usr/include
    $<INSTALL_INTERFACE:include>)

# Tells CMake that there is an executable called main which
# is build using main.cpp, guessing it should call the C++
# compiler based on the .cpp extension
add_executable(main main.cpp)
# Link the library adder to main.
# Corresponds to gcc -ladder
# which tells gcc to link adder.* to the executable
target_link_libraries(main adder)

add_executable(tests tests.cpp)
target_link_libraries(tests adder)

# Makes ctest work (tells it to generate the CTestTestfile.cmake)
enable_testing()
# Adds a test called "tests" that runs the executable "tests"
add_test(tests tests)

