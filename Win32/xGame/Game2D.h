#pragma once

#include"shader\GLProgram_Texture.h"
#include"Texture2D\Texture2D.h"

#include"CCSceneManager.h"
#include"CCAudioManager.h"


class Game2D
{
private:
	static EGLSurface m_EGLSurface;
	static EGLDisplay m_EGLDisplay;

public:
	static int m_Width;
	static int m_Height;

	static float mAspectRatio;

public:
	static void Init(EGLSurface& varEGLSurface, EGLDisplay& varEGLDisplay,int& varWidth,int& varHeight)
	{
		m_EGLSurface = varEGLSurface;
		m_EGLDisplay = varEGLDisplay;
		m_Width = varWidth;
		m_Height = varHeight;
		mAspectRatio = (float)m_Width / m_Height;

		CCSceneManager::SharedInstance()->RegisterAllScene();//注册所有的场景

		CCAudioManager::SharedInstance()->Init(0, NULL);//初始化OpenAL
	}


	static void render()
	{
		if (m_Width == 0 || m_Height == 0)
		{
			return;
		}

		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		
		glViewport(0, 0, m_Width, m_Height);


		CCSceneManager::SharedInstance()->Update();
		CCSceneManager::SharedInstance()->Draw();


		eglSwapBuffers(m_EGLDisplay, m_EGLSurface);
	}
};


