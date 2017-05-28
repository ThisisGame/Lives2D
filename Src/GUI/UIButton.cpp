#include "UIButton.h"



UIButton::UIButton(std::string varNormalImagePath, std::string varClickDownImagePath, float varPosX, float varPosY, float varWidth, float varHeight,std::function<void(void)> varOnClick)
	:mClickDown(false),mPosX(varPosX),mPosY(varPosY),mWidth(varWidth),mHeight(varHeight),mOnClick(varOnClick)
{
	mImageNormal = new Image();
	mImageNormal->Init(varNormalImagePath.c_str());

	mImageClickDown = new Image();
	mImageClickDown->Init(varClickDownImagePath.c_str());
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

	mOnClick();
}

void UIButton::OnTouchReleaseClickRect(float varX, float varY)
{
	mClickDown = false;
}



UIButton::~UIButton()
{

}




