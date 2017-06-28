#pragma once

#include"GLProgram\GLProgram_Texture.h"
#include"Texture2D\Texture2D.h"
#include"GUI\UIDrawRect.h"

class Image:public UIDrawRect
{
public:
	Image(void);
	~Image(void);

public:
	void  Init(const char* varFilePath); //加载图片，生成Texture;

	//绘制
	void Draw() override;


	//设置位置
	void SetPosition(float varPosX, float varPosY);


	//设置缩放
	void SetScale(float varScaleX, float varScaleY);

private:
	GLProgram_Texture m_GLProgram;
	Texture2D* mTexture2D;

public:
	float mPosX;
	float mPosY;
	float mScaleX;
	float mScaleY;
};

