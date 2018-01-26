#pragma once

#include<iostream>

#include "fmod.hpp"
#include "common.h"

extern FMOD::System     *FMOD_System;


class AudioSource
{
private:
	FMOD::Sound* mSound;


public:
	AudioSource();
	~AudioSource();

public:
	void LoadAudio(const char* varAudioPath);

	void Play();

	void Loop();
};

