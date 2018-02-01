#include "UIButton.h"
#include"Component/GameObject.h"
#include"Component/Transform.h"


IMPLEMENT_DYNCRT_ACTION(UIButton)
UIButton::UIButton() :UIClickRect(), mClickDown(false), mWidth(0), mHeight(0), mOnClickListener(NULL)
{
}


void UIButton::Init(std::string varNormalImagePath, std::string varClickDownImagePath, float varWidth, float varHeight)
{
	GameObject* tmpGoImageNormal = new GameObject("ImageNormal");
	mGameObject->AddChild(tmpGoImageNormal);
	mImageNormal = (UIImage*)tmpGoImageNormal->AddComponent("UIImage");
	mImageNormal->Init(varNormalImagePath.c_str());
	//mImageNormal->mTransform->SetLocalPosition(mPosX, mPosY);
	

	GameObject* tmpGoImageClickDown = new GameObject("ImageClickDown");
	mGameObject->AddChild(tmpGoImageClickDown);
	mImageClickDown =(UIImage*)tmpGoImageClickDown->AddComponent("UIImage");
	mImageClickDown->Init(varClickDownImagePath.c_str());
	//mImageClickDown->SetPosition(mPosX, mPosY);
	

	mWidth = varWidth;
	mHeight = varHeight;

	mPosX = mTransform->GetPosition().mX;
	mPosY = mTransform->GetPosition().mY;
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





