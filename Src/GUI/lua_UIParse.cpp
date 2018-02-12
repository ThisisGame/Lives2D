/*
** Lua binding: UIParser
** Generated automatically by tolua++-1.0.92 on Mon Feb 12 12:24:16 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UIParser_open (lua_State* tolua_S);

#include"UIParser.h"  

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UIParser (lua_State* tolua_S)
{
 UIParser* self = (UIParser*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UIRoot");
 tolua_usertype(tolua_S,"UIParser");
}

/* method: new of class  UIParser */
#ifndef TOLUA_DISABLE_tolua_UIParser_UIParser_new00
static int tolua_UIParser_UIParser_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIParser* tolua_ret = (UIParser*)  Mtolua_new((UIParser)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIParser");
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

/* method: new_local of class  UIParser */
#ifndef TOLUA_DISABLE_tolua_UIParser_UIParser_new00_local
static int tolua_UIParser_UIParser_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIParser* tolua_ret = (UIParser*)  Mtolua_new((UIParser)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIParser");
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

/* method: delete of class  UIParser */
#ifndef TOLUA_DISABLE_tolua_UIParser_UIParser_delete00
static int tolua_UIParser_UIParser_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIParser* self = (UIParser*)  tolua_tousertype(tolua_S,1,0);
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

/* method: CreateUI of class  UIParser */
#ifndef TOLUA_DISABLE_tolua_UIParser_UIParser_CreateUI00
static int tolua_UIParser_UIParser_CreateUI00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIParser",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIParser* self = (UIParser*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateUI'", NULL);
#endif
  {
   UIRoot* tolua_ret = (UIRoot*)  self->CreateUI(varFilePath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIRoot");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateUI'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_UIParser_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIParser","UIParser","",tolua_collect_UIParser);
  #else
  tolua_cclass(tolua_S,"UIParser","UIParser","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIParser");
   tolua_function(tolua_S,"new",tolua_UIParser_UIParser_new00);
   tolua_function(tolua_S,"new_local",tolua_UIParser_UIParser_new00_local);
   tolua_function(tolua_S,".call",tolua_UIParser_UIParser_new00_local);
   tolua_function(tolua_S,"delete",tolua_UIParser_UIParser_delete00);
   tolua_function(tolua_S,"CreateUI",tolua_UIParser_UIParser_CreateUI00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UIParser (lua_State* tolua_S) {
 return tolua_UIParser_open(tolua_S);
};
#endif

