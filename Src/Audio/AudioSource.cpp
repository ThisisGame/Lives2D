#include "AudioSource.h"
#include<string>


AudioSource::AudioSource()
{
}


AudioSource::~AudioSource()
{
}

void AudioSource::LoadAudio(const char * varAudioPath)
{
	m_SoundBuffer = alutCreateBufferFromFile(varAudioPath);
	if (m_SoundBuffer == AL_NONE)
	{
		ALenum tmpRet = alutGetError();
		//printf(alutGetErrorString(tmpRet));
		
	}
	

	alGenSources(1, &m_SoundSource);
	alSourcei(m_SoundSource, AL_BUFFER, m_SoundBuffer);
}


void AudioSource::Play()
{
	alSourcePlay(m_SoundSource);
}


void AudioSource::Loop()
{
	alSourcei(m_SoundSource, AL_LOOPING, AL_TRUE);
}