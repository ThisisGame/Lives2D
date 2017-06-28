#pragma once

#include"UIRect.h"


//UIDrawRect is base of ui widget
class UIDrawRect:public UIRect
{
public:
	UIDrawRect();
	~UIDrawRect();

public:
	//»æÖÆ
	virtual void Draw() {};


};

