#pragma once

#ifdef WIN32
#include"AL\alut.h"
#elif ANDROID

#endif

void AudioCardInit()
{
#ifdef WIN32
	ALboolean tmpRet=alutInit(0, 0);
#elif ANDROID

#endif
}


void AudioCardExit()
{
#ifdef WIN32
	alutExit();
#elif ANDROID

#endif
}
