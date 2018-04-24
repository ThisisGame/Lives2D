/*
** Lua binding: MeshFilter
** Generated automatically by tolua++-1.0.92 on Wed Apr 25 01:05:24 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_MeshFilter_open (lua_State* tolua_S);

#include"MeshFilter.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_MeshFilter (lua_State* tolua_S)
{
 MeshFilter* self = (MeshFilter*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"Mesh");
 tolua_usertype(tolua_S,"TiXmlElement");
 tolua_usertype(tolua_S,"MeshFilter");
}

/* method: new of class  MeshFilter */
#ifndef TOLUA_DISABLE_tolua_MeshFilter_MeshFilter_new00
static int tolua_MeshFilter_MeshFilter_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MeshFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MeshFilter* tolua_ret = (MeshFilter*)  Mtolua_new((MeshFilter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MeshFilter");
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

/* method: new_local of class  MeshFilter */
#ifndef TOLUA_DISABLE_tolua_MeshFilter_MeshFilter_new00_local
static int tolua_MeshFilter_MeshFilter_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MeshFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MeshFilter* tolua_ret = (MeshFilter*)  Mtolua_new((MeshFilter)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MeshFilter");
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

/* method: delete of class  MeshFilter */
#ifndef TOLUA_DISABLE_tolua_MeshFilter_MeshFilter_delete00
static int tolua_MeshFilter_MeshFilter_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MeshFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MeshFilter* self = (MeshFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: InitWithXml of class  MeshFilter */
#ifndef TOLUA_DISABLE_tolua_MeshFilter_MeshFilter_InitWithXml00
static int tolua_MeshFilter_MeshFilter_InitWithXml00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MeshFilter",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"TiXmlElement",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MeshFilter* self = (MeshFilter*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetMesh of class  MeshFilter */
#ifndef TOLUA_DISABLE_tolua_MeshFilter_MeshFilter_GetMesh00
static int tolua_MeshFilter_MeshFilter_GetMesh00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"MeshFilter",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  MeshFilter* self = (MeshFilter*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMesh'", NULL);
#endif
  {
   Mesh* tolua_ret = (Mesh*)  self->GetMesh();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Mesh");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMesh'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_MeshFilter_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"MeshFilter","MeshFilter","Component",tolua_collect_MeshFilter);
  #else
  tolua_cclass(tolua_S,"MeshFilter","MeshFilter","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"MeshFilter");
   tolua_function(tolua_S,"new",tolua_MeshFilter_MeshFilter_new00);
   tolua_function(tolua_S,"new_local",tolua_MeshFilter_MeshFilter_new00_local);
   tolua_function(tolua_S,".call",tolua_MeshFilter_MeshFilter_new00_local);
   tolua_function(tolua_S,"delete",tolua_MeshFilter_MeshFilter_delete00);
   tolua_function(tolua_S,"InitWithXml",tolua_MeshFilter_MeshFilter_InitWithXml00);
   tolua_function(tolua_S,"GetMesh",tolua_MeshFilter_MeshFilter_GetMesh00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_MeshFilter (lua_State* tolua_S) {
 return tolua_MeshFilter_open(tolua_S);
};
#endif

