#pragma once

#include"UIClickRect.h"
#include"Image\Image.h"

#include<string>
#include<functional>

class UIButton:public UIClickRect
{
private:
	float mPosX, mPosY, mWidth, mHeight;

	Image* mImageNormal;		//正常显示的图片
	Image* mImageClickDown;		//按下的图片

	bool mClickDown;		//是否按下

	std::function<void(void)> mOnClick;//点击回调

public:
	UIButton(std::string varNormalImagePath,std::string varClickDownImagePath,float varPosX,float varPosY,float varWidth,float varHeight, std::function<void(void)> varOnClick);
	~UIButton();


	void Update(float varDeltaTime) override final;

	void Draw() override final;

	void OnTouchClickRect(float varX, float varY) override final;

	void OnTouchReleaseClickRect(float varX, float varY) override final;
};

