/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// OpenGL ES 2.0 code

#include <jni.h>
#include <android/log.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define  LOG_TAG    "Lives2D"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

extern "C"
{
	#import "lua.h"
	#import "lualib.h"
	#import "luaconf.h"
	#import "lauxlib.h"
}


extern "C" {
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj);
};

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
	lua_State* p_Lua_State=luaL_newstate();
	luaL_openlibs(p_Lua_State);
	luaL_dostring(p_Lua_State, "print 'init'");
	lua_close(p_Lua_State);
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj)
{

}
