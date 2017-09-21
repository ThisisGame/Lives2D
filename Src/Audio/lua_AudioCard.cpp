/*
** Lua binding: AudioCard
** Generated automatically by tolua++-1.0.92 on Thu Sep 21 23:25:20 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_AudioCard_open (lua_State* tolua_S);

#include"AudioCard.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* function: AudioCardInit */
#ifndef TOLUA_DISABLE_tolua_AudioCard_AudioCardInit00
static int tolua_AudioCard_AudioCardInit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AudioCardInit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AudioCardInit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: AudioCardExit */
#ifndef TOLUA_DISABLE_tolua_AudioCard_AudioCardExit00
static int tolua_AudioCard_AudioCardExit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AudioCardExit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AudioCardExit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_AudioCard_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_function(tolua_S,"AudioCardInit",tolua_AudioCard_AudioCardInit00);
  tolua_function(tolua_S,"AudioCardExit",tolua_AudioCard_AudioCardExit00);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AudioCard (lua_State* tolua_S) {
 return tolua_AudioCard_open(tolua_S);
};
#endif

