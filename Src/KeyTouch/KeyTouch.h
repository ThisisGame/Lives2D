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
	static void OnKey(KeyCode varkeyCode);

	//ÆÁÄ»´¥Ãþµã»÷
	static void OnTouch(float varX, float varY);

	//ÊÍ·Åµã»÷
	static void OnTouchRelease(float varX, float varY);
};


