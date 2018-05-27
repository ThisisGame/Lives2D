#include "Renderer.h"
#include"Component/Transform.h"
#include"Component/GameObject.h"


Renderer::Renderer():mSetProperty(false),mMeshFilter(nullptr),mMesh(nullptr)
{
}


Renderer::~Renderer()
{
}

void Renderer::Update()
{
	if (mMesh == nullptr)
	{
		mMeshFilter = (MeshFilter*)mGameObject->GetComponent("MeshFilter");
		mMesh = mMeshFilter->GetMesh();
	}

	if (mVectorMaterial.size()==0)
	{
		std::vector<Component*> tmpVectorComponent= mGameObject->GetComponents("Material");
		for (size_t i = 0; i < tmpVectorComponent.size(); i++)
		{
			mVectorMaterial.push_back((Material*)tmpVectorComponent[i]);
		}
	}

	if (mMesh && mVectorMaterial.size()>0 && !mSetProperty)
	{
		mSetProperty = true;

		//∂‘Material…Ë÷√ Ù–‘
		for (size_t i = 0; i < mVectorMaterial.size(); i++)
		{
			mVectorMaterial[i]->SetVertexAttribPointer("m_position", 3, sizeof(Vertex), &(mMesh->GetVertexArray()->Position.x));
			mVectorMaterial[i]->SetVertexAttribPointer("m_uv", 2, sizeof(Vertex), &(mMesh->GetVertexArray()->TexCoords.x));

			mVectorMaterial[i]->SetVertexAttribPointer("m_normal", 3, sizeof(Vertex), &(mMesh->GetVertexArray()->Normal.x));

			mVectorMaterial[i]->SetVertexIndices(mMesh->GetVertexIndicesSize(),mMesh->GetVertexIndices());
		}
	}
	else
	{
		if (mMesh->GetApplyedSkin())
		{
			for (size_t i = 0; i < mVectorMaterial.size(); i++)
			{
				mVectorMaterial[i]->SetVertexAttribPointer("m_position", 3, sizeof(glm::vec3), mMesh->GetVertexPositionAnim());
			}
			
		}

		Render();
	}
}

void Renderer::Render()
{
	for (size_t i = 0; i < mVectorMaterial.size(); i++)
	{
		mVectorMaterial[i]->Render();
	}
	
}
