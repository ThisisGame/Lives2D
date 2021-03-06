#include "Camera.h"
#include<vector>
#include"Component/GameObject.h"
#include"glm/matrix.hpp"
#include<glm/gtc/matrix_transform.hpp>
#include"Tools/Application.h"
#include"Component/Transform.h"
#include<glm/gtx/euler_angles.hpp>

IMPLEMENT_DYNCRT_ACTION(Camera)
Camera::Camera()
{
}


Camera::~Camera()
{
}


std::vector<Camera*> Camera::sVectorCamera;
Camera* Camera::mainCamera;

void Camera::Awake()
{
	if (mainCamera == nullptr)
	{
		mainCamera = this;
	}

	sVectorCamera.push_back(this);
}

void Camera::Update()
{
	//mMatrix_View= glm::lookAt(glm::vec3(0, 0, 10 + Application::MouseWheel/120.0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	glm::vec3 tmpVector3CameraPosition = glm::vec3(mTransform->GetLocalPosition().mX, mTransform->GetLocalPosition().mY, mTransform->GetLocalPosition().mZ + Application::MouseWheel );
	glm::vec3 tmpVector3CameraRotation = glm::vec3(mTransform->GetLocalRotation().mX, mTransform->GetLocalRotation().mY, mTransform->GetLocalRotation().mZ);
	glm::vec3 tmpVector3CenterPosition = glm::vec3(mTransform->GetLocalPosition().mX, mTransform->GetLocalPosition().mY, mTransform->GetLocalPosition().mZ + Application::MouseWheel -10);
	glm::mat4 rotation = glm::eulerAngleYXZ(glm::radians(mTransform->GetLocalRotation().mY), glm::radians(mTransform->GetLocalRotation().mX), glm::radians(mTransform->GetLocalRotation().mZ));
	glm::vec4 tmpVector4CenterPosition = glm::vec4(tmpVector3CenterPosition,1) * rotation;
	tmpVector3CenterPosition.x = tmpVector4CenterPosition.x;
	tmpVector3CenterPosition.y = tmpVector4CenterPosition.y;
	tmpVector3CenterPosition.z = tmpVector4CenterPosition.z;

	mMatrix_View = glm::lookAt(tmpVector3CameraPosition, tmpVector3CenterPosition, glm::vec3(0, 1, 0));
	mMatrix_Projection = glm::perspective(glm::radians(45.0f), (float)Application::DesignWidth / (float)Application::DesignHeight, 0.3f, 1000.0f);
}

glm::mat4 Camera::GetMatrix_View()
{
	return mMatrix_View;
}

glm::mat4 Camera::GetMatrix_Projection()
{
	return mMatrix_Projection;
}


