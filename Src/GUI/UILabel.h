#pragma once

#include"UIDrawRect.h"
#include"Font.h"
#include"GLProgram/GLProgram_Font.h"


class UILabel:public UIDrawRect
{
	DECLEAR_DYNCRT_ACTION(UILabel)
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

	std::u32string mText;

	int mSpace;//字间距

	bool mAlignCenter;//居中对齐

public:
	UILabel();
	~UILabel();

	void InitWithXml(TiXmlElement* varTiXmlElement) override;

public:
	void Init(std::u32string& varText);

	//绘制				 
	void Draw() override;


	//设置位置
	void SetPosition(float varPosX, float varPosY);


	//设置缩放
	void SetScale(float varScaleX, float varScaleY);

	//设置字间距
	void SetSpace(int varSpace);

	//设置居中对其
	void SetAlignCenter(bool varAlignCenter);
};
