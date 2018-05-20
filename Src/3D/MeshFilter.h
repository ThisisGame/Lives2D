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

#ifdef MINI_MESH
	const std::vector<unsigned short>& GetVertexIndexInMaterial(int varMaterialIndex);
#else
	const std::vector<int>& GetVertexIndexInMaterial(int varMaterialIndex);
#endif
	
#ifdef MINI_MESH
	const std::vector<unsigned short>& GetIndexInMaterial(const char* varMaterialName);
#else
	const std::vector<int>& GetIndexInMaterial(const char* varMaterialName);
#endif
	

private:
	void LoadMesh(const char* varMeshPath);

private:
	Mesh* mMesh;

#ifdef MINI_MESH
	std::vector<std::vector<unsigned short>> mVertexIndexInMaterial;
#else
	std::vector<std::vector<int>> mVertexIndexInMaterial;
#endif
	


	struct cmp_str {
		bool operator()(const char* a, const char* b) const
		{
			return std::strcmp(a, b) < 0;//比较字符串的内容
		}
	};

#ifdef MINI_MESH
	std::map<const char*, std::vector<unsigned short>, cmp_str> mMapIndexInMaterial;
#else
	std::map<const char*, std::vector<int>, cmp_str> mMapIndexInMaterial;
#endif
	


};

