/*
** Lua binding: UIRoot
** Generated automatically by tolua++-1.0.92 on Sun Jan 28 23:44:03 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UIRoot_open (lua_State* tolua_S);

#include"UIRoot.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UIRoot (lua_State* tolua_S)
{
 UIRoot* self = (UIRoot*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Behavior");
 tolua_usertype(tolua_S,"UIRoot");
 tolua_usertype(tolua_S,"UIRect");
}

/* method: new of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_new00
static int tolua_UIRoot_UIRoot_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIRoot* tolua_ret = (UIRoot*)  Mtolua_new((UIRoot)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIRoot");
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

/* method: new_local of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_new00_local
static int tolua_UIRoot_UIRoot_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UIRoot* tolua_ret = (UIRoot*)  Mtolua_new((UIRoot)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UIRoot");
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

/* method: delete of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_delete00
static int tolua_UIRoot_UIRoot_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRoot* self = (UIRoot*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Update of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_Update00
static int tolua_UIRoot_UIRoot_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRoot* self = (UIRoot*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Draw of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_Draw00
static int tolua_UIRoot_UIRoot_Draw00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRoot* self = (UIRoot*)  tolua_tousertype(tolua_S,1,0);
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

/* method: AddChild of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_AddChild00
static int tolua_UIRoot_UIRoot_AddChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UIRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRoot* self = (UIRoot*)  tolua_tousertype(tolua_S,1,0);
  UIRect* varUIRect = ((UIRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddChild'", NULL);
#endif
  {
   self->AddChild(varUIRect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveChild of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_RemoveChild00
static int tolua_UIRoot_UIRoot_RemoveChild00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"UIRect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRoot* self = (UIRoot*)  tolua_tousertype(tolua_S,1,0);
  UIRect* varUIRect = ((UIRect*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveChild'", NULL);
#endif
  {
   self->RemoveChild(varUIRect);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveChild'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Sort of class  UIRoot */
#ifndef TOLUA_DISABLE_tolua_UIRoot_UIRoot_Sort00
static int tolua_UIRoot_UIRoot_Sort00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UIRoot",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UIRoot* self = (UIRoot*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Sort'", NULL);
#endif
  {
   self->Sort();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Sort'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_UIRoot_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UIRoot","UIRoot","Behavior",tolua_collect_UIRoot);
  #else
  tolua_cclass(tolua_S,"UIRoot","UIRoot","Behavior",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UIRoot");
   tolua_function(tolua_S,"new",tolua_UIRoot_UIRoot_new00);
   tolua_function(tolua_S,"new_local",tolua_UIRoot_UIRoot_new00_local);
   tolua_function(tolua_S,".call",tolua_UIRoot_UIRoot_new00_local);
   tolua_function(tolua_S,"delete",tolua_UIRoot_UIRoot_delete00);
   tolua_function(tolua_S,"Update",tolua_UIRoot_UIRoot_Update00);
   tolua_function(tolua_S,"Draw",tolua_UIRoot_UIRoot_Draw00);
   tolua_function(tolua_S,"AddChild",tolua_UIRoot_UIRoot_AddChild00);
   tolua_function(tolua_S,"RemoveChild",tolua_UIRoot_UIRoot_RemoveChild00);
   tolua_function(tolua_S,"Sort",tolua_UIRoot_UIRoot_Sort00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UIRoot (lua_State* tolua_S) {
 return tolua_UIRoot_open(tolua_S);
};
#endif

