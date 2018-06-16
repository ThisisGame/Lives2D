/*
** Lua binding: Time
** Generated automatically by tolua++-1.0.92 on Sat Jun 16 15:05:08 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Time_open (lua_State* tolua_S);

#include"Time.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Time (lua_State* tolua_S)
{
 Time* self = (Time*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Time");
}

/* method: new of class  Time */
#ifndef TOLUA_DISABLE_tolua_Time_Time_new00
static int tolua_Time_Time_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Time* tolua_ret = (Time*)  Mtolua_new((Time)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Time");
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

/* method: new_local of class  Time */
#ifndef TOLUA_DISABLE_tolua_Time_Time_new00_local
static int tolua_Time_Time_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Time* tolua_ret = (Time*)  Mtolua_new((Time)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Time");
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

/* method: delete of class  Time */
#ifndef TOLUA_DISABLE_tolua_Time_Time_delete00
static int tolua_Time_Time_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Time",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Time* self = (Time*)  tolua_tousertype(tolua_S,1,0);
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

/* method: GetTimeMS of class  Time */
#ifndef TOLUA_DISABLE_tolua_Time_Time_GetTimeMS00
static int tolua_Time_Time_GetTimeMS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  Time::GetTimeMS();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeMS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimeUS_Str of class  Time */
#ifndef TOLUA_DISABLE_tolua_Time_Time_GetTimeUS_Str00
static int tolua_Time_Time_GetTimeUS_Str00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Time",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  Time::GetTimeUS_Str();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimeUS_Str'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: deltaTime of class  Time */
#ifndef TOLUA_DISABLE_tolua_get_Time_deltaTime
static int tolua_get_Time_deltaTime(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Time::deltaTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: deltaTime of class  Time */
#ifndef TOLUA_DISABLE_tolua_set_Time_deltaTime
static int tolua_set_Time_deltaTime(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Time::deltaTime = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Time_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Time","Time","",tolua_collect_Time);
  #else
  tolua_cclass(tolua_S,"Time","Time","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Time");
   tolua_function(tolua_S,"new",tolua_Time_Time_new00);
   tolua_function(tolua_S,"new_local",tolua_Time_Time_new00_local);
   tolua_function(tolua_S,".call",tolua_Time_Time_new00_local);
   tolua_function(tolua_S,"delete",tolua_Time_Time_delete00);
   tolua_function(tolua_S,"GetTimeMS",tolua_Time_Time_GetTimeMS00);
   tolua_function(tolua_S,"GetTimeUS_Str",tolua_Time_Time_GetTimeUS_Str00);
   tolua_variable(tolua_S,"deltaTime",tolua_get_Time_deltaTime,tolua_set_Time_deltaTime);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Time (lua_State* tolua_S) {
 return tolua_Time_open(tolua_S);
};
#endif

