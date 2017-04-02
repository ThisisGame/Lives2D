#include "SceneWelcome.h"
#include"ShaderTest.h"
#include"CCAudioManager.h"



SceneWelcome::SceneWelcome(void)
{
	m_pLogoImg=new CCImage();
	m_pLogoImg->Init("./Resources/images/Logo.png");


	CCAudioManager::SharedInstance()->LoadBGMusic("Resources/sound/effect/skill.wav");
	CCAudioManager::SharedInstance()->PlayBGMusic("Resources/sound/effect/skill.wav");
}



void SceneWelcome::Draw()
{
	m_pLogoImg->Draw(0.0f,0.0f);
}


void SceneWelcome::Update()
{
}

SceneWelcome::~SceneWelcome(void)
{

}
