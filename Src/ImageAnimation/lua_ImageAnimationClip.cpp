/*
** Lua binding: ImageAnimationClip
** Generated automatically by tolua++-1.0.92 on Tue Sep 26 00:55:27 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_ImageAnimationClip_open (lua_State* tolua_S);

#include"ImageAnimationClip.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_ImageAnimationClip (lua_State* tolua_S)
{
 ImageAnimationClip* self = (ImageAnimationClip*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ImageAnimationClip");
 tolua_usertype(tolua_S,"std::vector<std::string>");
}

/* method: GetClipName of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_GetClipName00
static int tolua_ImageAnimationClip_ImageAnimationClip_GetClipName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClipName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->GetClipName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClipName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_new00
static int tolua_ImageAnimationClip_ImageAnimationClip_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string varClipName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::vector<std::string> varVectorFrameImagePath = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,3,0));
  int varKeyFrameCount = ((int)  tolua_tonumber(tolua_S,4,0));
  float varSpeed = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   ImageAnimationClip* tolua_ret = (ImageAnimationClip*)  Mtolua_new((ImageAnimationClip)(varClipName,varVectorFrameImagePath,varKeyFrameCount,varSpeed));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ImageAnimationClip");
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

/* method: new_local of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_new00_local
static int tolua_ImageAnimationClip_ImageAnimationClip_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string varClipName = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::vector<std::string> varVectorFrameImagePath = *((std::vector<std::string>*)  tolua_tousertype(tolua_S,3,0));
  int varKeyFrameCount = ((int)  tolua_tonumber(tolua_S,4,0));
  float varSpeed = ((float)  tolua_tonumber(tolua_S,5,0));
  {
   ImageAnimationClip* tolua_ret = (ImageAnimationClip*)  Mtolua_new((ImageAnimationClip)(varClipName,varVectorFrameImagePath,varKeyFrameCount,varSpeed));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ImageAnimationClip");
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

/* method: delete of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_delete00
static int tolua_ImageAnimationClip_ImageAnimationClip_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Update of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_Update00
static int tolua_ImageAnimationClip_ImageAnimationClip_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
  float varDeltaTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(varDeltaTime);
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

/* method: Draw of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_Draw00
static int tolua_ImageAnimationClip_ImageAnimationClip_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Draw'", NULL);
#endif
  {
   self->Draw();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Draw'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_Play00
static int tolua_ImageAnimationClip_ImageAnimationClip_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
  {
   self->Play();
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

/* method: Stop of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_Stop00
static int tolua_ImageAnimationClip_ImageAnimationClip_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Stop'", NULL);
#endif
  {
   self->Stop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Stop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_SetPosition00
static int tolua_ImageAnimationClip_ImageAnimationClip_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetScale of class  ImageAnimationClip */
#ifndef TOLUA_DISABLE_tolua_ImageAnimationClip_ImageAnimationClip_SetScale00
static int tolua_ImageAnimationClip_ImageAnimationClip_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageAnimationClip",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageAnimationClip* self = (ImageAnimationClip*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_ImageAnimationClip_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"ImageAnimationClip","ImageAnimationClip","",tolua_collect_ImageAnimationClip);
  #else
  tolua_cclass(tolua_S,"ImageAnimationClip","ImageAnimationClip","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"ImageAnimationClip");
   tolua_function(tolua_S,"GetClipName",tolua_ImageAnimationClip_ImageAnimationClip_GetClipName00);
   tolua_function(tolua_S,"new",tolua_ImageAnimationClip_ImageAnimationClip_new00);
   tolua_function(tolua_S,"new_local",tolua_ImageAnimationClip_ImageAnimationClip_new00_local);
   tolua_function(tolua_S,".call",tolua_ImageAnimationClip_ImageAnimationClip_new00_local);
   tolua_function(tolua_S,"delete",tolua_ImageAnimationClip_ImageAnimationClip_delete00);
   tolua_function(tolua_S,"Update",tolua_ImageAnimationClip_ImageAnimationClip_Update00);
   tolua_function(tolua_S,"Draw",tolua_ImageAnimationClip_ImageAnimationClip_Draw00);
   tolua_function(tolua_S,"Play",tolua_ImageAnimationClip_ImageAnimationClip_Play00);
   tolua_function(tolua_S,"Stop",tolua_ImageAnimationClip_ImageAnimationClip_Stop00);
   tolua_function(tolua_S,"SetPosition",tolua_ImageAnimationClip_ImageAnimationClip_SetPosition00);
   tolua_function(tolua_S,"SetScale",tolua_ImageAnimationClip_ImageAnimationClip_SetScale00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_ImageAnimationClip (lua_State* tolua_S) {
 return tolua_ImageAnimationClip_open(tolua_S);
};
#endif

