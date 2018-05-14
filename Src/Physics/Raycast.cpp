#include "Raycast.h"
#include"glm/glm.hpp"
#include"Tools/Application.h"

Raycast::Raycast()
{
}


Raycast::~Raycast()
{
}

void Raycast::RaycastScreenPosToWorld(int varScreenX, int varScreenY, Camera * varCamera, Vector3 & varOrigin, Vector3 & varDirection)
{

	//×ª»»µ½ NDC [-1,1] µÄ·¶Î§
	glm::vec4 tmpNDC_Start(
		((float)varScreenX / Application::ScreenWidth - 0.5f)*2.0f,
		((float)varScreenY / Application::ScreenWidth - 0.5f)*2.0f,
		-1.0f,// The near plane maps to Z=-1 in Normalized Device Coordinates
		1.0f
	);

	glm::vec4 tmpNDC_Start(
		((float)varScreenX / Application::ScreenWidth - 0.5f)*2.0f,
		((float)varScreenY / Application::ScreenWidth - 0.5f)*2.0f,
		0.0f,
		1.0f
	);

	glm::mat4 tmpMatrixInverseProjection =glm::inverse( Camera::mainCamera->GetMatrix_Projection());

	glm::mat4 tmpMatrixInverseView = glm::inverse(Camera::mainCamera->GetMatrix_View());
	


}

