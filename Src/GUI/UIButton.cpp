#include "UIButton.h"


IMPLEMENT_DYNCRT_ACTION(UIButton)
UIButton::UIButton(std::string varNormalImagePath, std::string varClickDownImagePath, float varPosX, float varPosY, float varWidth, float varHeight):UIClickRect(),mClickDown(false),mPosX(varPosX),mPosY(varPosY),mWidth(varWidth),mHeight(varHeight), mOnClickListener(NULL)
{
	mImageNormal = new UIImage();
	mImageNormal->Init(varNormalImagePath.c_str());
	mImageNormal->SetPosition(mPosX, mPosY);

	mImageClickDown = new UIImage();
	mImageClickDown->Init(varClickDownImagePath.c_str());
	mImageClickDown->SetPosition(mPosX, mPosY);
}

UIButton::UIButton()
{
}


void UIButton::SetOnClickListener(lua_State * varlua_State)
{
	mOnClickListener = new LuaFunctionPoint();
	mOnClickListener->mlua_State = varlua_State;
	mOnClickListener->mFunctionIndexInStack = -2;
	mOnClickListener->mArgumentIndexInStack = -1;
	mOnClickListener = LuaEngine::GetSingleton()->GetLuaFunction(mOnClickListener);
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
	if (mOnClickListener)
	{
		LuaEngine::GetSingleton()->ExecuteLuaFunction(mOnClickListener);
	}
}

void UIButton::OnTouchReleaseClickRect(float varX, float varY)
{
	mClickDown = false;
}



UIButton::~UIButton()
{

}





