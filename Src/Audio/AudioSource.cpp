#include "AudioSource.h"
#include<string>


AudioSource::AudioSource()
{
}


AudioSource::~AudioSource()
{
}

#ifdef WIN32
void AudioSource::LoadAudio(const char * varAudioPath)
{
	m_SoundBuffer = alutCreateBufferFromFile(varAudioPath);
	if (m_SoundBuffer == AL_NONE)
	{
		ALenum tmpRet = alutGetError();
		printf(alutGetErrorString(tmpRet));
	}
	

	alGenSources(1, &m_SoundSource);
	alSourcei(m_SoundSource, AL_BUFFER, m_SoundBuffer);
}


void AudioSource::Play()
{
	alSourcePlay(m_SoundSource);
}

#elif ANDROID

extern void AudioCardPlay(const char* varAudioPath);

void AudioSource::LoadAudio(const char * varAudioPath)
{
	mAudioPath = varAudioPath;
	
}

void AudioSource::Play()
{
	AudioCardPlay(mAudioPath.c_str());
}

#elif IOS


void AudioSource::LoadAudio(const char * varAudioPath)
{
    m_SoundBuffer = alutCreateBufferFromFile(varAudioPath);
    if (m_SoundBuffer == AL_NONE)
    {
        ALenum tmpRet = alutGetError();
        printf(alutGetErrorString(tmpRet));
    }
    
    
    alGenSources(1, &m_SoundSource);
    alSourcei(m_SoundSource, AL_BUFFER, m_SoundBuffer);
}


void AudioSource::Play()
{
    alSourcePlay(m_SoundSource);
}

#endif


void AudioSource::Loop()
{
#if ( WIN32 || __APPLE__)
	alSourcei(m_SoundSource, AL_LOOPING, AL_TRUE);
#elif ANDROID

#endif
}
