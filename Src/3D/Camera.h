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
	void OnEnable() override;
	void Start() override;

	void Update() override;

	void OnDisable() override;
	void OnDestroy() override;

private:
	glm::mat4 mMatrix_View;
	glm::mat4 mMatrix_Projection;//Perspective/Orthographic
};

