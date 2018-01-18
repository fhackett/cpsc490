cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(hellolua VERSION 0.1 LANGUAGES CXX)

# create an executable target called "hellolua"
add_executable(hellolua main.cpp)

# attempt to _somehow_ find lua - calls FindLua.cmake
# if Lua is found, defined LUA_FOUND (see the documentation
# for details)
find_package(Lua)

# this is what an if statement looks like
if(${LUA_FOUND})
    # these lines map from old-style CMake variables (LUA_LIBRARIES and such)
    # to the newer (and better) INTERFACE library concept
    # Adds a library of type INTERFACE - it doesn't compile anything, but can be
    # linked to other targets.
    add_library(Lua INTERFACE)
    # Add the directories in LUA_INCLUDE_DIR to the target's interface include
    # directories. INTERFACE means the directory is given to the targets Lua is
    # linked _to_, not Lua itself (which as above doesn't actually do anything).
    target_include_directories(Lua INTERFACE ${LUA_INCLUDE_DIR})
    # Same but with libraries, effectively says "to link to Lua you have to link
    # LUA_LIBRARIES".
    target_link_libraries(Lua INTERFACE ${LUA_LIBRARIES})

    # enable the feature (if lua is present on the system, link it in)
    target_link_libraries(hellolua Lua)
    # Let the source code know lua is present by passing a preprocessor definition.
    # You can check for these with #ifdef.
    target_compile_definitions(hellolua
        PRIVATE HAVE_LUA=1
    )
endif()

