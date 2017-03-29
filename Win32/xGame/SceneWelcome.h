#pragma once
#include "ccscenebase.h"

#include"CCSceneManager.h"

#include"CCImage.h"

class SceneWelcome :public CCSceneBase
{
public:
	SceneWelcome(void);
	~SceneWelcome(void);

	virtual void Draw();

	virtual void Update();

private:
	void test();

private:
	CCImage* m_pLogoImg;
	CCImage* m_pSuvImg;

	vector<string> m_anmationFileVec;
	vector<CCImage*> m_animImgVec;
};

