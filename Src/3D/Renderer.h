#pragma once
#include "Component/Component.h"
#include"Material.h"
#include"MeshFilter.h"

class Renderer :
	public Component
{
public:
	Renderer();
	~Renderer();

public:
	void Start() override;

	void Update() override;

public:
	virtual void Render();

protected:
	Material* mMaterial;
	Mesh* mMesh;
};

