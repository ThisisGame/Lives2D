#pragma once
#include "Component/Component.h"
#include"Mesh.h"

class MeshFilter :
	public Component
{
	DECLEAR_DYNCRT_ACTION(MeshFilter)

public:
	MeshFilter();
	~MeshFilter();


	void InitWithXml(TiXmlElement* varTiXmlElement) override;

	Mesh* GetMesh();

private:
	void LoadMesh(const char* varMeshPath);

private:
	Mesh* mMesh;
};

