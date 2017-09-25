/*
** Lua binding: UIDrawRect
** Generated automatically by tolua++-1.0.92 on Tue Sep 26 00:09:55 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UIDrawRect_open (lua_State* tolua_S);

#include"UIDrawRect.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UIDrawRect (lua_State* tolua_S)
{
 UIDrawRect* self = (UIDrawRect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UIDrawRect");
 tolua_usertype(tolua_S,"UIRect");
}

/* method: new of class  UIDrawRect */
#ifndef TOLUA_DISABLE_tolua_UIDrawRect_UIDrawRect_new00
static int tolua_UIDrawRect_UIDrawRect_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIDrawRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIDrawRect* tolua_ret = (UIDrawRect*)  Mtolua_new((UIDrawRect)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIDrawRect");
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

/* method: new_local of class  UIDrawRect */
#ifndef TOLUA_DISABLE_tolua_UIDrawRect_UIDrawRect_new00_local
static int tolua_UIDrawRect_UIDrawRect_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIDrawRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIDrawRect* tolua_ret = (UIDrawRect*)  Mtolua_new((UIDrawRect)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIDrawRect");
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

/* method: delete of class  UIDrawRect */
#ifndef TOLUA_DISABLE_tolua_UIDrawRect_UIDrawRect_delete00
static int tolua_UIDrawRect_UIDrawRect_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIDrawRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIDrawRect* self = (UIDrawRect*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_UIDrawRect_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIDrawRect","UIDrawRect","UIRect",tolua_collect_UIDrawRect);
  #else
  tolua_cclass(tolua_S,"UIDrawRect","UIDrawRect","UIRect",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIDrawRect");
   tolua_function(tolua_S,"new",tolua_UIDrawRect_UIDrawRect_new00);
   tolua_function(tolua_S,"new_local",tolua_UIDrawRect_UIDrawRect_new00_local);
   tolua_function(tolua_S,".call",tolua_UIDrawRect_UIDrawRect_new00_local);
   tolua_function(tolua_S,"delete",tolua_UIDrawRect_UIDrawRect_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UIDrawRect (lua_State* tolua_S) {
 return tolua_UIDrawRect_open(tolua_S);
};
#endif

