/*
** Lua binding: KeyTouch
** Generated automatically by tolua++-1.0.92 on Mon Sep 25 22:37:36 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_KeyTouch_open (lua_State* tolua_S);

#include"KeyTouch.h"  

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_KeyTouch (lua_State* tolua_S)
{
 KeyTouch* self = (KeyTouch*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"KeyTouch");
}

/* method: new of class  KeyTouch */
#ifndef TOLUA_DISABLE_tolua_KeyTouch_KeyTouch_new00
static int tolua_KeyTouch_KeyTouch_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"KeyTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   KeyTouch* tolua_ret = (KeyTouch*)  Mtolua_new((KeyTouch)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"KeyTouch");
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

/* method: new_local of class  KeyTouch */
#ifndef TOLUA_DISABLE_tolua_KeyTouch_KeyTouch_new00_local
static int tolua_KeyTouch_KeyTouch_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"KeyTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   KeyTouch* tolua_ret = (KeyTouch*)  Mtolua_new((KeyTouch)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"KeyTouch");
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

/* method: delete of class  KeyTouch */
#ifndef TOLUA_DISABLE_tolua_KeyTouch_KeyTouch_delete00
static int tolua_KeyTouch_KeyTouch_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"KeyTouch",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  KeyTouch* self = (KeyTouch*)  tolua_tousertype(tolua_S,1,0);
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

/* method: OnKey of class  KeyTouch */
#ifndef TOLUA_DISABLE_tolua_KeyTouch_KeyTouch_OnKey00
static int tolua_KeyTouch_KeyTouch_OnKey00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"KeyTouch",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int varkeyCode = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   KeyTouch::OnKey(varkeyCode);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnKey'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnTouch of class  KeyTouch */
#ifndef TOLUA_DISABLE_tolua_KeyTouch_KeyTouch_OnTouch00
static int tolua_KeyTouch_KeyTouch_OnTouch00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"KeyTouch",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int varX = ((int)  tolua_tonumber(tolua_S,2,0));
  int varY = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   KeyTouch::OnTouch(varX,varY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnTouch'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnTouchRelease of class  KeyTouch */
#ifndef TOLUA_DISABLE_tolua_KeyTouch_KeyTouch_OnTouchRelease00
static int tolua_KeyTouch_KeyTouch_OnTouchRelease00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"KeyTouch",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  int varX = ((int)  tolua_tonumber(tolua_S,2,0));
  int varY = ((int)  tolua_tonumber(tolua_S,3,0));
  {
   KeyTouch::OnTouchRelease(varX,varY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnTouchRelease'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_KeyTouch_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"KeyTouch","KeyTouch","",tolua_collect_KeyTouch);
  #else
  tolua_cclass(tolua_S,"KeyTouch","KeyTouch","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"KeyTouch");
   tolua_function(tolua_S,"new",tolua_KeyTouch_KeyTouch_new00);
   tolua_function(tolua_S,"new_local",tolua_KeyTouch_KeyTouch_new00_local);
   tolua_function(tolua_S,".call",tolua_KeyTouch_KeyTouch_new00_local);
   tolua_function(tolua_S,"delete",tolua_KeyTouch_KeyTouch_delete00);
   tolua_function(tolua_S,"OnKey",tolua_KeyTouch_KeyTouch_OnKey00);
   tolua_function(tolua_S,"OnTouch",tolua_KeyTouch_KeyTouch_OnTouch00);
   tolua_function(tolua_S,"OnTouchRelease",tolua_KeyTouch_KeyTouch_OnTouchRelease00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_KeyTouch (lua_State* tolua_S) {
 return tolua_KeyTouch_open(tolua_S);
};
#endif

