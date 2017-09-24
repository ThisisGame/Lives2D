/*
** Lua binding: UIButton
** Generated automatically by tolua++-1.0.92 on Mon Sep 25 01:11:31 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UIButton_open (lua_State* tolua_S);

#include"UIButton.h"  

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UIButton (lua_State* tolua_S)
{
 UIButton* self = (UIButton*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UIButton");
}

/* method: new of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_new00
static int tolua_UIButton_UIButton_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string varNormalImagePath = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string varClickDownImagePath = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  float varPosX = ((float)  tolua_tonumber(tolua_S,4,0));
  float varPosY = ((float)  tolua_tonumber(tolua_S,5,0));
  float varWidth = ((float)  tolua_tonumber(tolua_S,6,0));
  float varHeight = ((float)  tolua_tonumber(tolua_S,7,0));
  {
   UIButton* tolua_ret = (UIButton*)  Mtolua_new((UIButton)(varNormalImagePath,varClickDownImagePath,varPosX,varPosY,varWidth,varHeight));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIButton");
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

/* method: new_local of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_new00_local
static int tolua_UIButton_UIButton_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,7,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string varNormalImagePath = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string varClickDownImagePath = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  float varPosX = ((float)  tolua_tonumber(tolua_S,4,0));
  float varPosY = ((float)  tolua_tonumber(tolua_S,5,0));
  float varWidth = ((float)  tolua_tonumber(tolua_S,6,0));
  float varHeight = ((float)  tolua_tonumber(tolua_S,7,0));
  {
   UIButton* tolua_ret = (UIButton*)  Mtolua_new((UIButton)(varNormalImagePath,varClickDownImagePath,varPosX,varPosY,varWidth,varHeight));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIButton");
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

/* method: SetOnClickListener of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_SetOnClickListener00
static int tolua_UIButton_UIButton_SetOnClickListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButton* self = (UIButton*)  tolua_tousertype(tolua_S,1,0);
  lua_State* varlua_State =  tolua_S;
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetOnClickListener'", NULL);
#endif
  {
   self->SetOnClickListener(varlua_State);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetOnClickListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_Update00
static int tolua_UIButton_UIButton_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButton* self = (UIButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Draw of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_Draw00
static int tolua_UIButton_UIButton_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButton* self = (UIButton*)  tolua_tousertype(tolua_S,1,0);
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

/* method: OnTouchClickRect of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_OnTouchClickRect00
static int tolua_UIButton_UIButton_OnTouchClickRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButton* self = (UIButton*)  tolua_tousertype(tolua_S,1,0);
  float varX = ((float)  tolua_tonumber(tolua_S,2,0));
  float varY = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnTouchClickRect'", NULL);
#endif
  {
   self->OnTouchClickRect(varX,varY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnTouchClickRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnTouchReleaseClickRect of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_OnTouchReleaseClickRect00
static int tolua_UIButton_UIButton_OnTouchReleaseClickRect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButton* self = (UIButton*)  tolua_tousertype(tolua_S,1,0);
  float varX = ((float)  tolua_tonumber(tolua_S,2,0));
  float varY = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnTouchReleaseClickRect'", NULL);
#endif
  {
   self->OnTouchReleaseClickRect(varX,varY);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnTouchReleaseClickRect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_UIButton_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIButton","UIButton","",tolua_collect_UIButton);
  #else
  tolua_cclass(tolua_S,"UIButton","UIButton","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIButton");
   tolua_function(tolua_S,"new",tolua_UIButton_UIButton_new00);
   tolua_function(tolua_S,"new_local",tolua_UIButton_UIButton_new00_local);
   tolua_function(tolua_S,".call",tolua_UIButton_UIButton_new00_local);
   tolua_function(tolua_S,"SetOnClickListener",tolua_UIButton_UIButton_SetOnClickListener00);
   tolua_function(tolua_S,"Update",tolua_UIButton_UIButton_Update00);
   tolua_function(tolua_S,"Draw",tolua_UIButton_UIButton_Draw00);
   tolua_function(tolua_S,"OnTouchClickRect",tolua_UIButton_UIButton_OnTouchClickRect00);
   tolua_function(tolua_S,"OnTouchReleaseClickRect",tolua_UIButton_UIButton_OnTouchReleaseClickRect00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UIButton (lua_State* tolua_S) {
 return tolua_UIButton_open(tolua_S);
};
#endif

