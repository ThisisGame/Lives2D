#include "AudioSource.h"
#include<string>
#include"PlayerPrefs/Convert.h"
#include"Tools/Application.h"

IMPLEMENT_DYNCRT_ACTION(AudioSource)

AudioSource::AudioSource():mLoop(false), mAudioPath(nullptr)
{
}


AudioSource::~AudioSource()
{
}

void AudioSource::InitWithXml(TiXmlElement * varTiXmlElement)
{
	mAudioPath = varTiXmlElement->Attribute("Audio");
	char tmpFullFilePath[128];
	memset(tmpFullFilePath, 0, 128);

	strcat(tmpFullFilePath, Application::DataPath().c_str());
	strcat(tmpFullFilePath, "/Resource/");
	strcat(tmpFullFilePath, mAudioPath);


	mLoop =Convert::StringToBool( varTiXmlElement->Attribute("Loop"));

	LoadAudio(tmpFullFilePath);
	if (mLoop)
	{
		Loop();
	}
	Play();
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