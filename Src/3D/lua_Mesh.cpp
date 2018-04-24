/*
** Lua binding: Mesh
** Generated automatically by tolua++-1.0.92 on Wed Apr 25 01:34:57 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Mesh_open (lua_State* tolua_S);

#include"Mesh.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Mesh (lua_State* tolua_S)
{
 Mesh* self = (Mesh*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Mesh");
 tolua_usertype(tolua_S,"Object");
}

/* method: new of class  Mesh */
#ifndef TOLUA_DISABLE_tolua_Mesh_Mesh_new00
static int tolua_Mesh_Mesh_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Mesh* tolua_ret = (Mesh*)  Mtolua_new((Mesh)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mesh");
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

/* method: new_local of class  Mesh */
#ifndef TOLUA_DISABLE_tolua_Mesh_Mesh_new00_local
static int tolua_Mesh_Mesh_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Mesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Mesh* tolua_ret = (Mesh*)  Mtolua_new((Mesh)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mesh");
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

/* method: delete of class  Mesh */
#ifndef TOLUA_DISABLE_tolua_Mesh_Mesh_delete00
static int tolua_Mesh_Mesh_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Mesh",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Mesh* self = (Mesh*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_Mesh_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Mesh","Mesh","Object",tolua_collect_Mesh);
  #else
  tolua_cclass(tolua_S,"Mesh","Mesh","Object",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Mesh");
   tolua_function(tolua_S,"new",tolua_Mesh_Mesh_new00);
   tolua_function(tolua_S,"new_local",tolua_Mesh_Mesh_new00_local);
   tolua_function(tolua_S,".call",tolua_Mesh_Mesh_new00_local);
   tolua_function(tolua_S,"delete",tolua_Mesh_Mesh_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Mesh (lua_State* tolua_S) {
 return tolua_Mesh_open(tolua_S);
};
#endif

