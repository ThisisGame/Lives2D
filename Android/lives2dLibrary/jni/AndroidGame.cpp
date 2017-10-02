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

std::string mSdCardPath;

extern "C" {
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height);
    JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj);
	JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setSdCardPath(JNIEnv * env, jobject obj,jstring sdcardpath);
};

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_init(JNIEnv * env, jobject obj,  jint width, jint height)
{
	std::string tmpFilePath = mSdCardPath+"/1.png";
	
	LOGI("PNG Path:%s",tmpFilePath.c_str());
	
	//判断文件是否存在
	std::fstream fs;
	fs.open(tmpFilePath.c_str(),std::ios::in);
	if(!fs)
	{
		LOGE("file not exist");
	}
	
	FILE* fp;
	fp=fopen(tmpFilePath.c_str(),"a+");
	if(fp==NULL)
	{
		LOGE("C file not exist");
	}
	else
	{
		fclose(fp);
	}
	

	//1、获取图片格式;
	FREE_IMAGE_FORMAT imageformat = FreeImage_GetFileType(tmpFilePath.c_str(), 0);

	//2、根据获取到的格式来加载图片;
	FIBITMAP *bitmap = FreeImage_Load(imageformat, tmpFilePath.c_str(), 0);

	if (bitmap == nullptr)
	{
		LOGE("Error not exist or other error ");
		return;
	}
	else
	{
		LOGI("FreeImage Working");
	}
	
	//3、转化为rag 24色;
	bitmap = FreeImage_ConvertTo32Bits(bitmap);

	//4、获取数据指针;
	BYTE *pixels = (BYTE*)FreeImage_GetBits(bitmap);

	//5、使用;
	int textureWidth = FreeImage_GetWidth(bitmap);
	int textureHeight = FreeImage_GetHeight(bitmap);
	
	LOGI("textureWidth:%d textureHeight:%d",textureWidth,textureHeight);
}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_step(JNIEnv * env, jobject obj)
{

}

JNIEXPORT void JNICALL Java_com_lives2d_library_nativeWrap_setSdCardPath(JNIEnv * env, jobject obj,jstring javaString)
{
	const char *nativeString = env->GetStringUTFChars(javaString, JNI_FALSE);

	// use your string
	LOGI("sdcardpath:%s",nativeString);
	
	mSdCardPath=nativeString;

	env->ReleaseStringUTFChars(javaString, nativeString);
	
}
