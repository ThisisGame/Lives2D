/*
** Lua binding: SkinMeshRenderer
** Generated automatically by tolua++-1.0.92 on Wed Apr 25 01:28:58 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_SkinMeshRenderer_open (lua_State* tolua_S);

#include"SkinMeshRenderer.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_SkinMeshRenderer (lua_State* tolua_S)
{
 SkinMeshRenderer* self = (SkinMeshRenderer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"SkinMeshRenderer");
 tolua_usertype(tolua_S,"TiXmlElement");
}

/* method: new of class  SkinMeshRenderer */
#ifndef TOLUA_DISABLE_tolua_SkinMeshRenderer_SkinMeshRenderer_new00
static int tolua_SkinMeshRenderer_SkinMeshRenderer_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkinMeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SkinMeshRenderer* tolua_ret = (SkinMeshRenderer*)  Mtolua_new((SkinMeshRenderer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkinMeshRenderer");
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

/* method: new_local of class  SkinMeshRenderer */
#ifndef TOLUA_DISABLE_tolua_SkinMeshRenderer_SkinMeshRenderer_new00_local
static int tolua_SkinMeshRenderer_SkinMeshRenderer_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SkinMeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SkinMeshRenderer* tolua_ret = (SkinMeshRenderer*)  Mtolua_new((SkinMeshRenderer)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SkinMeshRenderer");
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

/* method: delete of class  SkinMeshRenderer */
#ifndef TOLUA_DISABLE_tolua_SkinMeshRenderer_SkinMeshRenderer_delete00
static int tolua_SkinMeshRenderer_SkinMeshRenderer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkinMeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkinMeshRenderer* self = (SkinMeshRenderer*)  tolua_tousertype(tolua_S,1,0);
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

/* method: InitWithXml of class  SkinMeshRenderer */
#ifndef TOLUA_DISABLE_tolua_SkinMeshRenderer_SkinMeshRenderer_InitWithXml00
static int tolua_SkinMeshRenderer_SkinMeshRenderer_InitWithXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkinMeshRenderer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TiXmlElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkinMeshRenderer* self = (SkinMeshRenderer*)  tolua_tousertype(tolua_S,1,0);
  TiXmlElement* varTiXmlElement = ((TiXmlElement*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'InitWithXml'", NULL);
#endif
  {
   self->InitWithXml(varTiXmlElement);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'InitWithXml'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  SkinMeshRenderer */
#ifndef TOLUA_DISABLE_tolua_SkinMeshRenderer_SkinMeshRenderer_Update00
static int tolua_SkinMeshRenderer_SkinMeshRenderer_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"SkinMeshRenderer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  SkinMeshRenderer* self = (SkinMeshRenderer*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_SkinMeshRenderer_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SkinMeshRenderer","SkinMeshRenderer","Component",tolua_collect_SkinMeshRenderer);
  #else
  tolua_cclass(tolua_S,"SkinMeshRenderer","SkinMeshRenderer","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SkinMeshRenderer");
   tolua_function(tolua_S,"new",tolua_SkinMeshRenderer_SkinMeshRenderer_new00);
   tolua_function(tolua_S,"new_local",tolua_SkinMeshRenderer_SkinMeshRenderer_new00_local);
   tolua_function(tolua_S,".call",tolua_SkinMeshRenderer_SkinMeshRenderer_new00_local);
   tolua_function(tolua_S,"delete",tolua_SkinMeshRenderer_SkinMeshRenderer_delete00);
   tolua_function(tolua_S,"InitWithXml",tolua_SkinMeshRenderer_SkinMeshRenderer_InitWithXml00);
   tolua_function(tolua_S,"Update",tolua_SkinMeshRenderer_SkinMeshRenderer_Update00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_SkinMeshRenderer (lua_State* tolua_S) {
 return tolua_SkinMeshRenderer_open(tolua_S);
};
#endif

