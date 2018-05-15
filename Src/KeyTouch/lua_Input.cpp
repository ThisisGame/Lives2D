/*
** Lua binding: Input
** Generated automatically by tolua++-1.0.92 on Tue May 15 20:30:54 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Input_open (lua_State* tolua_S);

#include"Input.h"  

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Input (lua_State* tolua_S)
{
 Input* self = (Input*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Input");
 tolua_usertype(tolua_S,"Vector3");
}

/* method: new of class  Input */
#ifndef TOLUA_DISABLE_tolua_Input_Input_new00
static int tolua_Input_Input_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Input",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Input* tolua_ret = (Input*)  Mtolua_new((Input)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Input");
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

/* method: new_local of class  Input */
#ifndef TOLUA_DISABLE_tolua_Input_Input_new00_local
static int tolua_Input_Input_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Input",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Input* tolua_ret = (Input*)  Mtolua_new((Input)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Input");
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

/* method: delete of class  Input */
#ifndef TOLUA_DISABLE_tolua_Input_Input_delete00
static int tolua_Input_Input_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Input",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Input* self = (Input*)  tolua_tousertype(tolua_S,1,0);
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

/* get function: mousePosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_mousePosition
static int tolua_get_Input_mousePosition(lua_State* tolua_S)
{
   tolua_pushusertype(tolua_S,(void*)&Input::mousePosition,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mousePosition of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_mousePosition
static int tolua_set_Input_mousePosition(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Input::mousePosition = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: touchCount of class  Input */
#ifndef TOLUA_DISABLE_tolua_get_Input_touchCount
static int tolua_get_Input_touchCount(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Input::touchCount);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: touchCount of class  Input */
#ifndef TOLUA_DISABLE_tolua_set_Input_touchCount
static int tolua_set_Input_touchCount(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Input::touchCount = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Input_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Input","Input","",tolua_collect_Input);
  #else
  tolua_cclass(tolua_S,"Input","Input","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Input");
   tolua_function(tolua_S,"new",tolua_Input_Input_new00);
   tolua_function(tolua_S,"new_local",tolua_Input_Input_new00_local);
   tolua_function(tolua_S,".call",tolua_Input_Input_new00_local);
   tolua_function(tolua_S,"delete",tolua_Input_Input_delete00);
   tolua_variable(tolua_S,"mousePosition",tolua_get_Input_mousePosition,tolua_set_Input_mousePosition);
   tolua_variable(tolua_S,"touchCount",tolua_get_Input_touchCount,tolua_set_Input_touchCount);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Input (lua_State* tolua_S) {
 return tolua_Input_open(tolua_S);
};
#endif

