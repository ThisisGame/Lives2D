/*
** Lua binding: UIImage
** Generated automatically by tolua++-1.0.92 on Wed Jan 17 21:34:48 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Image_open (lua_State* tolua_S);

#include"UIImage.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Image (lua_State* tolua_S)
{
 UIImage* self = (UIImage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UIDrawRect");
 tolua_usertype(tolua_S,"UIImage");
}

/* method: new of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_new00
static int tolua_Image_Image_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIImage* tolua_ret = (UIImage*)  Mtolua_new((UIImage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIImage");
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

/* method: new_local of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_new00_local
static int tolua_Image_Image_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIImage* tolua_ret = (UIImage*)  Mtolua_new((UIImage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIImage");
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

/* method: delete of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_delete00
static int tolua_Image_Image_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIImage* self = (UIImage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Init of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_Init00
static int tolua_Image_Image_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIImage* self = (UIImage*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init(varFilePath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_Init01
static int tolua_Image_Image_Init01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UIImage* self = (UIImage*)  tolua_tousertype(tolua_S,1,0);
  const char* varFilePath = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool varReceiveLightEffect = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init(varFilePath,varReceiveLightEffect);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Image_Image_Init00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Draw of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_Draw00
static int tolua_Image_Image_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIImage* self = (UIImage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetPosition of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_SetPosition00
static int tolua_Image_Image_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIImage* self = (UIImage*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetScale of class  UIImage */
#ifndef TOLUA_DISABLE_tolua_Image_Image_SetScale00
static int tolua_Image_Image_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIImage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIImage* self = (UIImage*)  tolua_tousertype(tolua_S,1,0);
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
TOLUA_API int tolua_Image_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIImage","UIImage","UIDrawRect",tolua_collect_Image);
  #else
  tolua_cclass(tolua_S,"UIImage","UIImage","UIDrawRect",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIImage");
   tolua_function(tolua_S,"new",tolua_Image_Image_new00);
   tolua_function(tolua_S,"new_local",tolua_Image_Image_new00_local);
   tolua_function(tolua_S,".call",tolua_Image_Image_new00_local);
   tolua_function(tolua_S,"delete",tolua_Image_Image_delete00);
   tolua_function(tolua_S,"Init",tolua_Image_Image_Init00);
   tolua_function(tolua_S,"Init",tolua_Image_Image_Init01);
   tolua_function(tolua_S,"Draw",tolua_Image_Image_Draw00);
   tolua_function(tolua_S,"SetPosition",tolua_Image_Image_SetPosition00);
   tolua_function(tolua_S,"SetScale",tolua_Image_Image_SetScale00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Image (lua_State* tolua_S) {
 return tolua_Image_open(tolua_S);
};
#endif

