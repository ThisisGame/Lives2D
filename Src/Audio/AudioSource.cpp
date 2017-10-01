#include "AudioSource.h"



AudioSource::AudioSource()
{
}


AudioSource::~AudioSource()
{
}

void AudioSource::LoadAudio(const char * varAudioPath)
{
#ifdef WIN32
	m_SoundBuffer = alutCreateBufferFromFile(varAudioPath);
	if (m_SoundBuffer == AL_NONE)
	{
		ALenum tmpRet = alutGetError();
		printf(alutGetErrorString(tmpRet));
	}
	

	alGenSources(1, &m_SoundSource);
	alSourcei(m_SoundSource, AL_BUFFER, m_SoundBuffer);
#elif ANDROID

#endif
}

void AudioSource::Play()
{
#ifdef WIN32
	alSourcePlay(m_SoundSource);
#elif ANDROID

#endif
}

void AudioSource::Loop()
{
#ifdef WIN32
	alSourcei(m_SoundSource, AL_LOOPING, AL_TRUE);
#elif ANDROID

#endif
}
