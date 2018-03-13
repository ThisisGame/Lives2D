#include "Renderer.h"
#include"Component/Transform.h"
#include"Component/GameObject.h"


Renderer::Renderer():mSetProperty(false),mMesh(nullptr),mMaterial(nullptr)
{
}


Renderer::~Renderer()
{
}

void Renderer::Update()
{
	if (mMesh == nullptr)
	{
		MeshFilter* tmpMeshFilter = (MeshFilter*)mGameObject->GetComponent("MeshFilter");
		mMesh = tmpMeshFilter->GetMesh();
	}

	if (mMaterial == nullptr)
	{
		mMaterial = (Material*)mGameObject->GetComponent("Material");
	}

	if (mMesh && mMaterial && !mSetProperty)
	{
		mSetProperty = true;

		//¶ÔMaterialÉèÖÃÊôĞÔ
		mMaterial->SetVertexAttribPointer("m_position", 3, sizeof(Vertex), &(mMesh->GetVertexArray()->Position.x));
		mMaterial->SetVertexAttribPointer("m_uv", 2, sizeof(Vertex), &(mMesh->GetVertexArray()->TexCoords.x));
		//mMaterial->SetVertexAttribPointer("normal", 3, sizeof(Vertex), &(mMesh->GetVertexArray()->Normal.x));
	}
	else
	{
		Render();
	}
}

void Renderer::Render()
{
	mMaterial->Render();
}
