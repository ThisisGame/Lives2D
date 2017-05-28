#include "UIClickRect.h"
#include"KeyTouch\KeyTouch.h"

#include"Lives2D_Main\Lives2D.h"


UIClickRect::UIClickRect():KeyTouchListener("UIClickRect"),mPosX(0),mPosY(0),mWidth(0),mHeight(0)
{
	//×¢²á¼üÅÌÊó±êÆÁÄ»¼àÌý
	KeyTouch::RegisterKeyTouchListener(this);
}


void UIClickRect::UpdateRect(float varPosX, float varPosY, float varWidth, float varHeight)
{
	mPosX = varPosX;
	mPosY = varPosY;
	mWidth = varWidth;
	mHeight = varHeight;
}

void UIClickRect::OnKey(KeyCode varkeyCode)
{

}

void UIClickRect::OnTouch(float varX, float varY)
{
	float tmpStartX = mPosX - mWidth / 2;
	float tmpStartY = mPosY + mHeight / 2;

	float tmpClickX =varX- Lives2D::m_Width/2;
	float tmpClickY = Lives2D::m_Height / 2 - varY;

	if( (tmpClickX > tmpStartX && tmpClickX< (tmpStartX+mWidth))  && ( tmpClickY<tmpStartY && tmpClickY > (tmpStartY - mHeight) ))
	{
		mOnTouchClick = true;
		OnTouchClickRect(tmpClickX, tmpClickY);
	}
}

void UIClickRect::OnTouchRelease(float varX, float varY)
{
	if (mOnTouchClick)
	{
		mOnTouchClick = false;
		float tmpClickX = varX - Lives2D::m_Width / 2;
		float tmpClickY = Lives2D::m_Height / 2 - varY;
		OnTouchReleaseClickRect(tmpClickX, tmpClickY);
	}
}

UIClickRect::~UIClickRect()
{
	KeyTouch::UnRegisterKeyTouchListener(this);
}
