/*
 * lua_export.hpp
 *
 * This file provides a structure for a Tolua++-like export interface
 * and a class registry for interfacing C++ with Lua.
 *
 * Author: Your Name (please replace)
 */

#ifndef LUA_EXPORT_HPP
#define LUA_EXPORT_HPP

#include <lua.hpp>
#include <string>
#include <map>

// Forward declaration of the class registry
class LuaRegistry;

class LuaExport {
public:
    // Method to register a class
    static void RegisterClass(const std::string& className);

    // Method to bind functions to a specific instance
    static void BindFunction(const std::string& className, const std::string& functionName, lua_CFunction func);

    // Method to create a Lua object from a C++ object
    static int CreateLuaObject(lua_State* L);

    // Method to retrieve a C++ object from a Lua object
    static void* GetCppObject(lua_State* L, int index);
};

class LuaRegistry {
public:
    // Method to add class to registry
    void AddClass(const std::string &className, LuaExport* exporter);

    // Method to find class exporter in registry
    LuaExport* FindExporter(const std::string &className);

private:
    std::map<std::string, LuaExport*> classMap;
};

#endif // LUA_EXPORT_HPP
