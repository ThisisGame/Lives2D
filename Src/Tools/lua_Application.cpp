/*
** Lua binding: Application
** Generated automatically by tolua++-1.0.92 on Tue Oct  3 17:43:44 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Application_open (lua_State* tolua_S);

#include"Application.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Application");
}

/* get function: ScreenWidth of class  Application */
#ifndef TOLUA_DISABLE_tolua_get_Application_ScreenWidth
static int tolua_get_Application_ScreenWidth(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Application::ScreenWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ScreenWidth of class  Application */
#ifndef TOLUA_DISABLE_tolua_set_Application_ScreenWidth
static int tolua_set_Application_ScreenWidth(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Application::ScreenWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ScreenHeight of class  Application */
#ifndef TOLUA_DISABLE_tolua_get_Application_ScreenHeight
static int tolua_get_Application_ScreenHeight(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Application::ScreenHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ScreenHeight of class  Application */
#ifndef TOLUA_DISABLE_tolua_set_Application_ScreenHeight
static int tolua_set_Application_ScreenHeight(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Application::ScreenHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DesignWidth of class  Application */
#ifndef TOLUA_DISABLE_tolua_get_Application_DesignWidth
static int tolua_get_Application_DesignWidth(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Application::DesignWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DesignWidth of class  Application */
#ifndef TOLUA_DISABLE_tolua_set_Application_DesignWidth
static int tolua_set_Application_DesignWidth(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Application::DesignWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DesignHeight of class  Application */
#ifndef TOLUA_DISABLE_tolua_get_Application_DesignHeight
static int tolua_get_Application_DesignHeight(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Application::DesignHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: DesignHeight of class  Application */
#ifndef TOLUA_DISABLE_tolua_set_Application_DesignHeight
static int tolua_set_Application_DesignHeight(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Application::DesignHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RenderWidth of class  Application */
#ifndef TOLUA_DISABLE_tolua_get_Application_RenderWidth
static int tolua_get_Application_RenderWidth(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Application::RenderWidth);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: RenderWidth of class  Application */
#ifndef TOLUA_DISABLE_tolua_set_Application_RenderWidth
static int tolua_set_Application_RenderWidth(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Application::RenderWidth = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: RenderHeight of class  Application */
#ifndef TOLUA_DISABLE_tolua_get_Application_RenderHeight
static int tolua_get_Application_RenderHeight(lua_State* tolua_S)
{
  tolua_pushnumber(tolua_S,(lua_Number)Application::RenderHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: RenderHeight of class  Application */
#ifndef TOLUA_DISABLE_tolua_set_Application_RenderHeight
static int tolua_set_Application_RenderHeight(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  Application::RenderHeight = ((int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDataPath of class  Application */
#ifndef TOLUA_DISABLE_tolua_Application_Application_SetDataPath00
static int tolua_Application_Application_SetDataPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Application",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* varDataPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Application::SetDataPath(varDataPath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDataPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DataPath of class  Application */
#ifndef TOLUA_DISABLE_tolua_Application_Application_DataPath00
static int tolua_Application_Application_DataPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Application",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  Application::DataPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DataPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPersistentDataPath of class  Application */
#ifndef TOLUA_DISABLE_tolua_Application_Application_SetPersistentDataPath00
static int tolua_Application_Application_SetPersistentDataPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Application",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* varpersistentDataPath = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   Application::SetPersistentDataPath(varpersistentDataPath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPersistentDataPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PersistentDataPath of class  Application */
#ifndef TOLUA_DISABLE_tolua_Application_Application_PersistentDataPath00
static int tolua_Application_Application_PersistentDataPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Application",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  Application::PersistentDataPath();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PersistentDataPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Application_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"Application","Application","",NULL);
  tolua_beginmodule(tolua_S,"Application");
   tolua_variable(tolua_S,"ScreenWidth",tolua_get_Application_ScreenWidth,tolua_set_Application_ScreenWidth);
   tolua_variable(tolua_S,"ScreenHeight",tolua_get_Application_ScreenHeight,tolua_set_Application_ScreenHeight);
   tolua_variable(tolua_S,"DesignWidth",tolua_get_Application_DesignWidth,tolua_set_Application_DesignWidth);
   tolua_variable(tolua_S,"DesignHeight",tolua_get_Application_DesignHeight,tolua_set_Application_DesignHeight);
   tolua_variable(tolua_S,"RenderWidth",tolua_get_Application_RenderWidth,tolua_set_Application_RenderWidth);
   tolua_variable(tolua_S,"RenderHeight",tolua_get_Application_RenderHeight,tolua_set_Application_RenderHeight);
   tolua_function(tolua_S,"SetDataPath",tolua_Application_Application_SetDataPath00);
   tolua_function(tolua_S,"DataPath",tolua_Application_Application_DataPath00);
   tolua_function(tolua_S,"SetPersistentDataPath",tolua_Application_Application_SetPersistentDataPath00);
   tolua_function(tolua_S,"PersistentDataPath",tolua_Application_Application_PersistentDataPath00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Application (lua_State* tolua_S) {
 return tolua_Application_open(tolua_S);
};
#endif

