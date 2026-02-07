// cpp-lua-binding-framework: This is the implementation file.

#include <lua.hpp>
#include <iostream>

class HelloWorld {
public:
    void greet() {
        std::cout << "Hello, World!" << std::endl;
    }
};

extern "C" int luaopen_helloworld(lua_State* L) {
    // Set up in Lua
    lua_newtable(L);
    lua_pushcfunction(L, [](lua_State* L) -> int {
        HelloWorld hw;
        hw.greet();
        return 0;
    });
    lua_setfield(L, -2, "greet");
    return 1;
}
