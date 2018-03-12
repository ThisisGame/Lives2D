#include "Camera.h"
#include<vector>
#include"Component/GameObject.h"
#include"glm/matrix.hpp"
#include<glm/gtc/matrix_transform.hpp>
#include"Tools/Application.h"

Camera::Camera()
{
}


Camera::~Camera()
{
}

void Camera::Awake()
{

}

void Camera::Update()
{
	mMatrix_View= glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	mMatrix_Projection = glm::perspectiveFov(3.14592f/2.0f, 1.0f, 1.0f, 0.0f, 100.0f);
}

glm::mat4 Camera::GetMatrix_View()
{
	return mMatrix_View;
}

glm::mat4 Camera::GetMatrix_Projection()
{
	return mMatrix_Projection;
}


