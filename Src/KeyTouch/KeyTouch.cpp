#include "KeyTouch.h"

#include"Tools\Helper.h"

std::vector<KeyTouchListener*> KeyTouch::mVectorKeyTouchListener;

KeyTouch::KeyTouch()
{
}


KeyTouch::~KeyTouch()
{
}

void KeyTouch::RegisterKeyTouchListener(KeyTouchListener* varKeyTouchListener)
{
	std::vector<KeyTouchListener*>::iterator tmpIterator= std::find(mVectorKeyTouchListener.begin(), mVectorKeyTouchListener.end(), varKeyTouchListener);

	if (tmpIterator != mVectorKeyTouchListener.end())
	{
		Helper::LOG("Error: KeyTouch::RegisterKeyTouchListener More Than Once.");
		Helper::LOG(varKeyTouchListener->ClassName().c_str());
	}
	else
	{
		mVectorKeyTouchListener.push_back(varKeyTouchListener);
	}
}

void KeyTouch::UnRegisterKeyTouchListener(KeyTouchListener * varKeyTouchListener)
{
	std::vector<KeyTouchListener*>::iterator tmpIterator = std::find(mVectorKeyTouchListener.begin(), mVectorKeyTouchListener.end(), varKeyTouchListener);

	if (tmpIterator != mVectorKeyTouchListener.end())
	{
		mVectorKeyTouchListener.erase(tmpIterator);
	}
	else
	{
		Helper::LOG("Error: KeyTouch::UnRegisterKeyTouchListener Not Register .");
		Helper::LOG(varKeyTouchListener->ClassName().c_str());
	}
}

void KeyTouch::OnKey(int varkeyCode)
{
	for (auto val : mVectorKeyTouchListener)
	{
		val->OnKey((KeyCode)varkeyCode);
	}
}

void KeyTouch::OnTouch(int varX, int varY)
{
	for (auto val : mVectorKeyTouchListener)
	{
		val->OnTouch(varX, varY);
	}
}

void KeyTouch::OnTouchRelease(int varX, int varY)
{
	for (auto val : mVectorKeyTouchListener)
	{
		val->OnTouchRelease(varX,varY);
	}
}
