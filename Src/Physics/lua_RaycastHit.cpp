/*
** Lua binding: RaycastHit
** Generated automatically by tolua++-1.0.92 on Tue May 15 21:03:01 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_RaycastHit_open (lua_State* tolua_S);

#include"RaycastHit.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_RaycastHit (lua_State* tolua_S)
{
 RaycastHit* self = (RaycastHit*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector3 (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"RaycastHit");
 tolua_usertype(tolua_S,"GameObject");
 tolua_usertype(tolua_S,"Vector3");
}

/* method: new of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_new00
static int tolua_RaycastHit_RaycastHit_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RaycastHit* tolua_ret = (RaycastHit*)  Mtolua_new((RaycastHit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RaycastHit");
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

/* method: new_local of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_new00_local
static int tolua_RaycastHit_RaycastHit_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RaycastHit* tolua_ret = (RaycastHit*)  Mtolua_new((RaycastHit)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RaycastHit");
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

/* method: delete of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_delete00
static int tolua_RaycastHit_RaycastHit_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RaycastHit* self = (RaycastHit*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetDistance of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_GetDistance00
static int tolua_RaycastHit_RaycastHit_GetDistance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RaycastHit* self = (RaycastHit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDistance'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetDistance();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDistance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPoint of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_SetPoint00
static int tolua_RaycastHit_RaycastHit_SetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RaycastHit* self = (RaycastHit*)  tolua_tousertype(tolua_S,1,0);
  Vector3* varPoint = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPoint'", NULL);
#endif
  {
   self->SetPoint(*varPoint);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPoint of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_GetPoint00
static int tolua_RaycastHit_RaycastHit_GetPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RaycastHit* self = (RaycastHit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPoint'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->GetPoint();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHitGameObject of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_SetHitGameObject00
static int tolua_RaycastHit_RaycastHit_SetHitGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"GameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RaycastHit* self = (RaycastHit*)  tolua_tousertype(tolua_S,1,0);
  GameObject* varGameObject = ((GameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHitGameObject'", NULL);
#endif
  {
   self->SetHitGameObject(varGameObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHitGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHitGameObject of class  RaycastHit */
#ifndef TOLUA_DISABLE_tolua_RaycastHit_RaycastHit_GetHitGameObject00
static int tolua_RaycastHit_RaycastHit_GetHitGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RaycastHit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RaycastHit* self = (RaycastHit*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHitGameObject'", NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->GetHitGameObject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHitGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_RaycastHit_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"RaycastHit","RaycastHit","",tolua_collect_RaycastHit);
  #else
  tolua_cclass(tolua_S,"RaycastHit","RaycastHit","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"RaycastHit");
   tolua_function(tolua_S,"new",tolua_RaycastHit_RaycastHit_new00);
   tolua_function(tolua_S,"new_local",tolua_RaycastHit_RaycastHit_new00_local);
   tolua_function(tolua_S,".call",tolua_RaycastHit_RaycastHit_new00_local);
   tolua_function(tolua_S,"delete",tolua_RaycastHit_RaycastHit_delete00);
   tolua_function(tolua_S,"GetDistance",tolua_RaycastHit_RaycastHit_GetDistance00);
   tolua_function(tolua_S,"SetPoint",tolua_RaycastHit_RaycastHit_SetPoint00);
   tolua_function(tolua_S,"GetPoint",tolua_RaycastHit_RaycastHit_GetPoint00);
   tolua_function(tolua_S,"SetHitGameObject",tolua_RaycastHit_RaycastHit_SetHitGameObject00);
   tolua_function(tolua_S,"GetHitGameObject",tolua_RaycastHit_RaycastHit_GetHitGameObject00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_RaycastHit (lua_State* tolua_S) {
 return tolua_RaycastHit_open(tolua_S);
};
#endif

