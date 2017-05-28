#pragma once

#include"../KeyTouch/KeyTouchListener.h"

class UIClickRect:KeyTouchListener
{
private:
	float mPosX, mPosY, mWidth, mHeight; //点击区域

	bool mOnTouchClick;//当前是否点击

public:
	UIClickRect();
	~UIClickRect();

	
	

	void OnKey(KeyCode varkeyCode) override final;

	void OnTouch(float varX, float varY) override final;

	//释放点击
	void OnTouchRelease(float varX, float varY) override final;



	virtual void OnTouchClickRect(float varX, float varY)=0;

	virtual void OnTouchReleaseClickRect(float varX, float varY) = 0;

protected:
	void UpdateRect(float varPosX, float varPosY, float varWidth, float varHeight);//设置点击范围
};

