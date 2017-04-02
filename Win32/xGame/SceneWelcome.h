#pragma once
#include "ccscenebase.h"
#include"CCSceneManager.h"
#include"CCImage.h"
#include<iostream>
#include<vector>

class SceneWelcome :public CCSceneBase
{
public:
	SceneWelcome(void);
	~SceneWelcome(void);

	virtual void Draw();

	virtual void Update();


private:
	CCImage* m_pLogoImg;
};

