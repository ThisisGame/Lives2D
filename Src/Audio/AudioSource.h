#pragma once

#include<iostream>



class AudioSource
{
private:



public:
	AudioSource();
	~AudioSource();

public:
	void LoadAudio(const char* varAudioPath);

	void Play();

	void Loop();
};

