#include "LuaComponent.h"
#include"LuaEngine/LuaEngine.h"
#include"Tools/Application.h"

IMPLEMENT_DYNCRT_ACTION(LuaComponent)
LuaComponent::LuaComponent()
{
}


LuaComponent::~LuaComponent()
{
}

void LuaComponent::DoFile(const char * varFilePath)
{
	mLuaFilePath = varFilePath;

	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		int tmpTop = lua_gettop(var_pLuaState);

		lua_pushstring(var_pLuaState,"Bind");

		lua_gettable(var_pLuaState, -2);

		int tmpType = lua_type(var_pLuaState, -1);

		if (tmpType == LUA_TFUNCTION)
		{
			lua_pushvalue(var_pLuaState, -2);
			tolua_pushusertype(var_pLuaState, this,"LuaComponent");
			int ret= lua_pcall(var_pLuaState, 2, 0, 0);
		}
	};
	LuaEngine::GetSingleton()->DoFile((Application::PersistentDataPath() + "/Resource/Script/"+ varFilePath).c_str(), tmpFunction);
}

void LuaComponent::BindAwake(const char * varLuaFunctionName)
{
	mLuaFunctionNameAwake = varLuaFunctionName;
}

void LuaComponent::BindOnEnable(const char * varLuaFunctionName)
{
	mLuaFunctionNameOnEnable = varLuaFunctionName;
}

void LuaComponent::BindStart(const char * varLuaFunctionName)
{
	mLuaFunctionNameStart = varLuaFunctionName;
}

void LuaComponent::BindUpdate(const char * varLuaFunctionName)
{
	mLuaFunctionNameUpdate = varLuaFunctionName;
}

void LuaComponent::BindOnDisable(const char * varLuaFunctionName)
{
	mLuaFunctionNameOnDisable = varLuaFunctionName;
}

void LuaComponent::BindOnDestroy(const char * varLuaFunctionName)
{
	mLuaFunctionNameOnDestroy = varLuaFunctionName;
}

void LuaComponent::Awake()
{
	if (mLuaFunctionNameAwake == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, mLuaFunctionNameAwake);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 1, tmpFunction);
}

void LuaComponent::OnEnable()
{
	if (mLuaFunctionNameOnEnable == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, mLuaFunctionNameOnEnable);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 1, tmpFunction);
}

void LuaComponent::Start()
{
	if (mLuaFunctionNameStart == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, mLuaFunctionNameStart);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 1, tmpFunction);
}

void LuaComponent::Update()
{
	if (mLuaFunctionNameUpdate == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, mLuaFunctionNameUpdate);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 1, tmpFunction);
}

void LuaComponent::OnDisable()
{
	if (mLuaFunctionNameOnDisable == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, mLuaFunctionNameOnDisable);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 1, tmpFunction);
}

void LuaComponent::OnDestroy()
{
	if (mLuaFunctionNameOnDestroy == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, mLuaFunctionNameOnDestroy);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 1, tmpFunction);
}
