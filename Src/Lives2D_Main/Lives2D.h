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

	//³õÊ¼»¯
	static void Init(EGLSurface& varEGLSurface, EGLDisplay& varEGLDisplay, int& varWidth, int& varHeight);

	//Ë¢Ö¡
	static void Update(float varDeltaTime);

	//»æÖÆ
	static void Draw();

	//¼üÅÌÊó±ê
	static void OnKey(KeyCode varkeyCode);

	//ÆÁÄ»´¥Ãþµã»÷
	static void OnTouch(float varX, float varY);
};


