#include "UIRoot.h"
#include"./../Tools/Helper.h"
#include"UIDrawRect.h"
#include"UIClickRect.h"


UIRoot::UIRoot():mDepth(0)
{
}


UIRoot::~UIRoot()
{
}

void UIRoot::Update(float varDeltaTime)
{
	for (auto val : mVectorUIRect)
	{
		val->Update(varDeltaTime);
	}
}

void UIRoot::Draw()
{
	for (auto val : mVectorUIRect)
	{
		if (val->mUIRectType == UIRectType::Type_UIDrawRect)
		{
			UIDrawRect* tmpUIDrawRect = (UIDrawRect*)val;
			tmpUIDrawRect->Draw();
		}
	}
}

void UIRoot::AddChild(UIRect * varUIRect)
{
	auto iter = std::find(mVectorUIRect.begin(), mVectorUIRect.end(), varUIRect);
	if (iter != mVectorUIRect.end())
	{
		LOGI("RegisterChild Twice");
		return;
	}
	mVectorUIRect.push_back(varUIRect);
}

void UIRoot::RemoveChild(UIRect * varUIRect)
{
	auto iter = std::find(mVectorUIRect.begin(), mVectorUIRect.end(), varUIRect);
	if (iter != mVectorUIRect.end())
	{
		mVectorUIRect.erase(iter);
	}
}
