/*
** Lua binding: Rigidbody
** Generated automatically by tolua++-1.0.92 on Sun May  6 11:45:49 2018.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_Rigidbody_open (lua_State* tolua_S);

#include"Rigidbody.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Rigidbody (lua_State* tolua_S)
{
 Rigidbody* self = (Rigidbody*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"Component");
 tolua_usertype(tolua_S,"Rigidbody");
}

/* method: new of class  Rigidbody */
#ifndef TOLUA_DISABLE_tolua_Rigidbody_Rigidbody_new00
static int tolua_Rigidbody_Rigidbody_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rigidbody",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Rigidbody* tolua_ret = (Rigidbody*)  Mtolua_new((Rigidbody)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rigidbody");
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

/* method: new_local of class  Rigidbody */
#ifndef TOLUA_DISABLE_tolua_Rigidbody_Rigidbody_new00_local
static int tolua_Rigidbody_Rigidbody_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Rigidbody",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Rigidbody* tolua_ret = (Rigidbody*)  Mtolua_new((Rigidbody)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Rigidbody");
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

/* method: delete of class  Rigidbody */
#ifndef TOLUA_DISABLE_tolua_Rigidbody_Rigidbody_delete00
static int tolua_Rigidbody_Rigidbody_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Rigidbody",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Rigidbody* self = (Rigidbody*)  tolua_tousertype(tolua_S,1,0);
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

/* method: SetCollisionShape of class  Rigidbody */
#ifndef TOLUA_DISABLE_tolua_Rigidbody_Rigidbody_SetCollisionShape00
static int tolua_Rigidbody_Rigidbody_SetCollisionShape00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Rigidbody",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,6,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Rigidbody* self = (Rigidbody*)  tolua_tousertype(tolua_S,1,0);
  int varRigidbodyShape = ((int)  tolua_tonumber(tolua_S,2,0));
  int varMass = ((int)  tolua_tonumber(tolua_S,3,0));
  float varX = ((float)  tolua_tonumber(tolua_S,4,0));
  float varY = ((float)  tolua_tonumber(tolua_S,5,0));
  float varZ = ((float)  tolua_tonumber(tolua_S,6,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCollisionShape'", NULL);
#endif
  {
   self->SetCollisionShape(varRigidbodyShape,varMass,varX,varY,varZ);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCollisionShape'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Rigidbody_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"Rigidbody","Rigidbody","Component",tolua_collect_Rigidbody);
  #else
  tolua_cclass(tolua_S,"Rigidbody","Rigidbody","Component",NULL);
  #endif
  tolua_beginmodule(tolua_S,"Rigidbody");
   tolua_function(tolua_S,"new",tolua_Rigidbody_Rigidbody_new00);
   tolua_function(tolua_S,"new_local",tolua_Rigidbody_Rigidbody_new00_local);
   tolua_function(tolua_S,".call",tolua_Rigidbody_Rigidbody_new00_local);
   tolua_function(tolua_S,"delete",tolua_Rigidbody_Rigidbody_delete00);
   tolua_function(tolua_S,"SetCollisionShape",tolua_Rigidbody_Rigidbody_SetCollisionShape00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Rigidbody (lua_State* tolua_S) {
 return tolua_Rigidbody_open(tolua_S);
};
#endif

