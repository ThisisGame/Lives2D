#pragma once

enum  UIRectType
{
	Type_UIClickRect=0,
	Type_UIDrawRect=1,
};

//UIRect is base of ui widget
class UIRect
{
public:
	int mDepth; //Depth use to control front or back

	UIRectType mUIRectType;

public:
	UIRect(UIRectType varUIRectType);
	~UIRect();

public:
	void Update(float varDeltaTime) {};
};

