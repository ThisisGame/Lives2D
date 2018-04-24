/*
** Lua binding: MeshRenderer
** Generated automatically by tolua++-1.0.92 on Wed Apr 25 01:38:37 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_MeshRenderer_open (lua_State* tolua_S);

#include"MeshRenderer.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_MeshRenderer (lua_State* tolua_S)
{
 MeshRenderer* self = (MeshRenderer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"MeshRenderer");
 tolua_usertype(tolua_S,"Renderer");
}

/* method: new of class  MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_MeshRenderer_MeshRenderer_new00
static int tolua_MeshRenderer_MeshRenderer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MeshRenderer* tolua_ret = (MeshRenderer*)  Mtolua_new((MeshRenderer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MeshRenderer");
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

/* method: new_local of class  MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_MeshRenderer_MeshRenderer_new00_local
static int tolua_MeshRenderer_MeshRenderer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MeshRenderer* tolua_ret = (MeshRenderer*)  Mtolua_new((MeshRenderer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MeshRenderer");
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

/* method: delete of class  MeshRenderer */
#ifndef TOLUA_DISABLE_tolua_MeshRenderer_MeshRenderer_delete00
static int tolua_MeshRenderer_MeshRenderer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MeshRenderer* self = (MeshRenderer*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_MeshRenderer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"MeshRenderer","MeshRenderer","Renderer",tolua_collect_MeshRenderer);
  #else
  tolua_cclass(tolua_S,"MeshRenderer","MeshRenderer","Renderer",NULL);
  #endif
  tolua_beginmodule(tolua_S,"MeshRenderer");
   tolua_function(tolua_S,"new",tolua_MeshRenderer_MeshRenderer_new00);
   tolua_function(tolua_S,"new_local",tolua_MeshRenderer_MeshRenderer_new00_local);
   tolua_function(tolua_S,".call",tolua_MeshRenderer_MeshRenderer_new00_local);
   tolua_function(tolua_S,"delete",tolua_MeshRenderer_MeshRenderer_delete00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MeshRenderer (lua_State* tolua_S) {
 return tolua_MeshRenderer_open(tolua_S);
};
#endif

