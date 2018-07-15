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
#include"Tools/Application.h"
#include"Tools/Time.h"
#include"Audio/AudioCard.h"

#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include "JniHelper.h"

#include"RakNetTime.h"
#include"GetTime.h"
#include"Physics/PhysicsWorld.h"

std::string mSdCardPath;

extern "C" 
{
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setAssetManager(JNIEnv * env, jobject obj,  jobject assetManager);
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj,jfloat deltaTime);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setSdCardPath(JNIEnv * env, jobject obj,jstring sdcardpath);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouch(JNIEnv * env, jobject obj,jint x, jint y);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouchRelease(JNIEnv * env, jobject obj,jint x, jint y);
};


bool initSuccess=false;


extern void AudioCardInit();
static RakNet::TimeUS sFixedUpdateTime = 1000000 / 15;
//初始化;
void onInit(JNIEnv * env, jobject obj,  int varWidth,int varHeight)
{
	glClearColor(0, 0, 0, 1);

	glViewport(0, 0, (GLsizei)varWidth, (GLsizei)varHeight);
	
	if(initSuccess)
	{
		return;
	}
	
	AudioCard::AudioCardInit();
	
	Application::ScreenWidth=varWidth;
	Application::ScreenHeight=varHeight;
	

	//LuaEngine Start
	LuaEngine::GetSingleton()->DoFile((Application::PersistentDataPath()+ "/Resource/Script/Engine/Lives2D.lua").c_str());

	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, varWidth);
		tolua_pushnumber(var_pLuaState, varHeight);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("Init",2, tmpFunction);
	
	initSuccess=true;
	int fixedUpdateFrame=LuaEngine::GetSingleton()->GetGlobalViriable("fixedUpdateFrame");
	LOGI("lua fixedUpdateFrame:%d\n", fixedUpdateFrame);
	sFixedUpdateTime =1000000/ fixedUpdateFrame;
	LOGI("sFixedUpdateTime:%llu\n", sFixedUpdateTime);
}


void update(float varDeltaTime)
{
	static RakNet::TimeUS tmpFixedUpdateEndTime = RakNet::GetTimeUS() + sFixedUpdateTime;

	PhysicsWorld::Simulation();

	//Lives2D::Update(varDeltaTime);
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, varDeltaTime);
	};
	Time::deltaTime = varDeltaTime;
	LuaEngine::GetSingleton()->CallLuaFunction("Update", 1, tmpFunction);

	RakNet::TimeUS tmpCurrentTimeUS = RakNet::GetTimeUS();

	if (RakNet::GreaterThan(tmpCurrentTimeUS, tmpFixedUpdateEndTime))
	{
		RakNet::TimeUS tmpTimeUpdateCost=  tmpCurrentTimeUS- tmpFixedUpdateEndTime;//如果这一帧花费了很长时间，那么应该把FixedUpdate补回来，计算应该调用的次数

		int tmpFixedUpdateNeedCallTime = tmpTimeUpdateCost / sFixedUpdateTime;

		for (size_t i = 0; i < tmpFixedUpdateNeedCallTime; i++)
		{
			LuaEngine::GetSingleton()->CallLuaFunction("FixedUpdate");
		}

		if (tmpFixedUpdateNeedCallTime > 0)
		{
			int tmpTimeUSRemain = tmpTimeUpdateCost%sFixedUpdateTime;//调用多次后，仍然超出，但是又不足一个FixedUpdate，就把下一个FixedUpdate时间扣除一点

			tmpFixedUpdateEndTime = RakNet::GetTimeUS() + sFixedUpdateTime - tmpTimeUSRemain;
		}
	}
}

//渲染函数;
void render()
{
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	//保持画面比例 进行缩放 会出现黑边
	float tmpDesignRatio = (float)Application::DesignWidth / Application::DesignHeight;
	float tmpScreenRatio = (float)Application::ScreenWidth / Application::ScreenHeight;
	if (tmpScreenRatio > tmpDesignRatio)//更宽,取heihgt做适配,width做黑边
	{
		Application::RenderWidth = Application::DesignWidth*((float)Application::ScreenHeight/Application::DesignHeight);
		Application::RenderHeight = Application::ScreenHeight;
	}
	else if (tmpScreenRatio < tmpDesignRatio)//更高,取width做适配,height做黑边
	{
		Application::RenderWidth = Application::ScreenWidth;
		Application::RenderHeight = Application::DesignHeight*((float)Application::ScreenWidth/Application::DesignWidth);
	}
	else
	{
		Application::RenderWidth = Application::ScreenWidth;
		Application::RenderHeight = Application::ScreenHeight;
	}
	
	float viewportoffsetWidth = (Application::ScreenWidth - Application::RenderWidth) / 2;
	float viewportoffsetHeight = (Application::ScreenHeight - Application::RenderHeight) / 2;
	glViewport(viewportoffsetWidth, viewportoffsetHeight, Application::RenderWidth, Application::RenderHeight);
	
	LuaEngine::GetSingleton()->CallLuaFunction("Draw");
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
	JniHelper::setJNIEnv(env);
	onInit(env,obj,width,height);
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setAssetManager(JNIEnv * env, jobject obj,  jobject assetManager)
{
	// AAssetManager* mgr = AAssetManager_fromJava(env, assetManager);
	// if(mgr==NULL) 
	// { 
	  // LOGI(" %s","AAssetManager==NULL"); 
	  // return ; 
	// } 
	
}


JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj,jfloat deltaTime)
{
	JniHelper::setJNIEnv(env);
	update(deltaTime);
	render();
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setSdCardPath(JNIEnv * env, jobject obj,jstring javaString)
{
	JniHelper::setJNIEnv(env);
	
	const char *nativeString = env->GetStringUTFChars(javaString, JNI_FALSE);

	// use your string
	LOGI("sdcardpath:%s",nativeString);

	Application::SetDataPath(nativeString);
	Application::SetPersistentDataPath(nativeString);

	env->ReleaseStringUTFChars(javaString, nativeString);
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouch(JNIEnv * env, jobject obj,jint x, jint y)
{
	JniHelper::setJNIEnv(env);
	
	int tmpX = x;
	int tmpY = y;

	//转换成零点在屏幕窗口中间，右上增长的坐标
	tmpX = tmpX - Application::ScreenWidth / 2;
	tmpY = Application::ScreenHeight /2 - tmpY;


	//适配设计分辨率
	float tmpWidthRatio = Application::RenderWidth / (float)Application::DesignWidth;
	float tmpHeightRatio = Application::RenderHeight / (float)Application::DesignHeight;

	tmpX = tmpX/tmpWidthRatio;
	tmpY = tmpY/tmpHeightRatio;

	//Lives2D::OnTouch(tmpX, tmpY);
	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, tmpX);
		tolua_pushnumber(var_pLuaState, tmpY);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("OnTouch", 2, tmpFunction);
	
	//10-05 01:04:40.186: I/Lives2D(3879): Error: ...orage/emulated/0/Resource/Script/Engine/Lives2D.lua:35: error in function 'OnTouch'.  
	//10-05 01:04:40.186: I/Lives2D(3879):      argument #4 is '202'; '[no object]' expected.
	//这个错误，原本是第二个参数的 #2 202 为什么变成了#4 202…… 是不是有其它的函数漏掉了 或者 多出来了传参！，或者是tolua写法不对，或者是lambda用坏了 逐一替换掉测试 模拟器按键精灵
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_onTouchRelease(JNIEnv * env, jobject obj,jint x, jint y)
{
	JniHelper::setJNIEnv(env);
	
	int tmpX = x;
	int tmpY = y;

	//转换成零点在屏幕窗口中间，右上增长的坐标
	tmpX = tmpX - Application::ScreenWidth / 2;
	tmpY = Application::ScreenHeight / 2 - tmpY;

	//适配设计分辨率
	float tmpWidthRatio = Application::RenderWidth / (float)Application::DesignWidth;
	float tmpHeightRatio = Application::RenderHeight / (float)Application::DesignHeight;

	tmpX = tmpX / tmpWidthRatio;
	tmpY = tmpY / tmpHeightRatio;

	std::function<void(lua_State*)> tmpFunction = [&](lua_State* var_pLuaState)
	{
		tolua_pushnumber(var_pLuaState, tmpX);
		tolua_pushnumber(var_pLuaState, tmpY);
	};
	LuaEngine::GetSingleton()->CallLuaFunction("OnTouchRelease", 2, tmpFunction);
}
