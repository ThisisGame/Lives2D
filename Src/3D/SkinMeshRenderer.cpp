#include "SkinMeshRenderer.h"
#include"Tools/Application.h"


IMPLEMENT_DYNCRT_ACTION(SkinMeshRenderer)
SkinMeshRenderer::SkinMeshRenderer()
{
}


SkinMeshRenderer::~SkinMeshRenderer()
{

}

void SkinMeshRenderer::InitWithXml(TiXmlElement * varTiXmlElement)
{
	const char* tmpMeshFilePath = varTiXmlElement->Attribute("Anim");
	LoadAnim(Application::GetFullPath(tmpMeshFilePath));
}

void SkinMeshRenderer::LoadAnim(const char* varAnimPath)
{
	std::ifstream tmpStream(varAnimPath, std::ios::binary);

	//∂¡»°BoneCount;
	int tmpBoneCount = 0;
	tmpStream.read((char*)(&tmpBoneCount), sizeof(tmpBoneCount));

	for (size_t tmpBoneIndex = 0; tmpBoneIndex < tmpBoneCount; tmpBoneIndex++)
	{
		//read bone name size
		int tmpBoneNameStringSize = 0;
		tmpStream.read((char*)(&tmpBoneNameStringSize), sizeof(tmpBoneNameStringSize));

		//read bone name
		char* tmpBoneNameStr = (char*)malloc(tmpBoneNameStringSize);
		memset(tmpBoneNameStr, 0, tmpBoneNameStringSize);
		tmpStream.read(tmpBoneNameStr, tmpBoneNameStringSize);

		mVectorBoneName.push_back(tmpBoneNameStr);
	}

	//the zero frame invert matrix
	int tmpVectorBoneMatrixInvertSize = 0;
	tmpStream.read((char*)(&tmpVectorBoneMatrixInvertSize), sizeof(tmpVectorBoneMatrixInvertSize));
	for (size_t tmpBoneGMatrixInvertIndex = 0; tmpBoneGMatrixInvertIndex < tmpVectorBoneMatrixInvertSize; tmpBoneGMatrixInvertIndex++)
	{
		glm::mat4x4 tmpMat4x4BoneMatrixInvert;
		tmpStream.read((char*)(&tmpMat4x4BoneMatrixInvert), sizeof(tmpMat4x4BoneMatrixInvert));

		mVectorBoneMatrixInvert.push_back(tmpMat4x4BoneMatrixInvert);
	}

	//the bone animation matrix data
	int tmpMapBoneMatrixSize = 0;
	tmpStream.read((char*)(&tmpMapBoneMatrixSize), sizeof(tmpMapBoneMatrixSize));
	for (int tmpMapBoneMatrixIndex = 0; tmpMapBoneMatrixIndex < tmpMapBoneMatrixSize; tmpMapBoneMatrixIndex++)
	{
		//read timeValueCurrent
		int tmpTimeValueCurrent = 0;
		tmpStream.read((char*)(&tmpTimeValueCurrent), sizeof(tmpTimeValueCurrent));

		//read bone matrix data currentTime
		vector<glm::mat4x4> tmpVectorMatrixCurrent;
		int tmpVectorMatrixCurrentSize = 0;
		tmpStream.read((char*)(&tmpVectorMatrixCurrentSize), sizeof(tmpVectorMatrixCurrentSize));

		for (int tmpVectorMatrixCurrentIndex = 0; tmpVectorMatrixCurrentIndex < tmpVectorMatrixCurrentSize; tmpVectorMatrixCurrentIndex++)
		{
			glm::mat4x4 tmpMat4x4BoneMatrix;
			tmpStream.read((char*)(&tmpMat4x4BoneMatrix), sizeof(tmpMat4x4BoneMatrix));

			tmpVectorMatrixCurrent.push_back(tmpMat4x4BoneMatrix);
		}

		mMapBoneMatrix.insert(pair<int, vector<glm::mat4x4>>(tmpTimeValueCurrent, tmpVectorMatrixCurrent));
	}

	//read vertex weight
	int tmpVectorVertexWeightSize = 0;
	tmpStream.read((char*)(&tmpVectorVertexWeightSize), sizeof(tmpVectorVertexWeightSize));

	for (int  tmpVectorVertexWeightIndex = 0; tmpVectorVertexWeightIndex < tmpVectorVertexWeightSize; tmpVectorVertexWeightIndex++)
	{
		//one vertex weight infos
		int tmpMapWeightOneVertexSize = 0;
		tmpStream.read((char*)(&tmpMapWeightOneVertexSize), sizeof(tmpMapWeightOneVertexSize));

		std::map<unsigned short, float> tmpMapWeight;

		for (int  tmpMapWeightOneVertexIndex = 0; tmpMapWeightOneVertexIndex < tmpMapWeightOneVertexSize; tmpMapWeightOneVertexIndex++)
		{
			//read bone index
			unsigned short tmpBoneIndex = 0;
			tmpStream.read((char*)(&tmpBoneIndex), sizeof(tmpBoneIndex));

			float tmpWeight = 0;
			tmpStream.read((char*)(&tmpWeight), sizeof(tmpWeight));

			tmpMapWeight.insert(std::pair<unsigned short, float>(tmpBoneIndex,tmpWeight));
		}

		mVectorWeight.push_back(tmpMapWeight);
	}

	tmpStream.close();
}

void SkinMeshRenderer::Update()
{
}
