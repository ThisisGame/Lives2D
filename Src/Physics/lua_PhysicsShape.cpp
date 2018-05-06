/*
** Lua binding: PhysicsShape
** Generated automatically by tolua++-1.0.92 on Sun May  6 11:17:36 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PhysicsShape_open (lua_State* tolua_S);

#include"PhysicsShape.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_PhysicsShape_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"BoxShape",BoxShape);
  tolua_constant(tolua_S,"SphereShape",SphereShape);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PhysicsShape (lua_State* tolua_S) {
 return tolua_PhysicsShape_open(tolua_S);
};
#endif

