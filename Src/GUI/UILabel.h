#pragma once

#include"UIDrawRect.h"
#include"Font.h"
#include"GLProgram\GLProgram_Font.h"

class UILabel:public UIDrawRect
{

public:
	float mPosX;
	float mPosY;
	float mScaleX;
	float mScaleY;

private:
	Font* mFont;

	GLProgram_Font m_GLProgram_Font;

	//字体使用GL_ALPHA格式;
	unsigned int m_fontTexture;//字体Texutre;

	UIVertex  vert[1024];

	std::string mText;

public:
	UILabel();
	~UILabel();

public:
	void Init(const char* varText);

	//绘制				 
	void Draw() override;


	//设置位置
	void SetPosition(float varPosX, float varPosY);


	//设置缩放
	void SetScale(float varScaleX, float varScaleY);
};