#pragma once

#include"UIClickRect.h"
#include "UIImage.h"

#include<string>
#include<functional>

#include "LuaEngine/LuaEngine.h"

class UIButton:public UIClickRect
{
	DECLEAR_DYNCRT_ACTION(UIButton)
public:
	float mPosX, mPosY, mWidth, mHeight;

	UIImage* mImageNormal;		//正常显示的图片
	UIImage* mImageClickDown;		//按下的图片

	bool mClickDown;		//是否按下
	

	LuaFunctionPoint* mOnClickListener;

public:
	
	UIButton();
	~UIButton();

	void Init(std::string varNormalImagePath, std::string varClickDownImagePath,float varWidth, float varHeight);

	void SetOnClickListener(lua_State* varlua_State);


	void Update(float varDeltaTime) override final;

	void Draw() override final;

	void OnTouchClickRect(float varX, float varY) override final;

	void OnTouchReleaseClickRect(float varX, float varY) override final;
};

