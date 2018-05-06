#include "LuaEngine.h"

#include<iostream>
#include<sstream>

#include"Tools/Application.h"
#include"Tools/Helper.h"

TOLUA_API int  tolua_Application_open(lua_State* tolua_S);
TOLUA_API int  tolua_BinaryPacker_open(lua_State* tolua_S);
TOLUA_API int  tolua_NetworkClient_open(lua_State* tolua_S);
TOLUA_API int  tolua_AudioSource_open(lua_State* tolua_S);

TOLUA_API int  tolua_KeyTouchListener_open(lua_State* tolua_S);
TOLUA_API int  tolua_KeyTouch_open(lua_State* tolua_S);

TOLUA_API int  tolua_Object_open(lua_State* tolua_S);
TOLUA_API int  tolua_GameObject_open(lua_State* tolua_S);
TOLUA_API int  tolua_Component_open(lua_State* tolua_S);
TOLUA_API int  tolua_LuaComponent_open(lua_State* tolua_S);
TOLUA_API int  tolua_Transform_open(lua_State* tolua_S);
TOLUA_API int  tolua_Behavior_open(lua_State* tolua_S);

TOLUA_API int  tolua_Math_open(lua_State* tolua_S);


TOLUA_API int  tolua_UIRect_open(lua_State* tolua_S);
TOLUA_API int  tolua_UIDrawRect_open(lua_State* tolua_S);
TOLUA_API int  tolua_UIClickRect_open(lua_State* tolua_S);
TOLUA_API int  tolua_Image_open(lua_State* tolua_S);
TOLUA_API int  tolua_ImageAnimationClip_open(lua_State* tolua_S);
TOLUA_API int  tolua_ImageAnimation_open(lua_State* tolua_S);
TOLUA_API int  tolua_UILabel_open(lua_State* tolua_S);
TOLUA_API int  tolua_UIButton_open(lua_State* tolua_S);
TOLUA_API int  tolua_UIRoot_open(lua_State* tolua_S);
TOLUA_API int  tolua_UIParser_open(lua_State* tolua_S);

TOLUA_API int  tolua_SceneParser_open(lua_State* tolua_S);
TOLUA_API int  tolua_Camera_open(lua_State* tolua_S);
TOLUA_API int  tolua_MeshFilter_open(lua_State* tolua_S);
TOLUA_API int  tolua_Material_open(lua_State* tolua_S);
TOLUA_API int  tolua_Mesh_open(lua_State* tolua_S);
TOLUA_API int  tolua_Renderer_open(lua_State* tolua_S);
TOLUA_API int  tolua_MeshRenderer_open(lua_State* tolua_S);
TOLUA_API int  tolua_SkinMeshRenderer_open(lua_State* tolua_S);

TOLUA_API int  tolua_PhysicsShape_open(lua_State* tolua_S);
TOLUA_API int  tolua_Rigidbody_open(lua_State* tolua_S);
TOLUA_API int  tolua_PhysicsWorld_open(lua_State* tolua_S);

LuaEngine* LuaEngine::m_pSingleton = nullptr;

LuaEngine::LuaEngine()
{

	m_pLua_State = luaL_newstate();
	luaL_openlibs(m_pLua_State);

	tolua_Application_open(m_pLua_State);
	tolua_BinaryPacker_open(m_pLua_State);
	tolua_NetworkClient_open(m_pLua_State);
	tolua_AudioSource_open(m_pLua_State);
	tolua_KeyTouchListener_open(m_pLua_State);
	tolua_KeyTouch_open(m_pLua_State);
	tolua_Object_open(m_pLua_State);
	tolua_GameObject_open(m_pLua_State);
	tolua_Component_open(m_pLua_State);
	tolua_LuaComponent_open(m_pLua_State);
	tolua_Transform_open(m_pLua_State);
	tolua_Behavior_open(m_pLua_State);

	tolua_Math_open(m_pLua_State);

	tolua_UIRect_open(m_pLua_State);
	tolua_UIDrawRect_open(m_pLua_State);
	tolua_UIClickRect_open(m_pLua_State);
	tolua_Image_open(m_pLua_State);
	tolua_ImageAnimationClip_open(m_pLua_State);
	tolua_ImageAnimation_open(m_pLua_State);
	tolua_UILabel_open(m_pLua_State);
	tolua_UIButton_open(m_pLua_State);
	tolua_UIRoot_open(m_pLua_State);
	tolua_UIParser_open(m_pLua_State);

	tolua_SceneParser_open(m_pLua_State);
	tolua_Camera_open(m_pLua_State);
	tolua_MeshFilter_open(m_pLua_State);
	tolua_Material_open(m_pLua_State);
	tolua_Mesh_open(m_pLua_State);
	tolua_Renderer_open(m_pLua_State);
	tolua_MeshRenderer_open(m_pLua_State);
	tolua_SkinMeshRenderer_open(m_pLua_State);

	tolua_PhysicsShape_open(m_pLua_State);
	tolua_Rigidbody_open(m_pLua_State);
	tolua_PhysicsWorld_open(m_pLua_State);

	mErrorPause = false;

	SetLuaPath();
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

void LuaEngine::SetLuaPath()
{
	std::string tmpPackagePath = "package.path='" + Application::PersistentDataPath() + "/Resource/Script/?.lua\'";

	Helper::LOG("Package.path=%s", tmpPackagePath.c_str());

	luaL_dostring(m_pLua_State, tmpPackagePath.c_str());
}

void LuaEngine::DoFile(const char * varFilePath)
{
	int ret = luaL_dofile(m_pLua_State, varFilePath);//top(-1)为 lua返回的table

	

	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);

		Helper::LOG(err);
		lua_pop(m_pLua_State, 1);

		mErrorPause = true;
	}

	//int top = lua_gettop(m_pLua_State);
	//

	//lua_pushnil(m_pLua_State);//top(-1)为nil 第二个(-2)为 lua返回的table

	//while (lua_next(m_pLua_State,-2))//lua_next首先取key，压入，再取value压入，top(-1)为value，(-2)为key,(-3)为lua返回的table
	//{
	//	top = lua_gettop(m_pLua_State);

	//	if (lua_isfunction(m_pLua_State, -1))
	//	{
	//		top = lua_gettop(m_pLua_State);

	//		const char* tmpFunctionName = lua_tostring(m_pLua_State, -2);

	//		top = lua_gettop(m_pLua_State);

	//		printf("function %s", tmpFunctionName);

	//		//生成唯一索引
	//		lua_pushvalue(m_pLua_State, -1);

	//		top = lua_gettop(m_pLua_State);

	//		int tmpStartIndex = luaL_ref(m_pLua_State, LUA_REGISTRYINDEX);

	//		top = lua_gettop(m_pLua_State);
	//	}


	//	//要维持循环，lua返回的table在上面写死了-2，那么要pop掉一个
	//	lua_pop(m_pLua_State, 1);//此时 top(-1)为key, (-2)为lua返回的table

	//	top = lua_gettop(m_pLua_State);
	//}

	//top = lua_gettop(m_pLua_State);

	//top = lua_gettop(m_pLua_State);
	//lua_rawgeti(m_pLua_State, LUA_REGISTRYINDEX, 1);
	//top = lua_gettop(m_pLua_State);
	//lua_call(m_pLua_State, 0, 0);
	//top = lua_gettop(m_pLua_State);
	//lua_rawgeti(m_pLua_State, LUA_REGISTRYINDEX, 2);
	//top = lua_gettop(m_pLua_State);
	//lua_call(m_pLua_State, 0, 0);
	//top = lua_gettop(m_pLua_State);

	////循环结束的状态  top(-1)为key, (-2)为lua返回的table
	////要恢复到原来 lua返回的table是top，那么要pop掉一个
	//lua_pop(m_pLua_State, 1);
}

void LuaEngine::DoFile(const char * varFilePath, std::function<void(lua_State*)> varFunction)
{
	int ret = luaL_dofile(m_pLua_State, varFilePath);//top(-1)为 lua返回的table



	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);

		Helper::LOG(err);
		lua_pop(m_pLua_State, 1);

		mErrorPause = true;
	}
	else
	{
		varFunction(m_pLua_State);
	}
}

void LuaEngine::CallLuaFunction(const char * varLuaFunctionName, int varParamCount,std::function<void(lua_State*)> varFunction)
{
	if (mErrorPause)
	{
		return;
	}
	lua_getglobal(m_pLua_State, varLuaFunctionName);
	if (!lua_isfunction(m_pLua_State, -1))
	{
		Helper::LOG("%s is not function", varLuaFunctionName);
		return;
	}

	varFunction(m_pLua_State);

	int ret = lua_pcall(m_pLua_State, varParamCount, 0, 0);
	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);
		Helper::LOG("Error: %s\n", err);
		lua_pop(m_pLua_State, 1);

		mErrorPause = true;
	}
}

void LuaEngine::CallLuaFunction(const char * varLuaFunctionName)
{
	if (mErrorPause)
	{
		return;
	}
	lua_getglobal(m_pLua_State, varLuaFunctionName);
	if (!lua_isfunction(m_pLua_State, -1))
	{
		Helper::LOG("%s is not function", varLuaFunctionName);
		return;
	}
	int ret = lua_pcall(m_pLua_State, 0, 0, 0);
	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);
		Helper::LOG("Error: %s\n", err);
		lua_pop(m_pLua_State, 1);

		mErrorPause = true;
	}
}

void LuaEngine::CallLuaFunction(const char * varLuaFunctionName, const char * varParamTypeName, void * varParamTypeData)
{
	if (mErrorPause)
	{
		return;
	}
	lua_getglobal(m_pLua_State, varLuaFunctionName);
	if (!lua_isfunction(m_pLua_State, -1))
	{
		Helper::LOG("%s is not function", varLuaFunctionName);
		return;
	}
	
	tolua_pushusertype(m_pLua_State, varParamTypeData, varParamTypeName);

	int ret = lua_pcall(m_pLua_State, 1, 0, 0);
	if (ret != 0)
	{
		int t = lua_type(m_pLua_State, -1);
		const char* err = lua_tostring(m_pLua_State, -1);
		Helper::LOG("Error: %s\n", err);
		lua_pop(m_pLua_State, 1);

		mErrorPause = true;
	}
}

LuaFunctionPoint* LuaEngine::GetLuaFunction(LuaFunctionPoint* varLuaFunctionPoint)
{
	lua_pushvalue(varLuaFunctionPoint->mlua_State, varLuaFunctionPoint->mFunctionIndexInStack);
	varLuaFunctionPoint->mFunctionPoint = luaL_ref(varLuaFunctionPoint->mlua_State, LUA_REGISTRYINDEX);

	lua_pushvalue(varLuaFunctionPoint->mlua_State, varLuaFunctionPoint->mArgumentIndexInStack);
	varLuaFunctionPoint->mArgumentPoint = luaL_ref(varLuaFunctionPoint->mlua_State, LUA_REGISTRYINDEX);
	return varLuaFunctionPoint;
}

void LuaEngine::ExecuteLuaFunction(LuaFunctionPoint* varLuaFunctionPoint)
{
	lua_rawgeti(m_pLua_State, LUA_REGISTRYINDEX, varLuaFunctionPoint->mFunctionPoint);
	lua_rawgeti(m_pLua_State, LUA_REGISTRYINDEX, varLuaFunctionPoint->mArgumentPoint);
	lua_call(m_pLua_State, 1, 0);
}

void LuaEngine::ExecuteLuaFunction(int varLuaFunctionUniqueIndex)
{
	lua_rawgeti(m_pLua_State, LUA_REGISTRYINDEX, varLuaFunctionUniqueIndex);
	lua_call(m_pLua_State, 0, 0);
}

void LuaEngine::PrintError()
{
	lua_Debug debug = {};
	int ret = lua_getstack(m_pLua_State, 2, &debug); // 0��pcall_callback_err_fun�Լ�, 1��error����, 2����������ĺ���  
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
