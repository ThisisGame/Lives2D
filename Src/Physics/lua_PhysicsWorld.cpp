/*
** Lua binding: PhysicsWorld
** Generated automatically by tolua++-1.0.92 on Sun May  6 00:50:25 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PhysicsWorld_open (lua_State* tolua_S);

#include"PhysicsWorld.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_PhysicsWorld (lua_State* tolua_S)
{
 PhysicsWorld* self = (PhysicsWorld*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"PhysicsWorld");
}

/* method: new of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsWorld_PhysicsWorld_new00
static int tolua_PhysicsWorld_PhysicsWorld_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PhysicsWorld* tolua_ret = (PhysicsWorld*)  Mtolua_new((PhysicsWorld)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsWorld");
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

/* method: new_local of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsWorld_PhysicsWorld_new00_local
static int tolua_PhysicsWorld_PhysicsWorld_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PhysicsWorld* tolua_ret = (PhysicsWorld*)  Mtolua_new((PhysicsWorld)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PhysicsWorld");
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

/* method: delete of class  PhysicsWorld */
#ifndef TOLUA_DISABLE_tolua_PhysicsWorld_PhysicsWorld_delete00
static int tolua_PhysicsWorld_PhysicsWorld_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PhysicsWorld",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PhysicsWorld* self = (PhysicsWorld*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_PhysicsWorld_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"PhysicsWorld","PhysicsWorld","Component",tolua_collect_PhysicsWorld);
  #else
  tolua_cclass(tolua_S,"PhysicsWorld","PhysicsWorld","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"PhysicsWorld");
   tolua_function(tolua_S,"new",tolua_PhysicsWorld_PhysicsWorld_new00);
   tolua_function(tolua_S,"new_local",tolua_PhysicsWorld_PhysicsWorld_new00_local);
   tolua_function(tolua_S,".call",tolua_PhysicsWorld_PhysicsWorld_new00_local);
   tolua_function(tolua_S,"delete",tolua_PhysicsWorld_PhysicsWorld_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PhysicsWorld (lua_State* tolua_S) {
 return tolua_PhysicsWorld_open(tolua_S);
};
#endif

