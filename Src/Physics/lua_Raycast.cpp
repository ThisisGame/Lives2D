/*
** Lua binding: Raycast
** Generated automatically by tolua++-1.0.92 on Tue May 15 20:38:34 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Raycast_open (lua_State* tolua_S);

#include"Raycast.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Raycast (lua_State* tolua_S)
{
 Raycast* self = (Raycast*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"RaycastHit");
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"Raycast");
 tolua_usertype(tolua_S,"Vector3");
}

/* method: new of class  Raycast */
#ifndef TOLUA_DISABLE_tolua_Raycast_Raycast_new00
static int tolua_Raycast_Raycast_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Raycast",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Raycast* tolua_ret = (Raycast*)  Mtolua_new((Raycast)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Raycast");
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

/* method: new_local of class  Raycast */
#ifndef TOLUA_DISABLE_tolua_Raycast_Raycast_new00_local
static int tolua_Raycast_Raycast_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Raycast",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Raycast* tolua_ret = (Raycast*)  Mtolua_new((Raycast)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Raycast");
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

/* method: delete of class  Raycast */
#ifndef TOLUA_DISABLE_tolua_Raycast_Raycast_delete00
static int tolua_Raycast_Raycast_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Raycast",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Raycast* self = (Raycast*)  tolua_tousertype(tolua_S,1,0);
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

/* method: ScreenPointToRay of class  Raycast */
#ifndef TOLUA_DISABLE_tolua_Raycast_Raycast_ScreenPointToRay00
static int tolua_Raycast_Raycast_ScreenPointToRay00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Raycast",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"Camera",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"RaycastHit",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Vector3* varScreenTouchPosition = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
  Camera* varCamera = ((Camera*)  tolua_tousertype(tolua_S,3,0));
  RaycastHit* varRaycastHit = ((RaycastHit*)  tolua_tousertype(tolua_S,4,0));
  {
   bool tolua_ret = (bool)  Raycast::ScreenPointToRay(*varScreenTouchPosition,varCamera,varRaycastHit);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ScreenPointToRay'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Raycast_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Raycast","Raycast","",tolua_collect_Raycast);
  #else
  tolua_cclass(tolua_S,"Raycast","Raycast","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Raycast");
   tolua_function(tolua_S,"new",tolua_Raycast_Raycast_new00);
   tolua_function(tolua_S,"new_local",tolua_Raycast_Raycast_new00_local);
   tolua_function(tolua_S,".call",tolua_Raycast_Raycast_new00_local);
   tolua_function(tolua_S,"delete",tolua_Raycast_Raycast_delete00);
   tolua_function(tolua_S,"ScreenPointToRay",tolua_Raycast_Raycast_ScreenPointToRay00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Raycast (lua_State* tolua_S) {
 return tolua_Raycast_open(tolua_S);
};
#endif

