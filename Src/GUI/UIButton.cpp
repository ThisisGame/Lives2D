#include "UIButton.h"



UIButton::UIButton(std::string varNormalImagePath, std::string varClickDownImagePath, float varPosX, float varPosY, float varWidth, float varHeight):UIClickRect(),mClickDown(false),mPosX(varPosX),mPosY(varPosY),mWidth(varWidth),mHeight(varHeight)
{
	mImageNormal = new Image();
	mImageNormal->Init(varNormalImagePath.c_str());
	mImageNormal->SetPosition(mPosX, mPosY);

	mImageClickDown = new Image();
	mImageClickDown->Init(varClickDownImagePath.c_str());
	mImageClickDown->SetPosition(mPosX, mPosY);
}


void UIButton::SetOnClickListener(lua_State * varlua_State)
{
	mOnClickListener = new LuaFunctionPoint();
	mOnClickListener->mlua_State = varlua_State;
	mOnClickListener->mFunctionIndexInStack = -2;
	mOnClickListener->mArgumentIndexInStack = -1;
	mOnClickListener = LuaEngine::GetSingleton()->GetLuaFunction(mOnClickListener);

	LuaEngine::GetSingleton()->ExecuteLuaFunction(mOnClickListener);
}

void UIButton::Update(float varDeltaTime)
{
	UIClickRect::UpdateRect(mPosX, mPosY, mWidth, mHeight);
}

void UIButton::Draw()
{
	if (mClickDown)
	{
		mImageClickDown->Draw();
	}
	else
	{
		mImageNormal->Draw();
	}
}

void UIButton::OnTouchClickRect(float varX, float varY)
{
	mClickDown = true;

	//mOnClick();
	LuaEngine::GetSingleton()->ExecuteLuaFunction(mOnClickListener);
}

void UIButton::OnTouchReleaseClickRect(float varX, float varY)
{
	mClickDown = false;
}



UIButton::~UIButton()
{

}





