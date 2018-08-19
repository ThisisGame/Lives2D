#pragma once
#include "Renderer.h"
#include<vector>
#include<map>
#include"glm/glm.hpp"

class AnimClip
{
public:
	AnimClip(const char* varName, const int varBegin, const int varEnd):mName(nullptr),mBegin(0),mEnd(0)
	{
		mName = varName;
		mBegin = varBegin;
		mEnd = varEnd;
	}


	~AnimClip()
	{

	}

public:
	const char* mName;
	int mBegin;
	int mEnd;
};

class SkinMeshRenderer:Component
{
	DECLEAR_DYNCRT_ACTION(SkinMeshRenderer)

public:
	SkinMeshRenderer();
	~SkinMeshRenderer();

	void InitWithXml(TiXmlElement* varTiXmlElement) override;

	void Play(const char* varName);

private:
	void LoadAnim(const char* varAnimPath);

public:
	void Update() override;


private:
	std::vector<AnimClip*> mVectorAnimClip;//AnimParts parse from xml

	const char* mCurrentAnimClip;//current playing animclip
	const char* mNextAnimClip;//will playing animclip

	std::vector<std::string> mVectorBoneName;

	std::vector<glm::mat4x4> mVectorBoneMatrixInvert;

	std::map<int, vector<glm::mat4x4>> mMapBoneMatrix;


	std::vector<std::map<unsigned short, float>> mVectorWeight;


	std::map<unsigned short, std::vector<glm::vec4>> mMapPositionInvert;

	

	std::vector<std::vector<glm::vec4>> mVectorVertexPositionNoBone;

	float mRunningTime;

	Mesh* mMesh;

	int mFrameCount;
	int mFrameTicks;
};

