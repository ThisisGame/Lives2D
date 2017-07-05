#pragma once
#include<iostream>
#include"AL\alut.h"

class AudioSource
{
private:
	ALenum format;
	ALsizei size;
	ALvoid* data;
	ALsizei freq;
	ALboolean loop;

	ALuint m_SoundBuffer; //ษ๙า๔สýพÝ
	ALuint m_SoundSource; //า๔ิด


public:
	AudioSource();
	~AudioSource();

public:
	void LoadAudio(const char* varAudioPath);

	void Play();

	void Loop();
};

