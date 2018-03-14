#include "MeshFilter.h"
#include<fstream>
#include<iostream>
#include"Texture.h"
#include"Tools/Application.h"

IMPLEMENT_DYNCRT_ACTION(MeshFilter)

MeshFilter::MeshFilter():mMesh(nullptr)
{
}


MeshFilter::~MeshFilter()
{
}

void MeshFilter::InitWithXml(TiXmlElement * varTiXmlElement)
{
	const char* tmpMeshFilePath = varTiXmlElement->Attribute("Mesh");
	LoadMesh(Application::GetFullPath(tmpMeshFilePath));
}

Mesh * MeshFilter::GetMesh()
{
	return mMesh;
}

void MeshFilter::LoadMesh(const char * varMeshPath)
{
	std::ifstream tmpStream(varMeshPath, std::ios::binary);

	//读取meshcount;
	int tmpMeshCount = 0;
	tmpStream.read((char*)(&tmpMeshCount), sizeof(int));

	for (int tmpMeshIndex = 0; tmpMeshIndex < tmpMeshCount; tmpMeshIndex++)
	{
		Mesh* tmpMesh=new Mesh();

		//读取VertexMemSize;
		int tmpVertexMemSize = 0;
		tmpStream.read((char*)(&tmpVertexMemSize), sizeof(int));
		
		//计算VertexCount;
		int tmpVertexCount = tmpVertexMemSize / sizeof(Vertex);

		tmpMesh->SetVertexCount(tmpVertexCount);

		//读取Vertex数据;
		Vertex* tmpVertexArray = (Vertex*)malloc(tmpVertexMemSize);
		tmpStream.read((char*)tmpVertexArray, tmpVertexMemSize);
		tmpMesh->PushVertexArray(tmpVertexArray);

		//读取IndicesMemSize;
		int tmpIndicesMemSize = 0;
		tmpStream.read((char*)(&tmpIndicesMemSize), sizeof(int));

		//计算IndexCount;
		int tmpIndexCount = tmpIndicesMemSize / sizeof(int);

		//读取index数据;
		for (int tmpIndexIndex = 0; tmpIndexIndex < tmpIndexCount; tmpIndexIndex++)
		{
			int index = 0;
			tmpStream.read((char*)(&index), sizeof(index));
			//mesh.indices.push_back(index);
		}

		//读取TextureMemSize;
		int tmpTextureMemSize = 0;
		tmpStream.read((char*)(&tmpTextureMemSize), sizeof(int));

		//计算 TextureCount;
		int tmpTextureCount = tmpTextureMemSize / sizeof(Texture);

		//读取Texture数据;
		for (int tmpTextureIndex = 0; tmpTextureIndex < tmpTextureCount; tmpTextureIndex++)
		{
			Texture tmpTexture;
			tmpStream.read((char*)(&tmpTexture), sizeof(Texture));
		}

		mMesh = tmpMesh;
	}

	tmpStream.close();
}
