/*
** Lua binding: UILabel
** Generated automatically by tolua++-1.0.92 on Sun Mar  4 20:55:42 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UILabel_open (lua_State* tolua_S);

#include"UILabel.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UILabel (lua_State* tolua_S)
{
 UILabel* self = (UILabel*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UIDrawRect");
 tolua_usertype(tolua_S,"std::u32string");
 tolua_usertype(tolua_S,"UILabel");
}

/* get function: mPosX of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_get_UILabel_mPosX
static int tolua_get_UILabel_mPosX(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPosX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mPosX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mPosX of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_set_UILabel_mPosX
static int tolua_set_UILabel_mPosX(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPosX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mPosX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mPosY of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_get_UILabel_mPosY
static int tolua_get_UILabel_mPosY(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPosY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mPosY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mPosY of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_set_UILabel_mPosY
static int tolua_set_UILabel_mPosY(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mPosY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mPosY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mScaleX of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_get_UILabel_mScaleX
static int tolua_get_UILabel_mScaleX(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mScaleX'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mScaleX);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mScaleX of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_set_UILabel_mScaleX
static int tolua_set_UILabel_mScaleX(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mScaleX'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mScaleX = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mScaleY of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_get_UILabel_mScaleY
static int tolua_get_UILabel_mScaleY(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mScaleY'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mScaleY);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mScaleY of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_set_UILabel_mScaleY
static int tolua_set_UILabel_mScaleY(lua_State* tolua_S)
{
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mScaleY'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mScaleY = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_new00
static int tolua_UILabel_UILabel_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UILabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UILabel* tolua_ret = (UILabel*)  Mtolua_new((UILabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UILabel");
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

/* method: new_local of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_new00_local
static int tolua_UILabel_UILabel_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UILabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UILabel* tolua_ret = (UILabel*)  Mtolua_new((UILabel)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UILabel");
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

/* method: delete of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_delete00
static int tolua_UILabel_UILabel_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Init of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_Init00
static int tolua_UILabel_UILabel_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"std::u32string",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
  std::u32string* varText = ((std::u32string*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init(*varText);
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

/* method: SetPosition of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_SetPosition00
static int tolua_UILabel_UILabel_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetScale of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_SetScale00
static int tolua_UILabel_UILabel_SetScale00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetSpace of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_SetSpace00
static int tolua_UILabel_UILabel_SetSpace00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
  int varSpace = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSpace'", NULL);
#endif
  {
   self->SetSpace(varSpace);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSpace'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAlignCenter of class  UILabel */
#ifndef TOLUA_DISABLE_tolua_UILabel_UILabel_SetAlignCenter00
static int tolua_UILabel_UILabel_SetAlignCenter00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UILabel",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UILabel* self = (UILabel*)  tolua_tousertype(tolua_S,1,0);
  bool varAlignCenter = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAlignCenter'", NULL);
#endif
  {
   self->SetAlignCenter(varAlignCenter);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAlignCenter'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_UILabel_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UILabel","UILabel","UIDrawRect",tolua_collect_UILabel);
  #else
  tolua_cclass(tolua_S,"UILabel","UILabel","UIDrawRect",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UILabel");
   tolua_variable(tolua_S,"mPosX",tolua_get_UILabel_mPosX,tolua_set_UILabel_mPosX);
   tolua_variable(tolua_S,"mPosY",tolua_get_UILabel_mPosY,tolua_set_UILabel_mPosY);
   tolua_variable(tolua_S,"mScaleX",tolua_get_UILabel_mScaleX,tolua_set_UILabel_mScaleX);
   tolua_variable(tolua_S,"mScaleY",tolua_get_UILabel_mScaleY,tolua_set_UILabel_mScaleY);
   tolua_function(tolua_S,"new",tolua_UILabel_UILabel_new00);
   tolua_function(tolua_S,"new_local",tolua_UILabel_UILabel_new00_local);
   tolua_function(tolua_S,".call",tolua_UILabel_UILabel_new00_local);
   tolua_function(tolua_S,"delete",tolua_UILabel_UILabel_delete00);
   tolua_function(tolua_S,"Init",tolua_UILabel_UILabel_Init00);
   tolua_function(tolua_S,"SetPosition",tolua_UILabel_UILabel_SetPosition00);
   tolua_function(tolua_S,"SetScale",tolua_UILabel_UILabel_SetScale00);
   tolua_function(tolua_S,"SetSpace",tolua_UILabel_UILabel_SetSpace00);
   tolua_function(tolua_S,"SetAlignCenter",tolua_UILabel_UILabel_SetAlignCenter00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UILabel (lua_State* tolua_S) {
 return tolua_UILabel_open(tolua_S);
};
#endif

