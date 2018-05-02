#pragma once
#include "Component/Component.h"
#include"Mesh.h"
#include<vector>

class MeshFilter :
	public Component
{
	DECLEAR_DYNCRT_ACTION(MeshFilter)

public:
	MeshFilter();
	~MeshFilter();


	void InitWithXml(TiXmlElement* varTiXmlElement) override;

	Mesh* GetMesh();

	const std::vector<unsigned short>& GetVertexIndexInMaterial(int varMaterialIndex);

private:
	void LoadMesh(const char* varMeshPath);

private:
	Mesh* mMesh;

	std::vector<std::vector<unsigned short>> mVertexIndexInMaterial;
};

