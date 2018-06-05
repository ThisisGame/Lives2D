/*
** Lua binding: UDPSocket
** Generated automatically by tolua++-1.0.92 on Sat Jun  2 00:48:50 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_UDPSocket_open (lua_State* tolua_S);

#include"UDPSocket.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_UDPSocket (lua_State* tolua_S)
{
 UDPSocket* self = (UDPSocket*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"UDPSocket");
 tolua_usertype(tolua_S,"SocketID");
}

/* method: new of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_new00
static int tolua_UDPSocket_UDPSocket_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UDPSocket* tolua_ret = (UDPSocket*)  Mtolua_new((UDPSocket)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UDPSocket");
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

/* method: new_local of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_new00_local
static int tolua_UDPSocket_UDPSocket_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   UDPSocket* tolua_ret = (UDPSocket*)  Mtolua_new((UDPSocket)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"UDPSocket");
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

/* method: delete of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_delete00
static int tolua_UDPSocket_UDPSocket_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Connect of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_Connect00
static int tolua_UDPSocket_UDPSocket_Connect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  char* varAddress = ((char*)  tolua_tostring(tolua_S,2,0));
  unsigned short varPort = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Connect'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Connect(varAddress,varPort);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Connect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Listen of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_Listen00
static int tolua_UDPSocket_UDPSocket_Listen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  char* varAddress = ((char*)  tolua_tostring(tolua_S,2,0));
  unsigned short varPort = ((unsigned short)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Listen'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Listen(varAddress,varPort);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Listen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetReceiveNewIncomingConnection of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_SetReceiveNewIncomingConnection00
static int tolua_UDPSocket_UDPSocket_SetReceiveNewIncomingConnection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReceiveNewIncomingConnection'", NULL);
#endif
  {
   self->SetReceiveNewIncomingConnection(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReceiveNewIncomingConnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetReceiveConnectAccepted of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_SetReceiveConnectAccepted00
static int tolua_UDPSocket_UDPSocket_SetReceiveConnectAccepted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReceiveConnectAccepted'", NULL);
#endif
  {
   self->SetReceiveConnectAccepted(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReceiveConnectAccepted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetReceiveNewPackListener of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_SetReceiveNewPackListener00
static int tolua_UDPSocket_UDPSocket_SetReceiveNewPackListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReceiveNewPackListener'", NULL);
#endif
  {
   self->SetReceiveNewPackListener(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReceiveNewPackListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetReceiveConnectionLost of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_SetReceiveConnectionLost00
static int tolua_UDPSocket_UDPSocket_SetReceiveConnectionLost00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* varLuaFunctionName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReceiveConnectionLost'", NULL);
#endif
  {
   self->SetReceiveConnectionLost(varLuaFunctionName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReceiveConnectionLost'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_Update00
static int tolua_UDPSocket_UDPSocket_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
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

/* method: Send of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_Send00
static int tolua_UDPSocket_UDPSocket_Send00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  const char* varJson = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Send'", NULL);
#endif
  {
   self->Send(varJson);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Send'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Send of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_Send01
static int tolua_UDPSocket_UDPSocket_Send01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SocketID",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  SocketID* var_pSocketID = ((SocketID*)  tolua_tousertype(tolua_S,2,0));
  const char* varJson = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Send'", NULL);
#endif
  {
   self->Send(var_pSocketID,varJson);
  }
 }
 return 0;
tolua_lerror:
 return tolua_UDPSocket_UDPSocket_Send00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CloseConnection of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_CloseConnection00
static int tolua_UDPSocket_UDPSocket_CloseConnection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SocketID",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
  SocketID* var_pSocketID = ((SocketID*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CloseConnection'", NULL);
#endif
  {
   self->CloseConnection(var_pSocketID);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CloseConnection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Stop of class  UDPSocket */
#ifndef TOLUA_DISABLE_tolua_UDPSocket_UDPSocket_Stop00
static int tolua_UDPSocket_UDPSocket_Stop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"UDPSocket",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  UDPSocket* self = (UDPSocket*)  tolua_tousertype(tolua_S,1,0);
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

/* Open function */
TOLUA_API int tolua_UDPSocket_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"UDPSocket","UDPSocket","",tolua_collect_UDPSocket);
  #else
  tolua_cclass(tolua_S,"UDPSocket","UDPSocket","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"UDPSocket");
   tolua_function(tolua_S,"new",tolua_UDPSocket_UDPSocket_new00);
   tolua_function(tolua_S,"new_local",tolua_UDPSocket_UDPSocket_new00_local);
   tolua_function(tolua_S,".call",tolua_UDPSocket_UDPSocket_new00_local);
   tolua_function(tolua_S,"delete",tolua_UDPSocket_UDPSocket_delete00);
   tolua_function(tolua_S,"Connect",tolua_UDPSocket_UDPSocket_Connect00);
   tolua_function(tolua_S,"Listen",tolua_UDPSocket_UDPSocket_Listen00);
   tolua_function(tolua_S,"SetReceiveNewIncomingConnection",tolua_UDPSocket_UDPSocket_SetReceiveNewIncomingConnection00);
   tolua_function(tolua_S,"SetReceiveConnectAccepted",tolua_UDPSocket_UDPSocket_SetReceiveConnectAccepted00);
   tolua_function(tolua_S,"SetReceiveNewPackListener",tolua_UDPSocket_UDPSocket_SetReceiveNewPackListener00);
   tolua_function(tolua_S,"SetReceiveConnectionLost",tolua_UDPSocket_UDPSocket_SetReceiveConnectionLost00);
   tolua_function(tolua_S,"Update",tolua_UDPSocket_UDPSocket_Update00);
   tolua_function(tolua_S,"Send",tolua_UDPSocket_UDPSocket_Send00);
   tolua_function(tolua_S,"Send",tolua_UDPSocket_UDPSocket_Send01);
   tolua_function(tolua_S,"CloseConnection",tolua_UDPSocket_UDPSocket_CloseConnection00);
   tolua_function(tolua_S,"Stop",tolua_UDPSocket_UDPSocket_Stop00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_UDPSocket (lua_State* tolua_S) {
 return tolua_UDPSocket_open(tolua_S);
};
#endif

