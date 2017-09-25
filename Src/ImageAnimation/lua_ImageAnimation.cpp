/*
** Lua binding: ImageAnimation
** Generated automatically by tolua++-1.0.92 on Tue Sep 26 00:56:19 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ImageAnimation_open (lua_State* tolua_S);

#include"ImageAnimation.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ImageAnimation (lua_State* tolua_S)
{
 ImageAnimation* self = (ImageAnimation*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UIDrawRect");
 tolua_usertype(tolua_S,"ImageAnimation");
}

/* method: new of class  ImageAnimation */
#ifndef TOLUA_DISABLE_tolua_ImageAnimation_ImageAnimation_new00
static int tolua_ImageAnimation_ImageAnimation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ImageAnimation",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string varConfigPath = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float varSpeed = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   ImageAnimation* tolua_ret = (ImageAnimation*)  Mtolua_new((ImageAnimation)(varConfigPath,varSpeed));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ImageAnimation");
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

/* method: new_local of class  ImageAnimation */
#ifndef TOLUA_DISABLE_tolua_ImageAnimation_ImageAnimation_new00_local
static int tolua_ImageAnimation_ImageAnimation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ImageAnimation",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string varConfigPath = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  float varSpeed = ((float)  tolua_tonumber(tolua_S,3,0));
  {
   ImageAnimation* tolua_ret = (ImageAnimation*)  Mtolua_new((ImageAnimation)(varConfigPath,varSpeed));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ImageAnimation");
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

/* method: delete of class  ImageAnimation */
#ifndef TOLUA_DISABLE_tolua_ImageAnimation_ImageAnimation_delete00
static int tolua_ImageAnimation_ImageAnimation_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimation",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimation* self = (ImageAnimation*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Play of class  ImageAnimation */
#ifndef TOLUA_DISABLE_tolua_ImageAnimation_ImageAnimation_Play00
static int tolua_ImageAnimation_ImageAnimation_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimation",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimation* self = (ImageAnimation*)  tolua_tousertype(tolua_S,1,0);
  std::string varClipName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
  {
   self->Play(varClipName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  ImageAnimation */
#ifndef TOLUA_DISABLE_tolua_ImageAnimation_ImageAnimation_SetPosition00
static int tolua_ImageAnimation_ImageAnimation_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimation* self = (ImageAnimation*)  tolua_tousertype(tolua_S,1,0);
  float varPosX = ((float)  tolua_tonumber(tolua_S,2,0));
  float varPosY = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(varPosX,varPosY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetScale of class  ImageAnimation */
#ifndef TOLUA_DISABLE_tolua_ImageAnimation_ImageAnimation_SetScale00
static int tolua_ImageAnimation_ImageAnimation_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimation",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimation* self = (ImageAnimation*)  tolua_tousertype(tolua_S,1,0);
  float varScaleX = ((float)  tolua_tonumber(tolua_S,2,0));
  float varScaleY = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetScale'", NULL);
#endif
  {
   self->SetScale(varScaleX,varScaleY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetScale'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_ImageAnimation_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ImageAnimation","ImageAnimation","UIDrawRect",tolua_collect_ImageAnimation);
  #else
  tolua_cclass(tolua_S,"ImageAnimation","ImageAnimation","UIDrawRect",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ImageAnimation");
   tolua_function(tolua_S,"new",tolua_ImageAnimation_ImageAnimation_new00);
   tolua_function(tolua_S,"new_local",tolua_ImageAnimation_ImageAnimation_new00_local);
   tolua_function(tolua_S,".call",tolua_ImageAnimation_ImageAnimation_new00_local);
   tolua_function(tolua_S,"delete",tolua_ImageAnimation_ImageAnimation_delete00);
   tolua_function(tolua_S,"Play",tolua_ImageAnimation_ImageAnimation_Play00);
   tolua_function(tolua_S,"SetPosition",tolua_ImageAnimation_ImageAnimation_SetPosition00);
   tolua_function(tolua_S,"SetScale",tolua_ImageAnimation_ImageAnimation_SetScale00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ImageAnimation (lua_State* tolua_S) {
 return tolua_ImageAnimation_open(tolua_S);
};
#endif

