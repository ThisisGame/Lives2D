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

	//¶ÔMaterialÉèÖÃÊôĞÔ
	mMaterial->SetVertexAttribPointer("pos", 3, sizeof(Vertex), &(mMesh->GetVertexArray()->Position.x));
	mMaterial->SetVertexAttribPointer("uv", 2, sizeof(Vertex),&(mMesh->GetVertexArray()->TexCoords.x));
	mMaterial->SetVertexAttribPointer("normal", 3, sizeof(Vertex), &(mMesh->GetVertexArray()->Normal.x));
}

void Renderer::Update()
{
	Render();
}

void Renderer::Render()
{
	mMaterial->Render();
}
