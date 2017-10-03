#include "UIClickRect.h"
#include"KeyTouch\KeyTouch.h"
#include"Tools\Application.h"


UIClickRect::UIClickRect():KeyTouchListener("UIClickRect"),UIRect(UIRectType::Type_UIClickRect),mPosX(0),mPosY(0),mWidth(0),mHeight(0)
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

void UIClickRect::OnTouch(int varX, int varY)
{
	float tmpStartX = mPosX - mWidth / 2;
	float tmpStartY = mPosY + mHeight / 2;

	float tmpClickX =varX;
	float tmpClickY = varY;


	if( (tmpClickX > tmpStartX && tmpClickX< (tmpStartX+mWidth))  && ( tmpClickY<tmpStartY && tmpClickY > (tmpStartY - mHeight) ))
	{
		mOnTouchClick = true;
		OnTouchClickRect(tmpClickX, tmpClickY);
	}
}

void UIClickRect::OnTouchRelease(int varX, int varY)
{
	if (mOnTouchClick)
	{
		mOnTouchClick = false;
		float tmpClickX = varX - Application::DesignWidth / 2;
		float tmpClickY = Application::DesignHeight/ 2 - varY;
		OnTouchReleaseClickRect(tmpClickX, tmpClickY);
	}
}

UIClickRect::~UIClickRect()
{
	KeyTouch::UnRegisterKeyTouchListener(this);
}
