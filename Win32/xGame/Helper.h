#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string>
#include<stdarg.h>
#include<iostream>
#include<assert.h>
using namespace std;

#ifdef ANDROID
#include <jni.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/log.h>
#define LOG_TAG "xGame-GLES"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#elif defined WIN32
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include"gles2\gl2.h"

#define LOGI(out,...) printf(out,##__VA_ARGS__);fflush(stdout)
#define LOGE(out,...) printf(out,##__VA_ARGS__);\
	printf("The file name: %s\n", __FILE__);\
	printf("The current line No:%d\n", __LINE__);\
	system("pause");\
	fflush(stdout)
#elif defined IOS

#endif

class Helper
{
public:
	Helper(void);
	~Helper(void);

	///输出GL变量的值
	static void PrintGLString(const char* name,GLenum s);

	///检查GL错误
	static void CheckGLError(const char* op);

	//输出LOG
	static void CCLOG(const char* str);
};

