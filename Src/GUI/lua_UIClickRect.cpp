/*
** Lua binding: UIClickRect
** Generated automatically by tolua++-1.0.92 on Tue Sep 26 00:52:09 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UIClickRect_open (lua_State* tolua_S);

#include"UIClickRect.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"KeyTouchListener");
 tolua_usertype(tolua_S,"UIClickRect");
 tolua_usertype(tolua_S,"UIRect");
}

/* get function: __KeyTouchListener__ of class  UIClickRect */
#ifndef TOLUA_DISABLE_tolua_get_UIClickRect___KeyTouchListener__
static int tolua_get_UIClickRect___KeyTouchListener__(lua_State* tolua_S)
{
  UIClickRect* self = (UIClickRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__KeyTouchListener__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<KeyTouchListener*>(self), "KeyTouchListener");
#else
   tolua_pushusertype(tolua_S,(void*)((KeyTouchListener*)self), "KeyTouchListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_UIClickRect_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"UIClickRect","UIClickRect","UIRect",NULL);
  tolua_beginmodule(tolua_S,"UIClickRect");
   tolua_variable(tolua_S,"__KeyTouchListener__",tolua_get_UIClickRect___KeyTouchListener__,NULL);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UIClickRect (lua_State* tolua_S) {
 return tolua_UIClickRect_open(tolua_S);
};
#endif

