#pragma once

enum  UIRectType
{
	Type_UIClickRect=0,
	Type_UIDrawRect=1,
};

//UIRect is base of ui widget
class UIRect
{
private:
	int mDepth; //Depth use to control front or back

	UIRectType mUIRectType;

public:
	UIRect(UIRectType varUIRectType);
	~UIRect();

public:


	//设置深度
	void SetDepth(int varDepth);

	//获取深度
	int GetDepth();


	virtual void Update(float varDeltaTime) {};

	//绘制
	virtual void Draw() {};
};

