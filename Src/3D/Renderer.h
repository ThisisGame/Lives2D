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
	void Update() override;

public:
	virtual void Render();

protected:
	std::vector<Material*> mVectorMaterial;
	MeshFilter* mMeshFilter;
	Mesh* mMesh;

private:
	bool mSetProperty;
};

