#pragma once

#ifdef WIN32
#include"AL\alut.h"

void AudioCardInit()
{
	ALboolean tmpRet=alutInit(0, 0);
}

void AudioCardExit()
{
	alutExit();
}

#elif ANDROID
#include <jni.h>
#include"Tools\Helper.h"

JNIEnv* mJNIEnv;
jobject mjobject;
jmethodID mjmethodID_PlayAudio;
void AudioCardInit(JNIEnv* env, jobject thiz)
{
	Helper::LOG("AudioCardInit");
	mJNIEnv=env;
	jclass clazz = env->FindClass("com/lives2d/library/lives2dActivity"); //获取当前对象的类信息
	if(clazz==NULL)
	{
		Helper::LOG("env->GetObjectClass(thiz) NULL");
		return;
	}
	
	mjobject=thiz;

	mjmethodID_PlayAudio = env->GetMethodID(clazz, "PlayAudio", "(Ljava/lang/String;)V");  // 根据类信息、方法名、参数返回值找到方法ID
	if(mjmethodID_PlayAudio ==NULL)
	{
		Helper::LOG("mjmethodID_PlayAudio NULL");
		return;
	}
}

void AudioCardPlay(const char* varAudioPath)
{
	Helper::LOG("AudioCardPlay 0 %s", varAudioPath);
	jstring jstringAudioPath=mJNIEnv->NewStringUTF(varAudioPath);
	mJNIEnv->CallVoidMethod(mjobject,mjmethodID_PlayAudio,jstringAudioPath);
	mJNIEnv->DeleteLocalRef(jstringAudioPath);
	Helper::LOG("AudioCardPlay 1 %s", varAudioPath);
}

void AudioCardExit()
{
	
}

#endif


