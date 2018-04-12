#pragma once
#include "Component/Component.h"
#include"glm/glm.hpp"

#include<vector>

class Camera :
	public Component
{
	DECLEAR_DYNCRT_ACTION(Camera)

public:
	Camera();
	~Camera();

public:
	void Awake() override;

	void Update() override;


public:
	glm::mat4 GetMatrix_View();

	glm::mat4 GetMatrix_Projection();

private:
	glm::mat4 mMatrix_View;
	glm::mat4 mMatrix_Projection;//Perspective/Orthographic


public:
	static std::vector<Camera*> sVectorCamera;
	static Camera* mainCamera;
};

