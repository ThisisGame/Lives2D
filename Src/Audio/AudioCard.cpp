#pragma once
#include "fmod.hpp"
#include "common.h"

#include"Tools/Helper.h"

FMOD::System     *FMOD_System;

int FMOD_Main()
{
	Helper::LOG("FMOD_Main 0");

	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata = 0;

	Common_Init(&extradriverdata);

	Helper::LOG("FMOD_Main 1");
	if (extradriverdata == NULL)
	{
		Helper::LOG("FMOD_Main 2");
	}

	/*
	Create a System object and initialize
	*/
	result = FMOD::System_Create(&FMOD_System);
	ERRCHECK(result);

	Helper::LOG("FMOD::System_Create %d", result);

	result = FMOD_System->getVersion(&version);
	ERRCHECK(result);

	Helper::LOG("FMOD_System->getVersion %d", result);

	if (version < FMOD_VERSION)
	{
		Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	result = FMOD_System->init(32, FMOD_INIT_NORMAL, extradriverdata);
	ERRCHECK(result);

	Helper::LOG("FMOD_System->init %d", result);

	return 0;
}


void AudioCardInit()
{
	FMOD_Main();
}

void AudioCardExit()
{
	
}