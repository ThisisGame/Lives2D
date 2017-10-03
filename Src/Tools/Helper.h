#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string>
#include<stdarg.h>
#include<iostream>
#include<assert.h>

#include <fstream>
#include <cassert>
#include <string>
#include<vector>

using namespace std;

#ifdef ANDROID
#include <jni.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <android/log.h>
#define LOG_TAG "Lives2D"
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
	static void LOG(const char* str,...);

public :
	//读取Txt文本
	static std::string ReadTxt(std::string& varFilePath);

	//字符串分割函数  
	static std::vector<std::string> Split(std::string& varStr, std::string& varPattern);

	//读取Txt文本，一行一行存储
	static std::vector<std::string> ReadLine(std::string & varFilePath);

	//获取时间
	static unsigned int GetTime();

	//从路径中获取目录
	static std::string GetDirPath(std::string varFilePath);
};

