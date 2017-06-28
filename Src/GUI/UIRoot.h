#pragma once

#include<vector>
#include"UIRect.h"

//UIRoot is base of ui widget
class UIRoot
{
private:
	int mDepth; //Depth use to control front or back

	std::vector<UIRect*> mVectorUIRect;//children widget
public:
	UIRoot();
	~UIRoot();

public:
	void Update(float varDeltaTime);

	void Draw();

public:
	void AddChild(UIRect* varUIRect);

	void RemoveChild(UIRect* varUIRect);
};

