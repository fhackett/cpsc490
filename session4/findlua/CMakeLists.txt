cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

project(hellolua VERSION 0.1 LANGUAGES CXX)

add_executable(hellolua main.cpp)

find_package(Lua)

if(${LUA_FOUND})
    add_library(Lua INTERFACE)
    target_include_directories(Lua INTERFACE ${LUA_INCLUDE_DIR})
    target_link_libraries(Lua INTERFACE ${LUA_LIBRARIES})

    # enable the feature
    target_link_libraries(hellolua Lua)
    target_compile_definitions(hellolua
        PRIVATE HAVE_LUA=1
    )
endif()

