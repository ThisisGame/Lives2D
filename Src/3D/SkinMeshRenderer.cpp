#include "SkinMeshRenderer.h"
#include"Tools/Application.h"
#include"Tools/Time.h"
#include"Component/Transform.h"
#include"Component/GameObject.h"

IMPLEMENT_DYNCRT_ACTION(SkinMeshRenderer)
SkinMeshRenderer::SkinMeshRenderer():mRunningTime(0),mMesh(nullptr), mFrameCount(0), mFrameTicks(160)
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

	//read FrameCount;
	tmpStream.read((char*)(&mFrameCount), sizeof(mFrameCount));

	//read frame ticks;
	tmpStream.read((char*)(&mFrameTicks), sizeof(mFrameTicks));

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
	if (mMesh == nullptr)
	{
		MeshFilter* tmpMeshFilter = (MeshFilter*)mGameObject->GetComponent("MeshFilter");
		mMesh = tmpMeshFilter->GetMesh();
	}

	if (mMesh== nullptr)
	{
		return;
	}

	int tmpVertexCount = mMesh->GetVertexCount();
	if (tmpVertexCount == 0)
	{
		return;
	}
	Vertex* tmpVertexArray = mMesh->GetVertexArray();
	if (tmpVertexArray == nullptr)
	{
		return;
	}

	//calculate current frame bone offset
	mRunningTime = mRunningTime + Time::deltaTime;
	int tmpCurrentFrame = mRunningTime * 30;
	tmpCurrentFrame = tmpCurrentFrame % mFrameCount;
	int tmpCurrentAnimTime = tmpCurrentFrame * mFrameTicks;

	//tmpCurrentAnimTime = 160*0;

	for (std::map<int, vector<glm::mat4x4>>::iterator  tmpIterBegin = mMapBoneMatrix.begin();  tmpIterBegin !=mMapBoneMatrix.end();  tmpIterBegin++)
	{
		if (tmpIterBegin->first == tmpCurrentAnimTime)
		{
			vector<glm::mat4x4> tmpVectorBoneMatrixOffset;

			for (size_t tmpVectorBoneMatrixIndex = 0; tmpVectorBoneMatrixIndex < tmpIterBegin->second.size(); tmpVectorBoneMatrixIndex++)
			{
				glm::mat4x4 tmpBoneMatrixOffset = tmpIterBegin->second[tmpVectorBoneMatrixIndex] * mVectorBoneMatrixInvert[tmpVectorBoneMatrixIndex];
				tmpVectorBoneMatrixOffset.push_back(tmpBoneMatrixOffset);
			}

			//calculate current frame vertex position
			glm::vec3* tmpVec3PositionAnim = (glm::vec3*)malloc(sizeof(glm::vec3)*mVectorWeight.size());

			for (size_t tmpVectorWeightIndex = 0; tmpVectorWeightIndex < mVectorWeight.size(); tmpVectorWeightIndex++)
			{
				glm::vec4 tmpVec4NewPosition;

				std::map<unsigned short, float> tmpMapOneVertexBoneWeight = mVectorWeight[tmpVectorWeightIndex];
				glm::vec3 tmpVec3PositionSrc = (tmpVertexArray + tmpVectorWeightIndex)->Position;

				for (std::map<unsigned short, float>::iterator tmpIterBegin = tmpMapOneVertexBoneWeight.begin(); tmpIterBegin != tmpMapOneVertexBoneWeight.end(); tmpIterBegin++)
				{
					glm::mat4x4 tmpMat4x4Offset= tmpVectorBoneMatrixOffset[tmpIterBegin->first];
					glm::vec4 tmpVec4PositionSrc(tmpVec3PositionSrc, 1);
					tmpVec4NewPosition+= (tmpMat4x4Offset*tmpVec4PositionSrc)*tmpIterBegin->second;
				}

				glm::vec3 tmpVec3NewPosition = glm::vec3(tmpVec4NewPosition.x, tmpVec4NewPosition.y, tmpVec4NewPosition.z);

				tmpVec3PositionAnim[tmpVectorWeightIndex] = tmpVec3NewPosition;
			}

			mMesh->PushVertexPositionAnim(tmpVec3PositionAnim);

			break;
		}
	}
}
