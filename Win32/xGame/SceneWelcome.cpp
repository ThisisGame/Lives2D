#include "SceneWelcome.h"
#include"ShaderNormal.h"
#include"CCTexture.h"
#include"ShaderTest.h"
#include"CCAudioManager.h"
#include"CCEventManager.h"



SceneWelcome::SceneWelcome(void)
{
	m_pLogoImg=new CCImage();
	m_pLogoImg->SetImageFile("./Resources/images/test.png");

	m_pSuvImg=new CCImage();
	m_pSuvImg->SetImageFile("./Resources/images/suv.png");

	for(int i=0;i<=154;i++)
	{
		char c[50];
		sprintf(c,"./Resources/images/leimileiya/%d.png",i);
		m_anmationFileVec.push_back(c);

		CCImage* image=new CCImage();
		image->SetImageFile(m_anmationFileVec[i]);
		m_animImgVec.push_back(image);
	}

	typedef void (SceneWelcome::*pFunc)(void);
	pFunc p=&SceneWelcome::test;
	
	CCEventManager<SceneWelcome>::SharedInstance()->RegisterEvent(KEY_A_PRESS,this,&SceneWelcome::test);

	
	CCAudioManager::SharedInstance()->LoadBGMusic("Resources/sound/effect/skill.wav");
	CCAudioManager::SharedInstance()->PlayBGMusic("Resources/sound/effect/skill.wav");
}

void SceneWelcome::test()
{
	Helper::CCLOG("test registerevent");
}

static int index=0;
void SceneWelcome::Draw()
{
	CCEngine::DrawBegin();
	static float m_xMove=0.0f;
	m_xMove+=0.0005f;
	if(m_xMove>0.5f)
	{
		m_xMove=-0.5f;
	}

	static float m_xMove1=0.0f;
	m_xMove1+=0.001f;
	if(m_xMove1>1.0f)
	{
		m_xMove1=-1.0f;
	}

	m_pLogoImg->DrawImage(m_xMove,0.0f,0.5f,0.5f);
	
	m_pSuvImg->DrawImage(m_xMove1,0.5f,0.5f,0.5f);

	
	index++;
	if(index>154*5)
	{
		index=0;
	}
	m_animImgVec[index/5]->DrawImage(-0.5f,-0.5f,0.2f,0.266666f);

	
	CCEngine::DrawEnd();
}


void SceneWelcome::Update()
{
}

SceneWelcome::~SceneWelcome(void)
{

}
