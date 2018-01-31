/*
** Lua binding: Component
** Generated automatically by tolua++-1.0.92 on Wed Jan 31 21:32:58 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Component_open (lua_State* tolua_S);

#include"Component.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Component (lua_State* tolua_S)
{
 Component* self = (Component*) tolua_tousertype(tolua_S,1,0);
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
}

/* method: new of class  Component */
#ifndef TOLUA_DISABLE_tolua_Component_Component_new00
static int tolua_Component_Component_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Component* tolua_ret = (Component*)  Mtolua_new((Component)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
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

/* method: new_local of class  Component */
#ifndef TOLUA_DISABLE_tolua_Component_Component_new00_local
static int tolua_Component_Component_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Component* tolua_ret = (Component*)  Mtolua_new((Component)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Component");
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

/* method: delete of class  Component */
#ifndef TOLUA_DISABLE_tolua_Component_Component_delete00
static int tolua_Component_Component_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetComponentName of class  Component */
#ifndef TOLUA_DISABLE_tolua_Component_Component_SetComponentName00
static int tolua_Component_Component_SetComponentName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
  std::string varComponentName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetComponentName'", NULL);
#endif
  {
   self->SetComponentName(varComponentName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetComponentName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetComponentName of class  Component */
#ifndef TOLUA_DISABLE_tolua_Component_Component_GetComponentName00
static int tolua_Component_Component_GetComponentName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Component",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetComponentName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetComponentName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetComponentName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mGameObject of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_mGameObject_ptr
static int tolua_get_Component_mGameObject_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mGameObject'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->mGameObject,"GameObject");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mGameObject of class  Component */
#ifndef TOLUA_DISABLE_tolua_set_Component_mGameObject_ptr
static int tolua_set_Component_mGameObject_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mGameObject'",NULL);
  if (!tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mGameObject = ((GameObject*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mTransform of class  Component */
#ifndef TOLUA_DISABLE_tolua_get_Component_mTransform_ptr
static int tolua_get_Component_mTransform_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mTransform'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->mTransform,"Transform");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mTransform of class  Component */
#ifndef TOLUA_DISABLE_tolua_set_Component_mTransform_ptr
static int tolua_set_Component_mTransform_ptr(lua_State* tolua_S)
{
  Component* self = (Component*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_Component_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Component","Component","Object",tolua_collect_Component);
  #else
  tolua_cclass(tolua_S,"Component","Component","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Component");
   tolua_function(tolua_S,"new",tolua_Component_Component_new00);
   tolua_function(tolua_S,"new_local",tolua_Component_Component_new00_local);
   tolua_function(tolua_S,".call",tolua_Component_Component_new00_local);
   tolua_function(tolua_S,"delete",tolua_Component_Component_delete00);
   tolua_function(tolua_S,"SetComponentName",tolua_Component_Component_SetComponentName00);
   tolua_function(tolua_S,"GetComponentName",tolua_Component_Component_GetComponentName00);
   tolua_variable(tolua_S,"mGameObject",tolua_get_Component_mGameObject_ptr,tolua_set_Component_mGameObject_ptr);
   tolua_variable(tolua_S,"mTransform",tolua_get_Component_mTransform_ptr,tolua_set_Component_mTransform_ptr);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Component (lua_State* tolua_S) {
 return tolua_Component_open(tolua_S);
};
#endif

