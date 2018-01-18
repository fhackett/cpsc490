#ifdef HAVE_LUA

// necessary or you get mystifying linker errors
// requires C++ to link any functions declared here using
// C-style linking (aka. don't mangle the function names)
extern "C"{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int main(){
    lua_State* ls = luaL_newstate();
    luaL_openlibs(ls);
    return luaL_dostring(ls, "print(\"Hello World from Lua!\")");
}

#else

#include <iostream>

int main(){
    std::cout << "No Lua, never mind. Hello World anyway!\n";
    return 0;
}

#endif

