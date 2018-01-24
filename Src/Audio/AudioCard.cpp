#pragma once

#include"AL\alut.h"

void AudioCardInit()
{
	ALboolean tmpRet=alutInit(0, 0);
}

void AudioCardExit()
{
	alutExit();
}