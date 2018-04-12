#include "Camera.h"
#include<vector>
#include"Component/GameObject.h"
#include"glm/matrix.hpp"
#include<glm/gtc/matrix_transform.hpp>
#include"Tools/Application.h"

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
	mMatrix_View= glm::lookAt(glm::vec3(0, 0, 10 + Application::MouseWheel/12.0), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
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


