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

bool Raycast::ScreenPointToRay(Vector3& varScreenTouchPosition, Camera* varCamera, RaycastHit* varRaycastHit)
{

	//×ª»»µ½ NDC [-1,1] µÄ·¶Î§
	glm::vec4 tmpNDC_Start(
		((float)varScreenTouchPosition.mX / Application::ScreenWidth)*2.0f,
		((float)varScreenTouchPosition.mY / Application::ScreenHeight)*2.0f,
		-1.0f,// The near plane maps to Z=-1 in Normalized Device Coordinates
		1.0f
	);

	glm::vec4 tmpNDC_End(
		((float)varScreenTouchPosition.mX / Application::ScreenWidth)*2.0f,
		((float)varScreenTouchPosition.mY / Application::ScreenHeight)*2.0f,
		0.0f,
		1.0f
	);

	if (Camera::mainCamera == nullptr)
	{
		return false;
	}

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


	//get the raycast hit object(rigidbody)
	glm::vec3 tmpOriginVec3 =glm::vec3( tmpRayStart_World);
	glm::vec3 tmpDirectionVec3 = glm::vec3(tmpRayDir);
	glm::vec3 tmpOutEndVec3 = tmpOriginVec3 + tmpDirectionVec3*1000.0f;


	btVector3 tmpOrigin(tmpOriginVec3.x, tmpOriginVec3.y, tmpOriginVec3.z);
	btVector3 tmpEnd(tmpOutEndVec3.x, tmpOutEndVec3.y, tmpOutEndVec3.z);
	return PhysicsWorld::RayTest(tmpOrigin, tmpEnd, varRaycastHit);
}

