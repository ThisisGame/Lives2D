#pragma once

#include"GLProgram\GLProgram_Texture.h"
#include"Texture2D\Texture2D.h"



//DemoScene
#include"./Sample/DemoScene.h"


class Lives2D
{
public:
	static int m_Width;
	static int m_Height;

	static float m_DesignWidth;
	static float m_DesignHeight;



	static DemoScene* mDemoScene;

public:

	//初始化
	static void Init(EGLSurface& varEGLSurface, EGLDisplay& varEGLDisplay, int& varWidth, int& varHeight);

	//刷帧
	static void Update(float varDeltaTime);

	//绘制
	static void Draw();

	//键盘鼠标
	static void OnKey(KeyCode varkeyCode);

	//屏幕触摸点击
	static void OnTouch(int varX, int varY);

	//释放点击
	static void OnTouchRelease(int varX, int varY);
};


