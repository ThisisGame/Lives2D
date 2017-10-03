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
jclass mjclass;
jobject mjobject;
jmethodID mjmethodID_PlayAudio;
void AudioCardInit(JNIEnv* env, jobject thiz)
{
	Helper::LOG("AudioCardInit");
	mJNIEnv=env;
	jclass clazz = env->GetObjectClass(thiz); //获取当前对象的类信息
	if(clazz==NULL)
	{
		Helper::LOG("env->GetObjectClass(thiz) NULL");
		return;
	}
	mjclass = (jclass)env->NewGlobalRef(clazz); //将类型信息存储到m_class中  
	if(mjclass==NULL)
	{
		Helper::LOG("env->NewGlobalRef(clazz) NULL");
		return;
	}
	
	mjobject = thiz;
	
	// = (jobject)env->NewGlobalRef(thiz); // 将对象信息存储到m_object中
	//if(mjobject==NULL)
	//{
	//	Helper::LOG("env->NewGlobalRef(thiz) NULL");
	//	return;
	//}
	mjmethodID_PlayAudio = env->GetMethodID(mjclass, "PlayAudio", "(Ljava/lang/String)V");  // 根据类信息、方法名、参数返回值找到方法ID
	if(mjmethodID_PlayAudio ==NULL)
	{
		Helper::LOG("mjmethodID_PlayAudio NULL");
		return;
	}
}

void AudioCardPlay(const char* varAudioPath)
{
	Helper::LOG("AudioCardPlay 0 %s", varAudioPath);
	mJNIEnv->CallVoidMethod(mjobject,mjmethodID_PlayAudio,varAudioPath);
	Helper::LOG("AudioCardPlay 1 %s", varAudioPath);
}

void AudioCardExit()
{
	
}

#endif


