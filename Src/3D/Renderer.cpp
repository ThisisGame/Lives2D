#include "Renderer.h"
#include"Component/Transform.h"
#include"Component/GameObject.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::Start()
{
	mMaterial = (Material*)mGameObject->GetComponent("Material");
	
	MeshFilter* tmpMeshFilter = (MeshFilter*)mGameObject->GetComponent("MeshFilter");
	mMesh = tmpMeshFilter->GetMesh();
}

void Renderer::Update()
{
	Render();
}

void Renderer::Render()
{
	
}
