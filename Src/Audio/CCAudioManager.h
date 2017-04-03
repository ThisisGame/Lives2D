#pragma once

#include"al.h"
#include"alc.h"
#include"alut.h"

/*OPENAL头和OPENGL头的定义上有许多的相似之处。除了“al.h","al
u.h","alut.h"与”gl.h","glu.h","glut.h"相似，还增加了一个"alc.h".ALC（
AUDIO LIBRARY CONTEXT）处理声音通过不同的平台，她也处理你在几个窗口下共
享设备的环境。
*/

#include<iostream>
#include<map>

using namespace std;

class CCAudioManager
{
public:

	static CCAudioManager* SharedInstance();

	//初始化
	void Init(int argc,char* argv[]);

	//加载音乐
	ALboolean LoadBGMusic(string filename);

	//播放音乐
	void PlayBGMusic(string filename);

	//暂停音乐
	void PauseBGMusic();

	//停止音乐
	void StopBGMusic();


	//加载音效
	ALboolean LoadEffectMusic(string filename);

	//播放音效
	void PlayEffectMusic(string filename);

	//暂停音效
	void PauseEffectMusic(string filename);

	//停止音效
	void StopEffectMusic(string filename);


	//设置静音，关闭一切声音
	void CloseAllSound();


	//设置听者的位置-角色的位置 角色移动时要更新角色位置等属性
	void SetListener();


private:
	CCAudioManager(void);
	~CCAudioManager(void);


private:
	static CCAudioManager* m_Instance;

	ALuint m_SoundBuffer; //声音数据
	ALuint m_SoundSource; //音源


	typedef map<string,ALuint> SOUND_MAP; //声音的Map
	SOUND_MAP m_SoundMap;
};

