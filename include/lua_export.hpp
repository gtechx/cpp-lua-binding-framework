#ifndef LUA_EXPORT_HPP
#define LUA_EXPORT_HPP

#include <lua.hpp>
#include <string>
#include <typeinfo>
#include <unordered_map>

class LuaBinder {
public:
    LuaBinder(lua_State* L) : L(L) {}

    template<typename T>
    void bindClass(const std::string& className) {
        // Register class to Lua
        // Implement the class registration logic here
    }

    template<typename T, typename... Args>
    void bindMethod(const std::string& methodName, T(*func)(Args...)) {
        // Bind method to Lua
        // Implement method binding logic here
    }

    // Function to track Lua subclasses
    void trackSubclass(const std::string& baseClass, const std::string& subClass) {
        // Implement logic to track Lua subclasses
    }

private:
    lua_State* L; // Lua state
};

#endif // LUA_EXPORT_HPP
