#pragma once

#include"GLProgram\GLProgram_Texture.h"
#include"Texture2D\Texture2D.h"
#include"Image\Image.h"


class Game2D
{
public:
	static int m_Width;
	static int m_Height;

	static float mAspectRatio;

	//绘制一个图片
	static Image* mImage;

public:
	static void Init(EGLSurface& varEGLSurface, EGLDisplay& varEGLDisplay,int& varWidth,int& varHeight)
	{

		m_Width = varWidth;
		m_Height = varHeight;
		mAspectRatio = (float)m_Width / m_Height;


		//图片初始化
		mImage = new Image();
		mImage->Init("../../Resources/images/logo.png");
	}


	static void render()
	{
		//绘制一个图片
		mImage->Draw(0, 0);
	}
};


