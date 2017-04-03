#pragma once
#include "Helper.h"

class CCSceneBase
{
public:
	CCSceneBase(void);
	~CCSceneBase(void);

	virtual void Draw(){};
	virtual void Update(){};
};

