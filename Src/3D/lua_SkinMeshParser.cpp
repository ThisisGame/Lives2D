/*
** Lua binding: SkinMeshParser
** Generated automatically by tolua++-1.0.92 on Sat Aug 18 14:33:02 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_SkinMeshParser_open (lua_State* tolua_S);

#include"SkinMeshParser.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_SkinMeshParser (lua_State* tolua_S)
{
 SkinMeshParser* self = (SkinMeshParser*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"SkinMeshParser");
 tolua_usertype(tolua_S,"GameObject");
}

/* method: new of class  SkinMeshParser */
#ifndef TOLUA_DISABLE_tolua_SkinMeshParser_SkinMeshParser_new00
static int tolua_SkinMeshParser_SkinMeshParser_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkinMeshParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SkinMeshParser* tolua_ret = (SkinMeshParser*)  Mtolua_new((SkinMeshParser)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkinMeshParser");
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

/* method: new_local of class  SkinMeshParser */
#ifndef TOLUA_DISABLE_tolua_SkinMeshParser_SkinMeshParser_new00_local
static int tolua_SkinMeshParser_SkinMeshParser_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkinMeshParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SkinMeshParser* tolua_ret = (SkinMeshParser*)  Mtolua_new((SkinMeshParser)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkinMeshParser");
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

/* method: delete of class  SkinMeshParser */
#ifndef TOLUA_DISABLE_tolua_SkinMeshParser_SkinMeshParser_delete00
static int tolua_SkinMeshParser_SkinMeshParser_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkinMeshParser",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkinMeshParser* self = (SkinMeshParser*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Create of class  SkinMeshParser */
#ifndef TOLUA_DISABLE_tolua_SkinMeshParser_SkinMeshParser_Create00
static int tolua_SkinMeshParser_SkinMeshParser_Create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkinMeshParser",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkinMeshParser* self = (SkinMeshParser*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Create'", NULL);
#endif
  {
   GameObject* tolua_ret = (GameObject*)  self->Create(varFilePath);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_SkinMeshParser_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SkinMeshParser","SkinMeshParser","",tolua_collect_SkinMeshParser);
  #else
  tolua_cclass(tolua_S,"SkinMeshParser","SkinMeshParser","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SkinMeshParser");
   tolua_function(tolua_S,"new",tolua_SkinMeshParser_SkinMeshParser_new00);
   tolua_function(tolua_S,"new_local",tolua_SkinMeshParser_SkinMeshParser_new00_local);
   tolua_function(tolua_S,".call",tolua_SkinMeshParser_SkinMeshParser_new00_local);
   tolua_function(tolua_S,"delete",tolua_SkinMeshParser_SkinMeshParser_delete00);
   tolua_function(tolua_S,"Create",tolua_SkinMeshParser_SkinMeshParser_Create00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_SkinMeshParser (lua_State* tolua_S) {
 return tolua_SkinMeshParser_open(tolua_S);
};
#endif

