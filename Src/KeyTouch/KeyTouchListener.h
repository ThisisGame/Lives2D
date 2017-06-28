#pragma once

#include"KeyCode.h"
#include<string>

class KeyTouchListener
{
private:
	std::string mClassName;

private:
	KeyTouchListener() {};

public:
	KeyTouchListener(std::string varClassName):mClassName(varClassName)
	{
		
	};


	~KeyTouchListener() {};


	

public:
	virtual void OnKey(KeyCode varkeyCode)=0;

	virtual void OnTouch(int varX, int varY)=0;

	virtual void OnTouchRelease(int varX, int varY) = 0;

	std::string ClassName()
	{
		return mClassName;
	}
};
