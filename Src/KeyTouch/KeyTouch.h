#pragma once

#include"KeyTouchListener.h"

#include<vector>

class KeyTouch
{
public:
	KeyTouch();
	~KeyTouch();

private:
	static std::vector<KeyTouchListener*> mVectorKeyTouchListener;

public:
	static void RegisterKeyTouchListener(KeyTouchListener* varKeyTouchListener);

	static void UnRegisterKeyTouchListener(KeyTouchListener* varKeyTouchListener);


	//¼üÅÌÊó±ê
	static void OnKey(int varkeyCode);

	//ÆÁÄ»´¥Ãşµã»÷
	static void OnTouch(int varX, int varY);

	//ÊÍ·Åµã»÷
	static void OnTouchRelease(int varX, int varY);
};


