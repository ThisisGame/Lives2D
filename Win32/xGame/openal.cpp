#include"al.h"
#include"alc.h"
#include"alut.h"

#include<iostream>
#include<windows.h>
#include <conio.h> 
#include <stdlib.h>

/*
  你会发现再OPENAL头和OPENGL头的定义上有许多的相似之处。除了“al.h","al
u.h","alut.h"与”gl.h","glu.h","glut.h"相似，还增加了一个"alc.h".ALC（
AUDIO LIBRARY CONTEXT）处理声音通过不同的平台，她也处理你在几个窗口下共
享设备的环境。
*/

ALboolean bRet;

  // 存储声音数据
ALuint Buffer;

// 用于播放声音
ALuint Source;

/*
  这是程序处理结构的初始化。在OPENAL中三种不同的结构，所有关于声音播放和
声音数据存储在一个内存中，源（source）是指向放声音的空间。明白源是非常
的重要。源只播放内存中的背景声音数据。源也给出了特殊的属性如位置和速度。
  第三个对象是听者，用户就是那唯一的听者。听者属性属于源属性，决定如何
听声音。例如，不同位置将决定声音的速度。
*/

  // 源声音的位置
ALfloat SourcePos[] = { 0.0, 0.0, 0.0 };

// 源声音的速度
ALfloat SourceVel[] = { 0.0, 0.0, 0.0 };


// 听者的位置
ALfloat ListenerPos[] = { 0.0, 0.0, 0.0 };

// 听者的速度
ALfloat ListenerVel[] = { 0.0, 0.0, 0.0 };

// 听者的方向 (first 3 elements are "at", second 3 are "up")
ALfloat ListenerOri[] = { 0.0, 0.0, -1.0,  0.0, 1.0, 0.0 };

/*
  在上面的代码中，我们定义了源和听者对象的位置和速度。这些数组是基于笛
卡儿坐标的矢量。你能很容易用结构或类做相同的事情。
*/

  ALboolean LoadALData()
{
    // 载入变量.

    ALenum format;
    ALsizei size;
    ALvoid* data;
    ALsizei freq;
    ALboolean loop;
    //在这里我们建立一个函数用于从一个文件中载入声音数据。变量用于存储适合
	//我们的ALUT信息。
	
  // 载入WAV数据
    alGenBuffers(1, &Buffer);
    if (alGetError() != AL_NO_ERROR)
        return AL_FALSE;

    alutLoadWAVFile("music.wav", &format, &data, &size, &freq, &loop);
    alBufferData(Buffer, format, data, size, freq);
    alutUnloadWAV(format, data, size, freq);
/*
  函数alGenBufers用于建立对象内存并把他们存储在我们定义的变量中。然后判断
数据是否存储。
  ALUT库为我们打开文件，提供我们建立内存所需的信息，并且在我们归属所有
数据到内存后，她将处理这些数据。
*/
  // 捆绑源
    alGenSources(1, &Source);

    if (alGetError() != AL_NO_ERROR)
        return AL_FALSE;

    alSourcei (Source, AL_BUFFER,   Buffer   );
    alSourcef (Source, AL_PITCH,    1.0f     );
    alSourcef (Source, AL_GAIN,     1.0f     );
    alSourcefv(Source, AL_POSITION, SourcePos);
    alSourcefv(Source, AL_VELOCITY, SourceVel);
    alSourcei (Source, AL_LOOPING,  loop     );
/*
  我们用建立内存对象的方法建立了源对象。然后，我们定义源属性用于录放。
最重要的属性是她用的内存。这告诉源用于录放。因此，我们只有捆绑她。同时，
我们也告诉她我们定义的源位置和速度。
*/
  // 做错误检测并返回
    if (alGetError() == AL_NO_ERROR)
        return AL_TRUE;

    return AL_FALSE;
  //在函数的结尾，我们将做更多的检测，以确定她的正确。
}
  void SetListenervalues()
{
    alListenerfv(AL_POSITION,    ListenerPos);
    alListenerfv(AL_VELOCITY,    ListenerVel);
    alListenerfv(AL_ORIENTATION, ListenerOri);
}
	//我们建立一个函数用于更新听者速度。
  void KillALData()
{
    alDeleteBuffers(1, &Buffer);
    alDeleteSources(1, &Source);
    alutExit();
}
	//这是一个关闭函数，用于释放内存和音频设备。
 int main(int argc, char *argv[])
{
    // 初始OPENAL并清错误字节

    bRet= alutInit(&argc, argv);
    alGetError();
/*
  函数alutInit将安装ALC需要的东西。ALUT通过ALC并设置她为当前建立OPENAL
环境描述。在WINDOWS平台上初始DIRECTSOUND。然后用‘GLGETERROR’检测错误。
*/
   // 载入WAV数据
    if (LoadALData() == AL_FALSE)
        return -1;

    SetListenervalues();

    // 设置退出函数
    atexit(KillALData);
	
  //我们将检测WAV文件是否正确载入。如果没有退出程序。正确后，更新听者参数，最后退出。
  ALubyte c = ' ';

    while (c != 'q')
    {
        c = getche();

        switch (c)
        {
            // Pressing 'p' will begin playing the sample.
            case 'p': alSourcePlay(Source); break;

            // Pressing 's' will stop the sample from playing.
            case 's': alSourceStop(Source); break;

            // Pressing 'h' will pause (hold) the sample.
            case 'h': alSourcePause(Source); break;
        };
    }

    return 0;
}