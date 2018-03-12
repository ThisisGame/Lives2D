/*
** Lua binding: SceneParser
** Generated automatically by tolua++-1.0.92 on Tue Mar 13 01:16:30 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_SceneParser_open (lua_State* tolua_S);

#include"SceneParser.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_SceneParser (lua_State* tolua_S)
{
 SceneParser* self = (SceneParser*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"SceneParser");
 tolua_usertype(tolua_S,"GameObject");
}

/* method: new of class  SceneParser */
#ifndef TOLUA_DISABLE_tolua_SceneParser_SceneParser_new00
static int tolua_SceneParser_SceneParser_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SceneParser* tolua_ret = (SceneParser*)  Mtolua_new((SceneParser)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneParser");
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

/* method: new_local of class  SceneParser */
#ifndef TOLUA_DISABLE_tolua_SceneParser_SceneParser_new00_local
static int tolua_SceneParser_SceneParser_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SceneParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SceneParser* tolua_ret = (SceneParser*)  Mtolua_new((SceneParser)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneParser");
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

/* method: delete of class  SceneParser */
#ifndef TOLUA_DISABLE_tolua_SceneParser_SceneParser_delete00
static int tolua_SceneParser_SceneParser_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneParser* self = (SceneParser*)  tolua_tousertype(tolua_S,1,0);
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

/* method: CreateScene of class  SceneParser */
#ifndef TOLUA_DISABLE_tolua_SceneParser_SceneParser_CreateScene00
static int tolua_SceneParser_SceneParser_CreateScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SceneParser",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SceneParser* self = (SceneParser*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateScene'", NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->CreateScene(varFilePath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_SceneParser_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SceneParser","SceneParser","",tolua_collect_SceneParser);
  #else
  tolua_cclass(tolua_S,"SceneParser","SceneParser","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SceneParser");
   tolua_function(tolua_S,"new",tolua_SceneParser_SceneParser_new00);
   tolua_function(tolua_S,"new_local",tolua_SceneParser_SceneParser_new00_local);
   tolua_function(tolua_S,".call",tolua_SceneParser_SceneParser_new00_local);
   tolua_function(tolua_S,"delete",tolua_SceneParser_SceneParser_delete00);
   tolua_function(tolua_S,"CreateScene",tolua_SceneParser_SceneParser_CreateScene00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_SceneParser (lua_State* tolua_S) {
 return tolua_SceneParser_open(tolua_S);
};
#endif

