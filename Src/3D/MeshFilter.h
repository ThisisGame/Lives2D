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

	const std::vector<unsigned short>& GetIndexInMaterial(const char* varMaterialName);

private:
	void LoadMesh(const char* varMeshPath);

private:
	Mesh* mMesh;

	std::vector<std::vector<unsigned short>> mVertexIndexInMaterial;


	struct cmp_str {
		bool operator()(const char* a, const char* b) const
		{
			return std::strcmp(a, b) < 0;//比较字符串的内容
		}
	};
	std::map<const char*, std::vector<unsigned short>, cmp_str> mMapIndexInMaterial;


};

