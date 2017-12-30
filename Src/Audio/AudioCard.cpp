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
#include "JniHelper.h"

extern  JavaVM* sJavaVM;
extern  pthread_key_t sThreadKey;
extern  void detach_current_thread(void* env);

static jclass mjclass;
static jobject mjobject;
static jmethodID mjmethodID_PlayAudio;
void AudioCardInit(JNIEnv* env, jobject thiz)
{
	Helper::LOG("AudioCardInit");
}

void AudioCardPlay(const char* varAudioPath)
{
	Helper::LOG("AudioCardPlay 0 %s", varAudioPath);
	
	
	JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, "com/lives2d/library/nativeWrap", "PlayAudio", "(Ljava/lang/String;)V")) 
	{
        jstring stringArg1;

        stringArg1 = t.env->NewStringUTF(varAudioPath);

        t.env->CallStaticVoidMethod(t.classID, t.methodID, stringArg1);

        t.env->DeleteLocalRef(stringArg1);
        t.env->DeleteLocalRef(t.classID);
    }
	
	Helper::LOG("AudioCardPlay 1 %s", varAudioPath);
}

void AudioCardExit()
{
	
}

#elif IOS

void AudioCardInit()
{
//    ALboolean tmpRet=alutInit(0, 0);
}

void AudioCardExit()
{
//    alutExit();
}

#endif


