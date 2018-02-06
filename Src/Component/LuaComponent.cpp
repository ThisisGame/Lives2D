#include "LuaComponent.h"
#include"LuaEngine/LuaEngine.h"
#include"Tools/Application.h"

IMPLEMENT_DYNCRT_ACTION(LuaComponent)
LuaComponent::LuaComponent():mAwakeIndex(0), mOnEnableIndex(0),mStartIndex(0),mUpdateIndex(0),mOnDisableIndex(0),mOnDestroyIndex(0)
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

		if (lua_istable(var_pLuaState, tmpTop))
		{
			lua_pushnil(var_pLuaState);//lua_next就是死的，一定要先pop一个出来，因为当前pop就是lua返回的table了，所以搞一个空的让他pop

									   //top(-1)为nil 第二个(-2)为 lua返回的table

			while (lua_next(var_pLuaState,-2))//lua_next首先取key，压入，再取value压入，top(-1)为value，(-2)为key,(-3)为lua返回的table
			{
				if (lua_isfunction(var_pLuaState, -1))
				{
					const char* tmpFunctionName = lua_tostring(var_pLuaState, -2);

					//printf("function %s", tmpFunctionName);

					if (strcmp(tmpFunctionName, "Start")==0)
					{
						//生成唯一索引
						lua_pushvalue(var_pLuaState, -1);
						mStartIndex = luaL_ref(var_pLuaState, LUA_REGISTRYINDEX);
					}
					else if (strcmp(tmpFunctionName, "Awake") == 0)
					{
						//生成唯一索引
						lua_pushvalue(var_pLuaState, -1);
						mAwakeIndex = luaL_ref(var_pLuaState, LUA_REGISTRYINDEX);
					}
					else if (strcmp(tmpFunctionName, "OnEnable") == 0)
					{
						//生成唯一索引
						lua_pushvalue(var_pLuaState, -1);
						mOnEnableIndex = luaL_ref(var_pLuaState, LUA_REGISTRYINDEX);
					}
					else if (strcmp(tmpFunctionName, "Update") == 0)
					{
						//生成唯一索引
						lua_pushvalue(var_pLuaState, -1);
						mUpdateIndex = luaL_ref(var_pLuaState, LUA_REGISTRYINDEX);
					}
					else if (strcmp(tmpFunctionName, "OnDisable") == 0)
					{
						//生成唯一索引
						lua_pushvalue(var_pLuaState, -1);
						mOnDisableIndex = luaL_ref(var_pLuaState, LUA_REGISTRYINDEX);
					}
					else if (strcmp(tmpFunctionName, "OnDestroy") == 0)
					{
						//生成唯一索引
						lua_pushvalue(var_pLuaState, -1);
						mOnDestroyIndex = luaL_ref(var_pLuaState, LUA_REGISTRYINDEX);
					}
				}

				//要维持循环，lua返回的table在上面写死了-2，那么要pop掉一个
				lua_pop(var_pLuaState, 1);//此时 top(-1)为key, (-2)为lua返回的table
			}

			//循环结束的状态  top(-1)为key, (-2)为lua返回的table
			//要恢复到原来 lua返回的table是top，那么要pop掉一个
			lua_pop(var_pLuaState, 1);
		}

	};
	LuaEngine::GetSingleton()->DoFile((Application::PersistentDataPath() + "/Resource/Script/"+ varFilePath).c_str(), tmpFunction);
}

void LuaComponent::Awake()
{
	LuaEngine::GetSingleton()->ExecuteLuaFunction(mAwakeIndex);
}

void LuaComponent::OnEnable()
{
	LuaEngine::GetSingleton()->ExecuteLuaFunction(mOnEnableIndex);
}

void LuaComponent::Start()
{
	LuaEngine::GetSingleton()->ExecuteLuaFunction(mStartIndex);
}

void LuaComponent::Update()
{
	LuaEngine::GetSingleton()->ExecuteLuaFunction(mUpdateIndex);
}

void LuaComponent::OnDisable()
{
	LuaEngine::GetSingleton()->ExecuteLuaFunction(mOnDisableIndex);
}

void LuaComponent::OnDestroy()
{
	LuaEngine::GetSingleton()->ExecuteLuaFunction(mOnDestroyIndex);
}
