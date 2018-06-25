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


void LuaComponent::Bind(const char * varKey, const char * varLuaFunctionName)
{
	mBindLuaFunctionMap[varKey] = varLuaFunctionName;
}

void LuaComponent::Invoke(const char * varKey)
{
	const char* tmpLuaFunctionName = mBindLuaFunctionMap[varKey];
	if (tmpLuaFunctionName == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, tmpLuaFunctionName);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 1, tmpFunction);
}

void LuaComponent::Invoke(const char * varKey, Transform * varTransA, Transform * varTransB)
{
	const char* tmpLuaFunctionName = mBindLuaFunctionMap[varKey];
	if (tmpLuaFunctionName == nullptr)
	{
		return;
	}
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* pLuaState)
	{
		tolua_pushstring(pLuaState, tmpLuaFunctionName);
		tolua_pushusertype(pLuaState, varTransA, "Transform");
		tolua_pushusertype(pLuaState, varTransB, "Transform");
	};
	LuaEngine::GetSingleton()->CallLuaFunction("RunWrap", 3, tmpFunction);
}

void LuaComponent::Awake()
{
	Invoke("Awake");
}

void LuaComponent::OnEnable()
{
	Invoke("OnEnable");
}

void LuaComponent::Start()
{
	Invoke("Start");
}

void LuaComponent::Update()
{
	Invoke("Update");
}

void LuaComponent::OnDisable()
{
	Invoke("OnDisable");
}

void LuaComponent::OnDestroy()
{
	Invoke("OnDestroy");
}
