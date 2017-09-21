/*
** Lua binding: AudioSource
** Generated automatically by tolua++-1.0.92 on Sun Jul  9 13:35:50 2017.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_AudioSource_open (lua_State* tolua_S);

#include"AudioSource.h"  

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_AudioSource (lua_State* tolua_S)
{
 AudioSource* self = (AudioSource*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"AudioSource");
}

/* method: new of class  AudioSource */
#ifndef TOLUA_DISABLE_tolua_AudioSource_AudioSource_new00
static int tolua_AudioSource_AudioSource_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AudioSource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AudioSource* tolua_ret = (AudioSource*)  Mtolua_new((AudioSource)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AudioSource");
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

/* method: new_local of class  AudioSource */
#ifndef TOLUA_DISABLE_tolua_AudioSource_AudioSource_new00_local
static int tolua_AudioSource_AudioSource_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"AudioSource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   AudioSource* tolua_ret = (AudioSource*)  Mtolua_new((AudioSource)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"AudioSource");
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

/* method: delete of class  AudioSource */
#ifndef TOLUA_DISABLE_tolua_AudioSource_AudioSource_delete00
static int tolua_AudioSource_AudioSource_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioSource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioSource* self = (AudioSource*)  tolua_tousertype(tolua_S,1,0);
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

/* method: LoadAudio of class  AudioSource */
#ifndef TOLUA_DISABLE_tolua_AudioSource_AudioSource_LoadAudio00
static int tolua_AudioSource_AudioSource_LoadAudio00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioSource",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioSource* self = (AudioSource*)  tolua_tousertype(tolua_S,1,0);
  const char* varAudioPath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadAudio'", NULL);
#endif
  {
   self->LoadAudio(varAudioPath);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadAudio'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Play of class  AudioSource */
#ifndef TOLUA_DISABLE_tolua_AudioSource_AudioSource_Play00
static int tolua_AudioSource_AudioSource_Play00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioSource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioSource* self = (AudioSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Play'", NULL);
#endif
  {
   self->Play();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Play'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Loop of class  AudioSource */
#ifndef TOLUA_DISABLE_tolua_AudioSource_AudioSource_Loop00
static int tolua_AudioSource_AudioSource_Loop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"AudioSource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  AudioSource* self = (AudioSource*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Loop'", NULL);
#endif
  {
   self->Loop();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Loop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_AudioSource_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"AudioSource","AudioSource","",tolua_collect_AudioSource);
  #else
  tolua_cclass(tolua_S,"AudioSource","AudioSource","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"AudioSource");
   tolua_function(tolua_S,"new",tolua_AudioSource_AudioSource_new00);
   tolua_function(tolua_S,"new_local",tolua_AudioSource_AudioSource_new00_local);
   tolua_function(tolua_S,".call",tolua_AudioSource_AudioSource_new00_local);
   tolua_function(tolua_S,"delete",tolua_AudioSource_AudioSource_delete00);
   tolua_function(tolua_S,"LoadAudio",tolua_AudioSource_AudioSource_LoadAudio00);
   tolua_function(tolua_S,"Play",tolua_AudioSource_AudioSource_Play00);
   tolua_function(tolua_S,"Loop",tolua_AudioSource_AudioSource_Loop00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_AudioSource (lua_State* tolua_S) {
 return tolua_AudioSource_open(tolua_S);
};
#endif

