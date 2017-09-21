#include "LuaEngine.h"

#include<iostream>
#include<sstream>

extern int  tolua_BinaryPacker_open(lua_State* tolua_S);
extern int  tolua_NetworkClient_open(lua_State* tolua_S);


LuaEngine* LuaEngine::m_pSingleton = nullptr;

LuaEngine::LuaEngine()
{
	m_pLua_State = luaL_newstate();
	luaL_openlibs(m_pLua_State);

	tolua_BinaryPacker_open(m_pLua_State);
	tolua_NetworkClient_open(m_pLua_State);
}


LuaEngine::~LuaEngine()
{
	lua_close(m_pLua_State);
}

LuaEngine * LuaEngine::GetSingleton()
{
	if (m_pSingleton == nullptr)
	{
		m_pSingleton = new	LuaEngine();
	}
	return m_pSingleton;
}

void LuaEngine::DoFile(const char * varFilePath)
{
	int ret = luaL_dofile(m_pLua_State, varFilePath);

	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);
		printf("Error: %s\n", err);
		lua_pop(m_pLua_State, 1);
	}
}

void LuaEngine::CallLuaFunction(const char * varLuaFunctionName, int varParamCount,std::function<void(lua_State*)> varFunction)
{
	lua_getglobal(m_pLua_State, varLuaFunctionName);
	if (!lua_isfunction(m_pLua_State, -1))
	{
		std::cout << varLuaFunctionName << " is not function" << std::endl;
		return;
	}

	varFunction(m_pLua_State);

	int ret = lua_pcall(m_pLua_State, varParamCount, 0, 0);
	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);
		printf("Error: %s\n", err);
		lua_pop(m_pLua_State, 1);
	}
}

void LuaEngine::CallLuaFunction(const char * varLuaFunctionName)
{
	lua_getglobal(m_pLua_State, varLuaFunctionName);
	if (!lua_isfunction(m_pLua_State, -1))
	{
		std::cout << varLuaFunctionName << " is not function" << std::endl;
		return;
	}
	int ret = lua_pcall(m_pLua_State, 0, 0, 0);
	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);
		printf("Error: %s\n", err);
		lua_pop(m_pLua_State, 1);
	}
}

void LuaEngine::CallLuaFunction(const char * varLuaFunctionName, const char * varParamTypeName, void * varParamTypeData)
{
	lua_getglobal(m_pLua_State, varLuaFunctionName);
	if (!lua_isfunction(m_pLua_State, -1))
	{
		std::cout << varLuaFunctionName << " is not function" << std::endl;
		return;
	}
	
	tolua_pushusertype(m_pLua_State, varParamTypeData, varParamTypeName);

	int ret = lua_pcall(m_pLua_State, 1, 0, 0);
	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);
		printf("Error: %s\n", err);
		lua_pop(m_pLua_State, 1);
	}
}

void LuaEngine::PrintError()
{
	lua_Debug debug = {};
	int ret = lua_getstack(m_pLua_State, 2, &debug); // 0是pcall_callback_err_fun自己, 1是error函数, 2是真正出错的函数  
	lua_getinfo(m_pLua_State, "Sln", &debug);

	std::string err = lua_tostring(m_pLua_State, -1);
	lua_pop(m_pLua_State, 1);
	std::stringstream msg;
	msg << debug.short_src << ":line " << debug.currentline;
	if (debug.name != 0) {
		msg << "(" << debug.namewhat << " " << debug.name << ")";
	}

	msg << " [" << err << "]";
	lua_pushstring(m_pLua_State, msg.str().c_str());
}
