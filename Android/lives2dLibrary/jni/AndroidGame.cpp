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


#include<iostream>
#include<string>
#include<fstream>
#include"FreeImage.h"

#include<glm\glm.hpp>
#include<glm\gtc\matrix_transform.hpp>
#include<glm\gtx\transform2.hpp>
#include<glm\gtx\euler_angles.hpp>

extern "C"
{
	#import "lua.h"
	#import "lualib.h"
	#import "luaconf.h"
	#import "lauxlib.h"
}
#include"LuaEngine/LuaEngine.h"
#include"Tools\Application.h"

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>

std::string mSdCardPath;

extern "C" {
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj,jfloat deltaTime);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setSdCardPath(JNIEnv * env, jobject obj,jstring sdcardpath);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouch(JNIEnv * env, jobject obj,jint x, jint y);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouchRelease(JNIEnv * env, jobject obj,jint x, jint y);
};

bool initSuccess=false;

//初始化;
void onInit(int varWidth,int varHeight)
{
	glClearColor(0, 0, 0, 1);

	glViewport(0, 0, (GLsizei)varWidth, (GLsizei)varHeight);
	
	if(initSuccess)
	{
		return;
	}
	
	Application::ScreenWidth=varWidth;
	Application::ScreenHeight=varHeight;
	
	//LuaEngine Start
	LuaEngine::GetSingleton()->DoFile((Application::PersistentDataPath()+ "/Resources/Script/Engine/Lives2D.lua").c_str());

	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, varWidth);
		tolua_pushnumber(var_pLuaState, varHeight);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("Init",2, tmpFunction);
	
	initSuccess=true;
}

void update(float varDeltaTime)
{
	//Lives2D::Update(varDeltaTime);
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, varDeltaTime);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("Update", 1, tmpFunction);
}

//渲染函数;
void render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	LuaEngine::GetSingleton()->CallLuaFunction("Draw");
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
	onInit(width,height);
}


JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj,jfloat deltaTime)
{
	update(deltaTime);
	render();
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setSdCardPath(JNIEnv * env, jobject obj,jstring javaString)
{
	const char *nativeString = env->GetStringUTFChars(javaString, JNI_FALSE);

	// use your string
	LOGI("sdcardpath:%s",nativeString);

	Application::SetDataPath(nativeString);
	Application::SetPersistentDataPath(nativeString);

	env->ReleaseStringUTFChars(javaString, nativeString);
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouch(JNIEnv * env, jobject obj,jint x, jint y)
{
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, x);
		tolua_pushnumber(var_pLuaState, y);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("OnTouch", 2, tmpFunction);
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouchRelease(JNIEnv * env, jobject obj,jint x, jint y)
{
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, x);
		tolua_pushnumber(var_pLuaState, y);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("OnTouchRelease", 2, tmpFunction);
}