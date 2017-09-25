#pragma once

#include"../KeyTouch/KeyTouchListener.h"
#include"UIRect.h"

class UIClickRect:public UIRect,public KeyTouchListener
{
private:
	float mPosX, mPosY, mWidth, mHeight; //点击区域

	bool mOnTouchClick;//当前是否点击

public:
	UIClickRect();
	~UIClickRect();

	
	

	void OnKey(KeyCode varkeyCode) override final;

	void OnTouch(int varX, int varY) override final;

	//释放点击
	void OnTouchRelease(int varX, int varY) override final;



	virtual void OnTouchClickRect(float varX, float varY)=0;

	virtual void OnTouchReleaseClickRect(float varX, float varY) = 0;

protected:
	void UpdateRect(float varPosX, float varPosY, float varWidth, float varHeight);//设置点击范围
};

