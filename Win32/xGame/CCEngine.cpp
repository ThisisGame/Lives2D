#include"CCEngine.h"

CCEngine::CCEngine()
{

}


void CCEngine::DrawBegin()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void CCEngine::DrawEnd()
{
	glutSwapBuffers();
}

CCEngine::~CCEngine()
{

}