/*
** Lua binding: BinaryPacker
** Generated automatically by tolua++-1.0.92 on Tue Sep 12 01:10:03 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_BinaryPacker_open (lua_State* tolua_S);

#include"BinaryPacker.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_BinaryPacker (lua_State* tolua_S)
{
 BinaryPacker* self = (BinaryPacker*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"BinaryPacker");
}

/* method: new of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_new00
static int tolua_BinaryPacker_BinaryPacker_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BinaryPacker* tolua_ret = (BinaryPacker*)  Mtolua_new((BinaryPacker)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BinaryPacker");
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

/* method: new_local of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_new00_local
static int tolua_BinaryPacker_BinaryPacker_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BinaryPacker* tolua_ret = (BinaryPacker*)  Mtolua_new((BinaryPacker)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BinaryPacker");
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

/* method: delete of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_delete00
static int tolua_BinaryPacker_BinaryPacker_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
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

/* method: Malloc of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_Malloc00
static int tolua_BinaryPacker_BinaryPacker_Malloc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
  int varSize = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Malloc'", NULL);
#endif
  {
   self->Malloc(varSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Malloc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PushInt of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_PushInt00
static int tolua_BinaryPacker_BinaryPacker_PushInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
  int varValue = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PushInt'", NULL);
#endif
  {
   self->PushInt(varValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PushFloat of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_PushFloat00
static int tolua_BinaryPacker_BinaryPacker_PushFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
  float varValue = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PushFloat'", NULL);
#endif
  {
   self->PushFloat(varValue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PushFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBinaryCache of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_GetBinaryCache00
static int tolua_BinaryPacker_BinaryPacker_GetBinaryCache00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBinaryCache'", NULL);
#endif
  {
   char* tolua_ret = (char*)  self->GetBinaryCache();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBinaryCache'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBinaryCacheSize of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_GetBinaryCacheSize00
static int tolua_BinaryPacker_BinaryPacker_GetBinaryCacheSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBinaryCacheSize'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetBinaryCacheSize();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBinaryCacheSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBinaryCache of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_SetBinaryCache00
static int tolua_BinaryPacker_BinaryPacker_SetBinaryCache00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
  char* varBinaryCache = ((char*)  tolua_tostring(tolua_S,2,0));
  int varSize = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBinaryCache'", NULL);
#endif
  {
   self->SetBinaryCache(varBinaryCache,varSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBinaryCache'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PopInt of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_PopInt00
static int tolua_BinaryPacker_BinaryPacker_PopInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PopInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->PopInt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PopFloat of class  BinaryPacker */
#ifndef TOLUA_DISABLE_tolua_BinaryPacker_BinaryPacker_PopFloat00
static int tolua_BinaryPacker_BinaryPacker_PopFloat00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BinaryPacker",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BinaryPacker* self = (BinaryPacker*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PopFloat'", NULL);
#endif
  {
   float tolua_ret = (float)  self->PopFloat();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PopFloat'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_BinaryPacker_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"BinaryPacker","BinaryPacker","",tolua_collect_BinaryPacker);
  #else
  tolua_cclass(tolua_S,"BinaryPacker","BinaryPacker","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"BinaryPacker");
   tolua_function(tolua_S,"new",tolua_BinaryPacker_BinaryPacker_new00);
   tolua_function(tolua_S,"new_local",tolua_BinaryPacker_BinaryPacker_new00_local);
   tolua_function(tolua_S,".call",tolua_BinaryPacker_BinaryPacker_new00_local);
   tolua_function(tolua_S,"delete",tolua_BinaryPacker_BinaryPacker_delete00);
   tolua_function(tolua_S,"Malloc",tolua_BinaryPacker_BinaryPacker_Malloc00);
   tolua_function(tolua_S,"PushInt",tolua_BinaryPacker_BinaryPacker_PushInt00);
   tolua_function(tolua_S,"PushFloat",tolua_BinaryPacker_BinaryPacker_PushFloat00);
   tolua_function(tolua_S,"GetBinaryCache",tolua_BinaryPacker_BinaryPacker_GetBinaryCache00);
   tolua_function(tolua_S,"GetBinaryCacheSize",tolua_BinaryPacker_BinaryPacker_GetBinaryCacheSize00);
   tolua_function(tolua_S,"SetBinaryCache",tolua_BinaryPacker_BinaryPacker_SetBinaryCache00);
   tolua_function(tolua_S,"PopInt",tolua_BinaryPacker_BinaryPacker_PopInt00);
   tolua_function(tolua_S,"PopFloat",tolua_BinaryPacker_BinaryPacker_PopFloat00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_BinaryPacker (lua_State* tolua_S) {
 return tolua_BinaryPacker_open(tolua_S);
};
#endif

