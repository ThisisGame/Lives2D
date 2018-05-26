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
	LoadMesh(Application::GetFullPath(tmpMeshFilePath).c_str());
}

Mesh * MeshFilter::GetMesh()
{
	return mMesh;
}

void MeshFilter::LoadMesh(const char * varMeshPath)
{
	std::ifstream tmpStream(varMeshPath, std::ios::binary);

	
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

		unsigned short tmpIndexCount = tmpIndicesMemSize / sizeof(unsigned short);

		
		tmpMesh->SetVertexIndicesSize(tmpIndexCount);

		//读取index数据;

		unsigned short* tmpVertexIndices = (unsigned short*)malloc(tmpIndicesMemSize);

		
		tmpStream.read((char*)tmpVertexIndices, tmpIndicesMemSize);
		tmpMesh->PushVertexIndicesArray(tmpVertexIndices);

		//读取材质数量
		int tmpMaterialSize = 0;
		tmpStream.read((char*)(&tmpMaterialSize), sizeof(tmpMaterialSize));


		for (size_t i = 0; i < tmpMaterialSize; i++)
		{
			//读取材质名字
			unsigned char tmpMaterialNameStringSize = 0;
			tmpStream.read((char*)(&tmpMaterialNameStringSize), sizeof(tmpMaterialNameStringSize));

			char* tmpMaterialNameStr = (char*)malloc(tmpMaterialNameStringSize);
			tmpStream.read(tmpMaterialNameStr, tmpMaterialNameStringSize);

			//读取贴图数量
			unsigned char tmpTextureCount = 0;
			tmpStream.read((char*)(&tmpTextureCount), sizeof(tmpTextureCount));

			for (unsigned char tmpTextureIndex = 0; tmpTextureIndex < tmpTextureCount; tmpTextureIndex++)
			{
				//读取贴图名字
				unsigned char tmpTextureNameStringSize = 0;
				tmpStream.read((char*)(&tmpTextureNameStringSize), sizeof(tmpTextureNameStringSize));

				char* tmpTextureNameStr = (char*)malloc(tmpTextureNameStringSize);
				tmpStream.read(tmpTextureNameStr, tmpTextureNameStringSize);

				//获取UV Tiling、Offset
				float tmpUTilingValue = 0.0f;
				tmpStream.read((char*)(&tmpUTilingValue), sizeof(tmpUTilingValue));

				float tmpVTilingValue = 0.0f;
				tmpStream.read((char*)(&tmpVTilingValue), sizeof(tmpVTilingValue));

				float tmpUOffsetValue = 0.0f;
				tmpStream.read((char*)(&tmpUOffsetValue), sizeof(tmpUOffsetValue));

				float tmpVOffsetValue = 0.0f;
				tmpStream.read((char*)(&tmpVOffsetValue), sizeof(tmpVOffsetValue));
			}
		}

		mMesh = tmpMesh;
	}

	tmpStream.close();
}
