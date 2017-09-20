#pragma once

extern "C"
{
#include "lua.h"    
#include "lualib.h"    
#include "lauxlib.h"    
#include "luaconf.h"    
}
#include "tolua++.h"

class LuaEngine
{
private:
	static LuaEngine* m_pSingleton;

	lua_State* m_pLua_State;
private:
	LuaEngine();
	~LuaEngine();

public:
	static LuaEngine* GetSingleton();

	void DoFile(const char* varFilePath);

	void CallLuaFunction(const char* varLuaFunctionName, const char* varTypeName, void* varTypeData);

private:
	void PrintError();
};

