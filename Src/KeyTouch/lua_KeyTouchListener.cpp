/*
** Lua binding: KeyTouchListener
** Generated automatically by tolua++-1.0.92 on Tue Sep 26 00:37:37 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_KeyTouchListener_open (lua_State* tolua_S);

#include"KeyTouchListener.h"  

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"KeyTouchListener");
}

/* Open function */
TOLUA_API int tolua_KeyTouchListener_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"KeyTouchListener","KeyTouchListener","",NULL);
  tolua_beginmodule(tolua_S,"KeyTouchListener");
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_KeyTouchListener (lua_State* tolua_S) {
 return tolua_KeyTouchListener_open(tolua_S);
};
#endif

