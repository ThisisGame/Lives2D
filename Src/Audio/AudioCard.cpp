#pragma once
#include "fmod.hpp"
#include "Audio/FMOD/common.h"

extern int FMOD_Platform_Main(int argc, char** argv);

FMOD::System     *FMOD_System;

int FMOD_Main()
{
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata = 0;

	Common_Init(&extradriverdata);

	/*
	Create a System object and initialize
	*/
	result = FMOD::System_Create(&FMOD_System);
	ERRCHECK(result);

	result = FMOD_System->getVersion(&version);
	ERRCHECK(result);

	if (version < FMOD_VERSION)
	{
		Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	result = FMOD_System->init(32, FMOD_INIT_NORMAL, extradriverdata);
	ERRCHECK(result);

	return 0;
}


void AudioCardInit()
{
	FMOD_Platform_Main(0, NULL);
}

void AudioCardExit()
{
	
}