#pragma once
#include "Component/Behavior.h"
#include"glm/glm.hpp"

class Camera :
	public Behavior
{
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
};

