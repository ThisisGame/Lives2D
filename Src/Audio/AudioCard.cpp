#pragma once
#include "fmod.hpp"
#include "Audio/FMOD/common.h"

extern int FMOD_Platform_Main(int argc, char** argv);

int FMOD_Main()
{
	FMOD::System     *system;
	FMOD::Sound      *sound1, *sound2, *sound3;
	FMOD::Channel    *channel = 0;
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata = 0;

	Common_Init(&extradriverdata);

	/*
	Create a System object and initialize
	*/
	result = FMOD::System_Create(&system);
	ERRCHECK(result);

	result = system->getVersion(&version);
	ERRCHECK(result);

	if (version < FMOD_VERSION)
	{
		Common_Fatal("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	ERRCHECK(result);

	result = system->createSound(Common_MediaPath("drumloop.wav"), FMOD_DEFAULT, 0, &sound1);
	ERRCHECK(result);

	result = sound1->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
	ERRCHECK(result);                           /* so turn it off here.  We could have also just put FMOD_LOOP_OFF in the above CreateSound call. */

	return 0;
}


void AudioCardInit()
{
	FMOD_Platform_Main(0, NULL);
}

void AudioCardExit()
{
	
}