#include "UIRoot.h"
#include"./../Tools/Helper.h"
#include"UIDrawRect.h"
#include"UIClickRect.h"

#include<iostream>
#include<algorithm>

IMPLEMENT_DYNCRT_ACTION(UIRoot)
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
		
		UIDrawRect* tmpUIDrawRect = (UIDrawRect*)val;
		tmpUIDrawRect->Draw();
	
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

	Sort();
}

void UIRoot::RemoveChild(UIRect * varUIRect)
{
	auto iter = std::find(mVectorUIRect.begin(), mVectorUIRect.end(), varUIRect);
	if (iter != mVectorUIRect.end())
	{
		mVectorUIRect.erase(iter);
	}
}

void UIRoot::Sort()
{

	//ÅÅÐò
	std::sort(mVectorUIRect.begin(), mVectorUIRect.end(), [](UIRect* varUIRect1, UIRect* varUIRect2)
	{
		return varUIRect1->GetDepth() < varUIRect2->GetDepth();
	});
}
