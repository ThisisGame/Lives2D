#pragma once

#include<iostream>

#include "fmod.hpp"
#include "common.h"
#include"Component/Behavior.h"



extern FMOD::System     *FMOD_System;
class AudioSource :public Behavior
{
	DECLEAR_DYNCRT_ACTION(AudioSource)
private:
	FMOD::Sound* mSound;
	bool mLoop;

	const char* mAudioPath;
public:
	AudioSource();
	~AudioSource();

	void InitWithXml(TiXmlElement* varTiXmlElement) override;

public:
	void LoadAudio(const char* varAudioPath);

	void Play();

	void Loop();
};

