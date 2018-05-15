#include "Raycast.h"
#include"glm/glm.hpp"
#include"Tools/Application.h"
#include"btBulletDynamicsCommon.h"
#include"PhysicsWorld.h"

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

	glm::vec4 tmpNDC_End(
		((float)varScreenX / Application::ScreenWidth - 0.5f)*2.0f,
		((float)varScreenY / Application::ScreenWidth - 0.5f)*2.0f,
		0.0f,
		1.0f
	);

	glm::mat4 tmpMatrixInverseProjection =glm::inverse( Camera::mainCamera->GetMatrix_Projection());

	glm::mat4 tmpMatrixInverseView = glm::inverse(Camera::mainCamera->GetMatrix_View());
	
	glm::vec4 tmpRayStart_Camera = tmpMatrixInverseProjection * tmpNDC_Start;
	tmpRayStart_Camera = tmpRayStart_Camera / tmpRayStart_Camera.w;

	glm::vec4 tmpRayEnd_Camera = tmpMatrixInverseProjection * tmpNDC_End;
	tmpRayEnd_Camera = tmpRayEnd_Camera / tmpRayEnd_Camera.w;

	glm::vec4 tmpRayStart_World = tmpMatrixInverseView*tmpRayStart_Camera;
	tmpRayStart_World = tmpRayStart_World / tmpRayStart_World.w;

	glm::vec4 tmpRayEnd_World = tmpMatrixInverseView*tmpRayEnd_Camera;
	tmpRayEnd_World = tmpRayEnd_World / tmpRayEnd_World.w;

	glm::vec4 tmpRayDir =glm::normalize( tmpRayEnd_World - tmpRayStart_World);
	varDirection.mX = tmpRayDir.x;
	varDirection.mY = tmpRayDir.y;
	varDirection.mZ = tmpRayDir.z;


	varOrigin.mX = tmpRayStart_World.x;
	varOrigin.mY = tmpRayStart_World.y;
	varOrigin.mZ = tmpRayStart_World.z;

	//get the raycast hit object(rigidbody)
	glm::vec3 tmpOrigin =glm::vec3( tmpRayStart_World);
	glm::vec3 tmpDirection = glm::vec3(tmpRayDir);
	glm::vec3 tmpOutEnd = tmpOrigin + tmpDirection*1000.0f;

	btCollisionWorld::ClosestRayResultCallback tmpRayResultCallback(btVector3(tmpOrigin.x, tmpOrigin.y, tmpOrigin.z), btVector3(tmpOutEnd.x, tmpOutEnd.y, tmpOutEnd.z));
	PhysicsWorld::dy
}

