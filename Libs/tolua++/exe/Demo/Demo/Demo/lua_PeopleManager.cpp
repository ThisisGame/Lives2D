/*
** Lua binding: PeopleManager
** Generated automatically by tolua++-1.0.92 on Sun Jul  9 14:29:53 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_PeopleManager_open (lua_State* tolua_S);

#include"Student.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_PeopleManager (lua_State* tolua_S)
{
 PeopleManager* self = (PeopleManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"PeopleManager");
}

/* method: new of class  PeopleManager */
#ifndef TOLUA_DISABLE_tolua_PeopleManager_PeopleManager_new00
static int tolua_PeopleManager_PeopleManager_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PeopleManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PeopleManager* tolua_ret = (PeopleManager*)  Mtolua_new((PeopleManager)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PeopleManager");
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

/* method: new_local of class  PeopleManager */
#ifndef TOLUA_DISABLE_tolua_PeopleManager_PeopleManager_new00_local
static int tolua_PeopleManager_PeopleManager_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"PeopleManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   PeopleManager* tolua_ret = (PeopleManager*)  Mtolua_new((PeopleManager)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"PeopleManager");
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

/* method: delete of class  PeopleManager */
#ifndef TOLUA_DISABLE_tolua_PeopleManager_PeopleManager_delete00
static int tolua_PeopleManager_PeopleManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PeopleManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PeopleManager* self = (PeopleManager*)  tolua_tousertype(tolua_S,1,0);
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

/* method: AddPeople of class  PeopleManager */
#ifndef TOLUA_DISABLE_tolua_PeopleManager_PeopleManager_AddPeople00
static int tolua_PeopleManager_PeopleManager_AddPeople00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"PeopleManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  PeopleManager* self = (PeopleManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPeople'", NULL);
#endif
  {
   self->AddPeople();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPeople'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_PeopleManager_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"PeopleManager","PeopleManager","",tolua_collect_PeopleManager);
  #else
  tolua_cclass(tolua_S,"PeopleManager","PeopleManager","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"PeopleManager");
   tolua_function(tolua_S,"new",tolua_PeopleManager_PeopleManager_new00);
   tolua_function(tolua_S,"new_local",tolua_PeopleManager_PeopleManager_new00_local);
   tolua_function(tolua_S,".call",tolua_PeopleManager_PeopleManager_new00_local);
   tolua_function(tolua_S,"delete",tolua_PeopleManager_PeopleManager_delete00);
   tolua_function(tolua_S,"AddPeople",tolua_PeopleManager_PeopleManager_AddPeople00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_PeopleManager (lua_State* tolua_S) {
 return tolua_PeopleManager_open(tolua_S);
};
#endif

