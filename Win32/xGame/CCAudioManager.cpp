#include "CCAudioManager.h"
#include "Helper.h"


CCAudioManager* CCAudioManager::m_Instance=NULL;


CCAudioManager* CCAudioManager::SharedInstance()
{
	if(m_Instance==NULL)
	{
		m_Instance=new CCAudioManager();
	}
	return m_Instance;
}

CCAudioManager::CCAudioManager(void)
{
}


//初始化
void CCAudioManager::Init(int argc,char* argv[])
{
	if(alutInit(&argc,argv)==AL_FALSE)
	{
		Helper::CCLOG("CCAudioManager::Init Faild");
	}
}

ALboolean CCAudioManager::LoadBGMusic(string filename)
{
	ALenum format;
	ALsizei size;
	ALvoid* data;
	ALsizei freq;
	ALboolean loop;

	alGenBuffers(1,&m_SoundBuffer); //建立内存对象，并存储在m_SoundBuffer中
	if(alGetError()!=AL_NO_ERROR) //判断数据是否存储
	{
		return AL_FALSE;
	}
	alutLoadWAVFile((ALbyte*)filename.c_str(),&format,&data,&size,&freq,&loop);//打开文件,传入创建内存所需信息
	alBufferData(m_SoundBuffer,format,data,size,freq);//把wav数据存入到m_SoundBuffer
	alutUnloadWAV(format,data,size,freq);//处理掉wav数据

	//捆绑音源
	alGenSources(1,&m_SoundSource);
	if(alGetError()!=AL_NO_ERROR)
	{
		return AL_FALSE;
	}
	alSourcei(m_SoundSource,AL_BUFFER,m_SoundBuffer);
	alSourcef(m_SoundSource,AL_PITCH,1.0f);
	alSourcef(m_SoundSource,AL_GAIN,1.0f);
	//alSourcefv(m_SoundSource,AL_POSITION,m_SoundSourcePos);
	alSourcefv(m_SoundSource,AL_POSITION,m_SoundSourcePosVec3.m_Data);
	alSourcefv(m_SoundSource,AL_VELOCITY,m_SoundSourceVelVec3.m_Data);
	alSourcei(m_SoundSource,AL_LOOPING,loop);
	if(alGetError()==AL_NO_ERROR)
	{
		return AL_TRUE;
	}
	return AL_FALSE;
}

//设置听者的位置-角色的位置 角色移动时要更新角色位置等属性
void CCAudioManager::SetListener()
{
	alListenerfv(AL_POSITION,m_ListenerPosVec3.m_Data);
	alListenerfv(AL_VELOCITY,m_ListenerVelVec3.m_Data);
	alListenerfv(AL_ORIENTATION,m_ListenerOriVec3.m_Data);
}

void CCAudioManager::PlayBGMusic(string filename)
{
	SetListener();
	alSourcePlay(m_SoundSource);
}


//暂停音乐
void CCAudioManager::PauseBGMusic()
{
	alSourcePause(m_SoundSource);
}

//停止音乐
void CCAudioManager::StopBGMusic()
{
	alSourceStop(m_SoundSource);
	alDeleteBuffers(1,&m_SoundBuffer);
	alDeleteSources(1,&m_SoundSource);
}

ALboolean CCAudioManager::LoadEffectMusic(string filename)
{
	return true;
}

void CCAudioManager::PlayEffectMusic(string filename)
{

}

//暂停音效
void CCAudioManager::PauseEffectMusic(string filename)
{

}

//停止音效
void CCAudioManager::StopEffectMusic(string filename)
{

}


//设置静音，关闭一切声音
void CCAudioManager::CloseAllSound()
{

}


CCAudioManager::~CCAudioManager(void)
{
	alDeleteBuffers(1,&m_SoundBuffer);
	alDeleteSources(1,&m_SoundSource);
}
