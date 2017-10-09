#pragma once

#include"UIDrawRect.h"
#include"Font.h"

class UILabel:public UIDrawRect
{

public:
	float mPosX;
	float mPosY;
	float mScaleX;
	float mScaleY;

private:
	Font& mFont;

public:
	UILabel();
	~UILabel();

public:
	void Init();

	//绘制				 
	void Draw() override;


	//设置位置
	void SetPosition(float varPosX, float varPosY);


	//设置缩放
	void SetScale(float varScaleX, float varScaleY);
};