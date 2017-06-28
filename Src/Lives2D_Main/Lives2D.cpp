#include"Lives2D.h"
#include"Tools\Helper.h"
#include"glm\glm.hpp"
#include"KeyTouch\KeyTouch.h"


int Lives2D::m_Width = 0;
int Lives2D::m_Height = 0;

float Lives2D::m_DesignWidth = 960.0f;
float Lives2D::m_DesignHeight = 540.0f;

DemoScene* Lives2D::mDemoScene = NULL;


void Lives2D::Init(EGLSurface & varEGLSurface, EGLDisplay & varEGLDisplay, int & varWidth, int & varHeight)
{
	m_Width = varWidth;
	m_Height = varHeight;


	mDemoScene = new DemoScene();
	mDemoScene->Init();
	
}



void Lives2D::Update(float varDeltaTime)
{
	mDemoScene->Update(varDeltaTime);
}



void Lives2D::Draw()
{
	mDemoScene->Draw();
}

void Lives2D::OnKey(KeyCode varkeyCode)
{
	KeyTouch::OnKey(varkeyCode);
}

void Lives2D::OnTouch(int varX, int varY)
{
	KeyTouch::OnTouch(varX, varY);
}

void Lives2D::OnTouchRelease(int varX, int varY)
{
	KeyTouch::OnTouchRelease(varX, varY);
}
