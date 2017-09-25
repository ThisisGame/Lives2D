/*
** Lua binding: UIRect
** Generated automatically by tolua++-1.0.92 on Tue Sep 26 00:46:10 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UIRect_open (lua_State* tolua_S);

#include"UIRect.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UIRect (lua_State* tolua_S)
{
 UIRect* self = (UIRect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UIRect");
}

/* method: new of class  UIRect */
#ifndef TOLUA_DISABLE_tolua_UIRect_UIRect_new00
static int tolua_UIRect_UIRect_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRectType varUIRectType = ((UIRectType) (int)  tolua_tonumber(tolua_S,2,0));
  {
   UIRect* tolua_ret = (UIRect*)  Mtolua_new((UIRect)(varUIRectType));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIRect");
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

/* method: new_local of class  UIRect */
#ifndef TOLUA_DISABLE_tolua_UIRect_UIRect_new00_local
static int tolua_UIRect_UIRect_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRectType varUIRectType = ((UIRectType) (int)  tolua_tonumber(tolua_S,2,0));
  {
   UIRect* tolua_ret = (UIRect*)  Mtolua_new((UIRect)(varUIRectType));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIRect");
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

/* method: delete of class  UIRect */
#ifndef TOLUA_DISABLE_tolua_UIRect_UIRect_delete00
static int tolua_UIRect_UIRect_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRect* self = (UIRect*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetDepth of class  UIRect */
#ifndef TOLUA_DISABLE_tolua_UIRect_UIRect_SetDepth00
static int tolua_UIRect_UIRect_SetDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRect* self = (UIRect*)  tolua_tousertype(tolua_S,1,0);
  int varDepth = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDepth'", NULL);
#endif
  {
   self->SetDepth(varDepth);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDepth of class  UIRect */
#ifndef TOLUA_DISABLE_tolua_UIRect_UIRect_GetDepth00
static int tolua_UIRect_UIRect_GetDepth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRect* self = (UIRect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDepth'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetDepth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDepth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_UIRect_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_constant(tolua_S,"Type_UIClickRect",Type_UIClickRect);
  tolua_constant(tolua_S,"Type_UIDrawRect",Type_UIDrawRect);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIRect","UIRect","",tolua_collect_UIRect);
  #else
  tolua_cclass(tolua_S,"UIRect","UIRect","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIRect");
   tolua_function(tolua_S,"new",tolua_UIRect_UIRect_new00);
   tolua_function(tolua_S,"new_local",tolua_UIRect_UIRect_new00_local);
   tolua_function(tolua_S,".call",tolua_UIRect_UIRect_new00_local);
   tolua_function(tolua_S,"delete",tolua_UIRect_UIRect_delete00);
   tolua_function(tolua_S,"SetDepth",tolua_UIRect_UIRect_SetDepth00);
   tolua_function(tolua_S,"GetDepth",tolua_UIRect_UIRect_GetDepth00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UIRect (lua_State* tolua_S) {
 return tolua_UIRect_open(tolua_S);
};
#endif

