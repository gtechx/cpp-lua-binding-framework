// lua_export.hpp

#ifndef LUA_EXPORT_HPP
#define LUA_EXPORT_HPP

#include <lua.hpp>
#include <string>

// Macro for binding C++ class to Lua
#define LUA_BIND_CLASS(ClassName) \
    static const char* s_className = #ClassName; \
    luaL_newmetatable(L, s_className); \
    lua_pushstring(L, "__index"); \
    lua_pushvalue(L, -2); \
    lua_settable(L, -3); \
    luaL_setfuncs(L, &ClassName::lua_methods, 0); // Register methods

// Template to register methods in Lua
template <typename T>
struct LuaBinding {
    static int lua_create(lua_State* L) {
        T* obj = new T();
        *(T**)lua_newuserdata(L, sizeof(T*)) = obj;
        luaL_getmetatable(L, #T);
        lua_setmetatable(L, -2);
        return 1;
    }

    static int lua_destroy(lua_State* L) {
        T* obj = *(T**)luaL_checkudata(L, 1, #T);
        delete obj;
        return 0;
    }
};

#endif // LUA_EXPORT_HPP
