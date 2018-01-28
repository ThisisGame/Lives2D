/*
** Lua binding: Behavior
** Generated automatically by tolua++-1.0.92 on Sun Jan 28 23:25:09 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Behavior_open (lua_State* tolua_S);

#include"Behavior.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Behavior (lua_State* tolua_S)
{
 Behavior* self = (Behavior*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Behavior");
 tolua_usertype(tolua_S,"Component");
}

/* method: new of class  Behavior */
#ifndef TOLUA_DISABLE_tolua_Behavior_Behavior_new00
static int tolua_Behavior_Behavior_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Behavior",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Behavior* tolua_ret = (Behavior*)  Mtolua_new((Behavior)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Behavior");
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

/* method: new_local of class  Behavior */
#ifndef TOLUA_DISABLE_tolua_Behavior_Behavior_new00_local
static int tolua_Behavior_Behavior_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Behavior",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Behavior* tolua_ret = (Behavior*)  Mtolua_new((Behavior)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Behavior");
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

/* method: delete of class  Behavior */
#ifndef TOLUA_DISABLE_tolua_Behavior_Behavior_delete00
static int tolua_Behavior_Behavior_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Behavior",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Behavior* self = (Behavior*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_Behavior_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Behavior","Behavior","Component",tolua_collect_Behavior);
  #else
  tolua_cclass(tolua_S,"Behavior","Behavior","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Behavior");
   tolua_function(tolua_S,"new",tolua_Behavior_Behavior_new00);
   tolua_function(tolua_S,"new_local",tolua_Behavior_Behavior_new00_local);
   tolua_function(tolua_S,".call",tolua_Behavior_Behavior_new00_local);
   tolua_function(tolua_S,"delete",tolua_Behavior_Behavior_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Behavior (lua_State* tolua_S) {
 return tolua_Behavior_open(tolua_S);
};
#endif

