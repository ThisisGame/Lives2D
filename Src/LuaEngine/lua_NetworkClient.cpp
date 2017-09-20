/*
** Lua binding: NetworkClient
** Generated automatically by tolua++-1.0.92 on Tue Sep 12 02:22:13 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_NetworkClient_open (lua_State* tolua_S);

#include"NetworkClient.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NetworkClient");
 tolua_usertype(tolua_S,"BinaryPacker");
}

/* method: GetSingleton of class  NetworkClient */
#ifndef TOLUA_DISABLE_tolua_NetworkClient_NetworkClient_GetSingleton00
static int tolua_NetworkClient_NetworkClient_GetSingleton00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NetworkClient",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NetworkClient* tolua_ret = (NetworkClient*)  NetworkClient::GetSingleton();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NetworkClient");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSingleton'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SendMessage of class  NetworkClient */
#ifndef TOLUA_DISABLE_tolua_NetworkClient_NetworkClient_SendMessage00
static int tolua_NetworkClient_NetworkClient_SendMessage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NetworkClient",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NetworkClient* self = (NetworkClient*)  tolua_tousertype(tolua_S,1,0);
  int varMsgID = ((int)  tolua_tonumber(tolua_S,2,0));
  BinaryPacker* var_pBinaryPacker = ((BinaryPacker*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SendMessage'", NULL);
#endif
  {
   self->SendMessage(varMsgID,var_pBinaryPacker);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SendMessage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_NetworkClient_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"NetworkClient","NetworkClient","",NULL);
  tolua_beginmodule(tolua_S,"NetworkClient");
   tolua_function(tolua_S,"GetSingleton",tolua_NetworkClient_NetworkClient_GetSingleton00);
   tolua_function(tolua_S,"SendMessage",tolua_NetworkClient_NetworkClient_SendMessage00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_NetworkClient (lua_State* tolua_S) {
 return tolua_NetworkClient_open(tolua_S);
};
#endif

