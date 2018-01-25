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
	FMOD_RESULT   tmpResult= FMOD_System->createSound(varAudioPath, FMOD_DEFAULT, 0, &mSound);
	ERRCHECK(tmpResult);
}


void AudioSource::Play()
{
	FMOD::Channel    *channel = 0;
	FMOD_RESULT   tmpResult = FMOD_System->playSound(mSound, 0, false, &channel);
	ERRCHECK(tmpResult);
}


void AudioSource::Loop()
{
	FMOD_RESULT   tmpResult = mSound->setMode(FMOD_LOOP_NORMAL);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
	ERRCHECK(tmpResult);                           /* so turn it off here.  We could have also just put FMOD_LOOP_OFF in the above CreateSound call. */
}