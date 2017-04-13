#pragma once

#include"GLProgram\GLProgram_Texture.h"
#include"Texture2D\Texture2D.h"
#include"Image\Image.h"


class Lives2D
{
public:
	static int m_Width;
	static int m_Height;

	static float m_DesignWidth;
	static float m_DesignHeight;

	//绘制一个图片
	static Image* mImage;

public:

	//初始化
	static void Init(EGLSurface& varEGLSurface, EGLDisplay& varEGLDisplay, int& varWidth, int& varHeight);

	//刷帧
	static void Update(float varDeltaTime);

	//绘制
	static void Draw();

};


