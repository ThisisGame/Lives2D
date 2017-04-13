#include"Game2D.h"
#include"Tools\Helper.h"
#include"glm\glm.hpp"


int Game2D::m_Width = 0;
int Game2D::m_Height = 0;

float Game2D::m_DesignWidth = 960.0f;
float Game2D::m_DesignHeight = 540.0f;

Image* Game2D::mImage = NULL;

void Game2D::Init(EGLSurface & varEGLSurface, EGLDisplay & varEGLDisplay, int & varWidth, int & varHeight)
{
	m_Width = varWidth;
	m_Height = varHeight;


	//图片初始化
	mImage = new Image();
	mImage->Init("../../Resources/images/logo.png");
}



void Game2D::Update(float varDeltaTime)
{
	Helper::LOG(std::to_string(varDeltaTime).c_str());

	//Scale Test
	mImage->SetScale(1.0f+ varDeltaTime, 1.0f+ varDeltaTime);
}



void Game2D::Draw()
{
	//绘制一个图片
	mImage->Draw();
}
