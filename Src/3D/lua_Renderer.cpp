/*
** Lua binding: Renderer
** Generated automatically by tolua++-1.0.92 on Wed Apr 25 01:27:22 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Renderer_open (lua_State* tolua_S);

#include"Renderer.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Renderer (lua_State* tolua_S)
{
 Renderer* self = (Renderer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Renderer");
 tolua_usertype(tolua_S,"Component");
}

/* method: new of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_Renderer_Renderer_new00
static int tolua_Renderer_Renderer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Renderer* tolua_ret = (Renderer*)  Mtolua_new((Renderer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Renderer");
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

/* method: new_local of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_Renderer_Renderer_new00_local
static int tolua_Renderer_Renderer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Renderer* tolua_ret = (Renderer*)  Mtolua_new((Renderer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Renderer");
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

/* method: delete of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_Renderer_Renderer_delete00
static int tolua_Renderer_Renderer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Update of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_Renderer_Renderer_Update00
static int tolua_Renderer_Renderer_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Render of class  Renderer */
#ifndef TOLUA_DISABLE_tolua_Renderer_Renderer_Render00
static int tolua_Renderer_Renderer_Render00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Renderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Renderer* self = (Renderer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Render'", NULL);
#endif
  {
   self->Render();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Render'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Renderer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Renderer","Renderer","Component",tolua_collect_Renderer);
  #else
  tolua_cclass(tolua_S,"Renderer","Renderer","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Renderer");
   tolua_function(tolua_S,"new",tolua_Renderer_Renderer_new00);
   tolua_function(tolua_S,"new_local",tolua_Renderer_Renderer_new00_local);
   tolua_function(tolua_S,".call",tolua_Renderer_Renderer_new00_local);
   tolua_function(tolua_S,"delete",tolua_Renderer_Renderer_delete00);
   tolua_function(tolua_S,"Update",tolua_Renderer_Renderer_Update00);
   tolua_function(tolua_S,"Render",tolua_Renderer_Renderer_Render00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Renderer (lua_State* tolua_S) {
 return tolua_Renderer_open(tolua_S);
};
#endif

