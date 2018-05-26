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
	LoadAnim(Application::GetFullPath(tmpMeshFilePath).c_str());
}

void SkinMeshRenderer::LoadAnim(const char* varAnimPath)
{
	std::ifstream tmpStream(varAnimPath, std::ios::binary);

	//read FrameCount;
	tmpStream.read((char*)(&mFrameCount), sizeof(mFrameCount));

	//read frame ticks;
	tmpStream.read((char*)(&mFrameTicks), sizeof(mFrameTicks));

	//读取BoneCount;
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


			tmpMapWeight.insert(std::pair<unsigned short, float>(tmpBoneIndex, tmpWeight));

			
		}

		mVectorWeight.push_back(tmpMapWeight);
	}


	//读取顶点初始位置
	for (int tmpVectorVertexWeightIndex = 0; tmpVectorVertexWeightIndex < tmpVectorVertexWeightSize; tmpVectorVertexWeightIndex++)
	{

		unsigned short tmpMapWeightOneVertexSize = 0;

		
		tmpStream.read((char*)(&tmpMapWeightOneVertexSize), sizeof(tmpMapWeightOneVertexSize));

		std::vector<glm::vec4> tmpVectorOneVertexPositionNoBone;
		for (int tmpMapWeightOneVertexIndex = 0; tmpMapWeightOneVertexIndex < tmpMapWeightOneVertexSize; tmpMapWeightOneVertexIndex++)
		{
			glm::vec4 tmpVec3PositionNoBone;
			tmpStream.read((char*)(&tmpVec3PositionNoBone), sizeof(tmpVec3PositionNoBone));

			tmpVectorOneVertexPositionNoBone.push_back(tmpVec3PositionNoBone);
		}

		mVectorVertexPositionNoBone.push_back(tmpVectorOneVertexPositionNoBone);
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

	//int tmpUpdateBeginTime = GetTickCount();

	//calculate current frame bone offset
	mRunningTime = mRunningTime + Time::deltaTime;
	int tmpCurrentFrame = mRunningTime * 30;
	tmpCurrentFrame = tmpCurrentFrame % mFrameCount;
	int tmpCurrentAnimTime = tmpCurrentFrame * mFrameTicks;

	//tmpCurrentAnimTime = 160*0;

	for (std::map<int, vector<glm::mat4x4>>::iterator  tmpMapBoneMatrixIterBegin = mMapBoneMatrix.begin();  tmpMapBoneMatrixIterBegin !=mMapBoneMatrix.end();  tmpMapBoneMatrixIterBegin++)
	{
		if (tmpMapBoneMatrixIterBegin->first == tmpCurrentAnimTime)
		{

			//calculate current frame vertex position
			glm::vec3* tmpVec3PositionAnim = mMesh->GetVertexPositionAnim();

			glm::vec4 tmpVec4PositionSrc;
			glm::vec4 tmpVec4PositionNew;

			for (size_t tmpVectorWeightIndex = 0; tmpVectorWeightIndex < mVectorWeight.size(); tmpVectorWeightIndex++)
			{
				glm::vec3& tmpVec3PositionSrc = (tmpVertexArray + tmpVectorWeightIndex)->Position;
				
				tmpVec4PositionSrc.x = tmpVec3PositionSrc.x;
				tmpVec4PositionSrc.y = -tmpVec3PositionSrc.z;
				tmpVec4PositionSrc.z = tmpVec3PositionSrc.y;
				tmpVec4PositionSrc.w = 1;



				
				tmpVec4PositionNew.x = 0;
				tmpVec4PositionNew.y = 0;
				tmpVec4PositionNew.z = 0;
				tmpVec4PositionNew.w = 1;


				std::map<unsigned short, float>& tmpMapOneVertexBoneWeight = mVectorWeight[tmpVectorWeightIndex];

				

				int tmpMapOneVertexBoneWeightBoneIndex = 0;


				for (std::map<unsigned short, float>::iterator tmpIterBegin = tmpMapOneVertexBoneWeight.begin(); tmpIterBegin != tmpMapOneVertexBoneWeight.end(); tmpIterBegin++)

				
				{
					glm::vec4 tmpPosition = mVectorVertexPositionNoBone[tmpVectorWeightIndex][tmpMapOneVertexBoneWeightBoneIndex];

					tmpPosition = tmpMapBoneMatrixIterBegin->second[tmpIterBegin->first] * tmpIterBegin->second*tmpPosition;

					tmpVec4PositionNew += tmpPosition;

					tmpMapOneVertexBoneWeightBoneIndex++;
				}

				
				tmpVec3PositionAnim[tmpVectorWeightIndex] = glm::vec3(tmpVec4PositionNew.x, tmpVec4PositionNew.y, tmpVec4PositionNew.z);

				
			}

			mMesh->ApplySkin();

			break;
		}
	}

	/*int tmpUpdateCost = GetTickCount() - tmpUpdateBeginTime;
	int a = 0;

	Helper::LOG("%d", tmpUpdateCost);*/
}
