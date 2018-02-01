/*
** Lua binding: UIButton
** Generated automatically by tolua++-1.0.92 on Thu Feb  1 17:18:31 2018.
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
 tolua_usertype(tolua_S,"UIClickRect");
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
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIButton* tolua_ret = (UIButton*)  Mtolua_new((UIButton)());
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
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIButton* tolua_ret = (UIButton*)  Mtolua_new((UIButton)());
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

/* method: delete of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_delete00
static int tolua_UIButton_UIButton_delete00(lua_State* tolua_S)
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

/* method: Init of class  UIButton */
#ifndef TOLUA_DISABLE_tolua_UIButton_UIButton_Init00
static int tolua_UIButton_UIButton_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIButton",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIButton* self = (UIButton*)  tolua_tousertype(tolua_S,1,0);
  std::string varNormalImagePath = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string varClickDownImagePath = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  float varWidth = ((float)  tolua_tonumber(tolua_S,4,0));
  float varHeight = ((float)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init(varNormalImagePath,varClickDownImagePath,varWidth,varHeight);
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

/* Open function */
TOLUA_API int tolua_UIButton_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIButton","UIButton","UIClickRect",tolua_collect_UIButton);
  #else
  tolua_cclass(tolua_S,"UIButton","UIButton","UIClickRect",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIButton");
   tolua_function(tolua_S,"new",tolua_UIButton_UIButton_new00);
   tolua_function(tolua_S,"new_local",tolua_UIButton_UIButton_new00_local);
   tolua_function(tolua_S,".call",tolua_UIButton_UIButton_new00_local);
   tolua_function(tolua_S,"delete",tolua_UIButton_UIButton_delete00);
   tolua_function(tolua_S,"Init",tolua_UIButton_UIButton_Init00);
   tolua_function(tolua_S,"SetOnClickListener",tolua_UIButton_UIButton_SetOnClickListener00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UIButton (lua_State* tolua_S) {
 return tolua_UIButton_open(tolua_S);
};
#endif

