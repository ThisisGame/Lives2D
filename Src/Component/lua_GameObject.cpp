/*
** Lua binding: GameObject
** Generated automatically by tolua++-1.0.92 on Sun Aug 19 02:50:19 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_GameObject_open (lua_State* tolua_S);

#include"GameObject.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_GameObject (lua_State* tolua_S)
{
 GameObject* self = (GameObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"Transform");
 tolua_usertype(tolua_S,"Object");
 tolua_usertype(tolua_S,"GameObject");
 tolua_usertype(tolua_S,"LuaComponent");
}

/* method: new of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_new00
static int tolua_GameObject_GameObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* varName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   GameObject* tolua_ret = (GameObject*)  Mtolua_new((GameObject)(varName));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_new00_local
static int tolua_GameObject_GameObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* varName = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   GameObject* tolua_ret = (GameObject*)  Mtolua_new((GameObject)(varName));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_delete00
static int tolua_GameObject_GameObject_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Destroy of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_Destroy00
static int tolua_GameObject_GameObject_Destroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* varGo = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
  {
   GameObject::Destroy(varGo);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Destroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: name of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_get_GameObject_name
static int tolua_get_GameObject_name(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
#endif
  tolua_pushcppstring(tolua_S,(const char*)self->name);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: name of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_set_GameObject_name
static int tolua_set_GameObject_name(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'name'",NULL);
  if (!tolua_iscppstring(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->name = ((std::string)  tolua_tocppstring(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mTransform of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_get_GameObject_mTransform_ptr
static int tolua_get_GameObject_mTransform_ptr(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mTransform'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->mTransform,"Transform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mTransform of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_set_GameObject_mTransform_ptr
static int tolua_set_GameObject_mTransform_ptr(lua_State* tolua_S)
{
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mTransform'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Transform",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mTransform = ((Transform*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddChild of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_AddChild00
static int tolua_GameObject_GameObject_AddChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* varGameObject = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddChild'", NULL);
#endif
  {
   self->AddChild(varGameObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChildCount of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_GetChildCount00
static int tolua_GameObject_GameObject_GetChildCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChildCount'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetChildCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChildCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChild of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_GetChild00
static int tolua_GameObject_GameObject_GetChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  int varIndex = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->GetChild(varIndex);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetChild of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_GetChild01
static int tolua_GameObject_GameObject_GetChild01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* varName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetChild'", NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->GetChild(varName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
tolua_lerror:
 return tolua_GameObject_GameObject_GetChild00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetParent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_SetParent00
static int tolua_GameObject_GameObject_SetParent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  GameObject* varGameObjectParent = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetParent'", NULL);
#endif
  {
   self->SetParent(varGameObjectParent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetParent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddComponent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_AddComponent00
static int tolua_GameObject_GameObject_AddComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* varComponentName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddComponent'", NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->AddComponent(varComponentName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret, varComponentName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveComponent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_RemoveComponent00
static int tolua_GameObject_GameObject_RemoveComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* varComponentName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveComponent'", NULL);
#endif
  {
   self->RemoveComponent(varComponentName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_GetComponent00
static int tolua_GameObject_GameObject_GetComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* varComponentName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponent'", NULL);
#endif
  {
   Component* tolua_ret = (Component*)  self->GetComponent(varComponentName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret, varComponentName);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddLuaComponent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_AddLuaComponent00
static int tolua_GameObject_GameObject_AddLuaComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddLuaComponent'", NULL);
#endif
  {
   LuaComponent* tolua_ret = (LuaComponent*)  self->AddLuaComponent(varFilePath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LuaComponent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddLuaComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveLuaComponent of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_RemoveLuaComponent00
static int tolua_GameObject_GameObject_RemoveLuaComponent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveLuaComponent'", NULL);
#endif
  {
   self->RemoveLuaComponent(varFilePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveLuaComponent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Awake of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_Awake00
static int tolua_GameObject_GameObject_Awake00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Awake'", NULL);
#endif
  {
   self->Awake();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Awake'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnEnable of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_OnEnable00
static int tolua_GameObject_GameObject_OnEnable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnEnable'", NULL);
#endif
  {
   self->OnEnable();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnEnable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Start of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_Start00
static int tolua_GameObject_GameObject_Start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Start'", NULL);
#endif
  {
   self->Start();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_Update00
static int tolua_GameObject_GameObject_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnDisable of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_OnDisable00
static int tolua_GameObject_GameObject_OnDisable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnDisable'", NULL);
#endif
  {
   self->OnDisable();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnDisable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnDestroy of class  GameObject */
#ifndef TOLUA_DISABLE_tolua_GameObject_GameObject_OnDestroy00
static int tolua_GameObject_GameObject_OnDestroy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GameObject* self = (GameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnDestroy'", NULL);
#endif
  {
   self->OnDestroy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnDestroy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_GameObject_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"GameObject","GameObject","Object",tolua_collect_GameObject);
  #else
  tolua_cclass(tolua_S,"GameObject","GameObject","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"GameObject");
   tolua_function(tolua_S,"new",tolua_GameObject_GameObject_new00);
   tolua_function(tolua_S,"new_local",tolua_GameObject_GameObject_new00_local);
   tolua_function(tolua_S,".call",tolua_GameObject_GameObject_new00_local);
   tolua_function(tolua_S,"delete",tolua_GameObject_GameObject_delete00);
   tolua_function(tolua_S,"Destroy",tolua_GameObject_GameObject_Destroy00);
   tolua_variable(tolua_S,"name",tolua_get_GameObject_name,tolua_set_GameObject_name);
   tolua_variable(tolua_S,"mTransform",tolua_get_GameObject_mTransform_ptr,tolua_set_GameObject_mTransform_ptr);
   tolua_function(tolua_S,"AddChild",tolua_GameObject_GameObject_AddChild00);
   tolua_function(tolua_S,"GetChildCount",tolua_GameObject_GameObject_GetChildCount00);
   tolua_function(tolua_S,"GetChild",tolua_GameObject_GameObject_GetChild00);
   tolua_function(tolua_S,"GetChild",tolua_GameObject_GameObject_GetChild01);
   tolua_function(tolua_S,"SetParent",tolua_GameObject_GameObject_SetParent00);
   tolua_function(tolua_S,"AddComponent",tolua_GameObject_GameObject_AddComponent00);
   tolua_function(tolua_S,"RemoveComponent",tolua_GameObject_GameObject_RemoveComponent00);
   tolua_function(tolua_S,"GetComponent",tolua_GameObject_GameObject_GetComponent00);
   tolua_function(tolua_S,"AddLuaComponent",tolua_GameObject_GameObject_AddLuaComponent00);
   tolua_function(tolua_S,"RemoveLuaComponent",tolua_GameObject_GameObject_RemoveLuaComponent00);
   tolua_function(tolua_S,"Awake",tolua_GameObject_GameObject_Awake00);
   tolua_function(tolua_S,"OnEnable",tolua_GameObject_GameObject_OnEnable00);
   tolua_function(tolua_S,"Start",tolua_GameObject_GameObject_Start00);
   tolua_function(tolua_S,"Update",tolua_GameObject_GameObject_Update00);
   tolua_function(tolua_S,"OnDisable",tolua_GameObject_GameObject_OnDisable00);
   tolua_function(tolua_S,"OnDestroy",tolua_GameObject_GameObject_OnDestroy00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_GameObject (lua_State* tolua_S) {
 return tolua_GameObject_open(tolua_S);
};
#endif

